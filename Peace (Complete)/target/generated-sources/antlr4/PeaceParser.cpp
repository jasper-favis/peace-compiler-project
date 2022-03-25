
#include "wci/intermediate/TypeSpec.h"
using namespace wci::intermediate;


// Generated from Peace.g4 by ANTLR 4.7.2


#include "PeaceVisitor.h"

#include "PeaceParser.h"


using namespace antlrcpp;
using namespace antlr4;

PeaceParser::PeaceParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

PeaceParser::~PeaceParser() {
  delete _interpreter;
}

std::string PeaceParser::getGrammarFileName() const {
  return "Peace.g4";
}

const std::vector<std::string>& PeaceParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& PeaceParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- ProgramContext ------------------------------------------------------------------

PeaceParser::ProgramContext::ProgramContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PeaceParser::HeaderContext* PeaceParser::ProgramContext::header() {
  return getRuleContext<PeaceParser::HeaderContext>(0);
}

PeaceParser::MainBlockContext* PeaceParser::ProgramContext::mainBlock() {
  return getRuleContext<PeaceParser::MainBlockContext>(0);
}


size_t PeaceParser::ProgramContext::getRuleIndex() const {
  return PeaceParser::RuleProgram;
}


antlrcpp::Any PeaceParser::ProgramContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PeaceVisitor*>(visitor))
    return parserVisitor->visitProgram(this);
  else
    return visitor->visitChildren(this);
}

PeaceParser::ProgramContext* PeaceParser::program() {
  ProgramContext *_localctx = _tracker.createInstance<ProgramContext>(_ctx, getState());
  enterRule(_localctx, 0, PeaceParser::RuleProgram);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(86);
    header();
    setState(87);
    mainBlock();
    setState(88);
    match(PeaceParser::T__0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- HeaderContext ------------------------------------------------------------------

PeaceParser::HeaderContext::HeaderContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PeaceParser::HeaderContext::PROG() {
  return getToken(PeaceParser::PROG, 0);
}

tree::TerminalNode* PeaceParser::HeaderContext::IDENTIFIER() {
  return getToken(PeaceParser::IDENTIFIER, 0);
}


size_t PeaceParser::HeaderContext::getRuleIndex() const {
  return PeaceParser::RuleHeader;
}


antlrcpp::Any PeaceParser::HeaderContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PeaceVisitor*>(visitor))
    return parserVisitor->visitHeader(this);
  else
    return visitor->visitChildren(this);
}

PeaceParser::HeaderContext* PeaceParser::header() {
  HeaderContext *_localctx = _tracker.createInstance<HeaderContext>(_ctx, getState());
  enterRule(_localctx, 2, PeaceParser::RuleHeader);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(90);
    match(PeaceParser::PROG);
    setState(91);
    match(PeaceParser::IDENTIFIER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- MainBlockContext ------------------------------------------------------------------

PeaceParser::MainBlockContext::MainBlockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PeaceParser::BlockContext* PeaceParser::MainBlockContext::block() {
  return getRuleContext<PeaceParser::BlockContext>(0);
}


size_t PeaceParser::MainBlockContext::getRuleIndex() const {
  return PeaceParser::RuleMainBlock;
}


antlrcpp::Any PeaceParser::MainBlockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PeaceVisitor*>(visitor))
    return parserVisitor->visitMainBlock(this);
  else
    return visitor->visitChildren(this);
}

PeaceParser::MainBlockContext* PeaceParser::mainBlock() {
  MainBlockContext *_localctx = _tracker.createInstance<MainBlockContext>(_ctx, getState());
  enterRule(_localctx, 4, PeaceParser::RuleMainBlock);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(93);
    block();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BlockContext ------------------------------------------------------------------

PeaceParser::BlockContext::BlockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PeaceParser::DeclarationsContext* PeaceParser::BlockContext::declarations() {
  return getRuleContext<PeaceParser::DeclarationsContext>(0);
}

PeaceParser::MainContext* PeaceParser::BlockContext::main() {
  return getRuleContext<PeaceParser::MainContext>(0);
}

PeaceParser::DefinitionsContext* PeaceParser::BlockContext::definitions() {
  return getRuleContext<PeaceParser::DefinitionsContext>(0);
}


size_t PeaceParser::BlockContext::getRuleIndex() const {
  return PeaceParser::RuleBlock;
}


antlrcpp::Any PeaceParser::BlockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PeaceVisitor*>(visitor))
    return parserVisitor->visitBlock(this);
  else
    return visitor->visitChildren(this);
}

PeaceParser::BlockContext* PeaceParser::block() {
  BlockContext *_localctx = _tracker.createInstance<BlockContext>(_ctx, getState());
  enterRule(_localctx, 6, PeaceParser::RuleBlock);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(95);
    declarations();
    setState(97);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PeaceParser::VOID

    || _la == PeaceParser::IDENTIFIER) {
      setState(96);
      definitions();
    }
    setState(99);
    main();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- MainContext ------------------------------------------------------------------

PeaceParser::MainContext::MainContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PeaceParser::MainContext::MAIN() {
  return getToken(PeaceParser::MAIN, 0);
}

PeaceParser::MainBodyContext* PeaceParser::MainContext::mainBody() {
  return getRuleContext<PeaceParser::MainBodyContext>(0);
}


size_t PeaceParser::MainContext::getRuleIndex() const {
  return PeaceParser::RuleMain;
}


antlrcpp::Any PeaceParser::MainContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PeaceVisitor*>(visitor))
    return parserVisitor->visitMain(this);
  else
    return visitor->visitChildren(this);
}

PeaceParser::MainContext* PeaceParser::main() {
  MainContext *_localctx = _tracker.createInstance<MainContext>(_ctx, getState());
  enterRule(_localctx, 8, PeaceParser::RuleMain);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(101);
    match(PeaceParser::MAIN);
    setState(102);
    mainBody();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- MainBodyContext ------------------------------------------------------------------

PeaceParser::MainBodyContext::MainBodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PeaceParser::StmtListContext* PeaceParser::MainBodyContext::stmtList() {
  return getRuleContext<PeaceParser::StmtListContext>(0);
}

PeaceParser::FuncDeclarationsContext* PeaceParser::MainBodyContext::funcDeclarations() {
  return getRuleContext<PeaceParser::FuncDeclarationsContext>(0);
}


size_t PeaceParser::MainBodyContext::getRuleIndex() const {
  return PeaceParser::RuleMainBody;
}


antlrcpp::Any PeaceParser::MainBodyContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PeaceVisitor*>(visitor))
    return parserVisitor->visitMainBody(this);
  else
    return visitor->visitChildren(this);
}

PeaceParser::MainBodyContext* PeaceParser::mainBody() {
  MainBodyContext *_localctx = _tracker.createInstance<MainBodyContext>(_ctx, getState());
  enterRule(_localctx, 10, PeaceParser::RuleMainBody);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(104);
    match(PeaceParser::T__1);
    setState(106);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx)) {
    case 1: {
      setState(105);
      funcDeclarations();
      break;
    }

    }
    setState(108);
    stmtList();
    setState(109);
    match(PeaceParser::T__2);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DeclarationsContext ------------------------------------------------------------------

PeaceParser::DeclarationsContext::DeclarationsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PeaceParser::DeclListContext* PeaceParser::DeclarationsContext::declList() {
  return getRuleContext<PeaceParser::DeclListContext>(0);
}


size_t PeaceParser::DeclarationsContext::getRuleIndex() const {
  return PeaceParser::RuleDeclarations;
}


antlrcpp::Any PeaceParser::DeclarationsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PeaceVisitor*>(visitor))
    return parserVisitor->visitDeclarations(this);
  else
    return visitor->visitChildren(this);
}

PeaceParser::DeclarationsContext* PeaceParser::declarations() {
  DeclarationsContext *_localctx = _tracker.createInstance<DeclarationsContext>(_ctx, getState());
  enterRule(_localctx, 12, PeaceParser::RuleDeclarations);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(111);
    declList();
    setState(112);
    match(PeaceParser::T__3);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DeclListContext ------------------------------------------------------------------

PeaceParser::DeclListContext::DeclListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<PeaceParser::DeclContext *> PeaceParser::DeclListContext::decl() {
  return getRuleContexts<PeaceParser::DeclContext>();
}

PeaceParser::DeclContext* PeaceParser::DeclListContext::decl(size_t i) {
  return getRuleContext<PeaceParser::DeclContext>(i);
}


size_t PeaceParser::DeclListContext::getRuleIndex() const {
  return PeaceParser::RuleDeclList;
}


antlrcpp::Any PeaceParser::DeclListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PeaceVisitor*>(visitor))
    return parserVisitor->visitDeclList(this);
  else
    return visitor->visitChildren(this);
}

PeaceParser::DeclListContext* PeaceParser::declList() {
  DeclListContext *_localctx = _tracker.createInstance<DeclListContext>(_ctx, getState());
  enterRule(_localctx, 14, PeaceParser::RuleDeclList);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(114);
    decl();
    setState(119);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(115);
        match(PeaceParser::T__3);
        setState(116);
        decl(); 
      }
      setState(121);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DeclContext ------------------------------------------------------------------

PeaceParser::DeclContext::DeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PeaceParser::TypeIdContext* PeaceParser::DeclContext::typeId() {
  return getRuleContext<PeaceParser::TypeIdContext>(0);
}

tree::TerminalNode* PeaceParser::DeclContext::SUB_OP() {
  return getToken(PeaceParser::SUB_OP, 0);
}

PeaceParser::VarListContext* PeaceParser::DeclContext::varList() {
  return getRuleContext<PeaceParser::VarListContext>(0);
}


size_t PeaceParser::DeclContext::getRuleIndex() const {
  return PeaceParser::RuleDecl;
}


antlrcpp::Any PeaceParser::DeclContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PeaceVisitor*>(visitor))
    return parserVisitor->visitDecl(this);
  else
    return visitor->visitChildren(this);
}

PeaceParser::DeclContext* PeaceParser::decl() {
  DeclContext *_localctx = _tracker.createInstance<DeclContext>(_ctx, getState());
  enterRule(_localctx, 16, PeaceParser::RuleDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(122);
    typeId();
    setState(123);
    match(PeaceParser::SUB_OP);
    setState(124);
    varList();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VarListContext ------------------------------------------------------------------

PeaceParser::VarListContext::VarListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<PeaceParser::VarIdContext *> PeaceParser::VarListContext::varId() {
  return getRuleContexts<PeaceParser::VarIdContext>();
}

PeaceParser::VarIdContext* PeaceParser::VarListContext::varId(size_t i) {
  return getRuleContext<PeaceParser::VarIdContext>(i);
}


size_t PeaceParser::VarListContext::getRuleIndex() const {
  return PeaceParser::RuleVarList;
}


antlrcpp::Any PeaceParser::VarListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PeaceVisitor*>(visitor))
    return parserVisitor->visitVarList(this);
  else
    return visitor->visitChildren(this);
}

PeaceParser::VarListContext* PeaceParser::varList() {
  VarListContext *_localctx = _tracker.createInstance<VarListContext>(_ctx, getState());
  enterRule(_localctx, 18, PeaceParser::RuleVarList);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(126);
    varId();
    setState(131);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == PeaceParser::T__4) {
      setState(127);
      match(PeaceParser::T__4);
      setState(128);
      varId();
      setState(133);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VarIdContext ------------------------------------------------------------------

PeaceParser::VarIdContext::VarIdContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PeaceParser::VarIdContext::IDENTIFIER() {
  return getToken(PeaceParser::IDENTIFIER, 0);
}


size_t PeaceParser::VarIdContext::getRuleIndex() const {
  return PeaceParser::RuleVarId;
}


antlrcpp::Any PeaceParser::VarIdContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PeaceVisitor*>(visitor))
    return parserVisitor->visitVarId(this);
  else
    return visitor->visitChildren(this);
}

