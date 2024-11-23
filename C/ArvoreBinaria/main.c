#include <stdio.h>
#include "arvorebinaria.h"

int main(void) {
    int vetor[5] = {3, 6, 0, 1, 2};

    Arvore *arvore = criarArvore();

    for(int i = 0;i < 5;i++) {
        inserir(arvore, criarNo(&vetor[i]), INT);
    }

    imprimirEmOrdem(arvore->raiz, PRINT_INT);

    int max = *(int*)maximo(arvore->raiz)->chave;
    int min = *(int*)minimo(arvore->raiz)->chave;

    printf("\n");

    printf("%d %d\n", max, min);

    // remover(arvore, minimo(arvore->raiz));
    // remover(arvore, maximo(arvore->raiz));

    remover(arvore, buscar(arvore->raiz, &vetor[2], INT));

    imprimirEmOrdem(arvore->raiz, PRINT_INT);

    return 0;
}
