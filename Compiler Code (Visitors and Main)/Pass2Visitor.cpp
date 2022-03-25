#include <iostream>
#include <string>
#include <regex>

#include "Pass2Visitor.h"
#include "wci/intermediate/SymTabStack.h"
#include "wci/intermediate/SymTabEntry.h"
#include "wci/intermediate/TypeSpec.h"
#include "wci/intermediate/symtabimpl/Predefined.h"
#include "wci/intermediate/symtabimpl/SymTabEntryImpl.h"

using namespace wci;
using namespace wci::intermediate;
using namespace wci::intermediate::symtabimpl;

Pass2Visitor::Pass2Visitor(ostream& j_file)
    : program_name(""), j_file(j_file)
{
}

Pass2Visitor::~Pass2Visitor() {}

antlrcpp::Any Pass2Visitor::visitProgram(PeaceParser::ProgramContext *ctx)
{
    auto value = visitChildren(ctx);
    //j_file.close();
    return value;
}

antlrcpp::Any Pass2Visitor::visitHeader(PeaceParser::HeaderContext *ctx)
{
    program_name = ctx->IDENTIFIER()->toString();
    return visitChildren(ctx);
}

antlrcpp::Any Pass2Visitor::visitMainBlock(PeaceParser::MainBlockContext *ctx)
{
    auto value = visitChildren(ctx);

    return value;
}

//////////////
//   NEW    //
//////////////
antlrcpp::Any Pass2Visitor::visitParameterList(PeaceParser::ParameterListContext *ctx)
{
	for (string i: ctx->paramList)
		j_file << i;

	return visitChildren(ctx);
}

//////////////
//   NEW    //
//////////////
antlrcpp::Any Pass2Visitor::visitParameter(PeaceParser::ParameterContext *ctx)
{
	localVars.push_back(ctx->localsVarArr.back());

	// TEST
//	Object slot = localVars.back()->get_attribute((SymTabKey) DATA_VALUE);
//	int slotNum = boost::any_cast<int>(slot);
//	cout << slotNum << endl;

	return visitChildren(ctx);
}

//////////////
//   NEW    //
//////////////
antlrcpp::Any Pass2Visitor::visitFuncDecl(PeaceParser::FuncDeclContext *ctx)
{
	j_file << "\n; " << ctx->getText() << "\n" << endl;

	for (string i: ctx->localsArr)
		j_file << i;

	for (SymTabEntry *i: ctx->localsVarArr)
		localVars.push_back(i);

	return visitChildren(ctx);
}

//////////////
//   NEW    //
//////////////
antlrcpp::Any Pass2Visitor::visitMain(PeaceParser::MainContext *ctx)
{
	// Emit the main program header.
	j_file << endl;
	j_file << ".method public static main([Ljava/lang/String;)V" << endl;
	j_file << endl;
	j_file << "\tnew RunTimer" << endl;
	j_file << "\tdup" << endl;
	j_file << "\tinvokenonvirtual  RunTimer/<init>()V" << endl;
	j_file << "\tputstatic         " << program_name
		   << "/_runTimer LRunTimer;" << endl;
	j_file << "\tnew PascalTextIn" << endl;
	j_file << "\tdup" << endl;
	j_file << "\tinvokenonvirtual  PascalTextIn/<init>()V" << endl;
	j_file << "\tputstatic         " + program_name
		   << "/_standardIn LPascalTextIn;" << endl;

	auto value = visitChildren(ctx);

	// Emit the main program epilogue.
	j_file << endl;
	j_file << "\tgetstatic         " << program_name
			   << "/_runTimer LRunTimer;" << endl;
	j_file << "\tinvokevirtual     RunTimer.printElapsedTime()V" << endl;
	j_file << endl;
	j_file << "\treturn" << endl;
	j_file << endl;
	j_file << ".limit locals " << ++ctx->limitLocals << endl;
	j_file << ".limit stack 50" << endl;
	j_file << ".end method" << endl;

	return value;
}

antlrcpp::Any Pass2Visitor::visitStmt(PeaceParser::StmtContext *ctx)
{
    j_file << endl << "; " + ctx->getText() << endl << endl;

    return visitChildren(ctx);
}

