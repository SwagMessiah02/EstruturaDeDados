#ifndef ARVOREBINARIA_H_INCLUDED
#define ARVOREBINARIA_H_INCLUDED

#include "comparadores.h"
#include "printers.h"

#define STRING (int (*)(void **, void **))comp_string
#define INT (int (*)(void **, void **))comp_int
#define CHAR (int (*)(void **, void **))comp_char

#define PRINT_INT (void (*)(void **))print_int
#define PRINT_CHAR (void (*)(void **))print_char
#define PRINT_STRING (void (*)(void **))print_string

typedef struct No {
    void *chave;
    struct No *dir;
    struct No *esq;
    struct No *p;
} No;

typedef struct Arvore {
    No *raiz;
} Arvore;

void inserir(Arvore *arvore, No *no, int (*compare)(void **, void **));

void remover(Arvore *arvore, No *no);

void transplante(Arvore *arvore, No *u, No *v);

void imprimirEmOrdem(No *raiz, void (*print)(void **));

No* criarNo(void *chave);

No* buscar(No *raiz, void *chave, int (*compare)(void **, void **));

No* minimo(No *raiz);

No* maximo(No *raiz);

Arvore* criarArvore();

#endif // ARVOREBINARIA_H_INCLUDED
