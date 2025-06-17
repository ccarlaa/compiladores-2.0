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
%token T_LPAREN T_RPAREN T_LBRACE T_RBRACE T_SEMICOLON T_COMMA T_COLON

/* --- Precedência dos Operadores --- */
// Order matters for resolving shift/reduce conflicts.
// Unary operators (NOT, INC, DEC, AMPERSAND, Pointer/Dereference) generally bind tighter.
%right T_ASSIGN T_PLUS_ASSIGN T_MINUS_ASSIGN
%left T_OR
%left T_AND
%left T_BIT_OR
%left T_EQ T_NEQ
%left T_GT T_LT T_GE T_LE
%left T_PLUS T_MINUS
%left T_MULT T_DIV T_MOD
%right T_NOT T_INC T_DEC T_AMPERSAND /* Unary operators */
%left T_DOT T_ARROW /* Member access */
%left T_LPAREN T_RPAREN /* Function calls and grouping */
%right '*' /* Usado para declarações de ponteiro e desreferenciação unária */


/* --- Tipos para nós da gramática --- */
%type <sval> type_specifier expression declaration_or_expression declaration assignment_statement
%type <sval> declarator direct_declarator pointer
%type statement_list case_list
%type top_level_declaration top_level_declarations top_level_content


%%

program:
    {
        printf("programa\n{\n");
    }
    top_level_content
    {
        printf("}\n");
    }
    ;

top_level_content:
    top_level_declarations
    function_declaration
    ;

top_level_declarations:
    %empty
    | top_level_declaration top_level_declarations
    ;

top_level_declaration:
    struct_declaration
    ;

function_declaration:
    type_specifier T_ID T_LPAREN T_RPAREN T_LBRACE
    {
        print_indent();
        printf("funcao inicio()\n");
        print_indent();
        printf("{\n");
        indent_level++;
    }
    declarations
    statements
    {
        indent_level--;
        print_indent();
        printf("}\n");
    }
    T_RBRACE
    ;

declarations:
    %empty
    | declaration declarations
    ;

declaration:
    type_specifier declarator T_SEMICOLON
    {
        print_indent();
        // Check if the type or declarator implies a commented output (struct or pointer)
        if (strstr($1, "// struct") == $1 || strstr($2, "*") != NULL) {
            printf("// %s%s;\n", $1, $2); // For struct or pointer types, output as comment with semicolon
        } else {
            printf("%s%s\n", $1, $2); // For standard types, output as regular declaration
        }
        free($1); free($2);
    }
    | type_specifier declarator T_ASSIGN expression T_SEMICOLON
    {
        print_indent();
        // Check if the type or declarator implies a commented output (struct or pointer)
        if (strstr($1, "// struct") == $1 || strstr($2, "*") != NULL) {
            printf("// %s%s = %s;\n", $1, $2, $4); // For struct or pointer types, output as comment with semicolon
        } else {
            printf("%s%s = %s\n", $1, $2, $4); // For standard types, output as regular declaration
        }
        free($1); free($2); free($4);
    }
    ;

declarator:
    pointer direct_declarator
    {
        asprintf(&$$, "%s%s", $1, $2); // Combine pointer (if any) with direct declarator
        free($1); free($2);
    }
    | direct_declarator
    {
        $$ = $1; // Just the direct declarator
    }
    ;

pointer:
    '*'
    {
        $$ = strdup("*");
    }
    | '*' pointer
    {
        asprintf(&$$, "*%s", $2); // For multiple pointers (e.g., **)
        free($2);
    }
    ;

direct_declarator:
    T_ID
    {
        $$ = $1;
    }
    ;

struct_declaration:
    T_STRUCT T_ID T_LBRACE
    {
        print_indent();
        printf("// struct %s {\n", $2);
        free($2);
        indent_level++;
    }
    declarations_in_struct T_RBRACE T_SEMICOLON
    {
        indent_level--;
        print_indent();
        printf("// }\n");
    }
    ;

declarations_in_struct:
    %empty
    | declaration_in_struct declarations_in_struct
    ;

