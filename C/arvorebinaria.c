#include <stdio.h>
#include <stdlib.h>
#include "arvorebinaria.h"

// Função para inserir elementos da árvore
void inserirNo(Arvore *r, No *no, int compare(void**, void**)) {
    No* current = r->raiz;
    No* pai = current;

    while(current != NULL) {
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

// Função para imprimir os elementos da árvore 'em-ordem'
void imprimirEmOrdem(No *raiz) {
    if(raiz != NULL) {
        imprimirEmOrdem(raiz->esq);
        printf("%c ", *(char*)raiz->chave);
        imprimirEmOrdem(raiz->dir);
    }
}

No* criarNo(void *valor) {
    No *no = (No*)malloc(sizeof(No));

    no->chave = valor;
    no->dir = NULL;
    no->esq = NULL;

    return no;
}

// Função para inicializar a estrutura de dados
Arvore* criarArvore() {
    Arvore *arvore = (Arvore*)malloc(sizeof(Arvore));

    arvore->raiz = NULL;

    return arvore;
}
