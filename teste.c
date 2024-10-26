#include <stdio.h>
#include <stdlib.h>
#include "arvorebinaria.h"

int compareint(int *a, int *b) {
    if(*a > *b)
        return 1;
    else if(*a < *b)
        return -1;
    else
        return 0;
}

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
    int v1[5] = {1, 5, 3, 0, 2};
    char v2[5] = {'b', 'f', 'c', 'd', 'i'};

    int (*ptr)(int *a, int *b) = &compareint;
    int (*ptr2)(char *a, char *b) = &comparechar;

    Arvore *arvore = criarArvore();

    for(int i = 0;i < 5;i++) {
        inserirNo(arvore, criarNo(&v2[i]), (int (*)(void**,void**))ptr2);
    }

    imprimirEmOrdem(arvore->raiz);

    return 0;
}