PeaceParser::VarIdContext* PeaceParser::varId() {
  VarIdContext *_localctx = _tracker.createInstance<VarIdContext>(_ctx, getState());
  enterRule(_localctx, 20, PeaceParser::RuleVarId);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(134);
    match(PeaceParser::IDENTIFIER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeIdContext ------------------------------------------------------------------

PeaceParser::TypeIdContext::TypeIdContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PeaceParser::TypeIdContext::IDENTIFIER() {
  return getToken(PeaceParser::IDENTIFIER, 0);
}


size_t PeaceParser::TypeIdContext::getRuleIndex() const {
  return PeaceParser::RuleTypeId;
}


antlrcpp::Any PeaceParser::TypeIdContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PeaceVisitor*>(visitor))
    return parserVisitor->visitTypeId(this);
  else
    return visitor->visitChildren(this);
}

PeaceParser::TypeIdContext* PeaceParser::typeId() {
  TypeIdContext *_localctx = _tracker.createInstance<TypeIdContext>(_ctx, getState());
  enterRule(_localctx, 22, PeaceParser::RuleTypeId);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(136);
    match(PeaceParser::IDENTIFIER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DefinitionsContext ------------------------------------------------------------------

PeaceParser::DefinitionsContext::DefinitionsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PeaceParser::DefinitionsListContext* PeaceParser::DefinitionsContext::definitionsList() {
  return getRuleContext<PeaceParser::DefinitionsListContext>(0);
}


size_t PeaceParser::DefinitionsContext::getRuleIndex() const {
  return PeaceParser::RuleDefinitions;
}


antlrcpp::Any PeaceParser::DefinitionsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PeaceVisitor*>(visitor))
    return parserVisitor->visitDefinitions(this);
  else
    return visitor->visitChildren(this);
}

PeaceParser::DefinitionsContext* PeaceParser::definitions() {
  DefinitionsContext *_localctx = _tracker.createInstance<DefinitionsContext>(_ctx, getState());
  enterRule(_localctx, 24, PeaceParser::RuleDefinitions);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(138);
    definitionsList();
    setState(139);
    match(PeaceParser::T__3);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DefinitionsListContext ------------------------------------------------------------------

PeaceParser::DefinitionsListContext::DefinitionsListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<PeaceParser::DefContext *> PeaceParser::DefinitionsListContext::def() {
  return getRuleContexts<PeaceParser::DefContext>();
}

PeaceParser::DefContext* PeaceParser::DefinitionsListContext::def(size_t i) {
  return getRuleContext<PeaceParser::DefContext>(i);
}


size_t PeaceParser::DefinitionsListContext::getRuleIndex() const {
  return PeaceParser::RuleDefinitionsList;
}


antlrcpp::Any PeaceParser::DefinitionsListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PeaceVisitor*>(visitor))
    return parserVisitor->visitDefinitionsList(this);
  else
    return visitor->visitChildren(this);
}

PeaceParser::DefinitionsListContext* PeaceParser::definitionsList() {
  DefinitionsListContext *_localctx = _tracker.createInstance<DefinitionsListContext>(_ctx, getState());
  enterRule(_localctx, 26, PeaceParser::RuleDefinitionsList);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(141);
    def();
    setState(146);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(142);
        match(PeaceParser::T__3);
        setState(143);
        def(); 
      }
      setState(148);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DefContext ------------------------------------------------------------------

PeaceParser::DefContext::DefContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PeaceParser::ProcContext* PeaceParser::DefContext::proc() {
  return getRuleContext<PeaceParser::ProcContext>(0);
}

PeaceParser::FuncContext* PeaceParser::DefContext::func() {
  return getRuleContext<PeaceParser::FuncContext>(0);
}


size_t PeaceParser::DefContext::getRuleIndex() const {
  return PeaceParser::RuleDef;
}


antlrcpp::Any PeaceParser::DefContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PeaceVisitor*>(visitor))
    return parserVisitor->visitDef(this);
  else
    return visitor->visitChildren(this);
}

PeaceParser::DefContext* PeaceParser::def() {
  DefContext *_localctx = _tracker.createInstance<DefContext>(_ctx, getState());
  enterRule(_localctx, 28, PeaceParser::RuleDef);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(151);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PeaceParser::VOID: {
        setState(149);
        proc();
        break;
      }

      case PeaceParser::IDENTIFIER: {
        setState(150);
        func();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ProcContext ------------------------------------------------------------------

PeaceParser::ProcContext::ProcContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PeaceParser::ProcContext::VOID() {
  return getToken(PeaceParser::VOID, 0);
}

tree::TerminalNode* PeaceParser::ProcContext::IDENTIFIER() {
  return getToken(PeaceParser::IDENTIFIER, 0);
}

PeaceParser::ParameterListContext* PeaceParser::ProcContext::parameterList() {
  return getRuleContext<PeaceParser::ParameterListContext>(0);
}

PeaceParser::ProcBodyContext* PeaceParser::ProcContext::procBody() {
  return getRuleContext<PeaceParser::ProcBodyContext>(0);
}


size_t PeaceParser::ProcContext::getRuleIndex() const {
  return PeaceParser::RuleProc;
}


antlrcpp::Any PeaceParser::ProcContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PeaceVisitor*>(visitor))
    return parserVisitor->visitProc(this);
  else
    return visitor->visitChildren(this);
}

PeaceParser::ProcContext* PeaceParser::proc() {
  ProcContext *_localctx = _tracker.createInstance<ProcContext>(_ctx, getState());
  enterRule(_localctx, 30, PeaceParser::RuleProc);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(153);
    match(PeaceParser::VOID);
    setState(154);
    match(PeaceParser::IDENTIFIER);
    setState(155);
    match(PeaceParser::T__5);
    setState(156);
    parameterList();
    setState(157);
    match(PeaceParser::T__6);
    setState(158);
    procBody();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ProcBodyContext ------------------------------------------------------------------

PeaceParser::ProcBodyContext::ProcBodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PeaceParser::StmtListContext* PeaceParser::ProcBodyContext::stmtList() {
  return getRuleContext<PeaceParser::StmtListContext>(0);
}

PeaceParser::FuncDeclarationsContext* PeaceParser::ProcBodyContext::funcDeclarations() {
  return getRuleContext<PeaceParser::FuncDeclarationsContext>(0);
}


size_t PeaceParser::ProcBodyContext::getRuleIndex() const {
  return PeaceParser::RuleProcBody;
}


antlrcpp::Any PeaceParser::ProcBodyContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PeaceVisitor*>(visitor))
    return parserVisitor->visitProcBody(this);
  else
    return visitor->visitChildren(this);
}

PeaceParser::ProcBodyContext* PeaceParser::procBody() {
  ProcBodyContext *_localctx = _tracker.createInstance<ProcBodyContext>(_ctx, getState());
  enterRule(_localctx, 32, PeaceParser::RuleProcBody);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(160);
    match(PeaceParser::T__1);
    setState(162);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx)) {
    case 1: {
      setState(161);
      funcDeclarations();
      break;
    }

    }
    setState(164);
    stmtList();
    setState(165);
    match(PeaceParser::T__2);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FuncContext ------------------------------------------------------------------

PeaceParser::FuncContext::FuncContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PeaceParser::TypeIdContext* PeaceParser::FuncContext::typeId() {
  return getRuleContext<PeaceParser::TypeIdContext>(0);
}

tree::TerminalNode* PeaceParser::FuncContext::IDENTIFIER() {
  return getToken(PeaceParser::IDENTIFIER, 0);
}

PeaceParser::ParameterListContext* PeaceParser::FuncContext::parameterList() {
  return getRuleContext<PeaceParser::ParameterListContext>(0);
}

PeaceParser::FuncBodyContext* PeaceParser::FuncContext::funcBody() {
  return getRuleContext<PeaceParser::FuncBodyContext>(0);
}


size_t PeaceParser::FuncContext::getRuleIndex() const {
  return PeaceParser::RuleFunc;
}


antlrcpp::Any PeaceParser::FuncContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PeaceVisitor*>(visitor))
    return parserVisitor->visitFunc(this);
  else
    return visitor->visitChildren(this);
}

PeaceParser::FuncContext* PeaceParser::func() {
  FuncContext *_localctx = _tracker.createInstance<FuncContext>(_ctx, getState());
  enterRule(_localctx, 34, PeaceParser::RuleFunc);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(167);
    typeId();
    setState(168);
    match(PeaceParser::IDENTIFIER);
    setState(169);
    match(PeaceParser::T__5);
    setState(170);
    parameterList();
    setState(171);
    match(PeaceParser::T__6);
    setState(172);
    funcBody();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FuncBodyContext ------------------------------------------------------------------

PeaceParser::FuncBodyContext::FuncBodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PeaceParser::StmtListContext* PeaceParser::FuncBodyContext::stmtList() {
  return getRuleContext<PeaceParser::StmtListContext>(0);
}

PeaceParser::ReturnStmtContext* PeaceParser::FuncBodyContext::returnStmt() {
  return getRuleContext<PeaceParser::ReturnStmtContext>(0);
}

PeaceParser::FuncDeclarationsContext* PeaceParser::FuncBodyContext::funcDeclarations() {
  return getRuleContext<PeaceParser::FuncDeclarationsContext>(0);
}


size_t PeaceParser::FuncBodyContext::getRuleIndex() const {
  return PeaceParser::RuleFuncBody;
}


antlrcpp::Any PeaceParser::FuncBodyContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PeaceVisitor*>(visitor))
    return parserVisitor->visitFuncBody(this);
  else
    return visitor->visitChildren(this);
}

PeaceParser::FuncBodyContext* PeaceParser::funcBody() {
  FuncBodyContext *_localctx = _tracker.createInstance<FuncBodyContext>(_ctx, getState());
  enterRule(_localctx, 36, PeaceParser::RuleFuncBody);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(174);
    match(PeaceParser::T__1);
    setState(176);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx)) {
    case 1: {
      setState(175);
      funcDeclarations();
      break;
    }

    }
    setState(178);
    stmtList();
    setState(179);
    returnStmt();
    setState(180);
    match(PeaceParser::T__2);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FuncDeclarationsContext ------------------------------------------------------------------

PeaceParser::FuncDeclarationsContext::FuncDeclarationsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PeaceParser::FuncDeclListContext* PeaceParser::FuncDeclarationsContext::funcDeclList() {
  return getRuleContext<PeaceParser::FuncDeclListContext>(0);
}


size_t PeaceParser::FuncDeclarationsContext::getRuleIndex() const {
  return PeaceParser::RuleFuncDeclarations;
}


antlrcpp::Any PeaceParser::FuncDeclarationsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PeaceVisitor*>(visitor))
    return parserVisitor->visitFuncDeclarations(this);
  else
    return visitor->visitChildren(this);
}