//////////////
//   NEW    //
//////////////
antlrcpp::Any Pass2Visitor::visitAssignmentStmt(PeaceParser::AssignmentStmtContext *ctx)
{
    auto value = visit(ctx->expr());

    // Determine type of expression
    string type_indicator =
                  (ctx->expr()->type == Predefined::integer_type) ? "I"
                : (ctx->expr()->type == Predefined::real_type)    ? "F"
                :                                                   "?";

    // Determine whether assignment is to program or local variable

    bool val = false;
    string varType;
    int varSlot;
    string varName = ctx->variable()->getText();
    SymTabEntry *l = nullptr;
    TypeSpec *t = nullptr;

    for (SymTabEntry *i : localVars)
    {
    	if (varName == i->get_name())
    	{
    		l = i;
    		val = true;
    		break;
    	}
    }
    if (val)
    {
    	varSlot = boost::any_cast<int>( l->get_attribute((SymTabKey) DATA_VALUE) );
    	t = l->get_typespec();
        varType = (t == Predefined::integer_type) ? "i" :
        		  (t == Predefined::real_type)    ? "f" :
        				                            "?" ;

        j_file << "\t" << varType << "store " << varSlot << endl;
    }
    else
    {
        // Emit a field put instruction.
        j_file << "\tputstatic         " << program_name
               << "/" << ctx->variable()->IDENTIFIER()->toString()
               << " " << type_indicator << endl;
    }

	// store instuction pops 1 operand
	--maxStack;

    return value;
}

//////////////
//   NEW    //
//////////////
antlrcpp::Any Pass2Visitor::visitIf_stmt(PeaceParser::If_stmtContext *ctx)
{
	auto value = visit(ctx->expr());

	string label = pad(++labelNumber);
	j_file << "\t" << "ifeq              L" << label << endl;

	// ifeq pops 1 operand
	--maxStack;

    value = visit(ctx->stmt());

    j_file << "L" << label << ":" << endl;

    return value;
}

//////////////
//   NEW    //
//////////////
antlrcpp::Any Pass2Visitor::visitWhileStmt(PeaceParser::WhileStmtContext *ctx)
{
	string loopLab = pad(++labelNumber);
	string lab;
	j_file << "L" << loopLab << ":" << endl;

	auto value = visit(ctx->expr());

	lab = pad(++labelNumber);
	j_file << "\t" << "ifeq              L" << lab << endl;

	// ifeq pops 1 operand
	--maxStack;

	value = visit(ctx->stmt());

	j_file << "\tgoto              L" << loopLab << endl;
	j_file << "L" << lab << ":" << endl;

	return value;
}

/////////////////
//   CHANGED   //
/////////////////
antlrcpp::Any Pass2Visitor::visitAddSubExpr(PeaceParser::AddSubExprContext *ctx)
{
    auto value = visitChildren(ctx);

    TypeSpec *type1 = ctx->expr(0)->type;
    TypeSpec *type2 = ctx->expr(1)->type;

    bool integer_mode =    (type1 == Predefined::integer_type)
                        && (type2 == Predefined::integer_type);
    bool real_mode    =    (type1 == Predefined::real_type)
                        && (type2 == Predefined::real_type);

    string op = ctx->addSubOp()->getText();
    string opcode;

    if (op == "+")
    {
        opcode = integer_mode ? "iadd"
               : real_mode    ? "fadd"
               :                "????";
    }
    else
    {
        opcode = integer_mode ? "isub"
               : real_mode    ? "fsub"
               :                "????";
    }

    // Emit an add or subtract instruction.
    j_file << "\t" << opcode << endl;

	// add & sub instructions pop 2 operands and pushes result onto stack
	if (opcode != "????")
		--maxStack;

    return value;
}

/////////////////
//   CHANGED   //
/////////////////
antlrcpp::Any Pass2Visitor::visitMulDivExpr(PeaceParser::MulDivExprContext *ctx)
{
	auto value = visitChildren(ctx);

	TypeSpec *type1 = ctx->expr(0)->type;
	TypeSpec *type2 = ctx->expr(1)->type;

	bool integer_mode =    (type1 == Predefined::integer_type)
						&& (type2 == Predefined::integer_type);
	bool real_mode    =    (type1 == Predefined::real_type)
						&& (type2 == Predefined::real_type);

	string op = ctx->mulDivOp()->getText();
	string opcode;

	if (op == "*")
	{
		opcode = integer_mode ? "imul"
			   : real_mode    ? "fmul"
			   :                "????";
	}
	else
	{
		opcode = integer_mode ? "idiv"
			   : real_mode    ? "fdiv"
			   :                "????";
	}

	// Emit a multiply or divide instruction.
	j_file << "\t" << opcode << endl;

	// mul & div instructions pop 2 operands and pushes result onto stack
	if (opcode != "????")
		--maxStack;

	return value;
}

