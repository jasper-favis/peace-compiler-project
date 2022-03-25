#ifndef PASS1VISITOR_H_
#define PASS1VISITOR_H_

#include <iostream>
#include "localVariables.h"

#include "wci/intermediate/SymTabStack.h"
#include "wci/intermediate/SymTabEntry.h"
#include "wci/intermediate/TypeSpec.h"

#include "PeaceBaseVisitor.h"
#include "antlr4-runtime.h"
#include "PeaceVisitor.h"

using namespace wci;
using namespace wci::intermediate;

class Pass1Visitor : public PeaceBaseVisitor
{
private:
    SymTabStack *symtab_stack;
    SymTabEntry *program_id;
    ofstream j_file;
    vector<SymTabEntry *> variable_id_list;
    vector<SymTabEntry *> localVars;          // NEW
    vector<string> parameter_id_list;         // NEW
	vector<string> printVariablesArr;         // NEW
	string program_name;                      // NEW
    string paramTypes;                        // NEW
    int slotNums = 0;                         // NEW


public:
    Pass1Visitor();
    virtual ~Pass1Visitor();

    ostream& get_assembly_file();

    antlrcpp::Any visitProgram(PeaceParser::ProgramContext *ctx) override;
    antlrcpp::Any visitHeader(PeaceParser::HeaderContext *ctx) override;
    antlrcpp::Any visitDeclarations(PeaceParser::DeclarationsContext *ctx) override;
    antlrcpp::Any visitDecl(PeaceParser::DeclContext *ctx) override;
    antlrcpp::Any visitFuncDecl(PeaceParser::FuncDeclContext *ctx) override;             // NEW
    antlrcpp::Any visitMain(PeaceParser::MainContext *ctx) override;                     // NEW
    antlrcpp::Any visitVarList(PeaceParser::VarListContext *ctx) override;
    antlrcpp::Any visitParameterList(PeaceParser::ParameterListContext *ctx) override;   // NEW
    antlrcpp::Any visitParameter(PeaceParser::ParameterContext *ctx) override;           // NEW
    antlrcpp::Any visitVarId(PeaceParser::VarIdContext *ctx) override;
    antlrcpp::Any visitTypeId(PeaceParser::TypeIdContext *ctx) override;
    antlrcpp::Any visitAddSubExpr(PeaceParser::AddSubExprContext *ctx) override;
    antlrcpp::Any visitMulDivExpr(PeaceParser::MulDivExprContext *ctx) override;
    antlrcpp::Any visitVariableExpr(PeaceParser::VariableExprContext *ctx) override;
    antlrcpp::Any visitSignedNumberExpr(PeaceParser::SignedNumberExprContext *ctx) override;
    antlrcpp::Any visitSignedNumber(PeaceParser::SignedNumberContext *ctx) override;
    antlrcpp::Any visitUnsignedNumberExpr(PeaceParser::UnsignedNumberExprContext *ctx) override;
    antlrcpp::Any visitBoolExpr(PeaceParser::BoolExprContext *ctx) override;             // NEW
    antlrcpp::Any visitIntegerConst(PeaceParser::IntegerConstContext *ctx) override;
    antlrcpp::Any visitFloatConst(PeaceParser::FloatConstContext *ctx) override;
    antlrcpp::Any visitParenExpr(PeaceParser::ParenExprContext *ctx) override;
    antlrcpp::Any visitProc(PeaceParser::ProcContext *ctx) override;                     // NEW
    antlrcpp::Any visitFunc(PeaceParser::FuncContext *ctx) override; 	                 // NEW
    antlrcpp::Any visitProcCall(PeaceParser::ProcCallContext *ctx) override;             // NEW
    antlrcpp::Any visitFuncCallExpr(PeaceParser::FuncCallExprContext *ctx) override;     // NEW
    antlrcpp::Any visitPrint(PeaceParser::PrintContext *ctx) override;                   // NEW
    antlrcpp::Any visitPrintVariables(PeaceParser::PrintVariablesContext *ctx) override; // NEW
};

#endif /* PASS1VISITOR_H_ */