declaration_in_struct:
    type_specifier declarator T_SEMICOLON
    {
        print_indent();
        // Always comment out struct members, including pointer syntax
        printf("//    %s%s;\n", $1, $2);
        free($1); free($2);
    }
    ;

type_specifier:
    T_INT      { $$ = strdup("inteiro"); }
    | T_FLOAT    { $$ = strdup("real"); }
    | T_CHAR     { $$ = strdup("caractere"); }
    | T_VOID     { $$ = strdup("vazio"); }
    | T_CONST    { $$ = strdup("constante"); }
    | T_UNSIGNED { $$ = strdup("inteiro"); }
    | T_STRUCT T_ID { asprintf(&$$, "// struct %s", $2); free($2); } /* Handles 'struct Name' as a type specifier */
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
    | for_statement
    | switch_statement
    | break_statement
    | continue_statement
    | return_statement
    | assignment_statement
    | increment_statement
    | decrement_statement
    | function_call_statement
    | T_SEMICOLON
    ;

do_while_statement:
    T_DO
    {
        print_indent();
        printf("faca\n");
        print_indent();
        printf("{\n");
        indent_level++;
    }
    T_LBRACE statements T_RBRACE T_WHILE T_LPAREN expression T_RPAREN T_SEMICOLON
    {
        indent_level--;
        print_indent();
        printf("} enquanto (%s)\n", $8);
        free($8);
    }
    ;

break_statement:
    T_BREAK T_SEMICOLON
    {
        print_indent();
        printf("pare\n");
    }
    ;

continue_statement:
    T_CONTINUE T_SEMICOLON
    {
        print_indent();
        printf("// continue não é diretamente suportado em Portugol Studio, pulando iteração\n");
    }
    ;

scanf_statement:
    T_SCANF T_LPAREN T_STRING T_COMMA T_AMPERSAND T_ID T_RPAREN T_SEMICOLON
    {
        print_indent();
        printf("leia(%s)\n", $6);
        free($3);
        free($6);
    }
    ;

while_statement:
    T_WHILE T_LPAREN expression T_RPAREN
    {
        print_indent();
        printf("enquanto (%s)\n", $3);
        free($3);
        print_indent();
        printf("{\n");
        indent_level++;
    }
    T_LBRACE statements T_RBRACE
    {
        indent_level--;
        print_indent();
        printf("}\n");
    }
    ;

for_statement:
    T_FOR T_LPAREN declaration_or_expression T_SEMICOLON expression T_SEMICOLON expression T_RPAREN
    {
        print_indent();
        printf("para (%s; %s; %s)\n", $3, $5, $7);
        free($3); free($5); free($7);
        print_indent();
        printf("{\n");
        indent_level++;
    }
    T_LBRACE statements T_RBRACE
    {
        indent_level--;
        print_indent();
        printf("}\n");
    }
    ;

declaration_or_expression:
    declaration            { $$ = $1; }
    | assignment_statement { $$ = $1; }
    | expression           { $$ = $1; }
    | %empty               { $$ = strdup(""); }
    ;

assignment_statement:
    T_ID T_ASSIGN expression T_SEMICOLON
    {
        print_indent();
        printf("%s = %s\n", $1, $3);
        asprintf(&$$, "%s = %s", $1, $3);
        free($1); free($3);
    }
    | T_ID T_PLUS_ASSIGN expression T_SEMICOLON
    {
        print_indent();
        printf("%s = %s + %s\n", $1, $1, $3);
        asprintf(&$$, "%s = %s + %s", $1, $1, $3);
        free($1); free($3);
    }
    | T_ID T_MINUS_ASSIGN expression T_SEMICOLON
    {
        print_indent();
        printf("%s = %s - %s\n", $1, $1, $3);
        asprintf(&$$, "%s = %s - %s", $1, $1, $3);
        free($1); free($3);
    }
    ;

increment_statement:
    T_ID T_INC T_SEMICOLON
    {
        print_indent();
        printf("%s = %s + 1\n", $1, $1);
        free($1);
    }
    | T_INC T_ID T_SEMICOLON
    {
        print_indent();
        printf("%s = %s + 1\n", $2, $2);
        free($2);
    }
    ;

