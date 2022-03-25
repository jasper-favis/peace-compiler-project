
#include "wci/intermediate/TypeSpec.h"
using namespace wci::intermediate;


// Generated from Peace.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"
#include "PeaceParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by PeaceParser.
 */
class  PeaceVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by PeaceParser.
   */
    virtual antlrcpp::Any visitProgram(PeaceParser::ProgramContext *context) = 0;

    virtual antlrcpp::Any visitHeader(PeaceParser::HeaderContext *context) = 0;

    virtual antlrcpp::Any visitMainBlock(PeaceParser::MainBlockContext *context) = 0;

    virtual antlrcpp::Any visitBlock(PeaceParser::BlockContext *context) = 0;

    virtual antlrcpp::Any visitMain(PeaceParser::MainContext *context) = 0;

    virtual antlrcpp::Any visitMainBody(PeaceParser::MainBodyContext *context) = 0;

    virtual antlrcpp::Any visitDeclarations(PeaceParser::DeclarationsContext *context) = 0;

    virtual antlrcpp::Any visitDeclList(PeaceParser::DeclListContext *context) = 0;

    virtual antlrcpp::Any visitDecl(PeaceParser::DeclContext *context) = 0;

    virtual antlrcpp::Any visitVarList(PeaceParser::VarListContext *context) = 0;

    virtual antlrcpp::Any visitVarId(PeaceParser::VarIdContext *context) = 0;

    virtual antlrcpp::Any visitTypeId(PeaceParser::TypeIdContext *context) = 0;

    virtual antlrcpp::Any visitDefinitions(PeaceParser::DefinitionsContext *context) = 0;

    virtual antlrcpp::Any visitDefinitionsList(PeaceParser::DefinitionsListContext *context) = 0;

    virtual antlrcpp::Any visitDef(PeaceParser::DefContext *context) = 0;

    virtual antlrcpp::Any visitProc(PeaceParser::ProcContext *context) = 0;

    virtual antlrcpp::Any visitProcBody(PeaceParser::ProcBodyContext *context) = 0;

    virtual antlrcpp::Any visitFunc(PeaceParser::FuncContext *context) = 0;

    virtual antlrcpp::Any visitFuncBody(PeaceParser::FuncBodyContext *context) = 0;

    virtual antlrcpp::Any visitFuncDeclarations(PeaceParser::FuncDeclarationsContext *context) = 0;

    virtual antlrcpp::Any visitFuncDeclList(PeaceParser::FuncDeclListContext *context) = 0;

    virtual antlrcpp::Any visitFuncDecl(PeaceParser::FuncDeclContext *context) = 0;

    virtual antlrcpp::Any visitParameterList(PeaceParser::ParameterListContext *context) = 0;

    virtual antlrcpp::Any visitParameter(PeaceParser::ParameterContext *context) = 0;

    virtual antlrcpp::Any visitCompoundStmt(PeaceParser::CompoundStmtContext *context) = 0;

    virtual antlrcpp::Any visitStmt(PeaceParser::StmtContext *context) = 0;

    virtual antlrcpp::Any visitStmtList(PeaceParser::StmtListContext *context) = 0;

    virtual antlrcpp::Any visitAssignmentStmt(PeaceParser::AssignmentStmtContext *context) = 0;

    virtual antlrcpp::Any visitIf_stmt(PeaceParser::If_stmtContext *context) = 0;

    virtual antlrcpp::Any visitWhileStmt(PeaceParser::WhileStmtContext *context) = 0;

    virtual antlrcpp::Any visitPrint(PeaceParser::PrintContext *context) = 0;

    virtual antlrcpp::Any visitProcCall(PeaceParser::ProcCallContext *context) = 0;

    virtual antlrcpp::Any visitReturnStmt(PeaceParser::ReturnStmtContext *context) = 0;

    virtual antlrcpp::Any visitPrintVariables(PeaceParser::PrintVariablesContext *context) = 0;

    virtual antlrcpp::Any visitVariable(PeaceParser::VariableContext *context) = 0;

    virtual antlrcpp::Any visitVariableExpr(PeaceParser::VariableExprContext *context) = 0;

    virtual antlrcpp::Any visitAddSubExpr(PeaceParser::AddSubExprContext *context) = 0;

    virtual antlrcpp::Any visitFuncCallExpr(PeaceParser::FuncCallExprContext *context) = 0;

    virtual antlrcpp::Any visitUnsignedNumberExpr(PeaceParser::UnsignedNumberExprContext *context) = 0;

    virtual antlrcpp::Any visitBoolExpr(PeaceParser::BoolExprContext *context) = 0;

    virtual antlrcpp::Any visitMulDivExpr(PeaceParser::MulDivExprContext *context) = 0;

    virtual antlrcpp::Any visitParenExpr(PeaceParser::ParenExprContext *context) = 0;

    virtual antlrcpp::Any visitSignedNumberExpr(PeaceParser::SignedNumberExprContext *context) = 0;

    virtual antlrcpp::Any visitMulDivOp(PeaceParser::MulDivOpContext *context) = 0;

    virtual antlrcpp::Any visitAddSubOp(PeaceParser::AddSubOpContext *context) = 0;

    virtual antlrcpp::Any visitRelOp(PeaceParser::RelOpContext *context) = 0;

    virtual antlrcpp::Any visitFuncCall(PeaceParser::FuncCallContext *context) = 0;

    virtual antlrcpp::Any visitSignedNumber(PeaceParser::SignedNumberContext *context) = 0;

    virtual antlrcpp::Any visitSign(PeaceParser::SignContext *context) = 0;

    virtual antlrcpp::Any visitIntegerConst(PeaceParser::IntegerConstContext *context) = 0;

    virtual antlrcpp::Any visitFloatConst(PeaceParser::FloatConstContext *context) = 0;


};

