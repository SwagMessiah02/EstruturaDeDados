#include <stdio.h>
#include <stdlib.h>
#include "arvorebinaria.h"

void insere(Arvore *r, No *no, const int compare(const void **, const void **))
{
    No *current = r->raiz;
    No *pai = current;

    while (current != NULL) {
        pai = current;

        if(compare(no->chave, current->chave) == 1)
            current = current->dir;
        else
            current = current->esq;
    }

    no->p = pai;

    if(pai == NULL)
        r->raiz = no;
    else if(compare(no->chave, pai->chave) == 1)
        pai->dir = no;
    else
        pai->esq = no;
}

void imprimir(No *raiz, const void print(const void **))
{
    if(raiz != NULL) {
        imprimir(raiz->esq, print);
        print(raiz->chave);
        imprimir(raiz->dir, print);
    }
}

No* criar_folha(void *valor)
{
    No *no = (No*)malloc(sizeof(No));

    no->chave = valor;
    no->dir = NULL;
    no->esq = NULL;

    return no;
}

Arvore* criar_arvore()
{
    Arvore *arvore = (Arvore*)malloc(sizeof(Arvore));

    arvore->raiz = NULL;

    return arvore;
}

/*
int comp_string(const char *a, const char *b)
{
    const double v1 = atof(a), v2 = atof(b);

    if(v1 < v2)
        return 1;
    else if(v1 > v2)
        return -1;
    else
        return 0;
}
*/