PeaceParser::FuncDeclarationsContext* PeaceParser::funcDeclarations() {
  FuncDeclarationsContext *_localctx = _tracker.createInstance<FuncDeclarationsContext>(_ctx, getState());
  enterRule(_localctx, 38, PeaceParser::RuleFuncDeclarations);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(182);
    funcDeclList();
    setState(183);
    match(PeaceParser::T__3);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FuncDeclListContext ------------------------------------------------------------------

PeaceParser::FuncDeclListContext::FuncDeclListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<PeaceParser::FuncDeclContext *> PeaceParser::FuncDeclListContext::funcDecl() {
  return getRuleContexts<PeaceParser::FuncDeclContext>();
}

PeaceParser::FuncDeclContext* PeaceParser::FuncDeclListContext::funcDecl(size_t i) {
  return getRuleContext<PeaceParser::FuncDeclContext>(i);
}


size_t PeaceParser::FuncDeclListContext::getRuleIndex() const {
  return PeaceParser::RuleFuncDeclList;
}


antlrcpp::Any PeaceParser::FuncDeclListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PeaceVisitor*>(visitor))
    return parserVisitor->visitFuncDeclList(this);
  else
    return visitor->visitChildren(this);
}

PeaceParser::FuncDeclListContext* PeaceParser::funcDeclList() {
  FuncDeclListContext *_localctx = _tracker.createInstance<FuncDeclListContext>(_ctx, getState());
  enterRule(_localctx, 40, PeaceParser::RuleFuncDeclList);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(185);
    funcDecl();
    setState(190);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(186);
        match(PeaceParser::T__3);
        setState(187);
        funcDecl(); 
      }
      setState(192);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FuncDeclContext ------------------------------------------------------------------

PeaceParser::FuncDeclContext::FuncDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PeaceParser::TypeIdContext* PeaceParser::FuncDeclContext::typeId() {
  return getRuleContext<PeaceParser::TypeIdContext>(0);
}

PeaceParser::VarListContext* PeaceParser::FuncDeclContext::varList() {
  return getRuleContext<PeaceParser::VarListContext>(0);
}


size_t PeaceParser::FuncDeclContext::getRuleIndex() const {
  return PeaceParser::RuleFuncDecl;
}


antlrcpp::Any PeaceParser::FuncDeclContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PeaceVisitor*>(visitor))
    return parserVisitor->visitFuncDecl(this);
  else
    return visitor->visitChildren(this);
}

PeaceParser::FuncDeclContext* PeaceParser::funcDecl() {
  FuncDeclContext *_localctx = _tracker.createInstance<FuncDeclContext>(_ctx, getState());
  enterRule(_localctx, 42, PeaceParser::RuleFuncDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(193);
    typeId();
    setState(194);
    varList();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParameterListContext ------------------------------------------------------------------

PeaceParser::ParameterListContext::ParameterListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<PeaceParser::ParameterContext *> PeaceParser::ParameterListContext::parameter() {
  return getRuleContexts<PeaceParser::ParameterContext>();
}

PeaceParser::ParameterContext* PeaceParser::ParameterListContext::parameter(size_t i) {
  return getRuleContext<PeaceParser::ParameterContext>(i);
}


size_t PeaceParser::ParameterListContext::getRuleIndex() const {
  return PeaceParser::RuleParameterList;
}


antlrcpp::Any PeaceParser::ParameterListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PeaceVisitor*>(visitor))
    return parserVisitor->visitParameterList(this);
  else
    return visitor->visitChildren(this);
}

PeaceParser::ParameterListContext* PeaceParser::parameterList() {
  ParameterListContext *_localctx = _tracker.createInstance<ParameterListContext>(_ctx, getState());
  enterRule(_localctx, 44, PeaceParser::RuleParameterList);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(196);
    parameter();
    setState(201);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == PeaceParser::T__4) {
      setState(197);
      match(PeaceParser::T__4);
      setState(198);
      parameter();
      setState(203);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParameterContext ------------------------------------------------------------------

PeaceParser::ParameterContext::ParameterContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PeaceParser::TypeIdContext* PeaceParser::ParameterContext::typeId() {
  return getRuleContext<PeaceParser::TypeIdContext>(0);
}

PeaceParser::VarIdContext* PeaceParser::ParameterContext::varId() {
  return getRuleContext<PeaceParser::VarIdContext>(0);
}


size_t PeaceParser::ParameterContext::getRuleIndex() const {
  return PeaceParser::RuleParameter;
}


antlrcpp::Any PeaceParser::ParameterContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PeaceVisitor*>(visitor))
    return parserVisitor->visitParameter(this);
  else
    return visitor->visitChildren(this);
}

PeaceParser::ParameterContext* PeaceParser::parameter() {
  ParameterContext *_localctx = _tracker.createInstance<ParameterContext>(_ctx, getState());
  enterRule(_localctx, 46, PeaceParser::RuleParameter);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(204);
    typeId();
    setState(206);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PeaceParser::T__7) {
      setState(205);
      match(PeaceParser::T__7);
    }
    setState(208);
    varId();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CompoundStmtContext ------------------------------------------------------------------

PeaceParser::CompoundStmtContext::CompoundStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PeaceParser::StmtListContext* PeaceParser::CompoundStmtContext::stmtList() {
  return getRuleContext<PeaceParser::StmtListContext>(0);
}


size_t PeaceParser::CompoundStmtContext::getRuleIndex() const {
  return PeaceParser::RuleCompoundStmt;
}


antlrcpp::Any PeaceParser::CompoundStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PeaceVisitor*>(visitor))
    return parserVisitor->visitCompoundStmt(this);
  else
    return visitor->visitChildren(this);
}

PeaceParser::CompoundStmtContext* PeaceParser::compoundStmt() {
  CompoundStmtContext *_localctx = _tracker.createInstance<CompoundStmtContext>(_ctx, getState());
  enterRule(_localctx, 48, PeaceParser::RuleCompoundStmt);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(210);
    match(PeaceParser::T__1);
    setState(211);
    stmtList();
    setState(212);
    match(PeaceParser::T__2);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StmtContext ------------------------------------------------------------------

PeaceParser::StmtContext::StmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PeaceParser::CompoundStmtContext* PeaceParser::StmtContext::compoundStmt() {
  return getRuleContext<PeaceParser::CompoundStmtContext>(0);
}

PeaceParser::AssignmentStmtContext* PeaceParser::StmtContext::assignmentStmt() {
  return getRuleContext<PeaceParser::AssignmentStmtContext>(0);
}

PeaceParser::If_stmtContext* PeaceParser::StmtContext::if_stmt() {
  return getRuleContext<PeaceParser::If_stmtContext>(0);
}

PeaceParser::WhileStmtContext* PeaceParser::StmtContext::whileStmt() {
  return getRuleContext<PeaceParser::WhileStmtContext>(0);
}

PeaceParser::PrintContext* PeaceParser::StmtContext::print() {
  return getRuleContext<PeaceParser::PrintContext>(0);
}

PeaceParser::ProcCallContext* PeaceParser::StmtContext::procCall() {
  return getRuleContext<PeaceParser::ProcCallContext>(0);
}


size_t PeaceParser::StmtContext::getRuleIndex() const {
  return PeaceParser::RuleStmt;
}


antlrcpp::Any PeaceParser::StmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PeaceVisitor*>(visitor))
    return parserVisitor->visitStmt(this);
  else
    return visitor->visitChildren(this);
}

PeaceParser::StmtContext* PeaceParser::stmt() {
  StmtContext *_localctx = _tracker.createInstance<StmtContext>(_ctx, getState());
  enterRule(_localctx, 50, PeaceParser::RuleStmt);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(221);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(214);
      compoundStmt();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(215);
      assignmentStmt();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(216);
      if_stmt();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(217);
      whileStmt();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(218);
      print();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(219);
      procCall();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);

      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StmtListContext ------------------------------------------------------------------

PeaceParser::StmtListContext::StmtListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<PeaceParser::StmtContext *> PeaceParser::StmtListContext::stmt() {
  return getRuleContexts<PeaceParser::StmtContext>();
}

PeaceParser::StmtContext* PeaceParser::StmtListContext::stmt(size_t i) {
  return getRuleContext<PeaceParser::StmtContext>(i);
}


size_t PeaceParser::StmtListContext::getRuleIndex() const {
  return PeaceParser::RuleStmtList;
}


antlrcpp::Any PeaceParser::StmtListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PeaceVisitor*>(visitor))
    return parserVisitor->visitStmtList(this);
  else
    return visitor->visitChildren(this);
}

PeaceParser::StmtListContext* PeaceParser::stmtList() {
  StmtListContext *_localctx = _tracker.createInstance<StmtListContext>(_ctx, getState());
  enterRule(_localctx, 52, PeaceParser::RuleStmtList);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(223);
    stmt();
    setState(228);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == PeaceParser::T__3) {
      setState(224);
      match(PeaceParser::T__3);
      setState(225);
      stmt();
      setState(230);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AssignmentStmtContext ------------------------------------------------------------------

PeaceParser::AssignmentStmtContext::AssignmentStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PeaceParser::VariableContext* PeaceParser::AssignmentStmtContext::variable() {
  return getRuleContext<PeaceParser::VariableContext>(0);
}

PeaceParser::ExprContext* PeaceParser::AssignmentStmtContext::expr() {
  return getRuleContext<PeaceParser::ExprContext>(0);
}


size_t PeaceParser::AssignmentStmtContext::getRuleIndex() const {
  return PeaceParser::RuleAssignmentStmt;
}


antlrcpp::Any PeaceParser::AssignmentStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PeaceVisitor*>(visitor))
    return parserVisitor->visitAssignmentStmt(this);
  else
    return visitor->visitChildren(this);
}

PeaceParser::AssignmentStmtContext* PeaceParser::assignmentStmt() {
  AssignmentStmtContext *_localctx = _tracker.createInstance<AssignmentStmtContext>(_ctx, getState());
  enterRule(_localctx, 54, PeaceParser::RuleAssignmentStmt);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(231);
    variable();
    setState(232);
    match(PeaceParser::T__8);
    setState(233);
    expr(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- If_stmtContext ------------------------------------------------------------------

PeaceParser::If_stmtContext::If_stmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PeaceParser::If_stmtContext::IF() {
  return getToken(PeaceParser::IF, 0);
}

PeaceParser::ExprContext* PeaceParser::If_stmtContext::expr() {
  return getRuleContext<PeaceParser::ExprContext>(0);
}

PeaceParser::StmtContext* PeaceParser::If_stmtContext::stmt() {
  return getRuleContext<PeaceParser::StmtContext>(0);
}


size_t PeaceParser::If_stmtContext::getRuleIndex() const {
  return PeaceParser::RuleIf_stmt;
}


antlrcpp::Any PeaceParser::If_stmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PeaceVisitor*>(visitor))
    return parserVisitor->visitIf_stmt(this);
  else
    return visitor->visitChildren(this);
}

PeaceParser::If_stmtContext* PeaceParser::if_stmt() {
  If_stmtContext *_localctx = _tracker.createInstance<If_stmtContext>(_ctx, getState());
  enterRule(_localctx, 56, PeaceParser::RuleIf_stmt);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(235);
    match(PeaceParser::IF);
    setState(236);
    expr(0);
    setState(237);
    stmt();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- WhileStmtContext ------------------------------------------------------------------

PeaceParser::WhileStmtContext::WhileStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PeaceParser::WhileStmtContext::WHILE() {
  return getToken(PeaceParser::WHILE, 0);
}

PeaceParser::ExprContext* PeaceParser::WhileStmtContext::expr() {
  return getRuleContext<PeaceParser::ExprContext>(0);
}

PeaceParser::StmtContext* PeaceParser::WhileStmtContext::stmt() {
  return getRuleContext<PeaceParser::StmtContext>(0);
}


size_t PeaceParser::WhileStmtContext::getRuleIndex() const {
  return PeaceParser::RuleWhileStmt;
}


antlrcpp::Any PeaceParser::WhileStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PeaceVisitor*>(visitor))
    return parserVisitor->visitWhileStmt(this);
  else
    return visitor->visitChildren(this);
}

