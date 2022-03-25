grammar Peace;  // A tiny subset of Pascal

@header {
#include "wci/intermediate/TypeSpec.h"
using namespace wci::intermediate;
}

program   : header mainBlock 'ENDPROG' ;         // CHANGED
header    : PROG IDENTIFIER ;                    // CHANGED
mainBlock : block;                               // CHANGED
block     : declarations definitions? main ;     // CHANGED
main        locals [ int limitLocals ]  
          : MAIN mainBody ;                      // NEW
mainBody  : '{' funcDeclarations? stmtList '}' ; // NEW

declarations : declList ';' ;         // CHANGED
declList     : decl ( ';' decl )* ;
decl         : typeId '-' varList ;   // CHANGED
varList      : varId ( ',' varId )* ;
varId        : IDENTIFIER ;
typeId       : IDENTIFIER ;

definitions     : definitionsList ';' ;                                   // NEW
definitionsList : def ( ';' def)* ;                                       // NEW
def             : (proc | func) ;                                         // NEW
proc              locals [ string parameterTypes = "", int limitLocals ]  // NEW
                : VOID IDENTIFIER '(' parameterList ')' procBody ;        // NEW
procBody        : '{' funcDeclarations? stmtList '}' ;                    // NEW
func	          locals [ string parameterTypes = "", int limitLocals ]  // NEW
                : typeId IDENTIFIER '(' parameterList ')' funcBody ;      // NEW
funcBody	    : '{' funcDeclarations? stmtList returnStmt '}' ;         // NEW

funcDeclarations : funcDeclList ';' ;                                                       // NEW
funcDeclList     : funcDecl ( ';' funcDecl )* ;                                             // NEW
funcDecl           locals [ vector<string> localsArr, vector<SymTabEntry *> localsVarArr ]  // NEW
				 : typeId varList ;                                                         // NEW

parameterList   locals [ vector<string> paramList ]           // NEW
              : parameter ( ',' parameter )* ;                // NEW
parameter       locals [ vector<SymTabEntry *> localsVarArr ] // NEW 
              : typeId '&'? varId ;                           // NEW

compoundStmt : '{' stmtList '}' ;   // CHANGED

stmt : compoundStmt       
     | assignmentStmt	  
     | if_stmt         // NEW
     | whileStmt       // NEW
     | print           // NEW
     | procCall        // NEW
     |                  
     ;
     
stmtList       : stmt ( ';' stmt )* ;
assignmentStmt : variable '=' expr ;
if_stmt        : IF expr stmt ;                               // NEW
whileStmt	   : WHILE expr stmt ;                            // NEW
print            locals [ vector<string> printVars ]          // NEW
			   : PRINT '(' STRING ( printVariables )* ')';    // NEW
procCall         locals [ string parameterTypes = "" ]        // NEW
               : IDENTIFIER '(' (expr)? ( ',' expr)* ')';     // NEW
returnStmt     : 'return' expr ;

printVariables : ',' variable ;
variable       : IDENTIFIER ;

expr locals [ TypeSpec *type = nullptr, string parameterTypes = "" ]
    : expr mulDivOp expr   # mulDivExpr
    | expr addSubOp expr   # addSubExpr
    | number               # unsignedNumberExpr
    | signedNumber         # signedNumberExpr
    | variable             # variableExpr
    | expr relOp expr      # boolExpr           // NEW
    | funcCall             # funcCallExpr       // NEW
    | '(' expr ')'         # parenExpr
    ;   
     
mulDivOp : MUL_OP | DIV_OP ;
addSubOp : ADD_OP | SUB_OP ;
relOp    : EQ_OP  | NE_OP  | LT_OP  | LE_OP  | GT_OP  | GE_OP  ; // NEW
funcCall : IDENTIFIER '(' (expr)? ( ',' expr)* ')';              // NEW
     
signedNumber locals [ TypeSpec *type = nullptr ] 
    : sign number 
    ;
    
sign : ADD_OP | SUB_OP ;

number locals [ TypeSpec *type = nullptr ]
    : INTEGER    # integerConst
    | FLOAT      # floatConst
    ;

PROG    : 'PROG' ;   // CHANGED
MAIN    : 'MAIN' ;   // NEW
IF      : 'IF' ;     // NEW
WHILE	: 'WHILE' ;  // NEW
PRINT   : 'PRINT' ;  // NEW

VOID       : 'VOID' ;                     // NEW
STRING     : '"' [!*=a-zA-Z0-9%\\ ]*  '"' ;  // NEW
IDENTIFIER : [a-zA-Z][a-zA-Z0-9]* ;
INTEGER    : [0-9]+ ;
FLOAT      : [0-9]+ '.' [0-9]+ ;

MUL_OP :   '*' ;
DIV_OP :   '/' ;
ADD_OP :   '+' ;
SUB_OP :   '-' ;
EQ_OP  :  '==' ; // NEW
NE_OP  :  '!=' ; // NEW
LT_OP  :   '<' ; // NEW
LE_OP  :  '<=' ; // NEW
GT_OP  :   '>' ; // NEW
GE_OP  :  '>=' ; // NEW

NEWLINE : '\r'? '\n' -> skip  ;
WS      : [ \t]+ -> skip ; 
