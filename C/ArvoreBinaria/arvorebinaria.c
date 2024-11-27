#include <stdio.h>
#include <stdlib.h>
#include "arvorebinaria.h"

Arvore* criarArvore() {
    Arvore *arvore = (Arvore*)malloc(sizeof(Arvore));

    arvore->raiz = NULL;

    return arvore;
}

No* criarNo(void *chave) {
    No *no = (No*)malloc(sizeof(No));

    no->chave = chave;
    no->dir = NULL;
    no->esq = NULL;
    no->p = NULL;

    return no;
}

No* minimo(No *raiz) {
    while(raiz->esq != NULL) {
        raiz = raiz->esq;
    }

    return raiz;
}

No* maximo(No *raiz) {
    while(raiz->dir != NULL) {
        raiz = raiz->dir;
    }

    return raiz;
}

No* buscar(No *raiz, void *chave, int (*compare)(void **, void **)) {
    if(compare(chave, raiz->chave) == 1) {
        buscar(raiz->dir, chave, compare);
    } else if(compare(chave, raiz->chave) == -1) {
        buscar(raiz->esq, chave, compare);
    } else {
        return raiz;
    }
}

void inserir(Arvore *arvore, No *no, int (*compare)(void **, void **)) {
    No *pai = NULL;
    No *current = arvore->raiz;

    while(current != NULL) {
        pai = current;

        if(compare(no->chave, current->chave) == 1) {
            current = current->dir;
        } else {
            current = current->esq;
        }
    }

    no->p = pai;

    if(pai == NULL) {
        arvore->raiz = no;
    } else if(compare(no->chave, pai->chave) == 1) {
        pai->dir = no;
    } else {
        pai->esq = no;
    }
}

void transplante(Arvore *arvore, No *u, No *v) {
    if(u->p == NULL) {
        arvore->raiz = v;
    } else if(u == u->p->esq) {
        u->p->esq = v;
    } else {
        u->p->dir = v;
        if(v != NULL) {
            v->p = u->p;
        }
    }
}

void remover(Arvore *arvore, No *z) {
    if(z->esq == NULL) {
        transplante(arvore, z, z->dir);
    } else if(z->dir == NULL) {
        transplante(arvore, z, z->esq);
    } else {
        No *y = minimo(z->dir);

        if(y->p != NULL) {
            transplante(arvore, y, y->dir);
            y->dir = z->dir;
            y->dir->p = y;
        }

        transplante(arvore, z, y);
        y->esq = z->esq;
        y->esq->p = y;
    }
}

void imprimirEmOrdem(No *raiz, void (*print)(void **)) {
    if(raiz != NULL) {
        imprimirEmOrdem(raiz->esq, print);
        print(raiz->chave);
        imprimirEmOrdem(raiz->dir, print);
    }
}
