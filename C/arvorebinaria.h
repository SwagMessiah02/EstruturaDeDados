#ifndef ARVOREBINARIA_H_INCLUDED
#define ARVOREBINARIA_H_INCLUDED

typedef struct No {
    void *chave;
    struct No *esq;
    struct No *dir;
    struct No *p;
} No;

typedef struct Arvore {
    No* raiz;
} Arvore;

No* criarNo(void *valor);

Arvore* criarArvore();

void inserirNo(Arvore *r, No *no, int compare(void **, void **));

void imprimirEmOrdem(No *raiz);

#endif // ARVOREBINARIA_H_INCLUDED
