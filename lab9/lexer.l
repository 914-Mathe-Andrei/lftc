%{
#include "parser.tab.h"
%}

%option noyywrap
%option yylineno

WHITESPACE              [[:space:]]

UNDERSCORE              _

UPPERCASE_LETTER        [A-Z]
LOWERCASE_LETTER        [a-z]
LETTER                  ({UPPERCASE_LETTER}|{LOWERCASE_LETTER})

ZERO_DIGIT              0
NONZERO_DIGIT           [1-9]
DIGIT                   ({ZERO_DIGIT}|{NONZERO_DIGIT})

ASSIGNMENT_OPERATOR     =
ARITHMETIC_OPERATOR     (\+|-|\*|\/|%)
LOGICAL_OPERATOR        (&&|\|\||!)
RELATIONAL_OPERATOR     (==|!=|<=|>=|<|>)
ACCESS_OPERATOR         \.

ID                      ({UNDERSCORE}|{LETTER})({UNDERSCORE}|{LETTER}|{DIGIT})*
INT                     ({ZERO_DIGIT}|{NONZERO_DIGIT}{DIGIT}*)
STR                     ({LETTER}|{DIGIT}|\s)*

%%

{ASSIGNMENT_OPERATOR}   { strcpy(yylval.text, yytext); return ASSIGNMENT_OPERATOR; }
{ARITHMETIC_OPERATOR}   { strcpy(yylval.text, yytext); return ARITHMETIC_OPERATOR; }
{LOGICAL_OPERATOR}      { strcpy(yylval.text, yytext); return LOGICAL_OPERATOR; }
{RELATIONAL_OPERATOR}   { strcpy(yylval.text, yytext); return RELATIONAL_OPERATOR; }
{ACCESS_OPERATOR}       { strcpy(yylval.text, yytext); return ACCESS_OPERATOR; }

->                      { return ARROW; }
;                       { return SEMICOLON; }
:                       { return COLON; }
,                       { return COMMA; }
\(                      { return LEFT_PARENTHESIS; }
\)                      { return RIGHT_PARENTHESIS; }
\[                      { return LEFT_BRACKET; }
\]                      { return RIGHT_BRACKET; }
\{                      { return LEFT_BRACE; }
\}                      { return RIGHT_BRACE; }

int                     { return INT_TYPE; }
str                     { return STR_TYPE; }
null                    { return NULL_TYPE; }
var                     { return VAR; }
const                   { return CONST; }
if                      { return IF; }
else                    { return ELSE; }
while                   { return WHILE; }
read                    { return READ; }
write                   { return WRITE; }
fn                      { return FN; }
return                  { return RETURN; }

{ID}                    { strcpy(yylval.text, yytext); return ID; }
{INT}{ID}               { fprintf(stderr, "LexicalError at line %d: id cannot start with digit: %s", yylineno, yytext); exit(1); }
{ZERO_DIGIT}{INT}       { fprintf(stderr, "LexicalError at line %d: int cannot have leading 0s: %s", yylineno, yytext); exit(1); }
{INT}                   { yylval.value = atoi(yytext); return INT; }
\"{STR}\"               { strcpy(yylval.text, yytext); return STR; }
\"{STR}                 { fprintf(stderr, "LexicalError at line %d: matching closing double quote not found: %s", yylineno, yytext); exit(1); }
{STR}\"                 { fprintf(stderr, "LexicalError at line %d: matching closing double quote not found: %s", yylineno, yytext); exit(1); }

{WHITESPACE}
<<EOF>>                 { return 0; }

.                       { fprintf(stderr, "LexicalError at line %d: unknown symbol: %s", yylineno, yytext); exit(1); }

%%