/////////////////
//   CHANGED   //
/////////////////
antlrcpp::Any Pass2Visitor::visitVariableExpr(PeaceParser::VariableExprContext *ctx)
{
    string variable_name = ctx->variable()->IDENTIFIER()->toString();
    TypeSpec *type = ctx->type;

    string type_indicator = (type == Predefined::integer_type) ? "I"
                          : (type == Predefined::real_type)    ? "F"
                          :                                      "?";

    int varSlot;
	string varType;
	string varName = ctx->variable()->getText();
	SymTabEntry *local = nullptr;
	type = nullptr;

	for (SymTabEntry *i : localVars)
	{
		if (varName == i->get_name())
		{
			local = i;
			break;
		}
	}

	if (local != nullptr)
	{
		varSlot = boost::any_cast<int>( local->get_attribute((SymTabKey) DATA_VALUE) );

		type = local->get_typespec();
		varType = (type == Predefined::integer_type) ? "i" :
			      (type == Predefined::real_type)    ? "f" :
							       					"?" ;

		j_file << "\t" << varType << "load " << varSlot << endl;
	}
	else
	{
	    // Emit a field get instruction.
	    j_file << "\tgetstatic         " << program_name
	           << "/" << variable_name << " " << type_indicator << endl;
	}

	// Load instruction pushes 1 operand to the stack
	// If current stack size > stack limit
	// set new stack limit
	if (type_indicator != "?")
	{
		if (++maxStack > stackLimit)
			stackLimit = maxStack;
	}

    return visitChildren(ctx);
}

//////////////
//   NEW    //
//////////////
antlrcpp::Any Pass2Visitor::visitBoolExpr(PeaceParser::BoolExprContext *ctx)
{
	auto value = visitChildren(ctx);

	TypeSpec *type1 = ctx->expr(0)->type;
	TypeSpec *type2 = ctx->expr(1)->type;

	bool integer_mode =    (type1 == Predefined::integer_type)
						&& (type2 == Predefined::integer_type);
	bool real_mode    =    (type1 == Predefined::real_type)
						&& (type2 == Predefined::real_type);

	string op = ctx->relOp()->getText();
	string opcode   = "";
	string opcodeR1 = "";
	string opcodeR2 = "";
	string zero = "";
	string one  = "";

	int lTrue;
	string labelTrue;
	int lExit;
	string labelExit;
	int lPop;
	string labelPop;

	if (integer_mode)
	{
		if (op == "==")
			opcode = "if_icmpeq";
		else if (op == "!=")
			opcode = "if_icmpne";
		else if (op == "<")
			opcode = "if_icmplt";
		else if (op == "<=")
			opcode = "if_icmple";
		else if (op == ">")
			opcode = "if_icmpgt";
		else if (op == ">=")
			opcode = "if_icmpge";
		else
			opcode = "????";

		// Emit a boolean expression for integers
		lTrue = ++labelNumber;
		labelTrue = pad(lTrue);

		j_file << "\t" << opcode << "         L" << labelTrue << endl;
		j_file << "\t" << "iconst_0" << endl;

		lExit = ++labelNumber;
		labelExit = pad(lExit);

		j_file << "\t" << "goto              L" << labelExit << endl;
		j_file << "L" << labelTrue << ":" << endl;
		j_file << "\t" << "iconst_1" << endl;
		j_file << "L" << labelExit << ":" << endl;
	}
	else if (real_mode)
	{

		if (op == "==")
			opcodeR1 = "ifeq";
		else if (op == "!=")
		{
			opcodeR1 = "ifeq";
			opcodeR2 = "NE";
		}
		else if (op == "<")
			opcodeR1 = "iflt";
		else if (op == "<=")
		{
			opcodeR1 = "iflt";
			opcodeR2 = "ifeq";
		}
		else if (op == ">")
			opcodeR1 = "ifgt";
		else if (op == ">=")
		{
			opcodeR1 = "ifgt";
			opcodeR2 = "ifeq";
		}
		else
			opcodeR1 = "????";

		j_file << "\tfcmp" << endl;

		if (opcodeR2 == "" || opcodeR2 == "NE")
		{
			zero = (opcodeR2 == "NE") ? "1" : "0";
			one  = (opcodeR2 == "NE") ? "0" : "1";

			lTrue = ++labelNumber;
			labelTrue = pad(lTrue);

			j_file << "\t" << opcodeR1 << "              L" << labelTrue << endl;
			j_file << "\t" << "iconst_" << zero << endl;

			lExit = ++labelNumber;
			labelExit = pad(lExit);

			j_file << "\t" << "goto              L" << labelExit << endl;
			j_file << "L" << labelTrue << ":" << endl;
			j_file << "\t" << "iconst_" << one << endl;
			j_file << "L" << labelExit << ":" << endl;
		}
		else
		{
			lPop = ++labelNumber;
			labelPop = pad(lPop);

			j_file << "\tdup" << endl;
			j_file << "\t" << opcodeR1 << "              L" << labelPop << endl;

			lTrue = ++labelNumber;
			labelTrue = pad(lTrue);

			j_file << "\t" << opcodeR2 << "              L" << labelTrue << endl;
			j_file << "\t" << "iconst_0" << endl;

			lExit = ++labelNumber;
			labelExit = pad(lExit);

			j_file << "\t" << "goto              L" << labelExit << endl;


			j_file << "L" << labelPop << ":\n"
				   << "\tpop" << endl;
			j_file << "L" << labelTrue << ":\n"
				   << "\ticonst_1" << endl;
			j_file << "L" << labelExit << ":\n";
		}
	}

	maxStack += 3;
	if (maxStack > stackLimit)
		stackLimit = maxStack;
	maxStack -= 3;

	return value;
}

