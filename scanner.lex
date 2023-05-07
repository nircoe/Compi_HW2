%{

/* Declarations section */
#include <stdio.h>
#include "output.hpp"
#include "parser.tab.hpp"
using namespace output;

%}

%option yylineno
%option noyywrap

void "void"
int "int"
byte "byte"
b "b"
bool "bool"
override "override"
and "and"
or "or"
not "not"
true "true"
false "false"
return "return"
if "if"
else "else"
while "while"
break "break"
continue "continue"
sc (\;)
comma (\,)
lparen (\()
rparen(\))
lbrace (\{)
rbrace (\})
assign (\=)
relop (==|!=|<|>|<=|>=)
plusminus ([\+\-])
multdiv ([\*\/])
comment (\/\/[^\n\r]*)
id ([a-zA-z][a-zA-Z0-9]*)
num (([1-9]+[0-9]*)|0)
digit ([0-9])
letter ([a-zA-Z])
whitespace ([ \t\n\r])

printable_char ([^\r\n\"\\])
legal_hex (\\x[0-7][0-9a-fA-F])
escape_sequence (\\[\\\"nrt0])

string (\"({printable_char}|{escape_sequence}|{legal_hex})*\")

%x STR
%x ESC_SEQ
%x STR_HEX

%%

{void}                      return VOID;
{int}                       return INT;
{byte}                      return BYTE;
{b}                         return B;
{bool}                      return BOOL;
{override}                  return OVERRIDE;
{and}                       return AND;
{or}                        return OR;
{not}                       return NOT;
{true}                      return TRUE;
{false}                     return FALSE;
{return}                    return RETURN;
{if}                        return IF;
{else}                      return ELSE;
{while}                     return WHILE;
{break}                     return BREAK;
{continue}                  return CONTINUE;
{sc}                        return SC;
{comma}                     return COMMA;
{lparen}                    return LPAREN;
{rparen}                    return RPAREN;
{lbrace}                    return LBRACE;
{rbrace}                    return RBRACE;
{assign}                    return ASSIGN;
{relop}                     return RELOP;
{plusminus}                 return PLUSMINUS;
{multdiv}                   return MULTDIV;
{comment}                   ;
{id}                        return ID;
{num}                       return NUM;
{whitespace}				;
{string}                    return STRING;

.		                    { errorLex(yylineno); exit(0); };

%%
