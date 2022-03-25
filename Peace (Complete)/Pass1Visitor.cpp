#include <iostream>
#include <string>
#include <vector>

#include "Pass1Visitor.h"
#include "wci/intermediate/SymTabFactory.h"
#include "wci/intermediate/symtabimpl/Predefined.h"
#include "wci/util/CrossReferencer.h"

using namespace std;
using namespace wci;
using namespace wci::intermediate;
using namespace wci::intermediate::symtabimpl;
using namespace wci::util;

Pass1Visitor::Pass1Visitor()
    : program_id(nullptr), j_file(nullptr)
{
    // Create and initialize the symbol table stack.
    symtab_stack = SymTabFactory::create_symtab_stack();
    Predefined::initialize(symtab_stack);

    //cout << "=== Pass1Visitor(): symtab stack initialized." << endl;
}

Pass1Visitor::~Pass1Visitor() {}

ostream& Pass1Visitor::get_assembly_file() { return j_file; }

antlrcpp::Any Pass1Visitor::visitProgram(PeaceParser::ProgramContext *ctx)
{
    auto value = visitChildren(ctx);

//    cout << "=== visitProgram: Printing xref table." << endl;

    // Print the cross-reference table.
    CrossReferencer cross_referencer;
    cross_referencer.print(symtab_stack);

    return value;
}

antlrcpp::Any Pass1Visitor::visitHeader(PeaceParser::HeaderContext *ctx)
{
//    cout << "=== visitHeader: " + ctx->getText() << endl;

    program_name = ctx->IDENTIFIER()->toString();

    program_id = symtab_stack->enter_local(program_name);
    program_id->set_definition((Definition)DF_PROGRAM);
    program_id->set_attribute((SymTabKey) ROUTINE_SYMTAB,
                              symtab_stack->push());
    symtab_stack->set_program_id(program_id);

    // Create the assembly output file.
    j_file.open(program_name + ".j");
    if (j_file.fail())
    {
            cout << "***** Cannot open assembly file." << endl;
            exit(-99);
    }

    // Emit the program header.
    j_file << ".class public " << program_name << endl;
    j_file << ".super java/lang/Object" << endl;

    // Emit the RunTimer and PascalTextIn fields.
    j_file << endl;
    j_file << ".field private static _runTimer LRunTimer;" << endl;
    j_file << ".field private static _standardIn LPascalTextIn;" << endl;

    return visitChildren(ctx);
}

antlrcpp::Any Pass1Visitor::visitDeclarations(PeaceParser::DeclarationsContext *ctx)
{
//    cout << "=== visitDeclarations: " << ctx->getText() << endl;

    auto value = visitChildren(ctx);

    // Emit the class constructor.
    j_file << endl;
    j_file << ".method public <init>()V" << endl;
    j_file << endl;
    j_file << "\taload_0" << endl;
    j_file << "\tinvokenonvirtual  java/lang/Object/<init>()V" << endl;
    j_file << "\treturn" << endl;
    j_file << endl;
    j_file << ".limit locals 1" << endl;
    j_file << ".limit stack 1" << endl;
    j_file << ".end method" << endl;

    return value;
}

antlrcpp::Any Pass1Visitor::visitDecl(PeaceParser::DeclContext *ctx)
{
//    cout << "=== visitDecl: " + ctx->getText() << endl;

    j_file << "\n; " << ctx->getText() << "\n" << endl;
    auto value = visitChildren(ctx);

	TypeSpec *type;
    string type_name = ctx->typeId()->getText();
    string type_indicator;

    if (type_name == "integer")
    {
        type = Predefined::integer_type;
        type_indicator = "I";
    }
    else if (type_name == "real")
    {
        type = Predefined::real_type;
        type_indicator = "F";
    }
    else
    {
        type = nullptr;
        type_indicator = "?";
    }

	for (SymTabEntry *id : variable_id_list)
	{
		id->set_typespec(type);

		// Emit a field declaration.
		j_file << ".field private static "
			   << id->get_name() << " " << type_indicator << endl;
	}

    return value;
}

