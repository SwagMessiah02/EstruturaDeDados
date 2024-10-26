#include <stdio.h>
#include <stdlib.h>
#include "arvorebinaria.h"

// Compara dois inteiros
int compareint(int *a, int *b) {
    if(*a > *b)
        return 1;
    else if(*a < *b)
        return -1;
    else
        return 0;
}

// Compara dois caracteres
int comparechar(char *a, char *b) {
    int v1 = (int)*a;
    int v2 = (int)*b;

    if(v1 < v2)
        return -1;
    else if (v1 > v2)
        return 1;
    else 
        return 0;
}

int main(void) {
    // Arrays para teste
    int vetor1[5] = {1, 5, 3, 0, 2};
    char vetor2[5] = {'b', 'f', 'c', 'd', 'i'};

    // Ponteiros para as respectivas funções de comparação
    int (*ptr)(int *a, int *b) = &compareint;
    int (*ptr2)(char *a, char *b) = &comparechar;

    // Inicializa a estrutura de dados
    Arvore *arvore = criarArvore();

    for(int i = 0;i < 5;i++) {
        inserirNo(arvore, criarNo(&vetor2[i]), (int (*)(void**,void**))ptr2); // Insere os valores do vetor v2 na árvore
    }

    // Imprime os elementos da árvore 'em-ordem'
    imprimirEmOrdem(arvore->raiz);

    return 0;
}
