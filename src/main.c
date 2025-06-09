// main.c
#include <stdio.h>

extern FILE *yyin;
extern int yylex();
extern void iniciar_conversao(FILE *saida);
extern void finalizar_conversao();

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Uso: %s arquivo.c\n", argv[0]);
        return 1;
    }

    FILE *input = fopen(argv[1], "r");
    if (!input) {
        perror("Erro ao abrir o arquivo de entrada");
        return 1;
    }

    yyin = input;

    FILE *saida = fopen("saida.portugol", "w");
    if (!saida) {
        perror("Erro ao abrir o arquivo de saída");
        return 1;
    }

    iniciar_conversao(saida);

    while (yylex() != 0);

    finalizar_conversao();

    fclose(input);
    fclose(saida);

    printf("Conversão concluída! Veja o arquivo 'saida.portugol'.\n");

    return 0;
}