//////////////
//   NEW    //
//////////////
antlrcpp::Any Pass1Visitor::visitFuncDecl(PeaceParser::FuncDeclContext *ctx)
{
    auto value = visitChildren(ctx);

	TypeSpec *type;
    string type_name = ctx->typeId()->getText();
    string type_indicator;

    if (type_name == "integer")
    {
        type = Predefined::integer_type;
        type_indicator = "I";
    }
    else if (type_name == "real")
    {
        type = Predefined::real_type;
        type_indicator = "F";
    }
    else
    {
        type = nullptr;
        type_indicator = "?";
    }


    string dec;
	for (SymTabEntry *id : variable_id_list)
	{
		id->set_typespec(type);
	    id->set_attribute((SymTabKey) DATA_VALUE, slotNums);
	    ctx->localsVarArr.push_back(id);

	    // Store local variable declarations to be used in print function
	    localVars.push_back(id);

		// Emit a variable declaration.
		dec = "\t.var " + to_string(slotNums) + " is " + id->get_name() + " " + type_indicator + "\n";
		slotNums++;
		ctx->localsArr.push_back(dec);
	}

    return value;
}

//////////////
//   NEW    //
//////////////
antlrcpp::Any Pass1Visitor::visitMain(PeaceParser::MainContext *ctx)
{
	slotNums = 0;

	auto value = visitChildren(ctx);

	ctx->limitLocals = slotNums;

	return value;
}


antlrcpp::Any Pass1Visitor::visitVarList(PeaceParser::VarListContext *ctx)
{
//    cout << "=== visitVarList: " + ctx->getText() << endl;

    variable_id_list.resize(0);

    return visitChildren(ctx);
}

//////////////
//   NEW    //
//////////////
antlrcpp::Any Pass1Visitor::visitParameterList(PeaceParser::ParameterListContext *ctx)
{
	variable_id_list.resize(0);
	parameter_id_list.resize(0);

    auto value = visitChildren(ctx);

    for (string i : parameter_id_list)
    	ctx->paramList.push_back(i);

    return value;
}

//////////////
//   NEW    //
//////////////
antlrcpp::Any Pass1Visitor::visitParameter(PeaceParser::ParameterContext *ctx)
{
	auto value = visitChildren(ctx);

	TypeSpec *type;
    string type_name = ctx->typeId()->getText();
    string type_indicator;

    if (type_name == "integer")
    {
        type = Predefined::integer_type;
        type_indicator = "I";
    }
    else if (type_name == "real")
    {
        type = Predefined::real_type;
        type_indicator = "F";
    }
    else
    {
        type = nullptr;
        type_indicator = "?";
    }

    // Store each parameter's type descriptor for method signature

    paramTypes += type_indicator;

    string variable_name = ctx->varId()->getText();

    SymTabEntry *variable_id = symtab_stack->lookup(variable_name);
    if (variable_id != nullptr)
    {
		variable_id->set_typespec(type);
		variable_id->set_attribute((SymTabKey) DATA_VALUE, slotNums);
		ctx->localsVarArr.push_back(variable_id);
    }


    string slots = to_string(slotNums);

    string param = "\t.var " + slots + " is " + variable_name + " " + type_indicator + "\n";
    slotNums++;
    parameter_id_list.push_back(param);

    return value;
}

antlrcpp::Any Pass1Visitor::visitVarId(PeaceParser::VarIdContext *ctx)
{
//    cout << "=== visitVarId: " + ctx->getText() << endl;

    string variable_name = ctx->IDENTIFIER()->toString();

    SymTabEntry *variable_id = symtab_stack->enter_local(variable_name);
    variable_id->set_definition((Definition) DF_VARIABLE);

    variable_id_list.push_back(variable_id);

    return visitChildren(ctx);
}


antlrcpp::Any Pass1Visitor::visitTypeId(PeaceParser::TypeIdContext *ctx)
{
    return visitChildren(ctx);
}

antlrcpp::Any Pass1Visitor::visitAddSubExpr(PeaceParser::AddSubExprContext *ctx)
{
//    cout << "=== visitAddSubExpr: " + ctx->getText() << endl;

    auto value = visitChildren(ctx);

    TypeSpec *type1 = ctx->expr(0)->type;
    TypeSpec *type2 = ctx->expr(1)->type;

    bool integer_mode =    (type1 == Predefined::integer_type)
                        && (type2 == Predefined::integer_type);
    bool real_mode    =    (type1 == Predefined::real_type)
                        && (type2 == Predefined::real_type);

    TypeSpec *type = integer_mode ? Predefined::integer_type
                   : real_mode    ? Predefined::real_type
                   :                nullptr;

    ctx->type = type;

    return value;
}