antlrcpp::Any Pass2Visitor::visitSignedNumber(PeaceParser::SignedNumberContext *ctx)
{
    auto value = visitChildren(ctx);
    TypeSpec *type = ctx->number()->type;

    if (ctx->sign()->children[0] == ctx->sign()->SUB_OP())
    {
        string opcode = (type == Predefined::integer_type) ? "ineg"
                      : (type == Predefined::real_type)    ? "fneg"
                      :                                      "?neg";

        // Emit a negate instruction.
        j_file << "\t" << opcode << endl;
    }

    return value;
}

/////////////////
//   CHANGED   //
/////////////////
antlrcpp::Any Pass2Visitor::visitIntegerConst(PeaceParser::IntegerConstContext *ctx)
{
    // Emit a load constant instruction.
    j_file << "\tldc               " << ctx->getText() << endl;

    // ldc increments stack by 1
    // If current size of operand stack > stack limit,
    // set new stack limit
    if (++maxStack > stackLimit)
    	stackLimit = maxStack;

    return visitChildren(ctx);
}

/////////////////
//   CHANGED   //
/////////////////
antlrcpp::Any Pass2Visitor::visitFloatConst(PeaceParser::FloatConstContext *ctx)
{
    // Emit a load constant instruction.
    j_file << "\tldc               " << ctx->getText() << endl;

    // ldc increments stack by 1
    // If current size of operand stack > stack limit,
    // set new stack limit
    if (++maxStack > stackLimit)
    	stackLimit = maxStack;

    return visitChildren(ctx);
}

//////////////
//   NEW    //
//////////////
antlrcpp::Any Pass2Visitor::visitProc(PeaceParser::ProcContext *ctx)
{
	j_file << endl << "; " + ctx->getText() << endl << endl;

	// Clear stack limit
	stackLimit = 0;
	// Clear max stack size
	maxStack   = 0;


	j_file << ".method private static " << ctx->IDENTIFIER()->toString()
		   << "(" << ctx->parameterTypes << ")V\n";

	auto value = visitChildren(ctx);

	j_file << "\treturn" << endl;

	// Emit routine epilogue
	j_file << ".limit locals " << ctx->limitLocals << endl;
	j_file << ".limit stack " << stackLimit << endl;
	j_file << ".end method" << endl;

	return value;
}

