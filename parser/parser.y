%{
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * CORREÇÃO 1: Definir _GNU_SOURCE para habilitar 'asprintf' 
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void yyerror(const char *s);
int yylex(void);

%}

%union {
    char *sval;
    int ival;
    float fval;
}

/* --- Declaração dos Tokens --- */
%token <sval> T_ID T_STRING T_CHAR_LITERAL
%token <ival> T_NUMBER_INT
%token <fval> T_NUMBER_FLOAT

%token T_INT T_FLOAT T_CHAR T_VOID
%token T_IF T_ELSE T_WHILE T_FOR T_RETURN T_PRINTF T_SCANF

%token T_PLUS T_MINUS T_MULT T_DIV
%token T_ASSIGN T_EQ T_NEQ T_LT T_GT T_LE T_GE
%token T_AND T_OR T_NOT

%token T_LPAREN T_RPAREN T_LBRACE T_RBRACE T_SEMICOLON T_COMMA

/* --- Precedência dos Operadores --- */
%left T_OR
%left T_AND
%left T_EQ T_NEQ
%left T_GT T_LT T_GE T_LE
%left T_PLUS T_MINUS
%left T_MULT T_DIV
%right T_NOT

/* --- Tipos para nós da gramática --- */
%type <sval> type_specifier expression

%%

program:
    function_declaration
    ;

function_declaration:
    type_specifier T_ID T_LPAREN T_RPAREN T_LBRACE
    {
        printf("algoritmo \"%s\"\n", $2);
        free($2);
        printf("var\n");
    }
    declarations
    {
        printf("inicio\n");
    }
    statements
    {
        printf("fimalgoritmo\n");
    }
    T_RBRACE
    ;

declarations:
    %empty /* AVISO CORRIGIDO: Regra vazia explícita */
    | declaration declarations
    ;

declaration:
    type_specifier T_ID T_SEMICOLON 
    { 
        printf("    %s: %s\n", $2, $1);
        free($1); free($2);
    }
    | type_specifier T_ID T_ASSIGN expression T_SEMICOLON 
    { 
        printf("    %s: %s <- %s\n", $2, $1, $4);
        free($1); free($2); free($4);
    }
    ;

type_specifier:
    T_INT   { $$ = strdup("inteiro"); }
    | T_FLOAT { $$ = strdup("real"); }
    | T_CHAR  { $$ = strdup("caractere"); }
    ;

statements:
    %empty /* AVISO CORRIGIDO: Regra vazia explícita */
    | statement statements
    ;

statement:
    printf_statement
    | if_statement
    | return_statement
    | T_SEMICOLON /* Permite ponto e vírgula extra */
    ;

return_statement:
    T_RETURN expression T_SEMICOLON
    {
        printf("    retorne %s\n", $2);
        free($2);
    }
    ;

/* --- Lógica IF-ELSE aprimorada --- */
if_statement:
    T_IF T_LPAREN expression T_RPAREN 
        {
            printf("    se (%s) entao\n", $3);
            free($3);
        }
    T_LBRACE statements T_RBRACE
    else_part
    ;

else_part:
    %empty 
        { printf("    fimse\n"); }
    | T_ELSE T_LBRACE 
        { printf("    senao\n"); } 
      statements T_RBRACE 
        { printf("    fimse\n"); }
    ;


expression:
    T_ID            { $$ = $1; }
    | T_NUMBER_INT  { asprintf(&$$, "%d", $1); }
    | T_NUMBER_FLOAT{ asprintf(&$$, "%.2f", $1); }
    | T_STRING      { $$ = $1; }
    | T_CHAR_LITERAL{ $$ = $1; }
    | expression T_PLUS expression   { asprintf(&$$, "%s + %s", $1, $3); free($1); free($3); }
    | expression T_MINUS expression  { asprintf(&$$, "%s - %s", $1, $3); free($1); free($3); }
    | expression T_MULT expression   { asprintf(&$$, "%s * %s", $1, $3); free($1); free($3); }
    | expression T_DIV expression    { asprintf(&$$, "%s / %s", $1, $3); free($1); free($3); }
    | expression T_EQ expression     { asprintf(&$$, "%s = %s", $1, $3); free($1); free($3); }
    | expression T_NEQ expression    { asprintf(&$$, "%s <> %s", $1, $3); free($1); free($3); }
    | expression T_LT expression     { asprintf(&$$, "%s < %s", $1, $3); free($1); free($3); }
    | expression T_GT expression     { asprintf(&$$, "%s > %s", $1, $3); free($1); free($3); }
    | expression T_LE expression     { asprintf(&$$, "%s <= %s", $1, $3); free($1); free($3); }
    | expression T_GE expression     { asprintf(&$$, "%s >= %s", $1, $3); free($1); free($3); }
    | expression T_AND expression    { asprintf(&$$, "%s e %s", $1, $3); free($1); free($3); }
    | expression T_OR expression     { asprintf(&$$, "%s ou %s", $1, $3); free($1); free($3); }
    | T_LPAREN expression T_RPAREN   { asprintf(&$$, "(%s)", $2); free($2); }
    ;

printf_statement:
    T_PRINTF T_LPAREN expression T_RPAREN T_SEMICOLON 
    { 
        printf("    escreva(%s)\n", $3); 
        free($3);
    }
    ;

%%

void yyerror(const char *s) {
    fprintf(stderr, "Erro de sintaxe: %s\n", s);
    exit(1);
}
