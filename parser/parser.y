%{
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void yyerror(const char *s);
int yylex(void);

/* --- Lógica de Indentação --- */
int indent_level = 1;
void print_indent() {
    for (int i = 0; i < indent_level; i++) {
        printf("    ");
    }
}
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
%token T_SWITCH T_CASE T_DEFAULT T_BREAK T_CONTINUE T_DO
%token T_STRUCT T_CONST T_UNSIGNED
%token T_MOD T_INC T_DEC T_PLUS_ASSIGN T_MINUS_ASSIGN
%token T_ARROW T_DOT T_AMPERSAND T_BIT_OR
%token T_PLUS T_MINUS T_MULT T_DIV
%token T_ASSIGN T_EQ T_NEQ T_LT T_GT T_LE T_GE
%token T_AND T_OR T_NOT
%token T_LPAREN T_RPAREN T_LBRACE T_RBRACE T_SEMICOLON T_COMMA

/* --- Precedência dos Operadores --- */
%right T_ASSIGN T_PLUS_ASSIGN T_MINUS_ASSIGN
%left T_OR
%left T_AND
%left T_BIT_OR
%left T_EQ T_NEQ
%left T_GT T_LT T_GE T_LE
%left T_PLUS T_MINUS
%left T_MULT T_DIV T_MOD
%right T_NOT T_INC T_DEC T_AMPERSAND /* T_AMPERSAND (unário) adicionado aqui */
%left T_DOT T_ARROW


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
    %empty
    | declaration declarations
    ;

declaration:
    type_specifier T_ID T_SEMICOLON
    {
        print_indent();
        printf("%s: %s\n", $2, $1);
        free($1); free($2);
    }
    | type_specifier T_ID T_ASSIGN expression T_SEMICOLON
    {
        print_indent();
        printf("%s: %s <- %s\n", $2, $1, $4);
        free($1); free($2); free($4);
    }
    ;

type_specifier:
    T_INT      { $$ = strdup("inteiro"); }
    | T_FLOAT    { $$ = strdup("real"); }
    | T_CHAR     { $$ = strdup("caractere"); }
    | T_CONST    { $$ = strdup("constante"); }
    | T_UNSIGNED { $$ = strdup("natural"); }
    ;

statements:
    %empty
    | statement statements
    ;

statement:
    printf_statement
    | scanf_statement
    | if_statement
    | while_statement
    | do_while_statement
    | break_statement
    | continue_statement
    | return_statement
    | assignment_statement
    | T_SEMICOLON
    ;

do_while_statement:
    T_DO
    {
        print_indent();
        printf("repita\n");
        indent_level++;
    }
    T_LBRACE statements T_RBRACE T_WHILE T_LPAREN expression T_RPAREN T_SEMICOLON
    {
        indent_level--;
        print_indent();
        printf("ate (%s)\n", $8);
        free($8);
    }
    ;

break_statement:
    T_BREAK T_SEMICOLON
    {
        print_indent();
        printf("interrompa\n");
    }
    ;

continue_statement:
    T_CONTINUE T_SEMICOLON
    {
        print_indent();
        printf("// continue (pular para próxima iteração)\n");
    }
    ;

scanf_statement:
    T_SCANF T_LPAREN expression T_RPAREN T_SEMICOLON
    {
        print_indent();
        printf("leia(%s)\n", $3);
        free($3);
    }
    ;

while_statement:
    T_WHILE T_LPAREN expression T_RPAREN
    {
        print_indent();
        printf("enquanto (%s) faca\n", $3);
        free($3);
        indent_level++;
    }
    T_LBRACE statements T_RBRACE
    {
        indent_level--;
        print_indent();
        printf("fimenquanto\n");
    }
    ;

/* --- REGRA ATUALIZADA --- para incluir atribuição composta */
assignment_statement:
    T_ID T_ASSIGN expression T_SEMICOLON
    {
        print_indent();
        printf("%s <- %s\n", $1, $3);
        free($1); free($3);
    }
    | T_ID T_PLUS_ASSIGN expression T_SEMICOLON
    {
        print_indent();
        printf("%s <- %s + %s\n", $1, $1, $3);
        free($1); free($3);
    }
    | T_ID T_MINUS_ASSIGN expression T_SEMICOLON
    {
        print_indent();
        printf("%s <- %s - %s\n", $1, $1, $3);
        free($1); free($3);
    }
    ;

return_statement:
    T_RETURN expression T_SEMICOLON
    {
        print_indent();
        printf("retorne %s\n", $2);
        free($2);
    }
    ;

if_statement:
    T_IF T_LPAREN expression T_RPAREN
        {
            print_indent();
            printf("se (%s) entao\n", $3);
            free($3);
            indent_level++;
        }
    T_LBRACE statements T_RBRACE
    {
        indent_level--;
    }
    else_part
    ;

else_part:
    %empty
        {
            print_indent();
            printf("fimse\n");
        }
    | T_ELSE T_LBRACE
        {
            print_indent();
            printf("senao\n");
            indent_level++;
        }
      statements T_RBRACE
        {
            indent_level--;
            print_indent();
            printf("fimse\n");
        }
    ;

/* --- REGRA EXPRESSION ATUALIZADA E COMPLETA --- */
expression:
    T_ID                     { $$ = $1; }
    | T_NUMBER_INT           { asprintf(&$$, "%d", $1); }
    | T_NUMBER_FLOAT         { asprintf(&$$, "%.2f", $1); }
    | T_STRING               { $$ = $1; }
    | T_CHAR_LITERAL         { $$ = $1; }
    | expression T_PLUS expression    { asprintf(&$$, "%s + %s", $1, $3); free($1); free($3); }
    | expression T_MINUS expression   { asprintf(&$$, "%s - %s", $1, $3); free($1); free($3); }
    | expression T_MULT expression    { asprintf(&$$, "%s * %s", $1, $3); free($1); free($3); }
    | expression T_DIV expression     { asprintf(&$$, "%s / %s", $1, $3); free($1); free($3); }
    | expression T_MOD expression     { asprintf(&$$, "%s %% %s", $1, $3); free($1); free($3); }
    | expression T_EQ expression      { asprintf(&$$, "%s = %s", $1, $3); free($1); free($3); }
    | expression T_NEQ expression     { asprintf(&$$, "%s <> %s", $1, $3); free($1); free($3); }
    | expression T_LT expression      { asprintf(&$$, "%s < %s", $1, $3); free($1); free($3); }
    | expression T_GT expression      { asprintf(&$$, "%s > %s", $1, $3); free($1); free($3); }
    | expression T_LE expression      { asprintf(&$$, "%s <= %s", $1, $3); free($1); free($3); }
    | expression T_GE expression      { asprintf(&$$, "%s >= %s", $1, $3); free($1); free($3); }
    | expression T_AND expression     { asprintf(&$$, "%s e %s", $1, $3); free($1); free($3); }
    | expression T_OR expression      { asprintf(&$$, "%s ou %s", $1, $3); free($1); free($3); }
    | expression T_BIT_OR expression  { asprintf(&$$, "%s | %s", $1, $3); free($1); free($3); } /* Adicionado */
    | T_AMPERSAND expression          { asprintf(&$$, "&%s", $2); free($2); }                 /* Adicionado (endereço de) */
    | T_LPAREN expression T_RPAREN    { asprintf(&$$, "(%s)", $2); free($2); }
    | T_INC expression                { asprintf(&$$, "++%s", $2); free($2); }                 /* Corrigido para expression */
    | T_DEC expression                { asprintf(&$$, "--%s", $2); free($2); }                 /* Adicionado */
    | expression T_INC                { asprintf(&$$, "%s++", $1); free($1); }                 /* Adicionado */
    | expression T_DEC                { asprintf(&$$, "%s--", $1); free($1); }                 /* Adicionado */
    | expression T_DOT T_ID           { asprintf(&$$, "%s.%s", $1, $3); free($1); free($3); }   /* Adicionado */
    | expression T_ARROW T_ID         { asprintf(&$$, "%s->%s", $1, $3); free($1); free($3); } /* Adicionado */
    ;

printf_statement:
    T_PRINTF T_LPAREN expression T_RPAREN T_SEMICOLON
    {
        print_indent();
        printf("escreva(%s)\n", $3);
        free($3);
    }
    ;

%%

void yyerror(const char *s) {
    fprintf(stderr, "Erro de sintaxe: %s\n", s);
    exit(1);
}