//////////////
//   NEW    //
//////////////
antlrcpp::Any Pass2Visitor::visitFunc(PeaceParser::FuncContext *ctx)
{
	j_file << endl << "; " + ctx->getText() << endl << endl;

	// Clear stack limit
	stackLimit = 0;
	// Clear max stack size
	maxStack   = 0;


    string type_name = ctx->typeId()->getText();
    string returnType;

    returnType = (type_name == "integer") ?  "I" :
    		     (type_name == "real")    ?  "F" :
    		    		                     "?" ;

	j_file << ".method private static " << ctx->IDENTIFIER()->toString()
		   << "(" << ctx->parameterTypes << ")" << returnType << "\n";

	auto value = visitChildren(ctx);

	j_file << "\t" << to_lower(returnType) << "return" << endl;

	// Emit routine epilogue
	j_file << ".limit locals " << ctx->limitLocals << endl;
	j_file << ".limit stack " << stackLimit << endl;
	j_file << ".end method" << endl;

	return value;
}

//////////////
//   NEW    //
//////////////
antlrcpp::Any Pass2Visitor::visitProcCall(PeaceParser::ProcCallContext *ctx)
{
    auto value = visitChildren(ctx);

    j_file << "\tinvokestatic      " << program_name
    	   << "/" << ctx->IDENTIFIER()->toString()
		   << "(" << ctx->parameterTypes << ")" << "V"
		   << endl;

	return value;
}

//////////////
//   NEW    //
//////////////
antlrcpp::Any Pass2Visitor::visitFuncCallExpr(PeaceParser::FuncCallExprContext *ctx)
{
    auto value = visitChildren(ctx);

    TypeSpec *type = ctx->type;
    string type_indicator = (type == Predefined::integer_type) ? "I"
                          : (type == Predefined::real_type)    ? "F"
                          :                                      "?";

    j_file << "\tinvokestatic      " << program_name
    	   << "/" << ctx->funcCall()->IDENTIFIER()->toString()
		   << "(" << ctx->parameterTypes << ")" << type_indicator
		   << endl;

	return value;
}

//////////////
//   NEW    //
//////////////
antlrcpp::Any Pass2Visitor::visitReturnStmt(PeaceParser::ReturnStmtContext *ctx)
{
	j_file << endl << "; " + ctx->getText() << endl << endl;

    auto value = visitChildren(ctx);

	return value;
}

//////////////
//   NEW    //
//////////////
antlrcpp::Any Pass2Visitor::visitPrint(PeaceParser::PrintContext *ctx)
{
	auto value = visitChildren(ctx);

	string printText = ctx->getText();
	string stringConstant = ctx->STRING()->toString();

	int index = 0;
	int varCount = 0;
	string indexLoad;

    j_file << "\tgetstatic         java/lang/System/out Ljava/io/PrintStream;" << endl;

    if (!stringConstant.empty())
    	j_file << "\tldc               " << stringConstant << endl;

    varCount = ctx->printVars.size();

    if (varCount > 0)
    {
    	indexLoad = (varCount < 6) ? "\ticonst_" + to_string(varCount) : "ldc              ";
    	j_file << indexLoad << endl;

        j_file << "\tanewarray         java/lang/Object" << endl;
    	j_file << "\tdup" << endl;

		for (string ldInstr : ctx->printVars)
		{
			// 1. Push index onto stack
			// Use shortcut instructions if index is less than 6
			// otherwise use regular ldc instruction
			indexLoad = (index < 6) ? "\ticonst_" + to_string(index) : "\tldc        ";
	    	j_file << indexLoad << endl;

			// 2. Push variable onto stack then wrap it as integer or float object
			j_file << ldInstr << endl;

			// 3. Store wrapped variable into array
			j_file << "\taastore" << endl;

			// 4. If current index is less than array size, duplicate array address
			if (index < varCount - 1)
				j_file << "\tdup" << endl;

			++index;

			maxStack += 8;
			if (maxStack > stackLimit)
				stackLimit = maxStack;
			maxStack -= 8;

		}

		// Emit print function call with format parameters
		j_file << "\tinvokevirtual     java/io/PrintStream.printf(Ljava/lang/String;[Ljava/lang/Object;)Ljava/io/PrintStream;" << endl;

		j_file << "\tpop" << endl;
    }
    else
    	// Emit print function call without format parameters
    	j_file << "\tinvokevirtual     java/io/PrintStream.print(Ljava/lang/String;)V" << endl;


    return value;
}

//////////////
//   NEW    //
//////////////
string Pass2Visitor::pad(int num)
{
    string p;
    p = (num < 10)  ? "00" :
        (num < 100) ? "0"  :
        		      ""   ;
    return p += to_string(num);
}
