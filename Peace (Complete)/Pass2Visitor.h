#ifndef PASS2VISITOR_H_
#define PASS2VISITOR_H_

#include <iostream>
#include <string>
#include <localVariables.h>

#include "wci/intermediate/SymTabStack.h"
#include "wci/intermediate/SymTabEntry.h"
#include "wci/intermediate/TypeSpec.h"

#include "PeaceBaseVisitor.h"
#include "antlr4-runtime.h"
#include "PeaceVisitor.h"

using namespace wci;
using namespace wci::intermediate;

class Pass2Visitor : public PeaceBaseVisitor
{
private:
	string program_name;
	ostream& j_file;
	int labelNumber  = 0;             // NEW
	int stackLimit   = 0;             // NEW Size limit of operand stack in method
	int maxStack     = 0;             // NEW Current max size of method operand stack
	vector<SymTabEntry *> localVars;  // NEW

public:
	Pass2Visitor(ostream& j_file);
    virtual ~Pass2Visitor();

    antlrcpp::Any visitProgram(PeaceParser::ProgramContext *ctx) override;
    antlrcpp::Any visitHeader(PeaceParser::HeaderContext *ctx) override;
    antlrcpp::Any visitMainBlock(PeaceParser::MainBlockContext *ctx) override;
    antlrcpp::Any visitParameterList(PeaceParser::ParameterListContext *ctx) override;   // NEW;
    antlrcpp::Any visitParameter(PeaceParser::ParameterContext *ctx) override;           // NEW
    antlrcpp::Any visitFuncDecl(PeaceParser::FuncDeclContext *ctx) override;             // NEW
    antlrcpp::Any visitMain(PeaceParser::MainContext *ctx) override;                     // NEW
    antlrcpp::Any visitStmt(PeaceParser::StmtContext *ctx) override;
    antlrcpp::Any visitAssignmentStmt(PeaceParser::AssignmentStmtContext *ctx) override;
    antlrcpp::Any visitIf_stmt(PeaceParser::If_stmtContext *ctx) override;               // NEW
    antlrcpp::Any visitWhileStmt(PeaceParser::WhileStmtContext *ctx) override;           // NEW
    antlrcpp::Any visitAddSubExpr(PeaceParser::AddSubExprContext *ctx) override;
    antlrcpp::Any visitMulDivExpr(PeaceParser::MulDivExprContext *ctx) override;
    antlrcpp::Any visitVariableExpr(PeaceParser::VariableExprContext *ctx) override;
    antlrcpp::Any visitBoolExpr(PeaceParser::BoolExprContext *ctx) override;             // NEW
    antlrcpp::Any visitSignedNumber(PeaceParser::SignedNumberContext *ctx) override;
    antlrcpp::Any visitIntegerConst(PeaceParser::IntegerConstContext *ctx) override;
    antlrcpp::Any visitFloatConst(PeaceParser::FloatConstContext *ctx) override;

    antlrcpp::Any visitProc(PeaceParser::ProcContext *ctx) override;                     // NEW
    antlrcpp::Any visitFunc(PeaceParser::FuncContext *ctx) override; 	                 // NEW
    antlrcpp::Any visitProcCall(PeaceParser::ProcCallContext *ctx) override;             // NEW
    antlrcpp::Any visitFuncCallExpr(PeaceParser::FuncCallExprContext *ctx) override;     // NEW
    antlrcpp::Any visitReturnStmt(PeaceParser::ReturnStmtContext *ctx) override;         // NEW
    antlrcpp::Any visitPrint(PeaceParser::PrintContext *ctx) override;                   // NEW

    string pad(int num);                                                                 // NEW
};

#endif /* PASS2VISITOR_H_ */