antlrcpp::Any Pass1Visitor::visitMulDivExpr(PeaceParser::MulDivExprContext *ctx)
{
//    cout << "=== visitMulDivExpr: " + ctx->getText() << endl;

    auto value = visitChildren(ctx);

    TypeSpec *type1 = ctx->expr(0)->type;
    TypeSpec *type2 = ctx->expr(1)->type;

    bool integer_mode =    (type1 == Predefined::integer_type)
                        && (type2 == Predefined::integer_type);
    bool real_mode    =    (type1 == Predefined::real_type)
                        && (type2 == Predefined::real_type);

    TypeSpec *type = integer_mode ? Predefined::integer_type
                   : real_mode    ? Predefined::real_type
                   :                nullptr;

    ctx->type = type;

    return value;
}

antlrcpp::Any Pass1Visitor::visitVariableExpr(PeaceParser::VariableExprContext *ctx)
{
//    cout << "=== visitVariableExpr: " + ctx->getText() << endl;

    string variable_name = ctx->variable()->IDENTIFIER()->toString();
    SymTabEntry *variable_id = symtab_stack->lookup(variable_name);

    if (variable_id != nullptr)
    	ctx->type = variable_id->get_typespec();

    return visitChildren(ctx);
}

antlrcpp::Any Pass1Visitor::visitSignedNumberExpr(PeaceParser::SignedNumberExprContext *ctx)
{
//    cout << "=== visitSignedNumberExpr: " + ctx->getText() << endl;

    auto value = visitChildren(ctx);

    ctx->type = ctx->signedNumber()->type;

    return value;
}

antlrcpp::Any Pass1Visitor::visitSignedNumber(PeaceParser::SignedNumberContext *ctx)
{
//    cout << "=== visitSignedNumber: " + ctx->getText() << endl;

    auto value = visit(ctx->number());

    ctx->type = ctx->number()->type;

    return value;
}

antlrcpp::Any Pass1Visitor::visitUnsignedNumberExpr(PeaceParser::UnsignedNumberExprContext *ctx)
{
//    cout << "=== visitUnsignedNumberExpr: " + ctx->getText() << endl;

    auto value = visit(ctx->number());

    ctx->type = ctx->number()->type;

    return value;
}

//////////////
//   NEW    //
//////////////
antlrcpp::Any Pass1Visitor::visitBoolExpr(PeaceParser::BoolExprContext *ctx)
{
	ctx->type = Predefined::boolean_type;

    return visitChildren(ctx);
}

antlrcpp::Any Pass1Visitor::visitIntegerConst(PeaceParser::IntegerConstContext *ctx)
{
//    cout << "=== visitIntegerConst: " + ctx->getText() << endl;

    ctx->type = Predefined::integer_type;

    return visitChildren(ctx);
}

antlrcpp::Any Pass1Visitor::visitFloatConst(PeaceParser::FloatConstContext *ctx)
{
//    cout << "=== visitFloatConst: " + ctx->getText() << endl;

    ctx->type = Predefined::real_type;

    return visitChildren(ctx);
}

antlrcpp::Any Pass1Visitor::visitParenExpr(PeaceParser::ParenExprContext *ctx)
{
//    cout << "=== visitParenExpr: " + ctx->getText() << endl;

    auto value = visitChildren(ctx);

    ctx->type = ctx->expr()->type;

    return value;
}

//////////////
//   NEW    //
//////////////
antlrcpp::Any Pass1Visitor::visitProc(PeaceParser::ProcContext *ctx)
{
	paramTypes = "";
	slotNums = 0;
	localVars.resize(0);

	// Store procedure into the symbol table

    string procedure_name = ctx->IDENTIFIER()->toString();

    SymTabEntry *procedure_id = symtab_stack->enter_local(procedure_name);
    procedure_id->set_definition((Definition) DF_PROCEDURE);
    procedure_id->set_typespec(Predefined::undefined_type);

	auto value = visitChildren(ctx);

	procedure_id->set_attribute((SymTabKey) DATA_VALUE, paramTypes);
	ctx->parameterTypes = paramTypes;
	ctx->limitLocals = slotNums;

	return value;
}

