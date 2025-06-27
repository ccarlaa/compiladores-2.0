// MultipleFiles/conversor.c
#include "conversor.h" // Inclui o cabeçalho atualizado

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Symbol *symbol_table = NULL;
int current_scope = 0; // Escopo global inicial

// Variável para rastrear a pilha de escopos
// Usaremos uma pilha simples de inteiros para representar os níveis de escopo
#define MAX_SCOPE_DEPTH 100
int scope_stack[MAX_SCOPE_DEPTH];
int scope_stack_top = -1;

void init_symbol_table() {
    // Limpa a tabela de símbolos e reinicia o escopo
    free_symbol_table(); // Libera qualquer símbolo existente
    symbol_table = NULL;
    current_scope = 0;
    scope_stack_top = -1;
    // Inicia com o escopo global
    enter_scope();
}

// Entra em um novo escopo
void enter_scope() {
    if (scope_stack_top >= MAX_SCOPE_DEPTH - 1) {
        fprintf(stderr, "Erro: Profundidade máxima de escopo atingida.\n");
        exit(1); // Erro fatal
    }
    current_scope++; // Incrementa o nível do escopo
    scope_stack_top++;
    scope_stack[scope_stack_top] = current_scope; // Adiciona o novo nível à pilha
    printf("DEBUG: Entrou no escopo %d\n", current_scope); // Para depuração
}

// Sai do escopo atual
void exit_scope() {
    if (scope_stack_top < 0) {
        fprintf(stderr, "Erro: Tentativa de sair de um escopo inexistente.\n");
        exit(1); // Erro fatal
    }
    // Remove símbolos do escopo que está sendo fechado
    Symbol *cur = symbol_table;
    Symbol *prev = NULL;
    while (cur) {
        if (cur->scope == scope_stack[scope_stack_top]) {
            // Este símbolo pertence ao escopo que está sendo fechado
            if (prev) {
                prev->next = cur->next;
            } else {
                symbol_table = cur->next;
            }
            free(cur->c_name);
            free(cur->portugol_name);
            free(cur->type);
            Symbol *to_free = cur;
            cur = cur->next;
            free(to_free);
        } else {
            prev = cur;
            cur = cur->next;
        }
    }

    scope_stack_top--; // Remove o escopo da pilha
    if (scope_stack_top >= 0) {
        current_scope = scope_stack[scope_stack_top]; // Volta para o escopo anterior
    } else {
        current_scope = 0; // Voltou para o escopo global (ou nenhum escopo ativo)
    }
     printf("DEBUG: Saiu do escopo. Escopo atual: %d\n", current_scope); // Para depuração
}

// Procura um símbolo APENAS no escopo atual
Symbol* lookup_symbol_in_current_scope(const char *c_name) {
    for (Symbol *cur = symbol_table; cur; cur = cur->next) {
        if (strcmp(cur->c_name, c_name) == 0 && cur->scope == current_scope) {
            return cur;
        }
    }
    return NULL;
}

// Insere um símbolo na tabela. Agora verifica redeclaração no escopo atual.
Symbol* insert_symbol(const char *c_name, const char *type, int scope) {
    // Verifica se o símbolo já existe no escopo atual
    if (lookup_symbol_in_current_scope(c_name) != NULL) {
        fprintf(stderr, "Erro semântico: Variável '%s' já declarada no escopo atual (%d).\n", c_name, current_scope);
        // Você pode optar por não inserir ou retornar NULL para indicar erro
        return NULL;
    }

    Symbol *new_symbol = (Symbol*) malloc(sizeof(Symbol));
    if (!new_symbol) {
        perror("Erro de alocação de memória para símbolo");
        exit(1);
    }
    new_symbol->c_name = strdup(c_name);
    new_symbol->portugol_name = strdup(c_name); // Por enquanto, igual ao C_name
    new_symbol->type = strdup(type);
    new_symbol->scope = current_scope; // Sempre insere no escopo atual
    new_symbol->next = symbol_table;
    symbol_table = new_symbol;

     printf("DEBUG: Inserido '%s' (tipo: %s, escopo: %d)\n", c_name, type, current_scope); // Para depuração
    return new_symbol;
}

// Procura um símbolo em todos os escopos visíveis (do mais interno ao global)
Symbol* lookup_symbol(const char *c_name) {
    // Percorre a tabela de símbolos do mais recente para o mais antigo
    // e verifica se o símbolo está em um escopo visível
    for (Symbol *cur = symbol_table; cur; cur = cur->next) {
        // Verifica se o escopo do símbolo está na pilha de escopos visíveis
        for (int i = scope_stack_top; i >= 0; i--) {
            if (cur->scope == scope_stack[i]) {
                if (strcmp(cur->c_name, c_name) == 0) {
                    return cur;
                }
            }
        }
    }
    return NULL;
}

// Para visualizar a tabela de simbolos (descomente se precisar)
/*
void print_symbol_table() {
    Symbol *cur = symbol_table;
    printf("\n--- Tabela de Símbolos ---\n");
    if (!cur) {
        printf("A tabela de símbolos está vazia.\n");
    }
    while (cur) {
        printf("  Nome C: %s | Portugol: %s | Tipo: %s | Escopo: %d\n",
               cur->c_name, cur->portugol_name, cur->type, cur->scope);
        cur = cur->next;
    }
    printf("--------------------------\n");
}
*/

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
// (Outras funções de conversão iriam aqui)
