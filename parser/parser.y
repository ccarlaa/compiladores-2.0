%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern int yylineno;

int yylex(YYSTYPE *yylval);
void yyerror(const char *s);

%}

%define api.pure full
%define api.prefix {parser}
%define parse.error verbose

%union {
    char *str;
}

%token <str> ID NUM
%token INT PRINTF
%type <str> expr comando comandos

%left '+'
%nonassoc '='

%start programa

%%

programa:
    INT ID '(' ')' '{' comandos PRINTF '(' ID ')' ';' '}' {
        printf("inicio\n%s    escreva(%s)\nfim\n", $6, $9);
    }
;

comandos:
    comando {
        $$ = strdup($1);
    }
    | comandos comando {
        $$ = malloc(strlen($1) + strlen($2) + 1);
        strcpy($$, $1);
        strcat($$, $2);
    }
;

comando:
    ID '=' expr ';' {
        char *linha = malloc(strlen($1) + strlen($3) + 20);
        sprintf(linha, "    %s <- %s\n", $1, $3);
        $$ = linha;
    }
    | NUM {
        $$ = strdup($1);
    }
    | expr '+' expr {
%type <str> expr comando comandos

%start programa

%%

programa:
    INT ID '(' ')' '{' comandos PRINTF '(' ID ')' ';' '}' {
        printf("inicio\n%s    escreva(%s)\nfim\n", $6, $9);
    }
;

comandos:
    comando {
        $$ = strdup($1);
    }
    | comandos comando {
        $$ = malloc(strlen($1) + strlen($2) + 1);
        strcpy($$, $1);
        strcat($$, $2);
    }
;

comando:
    ID '=' expr ';' {
        char *linha = malloc(strlen($1) + strlen($3) + 20);
        sprintf(linha, "    %s <- %s\n", $1, $3);
        $$ = linha;
    }
    | INT ID '=' NUM ';' {
        char *linha = malloc(strlen($2) + strlen($4) + 30);
        sprintf(linha, "    inteiro %s <- %s\n", $2, $4);
        $$ = linha;
    }
;

expr:
    ID { $$ = strdup($1); }
    | NUM { $$ = strdup($1); }
    | expr '+' expr {
        char *resultado = malloc(strlen($1) + strlen($3) + 20);
        sprintf(resultado, "(%s + %s)", $1, $3);
        $$ = resultado;
    }
;

%%

void yyerror(const char *s) {
    fprintf(stderr, "Erro de sintaxe (linha %d): %s\n", yylineno, s);
}

int main(void) {
    return yyparse();
}
