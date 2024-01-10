%{
#include <stdio.h>
#include <stdlib.h>

extern int yylineno;
%}

%token<text> ASSIGNMENT_OPERATOR ARITHMETIC_OPERATOR LOGICAL_OPERATOR RELATIONAL_OPERATOR ACCESS_OPERATOR
%token ARROW SEMICOLON COLON COMMA LEFT_PARENTHESIS RIGHT_PARENTHESIS LEFT_BRACKET RIGHT_BRACKET LEFT_BRACE RIGHT_BRACE
%token INT_TYPE STR_TYPE NULL_TYPE VAR CONST IF ELSE WHILE READ WRITE FN RETURN
%token<text> ID
%token<value> INT STR

%union {
    int value;
    char text[100];
}

%%

// start nonterminal
start: function                                 { printf("start -> function\n"); }
    | function start                            { printf("start -> function start\n"); }
    ;

// types
basic_type: INT_TYPE                            { printf("basic_type -> int\n"); }
    | STR_TYPE                                  { printf("basic_type -> str\n"); }
    | NULL_TYPE                                 { printf("basic_type -> null\n"); }
    ;
array_type: LEFT_BRACKET type SEMICOLON INT RIGHT_BRACKET   { printf("array_type -> [ type ; %d ]\n", $4); }
    ;
type: basic_type                                { printf("type -> array_type\n"); }
    | array_type                                { printf("type -> array_type\n"); }
    ;

// expressions
array_elem: expression                          { printf("array_elem -> expression\n"); }
    ;
array_elems: array_elem                         { printf("array_elems -> array_elem\n"); }
    | array_elem COMMA array_elems              { printf("array_elems -> array_elem , array_elems\n"); }
    ;
array: LEFT_BRACKET array_elems RIGHT_BRACKET   { printf("array -> [ array_elems ]\n"); }
    | LEFT_BRACKET RIGHT_BRACKET                { printf("array -> [ array_type ]\n"); }
    ;

lvalue: ID                                      { printf("lvalue -> %s\n", $1); }
    | ID ACCESS_OPERATOR ID                     { printf("lvalue -> %s . %s\n", $1, $3); }
    | ID LEFT_BRACKET rvalue RIGHT_BRACKET      { printf("lvalue -> %s[rvalue]\n", $1); }
    ;
rvalue: INT                                     { printf("rvalue -> %d\n", $1); }
    | STR                                       { printf("rvalue -> %s\n", $1); }
    | array                                     { printf("rvalue -> array\n"); }
    | lvalue                                    { printf("rvalue -> array\n"); }
    ;

term: rvalue                                    { printf("term -> rvalue\n"); }
    ;
expression_op: ARITHMETIC_OPERATOR              { printf("expression_op -> %s\n", $1); }
    | LOGICAL_OPERATOR                          { printf("expression_op -> %s\n", $1); }
    | RELATIONAL_OPERATOR                       { printf("expression_op -> %s\n", $1); }
    ;
expression: term                                { printf("expression -> term\n"); }
    | expression expression_op term             { printf("expression -> expression expression_op term\n"); }
    ;

condition: expression                           { printf("condition -> expression\n"); }
    ;

// declarations
var_declaration: VAR ID COLON type              { printf("var_declaration -> var %s: type\n", $2); }
    ;
const_declaration: CONST ID COLON type          { printf("const_declaration -> const %s: type\n", $2); }
    ;

// flow statements
if_stmt: IF LEFT_PARENTHESIS condition RIGHT_PARENTHESIS stmt_block else_stmt   { printf("if_stmt -> if ( condition ) stmt_block else_stmt\n"); }
    ;
else_stmt: ELSE stmt_block                      { printf("else_stmt -> else stmt_block\n"); }
    |                                           { printf("else_stmt -> EPSILON\n"); }
    ;
while_stmt: WHILE LEFT_PARENTHESIS condition RIGHT_PARENTHESIS stmt_block       { printf("while_stmt -> while ( condition ) stmt_block\n"); }
    ;
flow_stmt: if_stmt                              { printf("flow_stmt -> if_stmt\n"); }
    | while_stmt                                { printf("flow_stmt -> while_stmt\n"); }
    ;

// io statements
read_stmt: READ ID                              { printf("read_stmt -> read %s\n", $2); }
    ;
write_stmt: WRITE expression                    { printf("write_stmt -> write expression\n"); }
    ;
io_stmt: read_stmt                              { printf("io_stmt -> read_stmt\n"); }
    | write_stmt                                { printf("io_stmt -> write_stmt\n"); }
    ;

// other statements
assignment_stmt: lvalue ASSIGNMENT_OPERATOR expression      { printf("assignment_stmt -> lvalue %s expression\n", $2); }
    ;
return_stmt: RETURN term                                    { printf("return_stmt -> return term\n"); }
    ;
call_stmt: ID LEFT_PARENTHESIS args RIGHT_PARENTHESIS       { printf("call_stmt -> %s ( args )\n", $1); }
    | ID LEFT_PARENTHESIS RIGHT_PARENTHESIS                 { printf("call_stmt -> %s ( )\n", $1); }
    ;

stmt: var_declaration SEMICOLON                 { printf("stmt -> var_declaration ;\n"); }
    | const_declaration SEMICOLON               { printf("stmt -> const_declaration ;\n"); }
    | assignment_stmt SEMICOLON                 { printf("stmt -> assignment_stmt ;\n"); }
    | io_stmt SEMICOLON                         { printf("stmt -> io_stmt ;\n"); }
    | return_stmt SEMICOLON                     { printf("stmt -> return_stmt ;\n"); }
    | call_stmt SEMICOLON                       { printf("stmt -> call_stmt ;\n"); }
    | flow_stmt                                 { printf("stmt -> flow_stmt ;\n"); }
    ;
stmt_list: stmt stmt_list                       { printf("stmt_list -> stmt stmt_list\n"); }
    |                                           { printf("stmt_list -> EPSILON\n"); }
    ;
stmt_block: LEFT_BRACE stmt_list RIGHT_BRACE    { printf("stmt_block -> { stmt_list }\n"); }
    ;

function: FN ID LEFT_PARENTHESIS params RIGHT_PARENTHESIS ARROW type stmt_block     { printf("function -> fn %s ( params ) -> type stmt_block\n", $2); }
    | FN ID LEFT_PARENTHESIS RIGHT_PARENTHESIS ARROW type stmt_block                { printf("function -> fn %s ( ) -> type stmt_block\n", $2); }
    ;

param: ID COLON type                            { printf("param -> %s : type\n", $1); }
    ;
params: param                                   { printf("params -> param\n"); }
    | param COMMA params                        { printf("params -> param , param\n"); }
    ;

arg: term                                       { printf("arg -> term\n"); }
    ;
args: arg                                       { printf("args -> arg\n"); }
    | arg COMMA args                            { printf("args -> arg , args\n"); }
    ;

%%

int yyerror(const char* msg) {
    fprintf(stderr, "Syntax error at line %d: %s\n", yylineno, msg);
}

int main() {
    yyparse();
    return 0;
}
