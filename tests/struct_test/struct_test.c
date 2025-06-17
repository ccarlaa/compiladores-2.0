#include <stdio.h>

// Declaração de uma struct
struct Ponto {
    int x;
    float y;
};

// Outra struct aninhada
struct Linha {
    struct Ponto inicio;
    struct Ponto fim;
};


int main() {
    // Declaração de variáveis do tipo struct
    struct Ponto p1;
    struct Ponto *p2; // Ponteiro para struct

    // Atribuição de valores aos membros da struct
    p1.x = 10;
    p1.y = 20.5;

    // Acesso e atribuição via ponteiro (apenas para testar a sintaxe)
    // No Portugol Studio, ponteiros são um conceito mais complexo e não direto.
    // Esta linha é para verificar se o compilador reconhece a sintaxe `->`
    p2 = &p1; // O &p1 pode ou não ser interpretado, dependendo da gramática
    p2->x = 30; // Teste de acesso via ponteiro

    printf("Ponto p1: x=%d, y=%.2f\n", p1.x, p1.y);

    // Teste de struct aninhada
    struct Linha l1;
    l1.inicio.x = 1;
    l1.fim.y = 2.5;
    printf("Linha l1: inicio.x=%d, fim.y=%.2f\n", l1.inicio.x, l1.fim.y);


    return 0;
}
