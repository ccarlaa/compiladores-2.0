#include <stdio.h>
#include <string.h>
#include "conversor.h"

void processar_inteiro(const char *lexema) {
    printf("inteiro: %s\n", lexema);
}

void processar_texto(const char *lexema) {
    // Remove as aspas da string e imprime
    char texto[256];
    strncpy(texto, lexema + 1, strlen(lexema) - 2);
    texto[strlen(lexema) - 2] = '\0';
    printf("texto: \"%s\"\n", texto);
}