PeaceParser::WhileStmtContext* PeaceParser::whileStmt() {
  WhileStmtContext *_localctx = _tracker.createInstance<WhileStmtContext>(_ctx, getState());
  enterRule(_localctx, 58, PeaceParser::RuleWhileStmt);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(239);
    match(PeaceParser::WHILE);
    setState(240);
    expr(0);
    setState(241);
    stmt();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PrintContext ------------------------------------------------------------------

PeaceParser::PrintContext::PrintContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PeaceParser::PrintContext::PRINT() {
  return getToken(PeaceParser::PRINT, 0);
}

tree::TerminalNode* PeaceParser::PrintContext::STRING() {
  return getToken(PeaceParser::STRING, 0);
}

std::vector<PeaceParser::PrintVariablesContext *> PeaceParser::PrintContext::printVariables() {
  return getRuleContexts<PeaceParser::PrintVariablesContext>();
}

PeaceParser::PrintVariablesContext* PeaceParser::PrintContext::printVariables(size_t i) {
  return getRuleContext<PeaceParser::PrintVariablesContext>(i);
}


size_t PeaceParser::PrintContext::getRuleIndex() const {
  return PeaceParser::RulePrint;
}


antlrcpp::Any PeaceParser::PrintContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PeaceVisitor*>(visitor))
    return parserVisitor->visitPrint(this);
  else
    return visitor->visitChildren(this);
}

PeaceParser::PrintContext* PeaceParser::print() {
  PrintContext *_localctx = _tracker.createInstance<PrintContext>(_ctx, getState());
  enterRule(_localctx, 60, PeaceParser::RulePrint);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(243);
    match(PeaceParser::PRINT);
    setState(244);
    match(PeaceParser::T__5);
    setState(245);
    match(PeaceParser::STRING);
    setState(249);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == PeaceParser::T__4) {
      setState(246);
      printVariables();
      setState(251);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(252);
    match(PeaceParser::T__6);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ProcCallContext ------------------------------------------------------------------

PeaceParser::ProcCallContext::ProcCallContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PeaceParser::ProcCallContext::IDENTIFIER() {
  return getToken(PeaceParser::IDENTIFIER, 0);
}

std::vector<PeaceParser::ExprContext *> PeaceParser::ProcCallContext::expr() {
  return getRuleContexts<PeaceParser::ExprContext>();
}

PeaceParser::ExprContext* PeaceParser::ProcCallContext::expr(size_t i) {
  return getRuleContext<PeaceParser::ExprContext>(i);
}


size_t PeaceParser::ProcCallContext::getRuleIndex() const {
  return PeaceParser::RuleProcCall;
}


antlrcpp::Any PeaceParser::ProcCallContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PeaceVisitor*>(visitor))
    return parserVisitor->visitProcCall(this);
  else
    return visitor->visitChildren(this);
}

PeaceParser::ProcCallContext* PeaceParser::procCall() {
  ProcCallContext *_localctx = _tracker.createInstance<ProcCallContext>(_ctx, getState());
  enterRule(_localctx, 62, PeaceParser::RuleProcCall);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(254);
    match(PeaceParser::IDENTIFIER);
    setState(255);
    match(PeaceParser::T__5);
    setState(257);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << PeaceParser::T__5)
      | (1ULL << PeaceParser::IDENTIFIER)
      | (1ULL << PeaceParser::INTEGER)
      | (1ULL << PeaceParser::FLOAT)
      | (1ULL << PeaceParser::ADD_OP)
      | (1ULL << PeaceParser::SUB_OP))) != 0)) {
      setState(256);
      expr(0);
    }
    setState(263);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == PeaceParser::T__4) {
      setState(259);
      match(PeaceParser::T__4);
      setState(260);
      expr(0);
      setState(265);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(266);
    match(PeaceParser::T__6);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ReturnStmtContext ------------------------------------------------------------------

PeaceParser::ReturnStmtContext::ReturnStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PeaceParser::ExprContext* PeaceParser::ReturnStmtContext::expr() {
  return getRuleContext<PeaceParser::ExprContext>(0);
}


size_t PeaceParser::ReturnStmtContext::getRuleIndex() const {
  return PeaceParser::RuleReturnStmt;
}


antlrcpp::Any PeaceParser::ReturnStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PeaceVisitor*>(visitor))
    return parserVisitor->visitReturnStmt(this);
  else
    return visitor->visitChildren(this);
}

PeaceParser::ReturnStmtContext* PeaceParser::returnStmt() {
  ReturnStmtContext *_localctx = _tracker.createInstance<ReturnStmtContext>(_ctx, getState());
  enterRule(_localctx, 64, PeaceParser::RuleReturnStmt);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(268);
    match(PeaceParser::T__9);
    setState(269);
    expr(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PrintVariablesContext ------------------------------------------------------------------

PeaceParser::PrintVariablesContext::PrintVariablesContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PeaceParser::VariableContext* PeaceParser::PrintVariablesContext::variable() {
  return getRuleContext<PeaceParser::VariableContext>(0);
}


size_t PeaceParser::PrintVariablesContext::getRuleIndex() const {
  return PeaceParser::RulePrintVariables;
}


antlrcpp::Any PeaceParser::PrintVariablesContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PeaceVisitor*>(visitor))
    return parserVisitor->visitPrintVariables(this);
  else
    return visitor->visitChildren(this);
}

PeaceParser::PrintVariablesContext* PeaceParser::printVariables() {
  PrintVariablesContext *_localctx = _tracker.createInstance<PrintVariablesContext>(_ctx, getState());
  enterRule(_localctx, 66, PeaceParser::RulePrintVariables);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(271);
    match(PeaceParser::T__4);
    setState(272);
    variable();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VariableContext ------------------------------------------------------------------

PeaceParser::VariableContext::VariableContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PeaceParser::VariableContext::IDENTIFIER() {
  return getToken(PeaceParser::IDENTIFIER, 0);
}


size_t PeaceParser::VariableContext::getRuleIndex() const {
  return PeaceParser::RuleVariable;
}


antlrcpp::Any PeaceParser::VariableContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PeaceVisitor*>(visitor))
    return parserVisitor->visitVariable(this);
  else
    return visitor->visitChildren(this);
}

PeaceParser::VariableContext* PeaceParser::variable() {
  VariableContext *_localctx = _tracker.createInstance<VariableContext>(_ctx, getState());
  enterRule(_localctx, 68, PeaceParser::RuleVariable);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(274);
    match(PeaceParser::IDENTIFIER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExprContext ------------------------------------------------------------------

PeaceParser::ExprContext::ExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t PeaceParser::ExprContext::getRuleIndex() const {
  return PeaceParser::RuleExpr;
}

void PeaceParser::ExprContext::copyFrom(ExprContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
  this->type = ctx->type;
  this->parameterTypes = ctx->parameterTypes;
}

//----------------- VariableExprContext ------------------------------------------------------------------

PeaceParser::VariableContext* PeaceParser::VariableExprContext::variable() {
  return getRuleContext<PeaceParser::VariableContext>(0);
}

PeaceParser::VariableExprContext::VariableExprContext(ExprContext *ctx) { copyFrom(ctx); }


antlrcpp::Any PeaceParser::VariableExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PeaceVisitor*>(visitor))
    return parserVisitor->visitVariableExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- AddSubExprContext ------------------------------------------------------------------

std::vector<PeaceParser::ExprContext *> PeaceParser::AddSubExprContext::expr() {
  return getRuleContexts<PeaceParser::ExprContext>();
}

PeaceParser::ExprContext* PeaceParser::AddSubExprContext::expr(size_t i) {
  return getRuleContext<PeaceParser::ExprContext>(i);
}

PeaceParser::AddSubOpContext* PeaceParser::AddSubExprContext::addSubOp() {
  return getRuleContext<PeaceParser::AddSubOpContext>(0);
}

PeaceParser::AddSubExprContext::AddSubExprContext(ExprContext *ctx) { copyFrom(ctx); }


antlrcpp::Any PeaceParser::AddSubExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PeaceVisitor*>(visitor))
    return parserVisitor->visitAddSubExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- FuncCallExprContext ------------------------------------------------------------------

PeaceParser::FuncCallContext* PeaceParser::FuncCallExprContext::funcCall() {
  return getRuleContext<PeaceParser::FuncCallContext>(0);
}

PeaceParser::FuncCallExprContext::FuncCallExprContext(ExprContext *ctx) { copyFrom(ctx); }


antlrcpp::Any PeaceParser::FuncCallExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PeaceVisitor*>(visitor))
    return parserVisitor->visitFuncCallExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- UnsignedNumberExprContext ------------------------------------------------------------------

PeaceParser::NumberContext* PeaceParser::UnsignedNumberExprContext::number() {
  return getRuleContext<PeaceParser::NumberContext>(0);
}

PeaceParser::UnsignedNumberExprContext::UnsignedNumberExprContext(ExprContext *ctx) { copyFrom(ctx); }


antlrcpp::Any PeaceParser::UnsignedNumberExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PeaceVisitor*>(visitor))
    return parserVisitor->visitUnsignedNumberExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- BoolExprContext ------------------------------------------------------------------

std::vector<PeaceParser::ExprContext *> PeaceParser::BoolExprContext::expr() {
  return getRuleContexts<PeaceParser::ExprContext>();
}

PeaceParser::ExprContext* PeaceParser::BoolExprContext::expr(size_t i) {
  return getRuleContext<PeaceParser::ExprContext>(i);
}

PeaceParser::RelOpContext* PeaceParser::BoolExprContext::relOp() {
  return getRuleContext<PeaceParser::RelOpContext>(0);
}

PeaceParser::BoolExprContext::BoolExprContext(ExprContext *ctx) { copyFrom(ctx); }


antlrcpp::Any PeaceParser::BoolExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PeaceVisitor*>(visitor))
    return parserVisitor->visitBoolExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- MulDivExprContext ------------------------------------------------------------------

std::vector<PeaceParser::ExprContext *> PeaceParser::MulDivExprContext::expr() {
  return getRuleContexts<PeaceParser::ExprContext>();
}

PeaceParser::ExprContext* PeaceParser::MulDivExprContext::expr(size_t i) {
  return getRuleContext<PeaceParser::ExprContext>(i);
}

PeaceParser::MulDivOpContext* PeaceParser::MulDivExprContext::mulDivOp() {
  return getRuleContext<PeaceParser::MulDivOpContext>(0);
}

PeaceParser::MulDivExprContext::MulDivExprContext(ExprContext *ctx) { copyFrom(ctx); }


antlrcpp::Any PeaceParser::MulDivExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PeaceVisitor*>(visitor))
    return parserVisitor->visitMulDivExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ParenExprContext ------------------------------------------------------------------

PeaceParser::ExprContext* PeaceParser::ParenExprContext::expr() {
  return getRuleContext<PeaceParser::ExprContext>(0);
}

PeaceParser::ParenExprContext::ParenExprContext(ExprContext *ctx) { copyFrom(ctx); }


antlrcpp::Any PeaceParser::ParenExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PeaceVisitor*>(visitor))
    return parserVisitor->visitParenExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- SignedNumberExprContext ------------------------------------------------------------------

PeaceParser::SignedNumberContext* PeaceParser::SignedNumberExprContext::signedNumber() {
  return getRuleContext<PeaceParser::SignedNumberContext>(0);
}

PeaceParser::SignedNumberExprContext::SignedNumberExprContext(ExprContext *ctx) { copyFrom(ctx); }


