#ifndef ARVOREBINARIA_H
#define ARVOREBINARIA_H

#include "comparators.h"
#include "printers.h"

#define STRING comp_string
#define INT comp_int
#define CHAR comp_char

#define PRINT_INT print_int
#define PRINT_CHAR print_char
#define PRINT_STRING print_string

typedef struct No {
    void *chave;
    struct No *esq;
    struct No *dir;
    struct No *p;
} No;

typedef struct Arvore {
    No *raiz;
} Arvore;

void insere(Arvore *r, No *no, const int compare(const void **,const void **));

void imprimir(No *raiz, const void print(const void**));

No* criar_folha(void *valor);

Arvore* criar_arvore();

#endif //ARVOREBINARIA_H