decrement_statement:
    T_ID T_DEC T_SEMICOLON
    {
        print_indent();
        printf("%s = %s - 1\n", $1, $1);
        free($1);
    }
    | T_DEC T_ID T_SEMICOLON
    {
        print_indent();
        printf("%s = %s - 1\n", $2, $2);
        free($2);
    }
    ;


return_statement:
    T_RETURN expression T_SEMICOLON
    {
        print_indent();
        printf("// retorne %s\n", $2);
        free($2);
    }
    ;

if_statement:
    T_IF T_LPAREN expression T_RPAREN
        {
            print_indent();
            printf("se (%s)\n", $3);
            free($3);
            print_indent();
            printf("{\n");
            indent_level++;
        }
    T_LBRACE statements T_RBRACE
    {
        indent_level--;
        print_indent();
        printf("}\n");
    }
    else_part
    ;

else_part:
    %empty
    | T_ELSE T_LBRACE
        {
            print_indent();
            printf("senao\n");
            print_indent();
            printf("{\n");
            indent_level++;
        }
      statements T_RBRACE
        {
            indent_level--;
            print_indent();
            printf("}\n");
        }
    ;

switch_statement:
    T_SWITCH T_LPAREN expression T_RPAREN T_LBRACE
    {
        print_indent();
        printf("escolha (%s)\n", $3);
        free($3);
        print_indent();
        printf("{\n");
        indent_level++;
    }
    case_list T_RBRACE
    {
        indent_level--;
        print_indent();
        printf("}\n");
    }
    ;

case_list:
    %empty
    | case_statement case_list
    | default_statement
    ;

case_statement:
    T_CASE expression T_COLON
    {
        print_indent();
        printf("caso %s:\n", $2);
        free($2);
        indent_level++;
    }
    statement_list
    {
        indent_level--;
    }
    ;

default_statement:
    T_DEFAULT T_COLON
    {
        print_indent();
        printf("padrao:\n");
        indent_level++;
    }
    statement_list
    {
        indent_level--;
    }
    ;

statement_list:
    %empty
    | statement statement_list
    ;

function_call_statement:
    T_ID T_LPAREN T_RPAREN T_SEMICOLON
    {
        print_indent();
        printf("chamar %s()\n", $1);
        free($1);
    }
    ;

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
    | expression T_EQ expression      { asprintf(&$$, "%s == %s", $1, $3); free($1); free($3); }
    | expression T_NEQ expression     { asprintf(&$$, "%s != %s", $1, $3); free($1); free($3); }
    | expression T_LT expression      { asprintf(&$$, "%s < %s", $1, $3); free($1); free($3); }
    | expression T_GT expression      { asprintf(&$$, "%s > %s", $1, $3); free($1); free($3); }
    | expression T_LE expression      { asprintf(&$$, "%s <= %s", $1, $3); free($1); free($3); }
    | expression T_GE expression      { asprintf(&$$, "%s >= %s", $1, $3); free($1); free($3); }
    | expression T_AND expression     { asprintf(&$$, "%s e %s", $1, $3); free($1); free($3); }
    | expression T_OR expression      { asprintf(&$$, "%s ou %s", $1, $3); free($1); free($3); }
    | expression T_BIT_OR expression  { asprintf(&$$, "%s | %s", $1, $3); free($1); free($3); }
    | T_AMPERSAND expression          { asprintf(&$$, "&%s", $2); free($2); }
    | T_NOT expression                { asprintf(&$$, "nao %s", $2); free($2); }
    | T_LPAREN expression T_RPAREN    { asprintf(&$$, "(%s)", $2); free($2); }
    | expression T_DOT T_ID           { asprintf(&$$, "%s.%s", $1, $3); free($1); free($3); }
    | expression T_ARROW T_ID         { asprintf(&$$, "%s->%s", $1, $3); free($1); free($3); }
    | T_ID T_LPAREN T_RPAREN          { asprintf(&$$, "%s()", $1); free($1); }
    | '*' expression                  { asprintf(&$$, "*%s", $2); free($2); } // Dereference operator
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