antlrcpp::Any PeaceParser::SignedNumberExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PeaceVisitor*>(visitor))
    return parserVisitor->visitSignedNumberExpr(this);
  else
    return visitor->visitChildren(this);
}

PeaceParser::ExprContext* PeaceParser::expr() {
   return expr(0);
}

PeaceParser::ExprContext* PeaceParser::expr(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  PeaceParser::ExprContext *_localctx = _tracker.createInstance<ExprContext>(_ctx, parentState);
  PeaceParser::ExprContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 70;
  enterRecursionRule(_localctx, 70, PeaceParser::RuleExpr, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(285);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<UnsignedNumberExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;

      setState(277);
      number();
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<SignedNumberExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(278);
      signedNumber();
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<VariableExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(279);
      variable();
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<FuncCallExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(280);
      funcCall();
      break;
    }

    case 5: {
      _localctx = _tracker.createInstance<ParenExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(281);
      match(PeaceParser::T__5);
      setState(282);
      expr(0);
      setState(283);
      match(PeaceParser::T__6);
      break;
    }

    }
    _ctx->stop = _input->LT(-1);
    setState(301);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(299);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<MulDivExprContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(287);

          if (!(precpred(_ctx, 8))) throw FailedPredicateException(this, "precpred(_ctx, 8)");
          setState(288);
          mulDivOp();
          setState(289);
          expr(9);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<AddSubExprContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(291);

          if (!(precpred(_ctx, 7))) throw FailedPredicateException(this, "precpred(_ctx, 7)");
          setState(292);
          addSubOp();
          setState(293);
          expr(8);
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<BoolExprContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(295);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(296);
          relOp();
          setState(297);
          expr(4);
          break;
        }

        } 
      }
      setState(303);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- MulDivOpContext ------------------------------------------------------------------

PeaceParser::MulDivOpContext::MulDivOpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PeaceParser::MulDivOpContext::MUL_OP() {
  return getToken(PeaceParser::MUL_OP, 0);
}

tree::TerminalNode* PeaceParser::MulDivOpContext::DIV_OP() {
  return getToken(PeaceParser::DIV_OP, 0);
}


size_t PeaceParser::MulDivOpContext::getRuleIndex() const {
  return PeaceParser::RuleMulDivOp;
}


antlrcpp::Any PeaceParser::MulDivOpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PeaceVisitor*>(visitor))
    return parserVisitor->visitMulDivOp(this);
  else
    return visitor->visitChildren(this);
}

PeaceParser::MulDivOpContext* PeaceParser::mulDivOp() {
  MulDivOpContext *_localctx = _tracker.createInstance<MulDivOpContext>(_ctx, getState());
  enterRule(_localctx, 72, PeaceParser::RuleMulDivOp);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(304);
    _la = _input->LA(1);
    if (!(_la == PeaceParser::MUL_OP

    || _la == PeaceParser::DIV_OP)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AddSubOpContext ------------------------------------------------------------------

PeaceParser::AddSubOpContext::AddSubOpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PeaceParser::AddSubOpContext::ADD_OP() {
  return getToken(PeaceParser::ADD_OP, 0);
}

tree::TerminalNode* PeaceParser::AddSubOpContext::SUB_OP() {
  return getToken(PeaceParser::SUB_OP, 0);
}


size_t PeaceParser::AddSubOpContext::getRuleIndex() const {
  return PeaceParser::RuleAddSubOp;
}


antlrcpp::Any PeaceParser::AddSubOpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PeaceVisitor*>(visitor))
    return parserVisitor->visitAddSubOp(this);
  else
    return visitor->visitChildren(this);
}

PeaceParser::AddSubOpContext* PeaceParser::addSubOp() {
  AddSubOpContext *_localctx = _tracker.createInstance<AddSubOpContext>(_ctx, getState());
  enterRule(_localctx, 74, PeaceParser::RuleAddSubOp);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(306);
    _la = _input->LA(1);
    if (!(_la == PeaceParser::ADD_OP

    || _la == PeaceParser::SUB_OP)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RelOpContext ------------------------------------------------------------------

PeaceParser::RelOpContext::RelOpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PeaceParser::RelOpContext::EQ_OP() {
  return getToken(PeaceParser::EQ_OP, 0);
}

tree::TerminalNode* PeaceParser::RelOpContext::NE_OP() {
  return getToken(PeaceParser::NE_OP, 0);
}

tree::TerminalNode* PeaceParser::RelOpContext::LT_OP() {
  return getToken(PeaceParser::LT_OP, 0);
}

tree::TerminalNode* PeaceParser::RelOpContext::LE_OP() {
  return getToken(PeaceParser::LE_OP, 0);
}

tree::TerminalNode* PeaceParser::RelOpContext::GT_OP() {
  return getToken(PeaceParser::GT_OP, 0);
}

tree::TerminalNode* PeaceParser::RelOpContext::GE_OP() {
  return getToken(PeaceParser::GE_OP, 0);
}


size_t PeaceParser::RelOpContext::getRuleIndex() const {
  return PeaceParser::RuleRelOp;
}


antlrcpp::Any PeaceParser::RelOpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PeaceVisitor*>(visitor))
    return parserVisitor->visitRelOp(this);
  else
    return visitor->visitChildren(this);
}

PeaceParser::RelOpContext* PeaceParser::relOp() {
  RelOpContext *_localctx = _tracker.createInstance<RelOpContext>(_ctx, getState());
  enterRule(_localctx, 76, PeaceParser::RuleRelOp);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(308);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << PeaceParser::EQ_OP)
      | (1ULL << PeaceParser::NE_OP)
      | (1ULL << PeaceParser::LT_OP)
      | (1ULL << PeaceParser::LE_OP)
      | (1ULL << PeaceParser::GT_OP)
      | (1ULL << PeaceParser::GE_OP))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FuncCallContext ------------------------------------------------------------------

PeaceParser::FuncCallContext::FuncCallContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PeaceParser::FuncCallContext::IDENTIFIER() {
  return getToken(PeaceParser::IDENTIFIER, 0);
}

std::vector<PeaceParser::ExprContext *> PeaceParser::FuncCallContext::expr() {
  return getRuleContexts<PeaceParser::ExprContext>();
}

PeaceParser::ExprContext* PeaceParser::FuncCallContext::expr(size_t i) {
  return getRuleContext<PeaceParser::ExprContext>(i);
}


size_t PeaceParser::FuncCallContext::getRuleIndex() const {
  return PeaceParser::RuleFuncCall;
}


antlrcpp::Any PeaceParser::FuncCallContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PeaceVisitor*>(visitor))
    return parserVisitor->visitFuncCall(this);
  else
    return visitor->visitChildren(this);
}

PeaceParser::FuncCallContext* PeaceParser::funcCall() {
  FuncCallContext *_localctx = _tracker.createInstance<FuncCallContext>(_ctx, getState());
  enterRule(_localctx, 78, PeaceParser::RuleFuncCall);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(310);
    match(PeaceParser::IDENTIFIER);
    setState(311);
    match(PeaceParser::T__5);
    setState(313);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << PeaceParser::T__5)
      | (1ULL << PeaceParser::IDENTIFIER)
      | (1ULL << PeaceParser::INTEGER)
      | (1ULL << PeaceParser::FLOAT)
      | (1ULL << PeaceParser::ADD_OP)
      | (1ULL << PeaceParser::SUB_OP))) != 0)) {
      setState(312);
      expr(0);
    }
    setState(319);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == PeaceParser::T__4) {
      setState(315);
      match(PeaceParser::T__4);
      setState(316);
      expr(0);
      setState(321);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(322);
    match(PeaceParser::T__6);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SignedNumberContext ------------------------------------------------------------------

PeaceParser::SignedNumberContext::SignedNumberContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PeaceParser::SignContext* PeaceParser::SignedNumberContext::sign() {
  return getRuleContext<PeaceParser::SignContext>(0);
}

PeaceParser::NumberContext* PeaceParser::SignedNumberContext::number() {
  return getRuleContext<PeaceParser::NumberContext>(0);
}


size_t PeaceParser::SignedNumberContext::getRuleIndex() const {
  return PeaceParser::RuleSignedNumber;
}


antlrcpp::Any PeaceParser::SignedNumberContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PeaceVisitor*>(visitor))
    return parserVisitor->visitSignedNumber(this);
  else
    return visitor->visitChildren(this);
}

PeaceParser::SignedNumberContext* PeaceParser::signedNumber() {
  SignedNumberContext *_localctx = _tracker.createInstance<SignedNumberContext>(_ctx, getState());
  enterRule(_localctx, 80, PeaceParser::RuleSignedNumber);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(324);
    sign();
    setState(325);
    number();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SignContext ------------------------------------------------------------------

PeaceParser::SignContext::SignContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PeaceParser::SignContext::ADD_OP() {
  return getToken(PeaceParser::ADD_OP, 0);
}

tree::TerminalNode* PeaceParser::SignContext::SUB_OP() {
  return getToken(PeaceParser::SUB_OP, 0);
}


size_t PeaceParser::SignContext::getRuleIndex() const {
  return PeaceParser::RuleSign;
}


antlrcpp::Any PeaceParser::SignContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PeaceVisitor*>(visitor))
    return parserVisitor->visitSign(this);
  else
    return visitor->visitChildren(this);
}

PeaceParser::SignContext* PeaceParser::sign() {
  SignContext *_localctx = _tracker.createInstance<SignContext>(_ctx, getState());
  enterRule(_localctx, 82, PeaceParser::RuleSign);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(327);
    _la = _input->LA(1);
    if (!(_la == PeaceParser::ADD_OP

    || _la == PeaceParser::SUB_OP)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NumberContext ------------------------------------------------------------------

PeaceParser::NumberContext::NumberContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t PeaceParser::NumberContext::getRuleIndex() const {
  return PeaceParser::RuleNumber;
}

void PeaceParser::NumberContext::copyFrom(NumberContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
  this->type = ctx->type;
}

//----------------- FloatConstContext ------------------------------------------------------------------

tree::TerminalNode* PeaceParser::FloatConstContext::FLOAT() {
  return getToken(PeaceParser::FLOAT, 0);
}

PeaceParser::FloatConstContext::FloatConstContext(NumberContext *ctx) { copyFrom(ctx); }


antlrcpp::Any PeaceParser::FloatConstContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PeaceVisitor*>(visitor))
    return parserVisitor->visitFloatConst(this);
  else
    return visitor->visitChildren(this);
}
//----------------- IntegerConstContext ------------------------------------------------------------------

tree::TerminalNode* PeaceParser::IntegerConstContext::INTEGER() {
  return getToken(PeaceParser::INTEGER, 0);
}

PeaceParser::IntegerConstContext::IntegerConstContext(NumberContext *ctx) { copyFrom(ctx); }


