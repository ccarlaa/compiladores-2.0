#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ast.h"

ASTNode* create_node(NodeType type, const char *value) {
    ASTNode *node = malloc(sizeof(ASTNode));
    node->type = type;
    node->value = value ? strdup(value) : NULL;
    node->children = NULL;
    node->child_count = 0;
    return node;
}

void add_child(ASTNode *parent, ASTNode *child) {
    parent->children = realloc(parent->children, 
                              sizeof(ASTNode*) * (parent->child_count + 1));
    parent->children[parent->child_count] = child;
    parent->child_count++;
}

void free_ast(ASTNode *node) {
    if (!node) return;
    
    for (int i = 0; i < node->child_count; i++) {
        free_ast(node->children[i]);
    }
    free(node->children);
    free(node->value);
    free(node);
}

void print_ast(ASTNode *node, int depth) {
    for (int i = 0; i < depth; i++) printf("  ");
    
    const char *node_names[] = {
        "PROGRAM", "FUNCTION", "TYPE", "PARAM_LIST", "BLOCK", "DECLARATION", 
        "ASSIGNMENT", "IDENTIFIER", "CONST_INT", "CONST_FLOAT", "CONST_STRING", 
        "CONST_CHAR", "BINARY_OP", "UNARY_OP", "IF", "ELSE_IF", "ELSE", 
        "WHILE", "DO_WHILE", "FOR", "PRINTF", "SCANF", "RETURN", "STRUCT", 
        "STRUCT_MEMBER", "STRUCT_MEMBER_LIST", "SWITCH", "CASE", "DEFAULT", 
        "CASE_LIST", "STATEMENT_LIST", "DECLARATION_LIST", "FUNCTION_CALL", 
        "MEMBER_ACCESS", "POINTER_ACCESS", "BREAK", "CONTINUE", "EMPTY"
    };
    
    printf("%s", node_names[node->type]);
    if (node->value) printf(" (%s)", node->value);
    printf("\n");
    
    for (int i = 0; i < node->child_count; i++) {
        print_ast(node->children[i], depth + 1);
    }
}