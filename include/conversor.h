#ifndef CONVERSOR_H
#define CONVERSOR_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura para um nó da tabela de símbolos
typedef struct Symbol {
    char *c_name;       // Nome do símbolo em C
    char *portugol_name; // Nome do símbolo em Portugol
    char *type;         // Tipo do símbolo (ex: "int", "float", "char", "void")
    int scope;          // Escopo do símbolo (ex: 0 para global, 1 para função, etc.)
    struct Symbol *next; // Próximo símbolo na lista
} Symbol;

extern Symbol *symbol_table;
extern int current_scope;

void init_symbol_table();
Symbol* insert_symbol(const char *c_name, const char *type, int scope);
Symbol* lookup_symbol(const char *c_name);
void print_symbol_table();
void free_symbol_table();
void enter_scope(); 
void exit_scope();
Symbol* lookup_symbol_in_current_scope(const char *c_name);

#endif
