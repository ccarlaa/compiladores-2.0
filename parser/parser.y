%{
#include <stdio.h>
#include <string.h>

void yyerror(const char *s);
int yylex(void);

%}

%union {
    char *sval;
    int ival;
}

%token <sval> T_ID T_STRING
%token <ival> T_NUMBER
%token T_INT T_PRINTF

%type <sval> expression

%%

program:
    function_declaration
    ;

function_declaration:
    T_INT T_ID '(' ')' '{'
    {
        printf("algoritmo \"%s\"\n", $2);
        printf("inicio\n");
    }
    body
    {
        printf("fimalgoritmo\n");
    }
    '}'
    ;

body:
    declarations statements
    ;

declarations:
    /* pode ser vazio */
    | declaration declarations
    ;

declaration:
    T_INT T_ID ';' { printf("   inteiro %s\n", $2); }
    | T_INT T_ID '=' T_NUMBER ';' { printf("   inteiro %s = %d\n", $2, $4); }
    ;

statements:
    /* pode ser vazio */
    | statement statements
    ;

statement:
    printf_statement
    ;

printf_statement:
    T_PRINTF '(' expression ')' ';' { printf("   escreva(%s)\n", $3); }
    ;

expression:
    T_STRING { $$ = $1; }
    | T_ID     { $$ = $1; }
    ;

%%

void yyerror(const char *s) {
    fprintf(stderr, "Erro de sintaxe: %s\n", s);
}
