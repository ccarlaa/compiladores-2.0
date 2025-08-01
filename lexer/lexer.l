%{
/* * Analisador Léxico (Lexer) para um subconjunto da linguagem C.
 * Este arquivo define as "palavras" ou "tokens" que o parser irá usar.
 */
#include "y.tab.h" // Inclui os tokens definidos pelo Bison
#include <string.h>

// Função para retornar strings, evitando warnings
char* dupstr(const char* s) {
    char* ret = strdup(s);
    if (!ret) {
        perror("strdup");
        exit(1);
    }
    return ret;
}
%}

/* Definições para evitar warnings de 'flex' não utilizado */
%option noyywrap nounput noinput

/* Definições de padrões para facilitar a leitura */
DIGITO              [0-9]
LETRA               [a-zA-Z_]
IDENTIFICADOR       {LETRA}({LETRA}|{DIGITO})*
NUMERO_INTEIRO      {DIGITO}+
NUMERO_REAL         {DIGITO}+\.{DIGITO}+
TEXTO               \"(\\.|[^"\\])*\"
CARACTERE           \'(.|\\.)\'

%%

"//".* ; /* Ignora comentários de uma linha */
"/*"([^*]|"*"+[^*/])*"*"+"/" ; /* Ignora comentários de múltiplas linhas */

^#.*$ ; /* Ignora linhas de pré-processador (ex: #include, #define) */

 /* --- Palavras-chave --- */
"if"                { return T_IF; }
"else"              { return T_ELSE; }
"while"             { return T_WHILE; }
"for"               { return T_FOR; }
"return"            { return T_RETURN; }
"printf"            { return T_PRINTF; }
"scanf"             { return T_SCANF; }

 /* --- NOVAS Palavras-chave --- */
"switch"            { return T_SWITCH; }
"case"              { return T_CASE; }
"default"           { return T_DEFAULT; }
"break"             { return T_BREAK; }
"continue"          { return T_CONTINUE; }
"do"                { return T_DO; }
"struct"            { return T_STRUCT; }
"const"             { return T_CONST; }
"unsigned"          { return T_UNSIGNED; }

 /* --- Tipos de Dados --- */
"int"               { return T_INT; }
"float"             { return T_FLOAT; }
"char"              { return T_CHAR; }
"void"              { return T_VOID; }

 /* --- Identificadores e Literais --- */
{IDENTIFICADOR}     { yylval.sval = dupstr(yytext); return T_ID; }
{NUMERO_INTEIRO}    { yylval.ival = atoi(yytext); return T_NUMBER_INT; }
{NUMERO_REAL}       { yylval.fval = atof(yytext); return T_NUMBER_FLOAT; }
{TEXTO}             { yylval.sval = dupstr(yytext); return T_STRING; }
{CARACTERE}         { yylval.sval = dupstr(yytext); return T_CHAR_LITERAL; }

 /* --- Operadores --- */
"++"                { return T_INC; }
"--"                { return T_DEC; }
"+="                { return T_PLUS_ASSIGN; }
"-="                { return T_MINUS_ASSIGN; }
"->"                { return T_ARROW; }
"+"                 { return T_PLUS; }
"-"                 { return T_MINUS; }
"*"                 { return T_MULT; }
"/"                 { return T_DIV; }
"%"                 { return T_MOD; }
"=="                { return T_EQ; }
"!="                { return T_NEQ; }
"<="                { return T_LE; }
">="                { return T_GE; }
"<"                 { return T_LT; }
">"                 { return T_GT; }
"&&"                { return T_AND; }
"||"                { return T_OR; }
"&"                 { return T_AMPERSAND; }
"|"                 { return T_BIT_OR; }
"!"                 { return T_NOT; }
"="                 { return T_ASSIGN; }


 /* --- Pontuação e Símbolos --- */
"{"                 { return T_LBRACE; }
"}"                 { return T_RBRACE; }
"("                 { return T_LPAREN; }
")"                 { return T_RPAREN; }
";"                 { return T_SEMICOLON; }
","                 { return T_COMMA; }
"."                 { return T_DOT; }
":"                 { return T_COLON; }


 /* Ignora espaços em branco, tabs e novas linhas */
[ \t\n\r]+          ;

 /* Trata qualquer outro caractere como um erro */
.                   { fprintf(stderr, "Erro lexico: Caractere inesperado '%s'\n", yytext); }

%%
