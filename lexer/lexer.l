%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

%}

%option yylineno

%{
#include "parser.tab.h"

extern YYSTYPE yylval;

%}

%option yylineno

%%

"int"             { return INT; }
"printf"          { return PRINTF; }

[0-9]+            { yylval.str = strdup(yytext); return NUM; }
[a-zA-Z_][a-zA-Z0-9_]* { yylval.str = strdup(yytext); return ID; }

"="               { return '='; }
";"               { return ';'; }
"("               { return '('; }
")"               { return ')'; }
"{"               { return '{'; }
"}"               { return '}'; }
"+"               { return '+'; }

[ \t\n]           ; // ignora espaços
.                 { printf("Caractere inválido: %s\n", yytext); exit(1); }

%%