antlrcpp::Any PeaceParser::IntegerConstContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PeaceVisitor*>(visitor))
    return parserVisitor->visitIntegerConst(this);
  else
    return visitor->visitChildren(this);
}
PeaceParser::NumberContext* PeaceParser::number() {
  NumberContext *_localctx = _tracker.createInstance<NumberContext>(_ctx, getState());
  enterRule(_localctx, 84, PeaceParser::RuleNumber);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(331);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PeaceParser::INTEGER: {
        _localctx = dynamic_cast<NumberContext *>(_tracker.createInstance<PeaceParser::IntegerConstContext>(_localctx));
        enterOuterAlt(_localctx, 1);
        setState(329);
        match(PeaceParser::INTEGER);
        break;
      }

      case PeaceParser::FLOAT: {
        _localctx = dynamic_cast<NumberContext *>(_tracker.createInstance<PeaceParser::FloatConstContext>(_localctx));
        enterOuterAlt(_localctx, 2);
        setState(330);
        match(PeaceParser::FLOAT);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

bool PeaceParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 35: return exprSempred(dynamic_cast<ExprContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool PeaceParser::exprSempred(ExprContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 8);
    case 1: return precpred(_ctx, 7);
    case 2: return precpred(_ctx, 3);

  default:
    break;
  }
  return true;
}

// Static vars and initialization.
std::vector<dfa::DFA> PeaceParser::_decisionToDFA;
atn::PredictionContextCache PeaceParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN PeaceParser::_atn;
std::vector<uint16_t> PeaceParser::_serializedATN;

std::vector<std::string> PeaceParser::_ruleNames = {
  "program", "header", "mainBlock", "block", "main", "mainBody", "declarations", 
  "declList", "decl", "varList", "varId", "typeId", "definitions", "definitionsList", 
  "def", "proc", "procBody", "func", "funcBody", "funcDeclarations", "funcDeclList", 
  "funcDecl", "parameterList", "parameter", "compoundStmt", "stmt", "stmtList", 
  "assignmentStmt", "if_stmt", "whileStmt", "print", "procCall", "returnStmt", 
  "printVariables", "variable", "expr", "mulDivOp", "addSubOp", "relOp", 
  "funcCall", "signedNumber", "sign", "number"
};

std::vector<std::string> PeaceParser::_literalNames = {
  "", "'ENDPROG'", "'{'", "'}'", "';'", "','", "'('", "')'", "'&'", "'='", 
  "'return'", "'PROG'", "'MAIN'", "'IF'", "'WHILE'", "'PRINT'", "'VOID'", 
  "", "", "", "", "'*'", "'/'", "'+'", "'-'", "'=='", "'!='", "'<'", "'<='", 
  "'>'", "'>='"
};

std::vector<std::string> PeaceParser::_symbolicNames = {
  "", "", "", "", "", "", "", "", "", "", "", "PROG", "MAIN", "IF", "WHILE", 
  "PRINT", "VOID", "STRING", "IDENTIFIER", "INTEGER", "FLOAT", "MUL_OP", 
  "DIV_OP", "ADD_OP", "SUB_OP", "EQ_OP", "NE_OP", "LT_OP", "LE_OP", "GT_OP", 
  "GE_OP", "NEWLINE", "WS"
};

dfa::Vocabulary PeaceParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> PeaceParser::_tokenNames;

PeaceParser::Initializer::Initializer() {
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  _serializedATN = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
    0x3, 0x22, 0x150, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
    0x9, 0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 
    0x4, 0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 
    0x9, 0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 
    0x4, 0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 0x9, 0x11, 0x4, 
    0x12, 0x9, 0x12, 0x4, 0x13, 0x9, 0x13, 0x4, 0x14, 0x9, 0x14, 0x4, 0x15, 
    0x9, 0x15, 0x4, 0x16, 0x9, 0x16, 0x4, 0x17, 0x9, 0x17, 0x4, 0x18, 0x9, 
    0x18, 0x4, 0x19, 0x9, 0x19, 0x4, 0x1a, 0x9, 0x1a, 0x4, 0x1b, 0x9, 0x1b, 
    0x4, 0x1c, 0x9, 0x1c, 0x4, 0x1d, 0x9, 0x1d, 0x4, 0x1e, 0x9, 0x1e, 0x4, 
    0x1f, 0x9, 0x1f, 0x4, 0x20, 0x9, 0x20, 0x4, 0x21, 0x9, 0x21, 0x4, 0x22, 
    0x9, 0x22, 0x4, 0x23, 0x9, 0x23, 0x4, 0x24, 0x9, 0x24, 0x4, 0x25, 0x9, 
    0x25, 0x4, 0x26, 0x9, 0x26, 0x4, 0x27, 0x9, 0x27, 0x4, 0x28, 0x9, 0x28, 
    0x4, 0x29, 0x9, 0x29, 0x4, 0x2a, 0x9, 0x2a, 0x4, 0x2b, 0x9, 0x2b, 0x4, 
    0x2c, 0x9, 0x2c, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 0x5, 0x3, 0x5, 0x5, 0x5, 0x64, 
    0xa, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x7, 
    0x3, 0x7, 0x5, 0x7, 0x6d, 0xa, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 
    0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x7, 0x9, 0x78, 
    0xa, 0x9, 0xc, 0x9, 0xe, 0x9, 0x7b, 0xb, 0x9, 0x3, 0xa, 0x3, 0xa, 0x3, 
    0xa, 0x3, 0xa, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x7, 0xb, 0x84, 0xa, 0xb, 
    0xc, 0xb, 0xe, 0xb, 0x87, 0xb, 0xb, 0x3, 0xc, 0x3, 0xc, 0x3, 0xd, 0x3, 
    0xd, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x7, 
    0xf, 0x93, 0xa, 0xf, 0xc, 0xf, 0xe, 0xf, 0x96, 0xb, 0xf, 0x3, 0x10, 
    0x3, 0x10, 0x5, 0x10, 0x9a, 0xa, 0x10, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 
    0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x12, 0x3, 0x12, 0x5, 
    0x12, 0xa5, 0xa, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x13, 0x3, 
    0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x14, 
    0x3, 0x14, 0x5, 0x14, 0xb3, 0xa, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 
    0x3, 0x14, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x16, 0x3, 0x16, 0x3, 
    0x16, 0x7, 0x16, 0xbf, 0xa, 0x16, 0xc, 0x16, 0xe, 0x16, 0xc2, 0xb, 0x16, 
    0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x7, 
    0x18, 0xca, 0xa, 0x18, 0xc, 0x18, 0xe, 0x18, 0xcd, 0xb, 0x18, 0x3, 0x19, 
    0x3, 0x19, 0x5, 0x19, 0xd1, 0xa, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x1a, 
    0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x3, 
    0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x5, 0x1b, 0xe0, 0xa, 0x1b, 0x3, 
    0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x7, 0x1c, 0xe5, 0xa, 0x1c, 0xc, 0x1c, 0xe, 
    0x1c, 0xe8, 0xb, 0x1c, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x3, 
    0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 
    0x3, 0x1f, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 0x7, 0x20, 0xfa, 
    0xa, 0x20, 0xc, 0x20, 0xe, 0x20, 0xfd, 0xb, 0x20, 0x3, 0x20, 0x3, 0x20, 
    0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x5, 0x21, 0x104, 0xa, 0x21, 0x3, 0x21, 
    0x3, 0x21, 0x7, 0x21, 0x108, 0xa, 0x21, 0xc, 0x21, 0xe, 0x21, 0x10b, 
    0xb, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 0x3, 
    0x23, 0x3, 0x23, 0x3, 0x23, 0x3, 0x24, 0x3, 0x24, 0x3, 0x25, 0x3, 0x25, 
    0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 0x3, 
    0x25, 0x5, 0x25, 0x120, 0xa, 0x25, 0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 
    0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 0x3, 
    0x25, 0x3, 0x25, 0x3, 0x25, 0x7, 0x25, 0x12e, 0xa, 0x25, 0xc, 0x25, 
    0xe, 0x25, 0x131, 0xb, 0x25, 0x3, 0x26, 0x3, 0x26, 0x3, 0x27, 0x3, 0x27, 
    0x3, 0x28, 0x3, 0x28, 0x3, 0x29, 0x3, 0x29, 0x3, 0x29, 0x5, 0x29, 0x13c, 
    0xa, 0x29, 0x3, 0x29, 0x3, 0x29, 0x7, 0x29, 0x140, 0xa, 0x29, 0xc, 0x29, 
    0xe, 0x29, 0x143, 0xb, 0x29, 0x3, 0x29, 0x3, 0x29, 0x3, 0x2a, 0x3, 0x2a, 
    0x3, 0x2a, 0x3, 0x2b, 0x3, 0x2b, 0x3, 0x2c, 0x3, 0x2c, 0x5, 0x2c, 0x14e, 
    0xa, 0x2c, 0x3, 0x2c, 0x2, 0x3, 0x48, 0x2d, 0x2, 0x4, 0x6, 0x8, 0xa, 
    0xc, 0xe, 0x10, 0x12, 0x14, 0x16, 0x18, 0x1a, 0x1c, 0x1e, 0x20, 0x22, 
    0x24, 0x26, 0x28, 0x2a, 0x2c, 0x2e, 0x30, 0x32, 0x34, 0x36, 0x38, 0x3a, 
    0x3c, 0x3e, 0x40, 0x42, 0x44, 0x46, 0x48, 0x4a, 0x4c, 0x4e, 0x50, 0x52, 
    0x54, 0x56, 0x2, 0x5, 0x3, 0x2, 0x17, 0x18, 0x3, 0x2, 0x19, 0x1a, 0x3, 
    0x2, 0x1b, 0x20, 0x2, 0x143, 0x2, 0x58, 0x3, 0x2, 0x2, 0x2, 0x4, 0x5c, 
    0x3, 0x2, 0x2, 0x2, 0x6, 0x5f, 0x3, 0x2, 0x2, 0x2, 0x8, 0x61, 0x3, 0x2, 
    0x2, 0x2, 0xa, 0x67, 0x3, 0x2, 0x2, 0x2, 0xc, 0x6a, 0x3, 0x2, 0x2, 0x2, 
    0xe, 0x71, 0x3, 0x2, 0x2, 0x2, 0x10, 0x74, 0x3, 0x2, 0x2, 0x2, 0x12, 
    0x7c, 0x3, 0x2, 0x2, 0x2, 0x14, 0x80, 0x3, 0x2, 0x2, 0x2, 0x16, 0x88, 
    0x3, 0x2, 0x2, 0x2, 0x18, 0x8a, 0x3, 0x2, 0x2, 0x2, 0x1a, 0x8c, 0x3, 
    0x2, 0x2, 0x2, 0x1c, 0x8f, 0x3, 0x2, 0x2, 0x2, 0x1e, 0x99, 0x3, 0x2, 
    0x2, 0x2, 0x20, 0x9b, 0x3, 0x2, 0x2, 0x2, 0x22, 0xa2, 0x3, 0x2, 0x2, 
    0x2, 0x24, 0xa9, 0x3, 0x2, 0x2, 0x2, 0x26, 0xb0, 0x3, 0x2, 0x2, 0x2, 
    0x28, 0xb8, 0x3, 0x2, 0x2, 0x2, 0x2a, 0xbb, 0x3, 0x2, 0x2, 0x2, 0x2c, 
    0xc3, 0x3, 0x2, 0x2, 0x2, 0x2e, 0xc6, 0x3, 0x2, 0x2, 0x2, 0x30, 0xce, 
    0x3, 0x2, 0x2, 0x2, 0x32, 0xd4, 0x3, 0x2, 0x2, 0x2, 0x34, 0xdf, 0x3, 
    0x2, 0x2, 0x2, 0x36, 0xe1, 0x3, 0x2, 0x2, 0x2, 0x38, 0xe9, 0x3, 0x2, 
    0x2, 0x2, 0x3a, 0xed, 0x3, 0x2, 0x2, 0x2, 0x3c, 0xf1, 0x3, 0x2, 0x2, 
    0x2, 0x3e, 0xf5, 0x3, 0x2, 0x2, 0x2, 0x40, 0x100, 0x3, 0x2, 0x2, 0x2, 
    0x42, 0x10e, 0x3, 0x2, 0x2, 0x2, 0x44, 0x111, 0x3, 0x2, 0x2, 0x2, 0x46, 
    0x114, 0x3, 0x2, 0x2, 0x2, 0x48, 0x11f, 0x3, 0x2, 0x2, 0x2, 0x4a, 0x132, 
    0x3, 0x2, 0x2, 0x2, 0x4c, 0x134, 0x3, 0x2, 0x2, 0x2, 0x4e, 0x136, 0x3, 
    0x2, 0x2, 0x2, 0x50, 0x138, 0x3, 0x2, 0x2, 0x2, 0x52, 0x146, 0x3, 0x2, 
    0x2, 0x2, 0x54, 0x149, 0x3, 0x2, 0x2, 0x2, 0x56, 0x14d, 0x3, 0x2, 0x2, 
    0x2, 0x58, 0x59, 0x5, 0x4, 0x3, 0x2, 0x59, 0x5a, 0x5, 0x6, 0x4, 0x2, 
    0x5a, 0x5b, 0x7, 0x3, 0x2, 0x2, 0x5b, 0x3, 0x3, 0x2, 0x2, 0x2, 0x5c, 
    0x5d, 0x7, 0xd, 0x2, 0x2, 0x5d, 0x5e, 0x7, 0x14, 0x2, 0x2, 0x5e, 0x5, 
    0x3, 0x2, 0x2, 0x2, 0x5f, 0x60, 0x5, 0x8, 0x5, 0x2, 0x60, 0x7, 0x3, 
    0x2, 0x2, 0x2, 0x61, 0x63, 0x5, 0xe, 0x8, 0x2, 0x62, 0x64, 0x5, 0x1a, 
    0xe, 0x2, 0x63, 0x62, 0x3, 0x2, 0x2, 0x2, 0x63, 0x64, 0x3, 0x2, 0x2, 
    0x2, 0x64, 0x65, 0x3, 0x2, 0x2, 0x2, 0x65, 0x66, 0x5, 0xa, 0x6, 0x2, 
    0x66, 0x9, 0x3, 0x2, 0x2, 0x2, 0x67, 0x68, 0x7, 0xe, 0x2, 0x2, 0x68, 
    0x69, 0x5, 0xc, 0x7, 0x2, 0x69, 0xb, 0x3, 0x2, 0x2, 0x2, 0x6a, 0x6c, 
    0x7, 0x4, 0x2, 0x2, 0x6b, 0x6d, 0x5, 0x28, 0x15, 0x2, 0x6c, 0x6b, 0x3, 
    0x2, 0x2, 0x2, 0x6c, 0x6d, 0x3, 0x2, 0x2, 0x2, 0x6d, 0x6e, 0x3, 0x2, 
    0x2, 0x2, 0x6e, 0x6f, 0x5, 0x36, 0x1c, 0x2, 0x6f, 0x70, 0x7, 0x5, 0x2, 
    0x2, 0x70, 0xd, 0x3, 0x2, 0x2, 0x2, 0x71, 0x72, 0x5, 0x10, 0x9, 0x2, 
    0x72, 0x73, 0x7, 0x6, 0x2, 0x2, 0x73, 0xf, 0x3, 0x2, 0x2, 0x2, 0x74, 
    0x79, 0x5, 0x12, 0xa, 0x2, 0x75, 0x76, 0x7, 0x6, 0x2, 0x2, 0x76, 0x78, 
    0x5, 0x12, 0xa, 0x2, 0x77, 0x75, 0x3, 0x2, 0x2, 0x2, 0x78, 0x7b, 0x3, 
    0x2, 0x2, 0x2, 0x79, 0x77, 0x3, 0x2, 0x2, 0x2, 0x79, 0x7a, 0x3, 0x2, 
    0x2, 0x2, 0x7a, 0x11, 0x3, 0x2, 0x2, 0x2, 0x7b, 0x79, 0x3, 0x2, 0x2, 
    0x2, 0x7c, 0x7d, 0x5, 0x18, 0xd, 0x2, 0x7d, 0x7e, 0x7, 0x1a, 0x2, 0x2, 
    0x7e, 0x7f, 0x5, 0x14, 0xb, 0x2, 0x7f, 0x13, 0x3, 0x2, 0x2, 0x2, 0x80, 
    0x85, 0x5, 0x16, 0xc, 0x2, 0x81, 0x82, 0x7, 0x7, 0x2, 0x2, 0x82, 0x84, 
    0x5, 0x16, 0xc, 0x2, 0x83, 0x81, 0x3, 0x2, 0x2, 0x2, 0x84, 0x87, 0x3, 
    0x2, 0x2, 0x2, 0x85, 0x83, 0x3, 0x2, 0x2, 0x2, 0x85, 0x86, 0x3, 0x2, 
    0x2, 0x2, 0x86, 0x15, 0x3, 0x2, 0x2, 0x2, 0x87, 0x85, 0x3, 0x2, 0x2, 
    0x2, 0x88, 0x89, 0x7, 0x14, 0x2, 0x2, 0x89, 0x17, 0x3, 0x2, 0x2, 0x2, 
    0x8a, 0x8b, 0x7, 0x14, 0x2, 0x2, 0x8b, 0x19, 0x3, 0x2, 0x2, 0x2, 0x8c, 
    0x8d, 0x5, 0x1c, 0xf, 0x2, 0x8d, 0x8e, 0x7, 0x6, 0x2, 0x2, 0x8e, 0x1b, 
    0x3, 0x2, 0x2, 0x2, 0x8f, 0x94, 0x5, 0x1e, 0x10, 0x2, 0x90, 0x91, 0x7, 
    0x6, 0x2, 0x2, 0x91, 0x93, 0x5, 0x1e, 0x10, 0x2, 0x92, 0x90, 0x3, 0x2, 
    0x2, 0x2, 0x93, 0x96, 0x3, 0x2, 0x2, 0x2, 0x94, 0x92, 0x3, 0x2, 0x2, 
    0x2, 0x94, 0x95, 0x3, 0x2, 0x2, 0x2, 0x95, 0x1d, 0x3, 0x2, 0x2, 0x2, 
    0x96, 0x94, 0x3, 0x2, 0x2, 0x2, 0x97, 0x9a, 0x5, 0x20, 0x11, 0x2, 0x98, 
    0x9a, 0x5, 0x24, 0x13, 0x2, 0x99, 0x97, 0x3, 0x2, 0x2, 0x2, 0x99, 0x98, 
    0x3, 0x2, 0x2, 0x2, 0x9a, 0x1f, 0x3, 0x2, 0x2, 0x2, 0x9b, 0x9c, 0x7, 
    0x12, 0x2, 0x2, 0x9c, 0x9d, 0x7, 0x14, 0x2, 0x2, 0x9d, 0x9e, 0x7, 0x8, 
    0x2, 0x2, 0x9e, 0x9f, 0x5, 0x2e, 0x18, 0x2, 0x9f, 0xa0, 0x7, 0x9, 0x2, 
    0x2, 0xa0, 0xa1, 0x5, 0x22, 0x12, 0x2, 0xa1, 0x21, 0x3, 0x2, 0x2, 0x2, 
    0xa2, 0xa4, 0x7, 0x4, 0x2, 0x2, 0xa3, 0xa5, 0x5, 0x28, 0x15, 0x2, 0xa4, 
    0xa3, 0x3, 0x2, 0x2, 0x2, 0xa4, 0xa5, 0x3, 0x2, 0x2, 0x2, 0xa5, 0xa6, 
    0x3, 0x2, 0x2, 0x2, 0xa6, 0xa7, 0x5, 0x36, 0x1c, 0x2, 0xa7, 0xa8, 0x7, 
    0x5, 0x2, 0x2, 0xa8, 0x23, 0x3, 0x2, 0x2, 0x2, 0xa9, 0xaa, 0x5, 0x18, 
    0xd, 0x2, 0xaa, 0xab, 0x7, 0x14, 0x2, 0x2, 0xab, 0xac, 0x7, 0x8, 0x2, 
    0x2, 0xac, 0xad, 0x5, 0x2e, 0x18, 0x2, 0xad, 0xae, 0x7, 0x9, 0x2, 0x2, 
    0xae, 0xaf, 0x5, 0x26, 0x14, 0x2, 0xaf, 0x25, 0x3, 0x2, 0x2, 0x2, 0xb0, 
    0xb2, 0x7, 0x4, 0x2, 0x2, 0xb1, 0xb3, 0x5, 0x28, 0x15, 0x2, 0xb2, 0xb1, 
    0x3, 0x2, 0x2, 0x2, 0xb2, 0xb3, 0x3, 0x2, 0x2, 0x2, 0xb3, 0xb4, 0x3, 
    0x2, 0x2, 0x2, 0xb4, 0xb5, 0x5, 0x36, 0x1c, 0x2, 0xb5, 0xb6, 0x5, 0x42, 
    0x22, 0x2, 0xb6, 0xb7, 0x7, 0x5, 0x2, 0x2, 0xb7, 0x27, 0x3, 0x2, 0x2, 
    0x2, 0xb8, 0xb9, 0x5, 0x2a, 0x16, 0x2, 0xb9, 0xba, 0x7, 0x6, 0x2, 0x2, 
    0xba, 0x29, 0x3, 0x2, 0x2, 0x2, 0xbb, 0xc0, 0x5, 0x2c, 0x17, 0x2, 0xbc, 
    0xbd, 0x7, 0x6, 0x2, 0x2, 0xbd, 0xbf, 0x5, 0x2c, 0x17, 0x2, 0xbe, 0xbc, 
    0x3, 0x2, 0x2, 0x2, 0xbf, 0xc2, 0x3, 0x2, 0x2, 0x2, 0xc0, 0xbe, 0x3, 
    0x2, 0x2, 0x2, 0xc0, 0xc1, 0x3, 0x2, 0x2, 0x2, 0xc1, 0x2b, 0x3, 0x2, 
    0x2, 0x2, 0xc2, 0xc0, 0x3, 0x2, 0x2, 0x2, 0xc3, 0xc4, 0x5, 0x18, 0xd, 
    0x2, 0xc4, 0xc5, 0x5, 0x14, 0xb, 0x2, 0xc5, 0x2d, 0x3, 0x2, 0x2, 0x2, 
    0xc6, 0xcb, 0x5, 0x30, 0x19, 0x2, 0xc7, 0xc8, 0x7, 0x7, 0x2, 0x2, 0xc8, 
    0xca, 0x5, 0x30, 0x19, 0x2, 0xc9, 0xc7, 0x3, 0x2, 0x2, 0x2, 0xca, 0xcd, 
    0x3, 0x2, 0x2, 0x2, 0xcb, 0xc9, 0x3, 0x2, 0x2, 0x2, 0xcb, 0xcc, 0x3, 
    0x2, 0x2, 0x2, 0xcc, 0x2f, 0x3, 0x2, 0x2, 0x2, 0xcd, 0xcb, 0x3, 0x2, 
    0x2, 0x2, 0xce, 0xd0, 0x5, 0x18, 0xd, 0x2, 0xcf, 0xd1, 0x7, 0xa, 0x2, 
    0x2, 0xd0, 0xcf, 0x3, 0x2, 0x2, 0x2, 0xd0, 0xd1, 0x3, 0x2, 0x2, 0x2, 
    0xd1, 0xd2, 0x3, 0x2, 0x2, 0x2, 0xd2, 0xd3, 0x5, 0x16, 0xc, 0x2, 0xd3, 
    0x31, 0x3, 0x2, 0x2, 0x2, 0xd4, 0xd5, 0x7, 0x4, 0x2, 0x2, 0xd5, 0xd6, 
    0x5, 0x36, 0x1c, 0x2, 0xd6, 0xd7, 0x7, 0x5, 0x2, 0x2, 0xd7, 0x33, 0x3, 
    0x2, 0x2, 0x2, 0xd8, 0xe0, 0x5, 0x32, 0x1a, 0x2, 0xd9, 0xe0, 0x5, 0x38, 
    0x1d, 0x2, 0xda, 0xe0, 0x5, 0x3a, 0x1e, 0x2, 0xdb, 0xe0, 0x5, 0x3c, 
    0x1f, 0x2, 0xdc, 0xe0, 0x5, 0x3e, 0x20, 0x2, 0xdd, 0xe0, 0x5, 0x40, 
    0x21, 0x2, 0xde, 0xe0, 0x3, 0x2, 0x2, 0x2, 0xdf, 0xd8, 0x3, 0x2, 0x2, 
    0x2, 0xdf, 0xd9, 0x3, 0x2, 0x2, 0x2, 0xdf, 0xda, 0x3, 0x2, 0x2, 0x2, 
    0xdf, 0xdb, 0x3, 0x2, 0x2, 0x2, 0xdf, 0xdc, 0x3, 0x2, 0x2, 0x2, 0xdf, 
    0xdd, 0x3, 0x2, 0x2, 0x2, 0xdf, 0xde, 0x3, 0x2, 0x2, 0x2, 0xe0, 0x35, 
    0x3, 0x2, 0x2, 0x2, 0xe1, 0xe6, 0x5, 0x34, 0x1b, 0x2, 0xe2, 0xe3, 0x7, 
    0x6, 0x2, 0x2, 0xe3, 0xe5, 0x5, 0x34, 0x1b, 0x2, 0xe4, 0xe2, 0x3, 0x2, 
    0x2, 0x2, 0xe5, 0xe8, 0x3, 0x2, 0x2, 0x2, 0xe6, 0xe4, 0x3, 0x2, 0x2, 
    0x2, 0xe6, 0xe7, 0x3, 0x2, 0x2, 0x2, 0xe7, 0x37, 0x3, 0x2, 0x2, 0x2, 
    0xe8, 0xe6, 0x3, 0x2, 0x2, 0x2, 0xe9, 0xea, 0x5, 0x46, 0x24, 0x2, 0xea, 
    0xeb, 0x7, 0xb, 0x2, 0x2, 0xeb, 0xec, 0x5, 0x48, 0x25, 0x2, 0xec, 0x39, 
    0x3, 0x2, 0x2, 0x2, 0xed, 0xee, 0x7, 0xf, 0x2, 0x2, 0xee, 0xef, 0x5, 
    0x48, 0x25, 0x2, 0xef, 0xf0, 0x5, 0x34, 0x1b, 0x2, 0xf0, 0x3b, 0x3, 
    0x2, 0x2, 0x2, 0xf1, 0xf2, 0x7, 0x10, 0x2, 0x2, 0xf2, 0xf3, 0x5, 0x48, 
    0x25, 0x2, 0xf3, 0xf4, 0x5, 0x34, 0x1b, 0x2, 0xf4, 0x3d, 0x3, 0x2, 0x2, 
    0x2, 0xf5, 0xf6, 0x7, 0x11, 0x2, 0x2, 0xf6, 0xf7, 0x7, 0x8, 0x2, 0x2, 
    0xf7, 0xfb, 0x7, 0x13, 0x2, 0x2, 0xf8, 0xfa, 0x5, 0x44, 0x23, 0x2, 0xf9, 
    0xf8, 0x3, 0x2, 0x2, 0x2, 0xfa, 0xfd, 0x3, 0x2, 0x2, 0x2, 0xfb, 0xf9, 
    0x3, 0x2, 0x2, 0x2, 0xfb, 0xfc, 0x3, 0x2, 0x2, 0x2, 0xfc, 0xfe, 0x3, 
    0x2, 0x2, 0x2, 0xfd, 0xfb, 0x3, 0x2, 0x2, 0x2, 0xfe, 0xff, 0x7, 0x9, 
    0x2, 0x2, 0xff, 0x3f, 0x3, 0x2, 0x2, 0x2, 0x100, 0x101, 0x7, 0x14, 0x2, 
    0x2, 0x101, 0x103, 0x7, 0x8, 0x2, 0x2, 0x102, 0x104, 0x5, 0x48, 0x25, 
    0x2, 0x103, 0x102, 0x3, 0x2, 0x2, 0x2, 0x103, 0x104, 0x3, 0x2, 0x2, 
    0x2, 0x104, 0x109, 0x3, 0x2, 0x2, 0x2, 0x105, 0x106, 0x7, 0x7, 0x2, 
    0x2, 0x106, 0x108, 0x5, 0x48, 0x25, 0x2, 0x107, 0x105, 0x3, 0x2, 0x2, 
    0x2, 0x108, 0x10b, 0x3, 0x2, 0x2, 0x2, 0x109, 0x107, 0x3, 0x2, 0x2, 
    0x2, 0x109, 0x10a, 0x3, 0x2, 0x2, 0x2, 0x10a, 0x10c, 0x3, 0x2, 0x2, 
    0x2, 0x10b, 0x109, 0x3, 0x2, 0x2, 0x2, 0x10c, 0x10d, 0x7, 0x9, 0x2, 
    0x2, 0x10d, 0x41, 0x3, 0x2, 0x2, 0x2, 0x10e, 0x10f, 0x7, 0xc, 0x2, 0x2, 
    0x10f, 0x110, 0x5, 0x48, 0x25, 0x2, 0x110, 0x43, 0x3, 0x2, 0x2, 0x2, 
    0x111, 0x112, 0x7, 0x7, 0x2, 0x2, 0x112, 0x113, 0x5, 0x46, 0x24, 0x2, 
    0x113, 0x45, 0x3, 0x2, 0x2, 0x2, 0x114, 0x115, 0x7, 0x14, 0x2, 0x2, 
    0x115, 0x47, 0x3, 0x2, 0x2, 0x2, 0x116, 0x117, 0x8, 0x25, 0x1, 0x2, 
    0x117, 0x120, 0x5, 0x56, 0x2c, 0x2, 0x118, 0x120, 0x5, 0x52, 0x2a, 0x2, 
    0x119, 0x120, 0x5, 0x46, 0x24, 0x2, 0x11a, 0x120, 0x5, 0x50, 0x29, 0x2, 
    0x11b, 0x11c, 0x7, 0x8, 0x2, 0x2, 0x11c, 0x11d, 0x5, 0x48, 0x25, 0x2, 
    0x11d, 0x11e, 0x7, 0x9, 0x2, 0x2, 0x11e, 0x120, 0x3, 0x2, 0x2, 0x2, 
    0x11f, 0x116, 0x3, 0x2, 0x2, 0x2, 0x11f, 0x118, 0x3, 0x2, 0x2, 0x2, 
    0x11f, 0x119, 0x3, 0x2, 0x2, 0x2, 0x11f, 0x11a, 0x3, 0x2, 0x2, 0x2, 
    0x11f, 0x11b, 0x3, 0x2, 0x2, 0x2, 0x120, 0x12f, 0x3, 0x2, 0x2, 0x2, 
    0x121, 0x122, 0xc, 0xa, 0x2, 0x2, 0x122, 0x123, 0x5, 0x4a, 0x26, 0x2, 
    0x123, 0x124, 0x5, 0x48, 0x25, 0xb, 0x124, 0x12e, 0x3, 0x2, 0x2, 0x2, 
    0x125, 0x126, 0xc, 0x9, 0x2, 0x2, 0x126, 0x127, 0x5, 0x4c, 0x27, 0x2, 
    0x127, 0x128, 0x5, 0x48, 0x25, 0xa, 0x128, 0x12e, 0x3, 0x2, 0x2, 0x2, 
    0x129, 0x12a, 0xc, 0x5, 0x2, 0x2, 0x12a, 0x12b, 0x5, 0x4e, 0x28, 0x2, 
    0x12b, 0x12c, 0x5, 0x48, 0x25, 0x6, 0x12c, 0x12e, 0x3, 0x2, 0x2, 0x2, 
    0x12d, 0x121, 0x3, 0x2, 0x2, 0x2, 0x12d, 0x125, 0x3, 0x2, 0x2, 0x2, 
    0x12d, 0x129, 0x3, 0x2, 0x2, 0x2, 0x12e, 0x131, 0x3, 0x2, 0x2, 0x2, 
    0x12f, 0x12d, 0x3, 0x2, 0x2, 0x2, 0x12f, 0x130, 0x3, 0x2, 0x2, 0x2, 
    0x130, 0x49, 0x3, 0x2, 0x2, 0x2, 0x131, 0x12f, 0x3, 0x2, 0x2, 0x2, 0x132, 
    0x133, 0x9, 0x2, 0x2, 0x2, 0x133, 0x4b, 0x3, 0x2, 0x2, 0x2, 0x134, 0x135, 
    0x9, 0x3, 0x2, 0x2, 0x135, 0x4d, 0x3, 0x2, 0x2, 0x2, 0x136, 0x137, 0x9, 
    0x4, 0x2, 0x2, 0x137, 0x4f, 0x3, 0x2, 0x2, 0x2, 0x138, 0x139, 0x7, 0x14, 
    0x2, 0x2, 0x139, 0x13b, 0x7, 0x8, 0x2, 0x2, 0x13a, 0x13c, 0x5, 0x48, 
    0x25, 0x2, 0x13b, 0x13a, 0x3, 0x2, 0x2, 0x2, 0x13b, 0x13c, 0x3, 0x2, 
    0x2, 0x2, 0x13c, 0x141, 0x3, 0x2, 0x2, 0x2, 0x13d, 0x13e, 0x7, 0x7, 
    0x2, 0x2, 0x13e, 0x140, 0x5, 0x48, 0x25, 0x2, 0x13f, 0x13d, 0x3, 0x2, 
    0x2, 0x2, 0x140, 0x143, 0x3, 0x2, 0x2, 0x2, 0x141, 0x13f, 0x3, 0x2, 
    0x2, 0x2, 0x141, 0x142, 0x3, 0x2, 0x2, 0x2, 0x142, 0x144, 0x3, 0x2, 
    0x2, 0x2, 0x143, 0x141, 0x3, 0x2, 0x2, 0x2, 0x144, 0x145, 0x7, 0x9, 
    0x2, 0x2, 0x145, 0x51, 0x3, 0x2, 0x2, 0x2, 0x146, 0x147, 0x5, 0x54, 
    0x2b, 0x2, 0x147, 0x148, 0x5, 0x56, 0x2c, 0x2, 0x148, 0x53, 0x3, 0x2, 
    0x2, 0x2, 0x149, 0x14a, 0x9, 0x3, 0x2, 0x2, 0x14a, 0x55, 0x3, 0x2, 0x2, 
    0x2, 0x14b, 0x14e, 0x7, 0x15, 0x2, 0x2, 0x14c, 0x14e, 0x7, 0x16, 0x2, 
    0x2, 0x14d, 0x14b, 0x3, 0x2, 0x2, 0x2, 0x14d, 0x14c, 0x3, 0x2, 0x2, 
    0x2, 0x14e, 0x57, 0x3, 0x2, 0x2, 0x2, 0x18, 0x63, 0x6c, 0x79, 0x85, 
    0x94, 0x99, 0xa4, 0xb2, 0xc0, 0xcb, 0xd0, 0xdf, 0xe6, 0xfb, 0x103, 0x109, 
    0x11f, 0x12d, 0x12f, 0x13b, 0x141, 0x14d, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

PeaceParser::Initializer PeaceParser::_init;
