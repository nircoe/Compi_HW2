#include <iostream>
#include "output.hpp"
#include <sstream>

const std::string output::rules[] = {
    "Program -> Funcs",
    "Funcs -> epsilon",
    "Funcs -> FuncDecl Funcs",
    "FuncDecl -> OverRide RetType ID LPAREN Formals RPAREN LBRACE Statements RBRACE",
	"OverRide -> epsilon",
	"OverRide -> OVERRIDE",
    "RetType -> Type",
    "RetType ->  VOID",
    "Formals -> epsilon",
    "Formals -> FormalsList",
    "FormalsList -> FormalDecl",
    "FormalsList -> FormalDecl COMMA FormalsList",
    "FormalDecl -> Type ID",
    "Statements -> Statement",
    "Statements -> Statements Statement",
    "Statement -> LBRACE Statements RBRACE",
    "Statement -> Type ID SC",
    "Statement -> Type ID ASSIGN Exp SC",
    "Statement -> ID ASSIGN Exp SC",
    "Statement -> Call SC",
    "Statement -> RETURN SC",
    "Statement -> RETURN Exp SC",
    "Statement -> IF LPAREN Exp RPAREN Statement",
    "Statement -> IF LPAREN Exp RPAREN Statement ELSE Statement",
    "Statement -> WHILE LPAREN Exp RPAREN Statement",
    "Statement -> BREAK SC",
    "Statement -> CONTINUE SC",
    "Call -> ID LPAREN ExpList RPAREN",
    "Call -> ID LPAREN RPAREN",
    "ExpList -> Exp",
    "ExpList -> Exp COMMA ExpList",
    "Type -> INT",
    "Type -> BYTE",
    "Type -> BOOL",
    "Exp -> LPAREN Exp RPAREN",
    "Exp -> Exp BINOP Exp",
    "Exp -> ID",
    "Exp -> Call",
    "Exp -> NUM",
    "Exp -> NUM B",
    "Exp -> STRING",
    "Exp -> TRUE",
    "Exp -> FALSE",
    "Exp -> NOT Exp",
    "Exp -> Exp AND Exp",
    "Exp -> Exp OR Exp",
    "Exp -> Exp RELOP Exp",
    "Exp -> LPAREN Type RPAREN Exp"
};

void output::printProductionRule(const int ruleno) {
    std::cout << ruleno << ": " << output::rules[ruleno-1] << "\n";
}

void output::errorLex(const int lineno) {
    std::cout << "line " << lineno << ": lexical error\n";
}

void output::errorSyn(const int lineno) {
    std::cout << "line " << lineno << ": syntax error\n";
}
