#include "conversor.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "conversor.h"

Symbol *symbol_table = NULL;
int current_scope = 0;

void init_symbol_table() {
    symbol_table = NULL;
    current_scope = 0;
}

Symbol* insert_symbol(const char *c_name, const char *type, int scope) {
    Symbol *new_symbol = (Symbol*) malloc(sizeof(Symbol));
    if (!new_symbol) exit(1);
    new_symbol->c_name = strdup(c_name);
    new_symbol->portugol_name = strdup(c_name);
    new_symbol->type = strdup(type);
    new_symbol->scope = scope;
    new_symbol->next = symbol_table;
    symbol_table = new_symbol;

    return new_symbol;
}

Symbol* lookup_symbol(const char *c_name) {
    for (Symbol *cur = symbol_table; cur; cur = cur->next) {
        if (strcmp(cur->c_name, c_name) == 0) {

            return cur;
        }
    }

    return NULL;
}

// Para visualizar a tabela de simbolos

// void print_symbol_table() {
//     Symbol *cur = symbol_table;
//     printf("\n--- Tabela de Símbolos ---\n");
//     if (!cur) {
//         printf("A tabela de símbolos está vazia.\n");
//     }
//     while (cur) {
//         printf("  Nome C: %s | Portugol: %s | Tipo: %s | Escopo: %d\n",
//                cur->c_name, cur->portugol_name, cur->type, cur->scope);
//         cur = cur->next;
//     }
//     printf("--------------------------\n");
// }


void free_symbol_table() {
    Symbol *cur = symbol_table;
    while (cur) {
        Symbol *next = cur->next;
        free(cur->c_name);
        free(cur->portugol_name);
        free(cur->type);
        free(cur);
        cur = next;
    }
    symbol_table = NULL;
}

// Implementação das funções de conversão declaradas em conversor.h