//////////////
//   NEW    //
//////////////
antlrcpp::Any Pass1Visitor::visitFunc(PeaceParser::FuncContext *ctx)
{
	paramTypes = "";
	slotNums = 0;

	// Store function into the symbol table

    string function_name = ctx->IDENTIFIER()->toString();

	TypeSpec *type;
    string type_name = ctx->typeId()->getText();

    if (type_name == "integer")
        type = Predefined::integer_type;
    else if (type_name == "real")
        type = Predefined::real_type;
    else
        type = nullptr;

    SymTabEntry *function_id = symtab_stack->enter_local(function_name);
    function_id->set_definition((Definition) DF_FUNCTION);
    function_id->set_typespec(type);

	auto value = visitChildren(ctx);

	function_id->set_attribute((SymTabKey) DATA_VALUE, paramTypes);
	ctx->parameterTypes = paramTypes;
	ctx->limitLocals = slotNums;

	return value;
}

//////////////
//   NEW    //
//////////////
antlrcpp::Any Pass1Visitor::visitProcCall(PeaceParser::ProcCallContext *ctx)
{
	auto value = visitChildren(ctx);

    string procedure_name = ctx->IDENTIFIER()->toString();
    SymTabEntry *procedure_id = symtab_stack->lookup(procedure_name);

    if (procedure_id != nullptr)
    {
    	ctx->parameterTypes = boost::any_cast<string>( procedure_id->get_attribute((SymTabKey) DATA_VALUE) );
    }

	return value;
}

//////////////
//   NEW    //
//////////////
antlrcpp::Any Pass1Visitor::visitFuncCallExpr(PeaceParser::FuncCallExprContext *ctx)
{
	auto value = visitChildren(ctx);

    string function_name = ctx->funcCall()->IDENTIFIER()->toString();
    SymTabEntry *function_id = symtab_stack->lookup(function_name);

    if (function_id != nullptr)
    {
		ctx->type = function_id->get_typespec();
		ctx->parameterTypes = boost::any_cast<string>( function_id->get_attribute((SymTabKey) DATA_VALUE) );
    }

	return value;
}

//////////////
//   NEW    //
//////////////
antlrcpp::Any Pass1Visitor::visitPrint(PeaceParser::PrintContext *ctx)
{
	printVariablesArr.resize(0);

	auto value =  visitChildren(ctx);

	int slot;
	string variable_slot;
	string variable_type;
	string ldInstr;
	string wrapper;

	SymTabEntry *local = nullptr;
	TypeSpec    *type  = nullptr;

	for (string variable_name : printVariablesArr)
	{
		local = nullptr;
		type  = nullptr;

		for (SymTabEntry *i : localVars)
		{
			if (variable_name == i->get_name())
			{
				local = i;
				break;
			}
		}

		if (local != nullptr) // local variable?
		{
			slot = boost::any_cast<int>( local->get_attribute((SymTabKey) DATA_VALUE) );
		    variable_slot = to_string(slot);

			type = local->get_typespec();
			variable_type = (type == Predefined::integer_type) ? "i" :
				            (type == Predefined::real_type)    ? "f" :
 							                				     "?" ;

			// Emit local variable instruction
			ldInstr = "\t" + variable_type + "load_" + variable_slot + "\n";
		}
		else
		{
			local = symtab_stack->lookup(variable_name);
			if (local != nullptr)
				type = local->get_typespec();

			variable_type = (type == Predefined::integer_type) ? "I" :
							(type == Predefined::real_type)    ? "F" :
			 							                	     "?" ;

		    // Emit field variable instructions
		    ldInstr = "\tgetstatic         " + program_name
		            + "/" + variable_name + " " + variable_type + "\n";
		}

		ctx->printVars.push_back(ldInstr);

		wrapper = (variable_type == "I" || variable_type == "i") ?
				  "\tinvokestatic      java/lang/Integer.valueOf(I)Ljava/lang/Integer;":
				  (variable_type == "F" || variable_type == "f") ?
			      "\tinvokestatic      java/lang/Float.valueOf(F)Ljava/lang/Float;":
                  "?";

		ctx->printVars.back() += wrapper;
	}

	return value;
}

//////////////
//   NEW    //
//////////////
antlrcpp::Any Pass1Visitor::visitPrintVariables(PeaceParser::PrintVariablesContext *ctx)
{
	auto value = visitChildren(ctx);

	printVariablesArr.push_back( ctx->variable()->IDENTIFIER()->toString() );

	return value;
}
