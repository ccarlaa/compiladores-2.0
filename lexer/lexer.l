%{
#include "y.tab.h" // Inclui os tokens definidos pelo Bison
%}

%%

"int"               { return T_INT; }
"printf"            { return T_PRINTF; }
[a-zA-Z_][a-zA-Z0-9_]* { yylval.sval = strdup(yytext); return T_ID; }
[0-9]+              { yylval.ival = atoi(yytext); return T_NUMBER; }
\"(\\.|[^"\\])*\"  { yylval.sval = strdup(yytext); return T_STRING; }

"{"                 { return '{'; }
"}"                 { return '}'; }
"("                 { return '('; }
")"                 { return ')'; }
";"                 { return ';'; }
"="                 { return '='; }

[ \t\n]+            ; /* Ignora espaços em branco, tabs e novas linhas */
.                   { /* Ignora qualquer outro caractere */ }

%%

int yywrap(void) {
    return 1;
}