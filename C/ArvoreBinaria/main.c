#include <stdio.h>
#include "arvorebinaria.h"

#define LENGTH(v) sizeof(v)/sizeof(v[0])

const int vetor_1[5] = {1,0,5,3,2};
const char vetor_2[5] = {'d','b','e','f','a'};
const char* vetor_3[4] = {"Okarun", "Momo", "JiJi", "Vovó Turbo"};
const int length = LENGTH(vetor_1);

int main(void)
{
   Arvore *arvore = criar_arvore();

   for (int i = 0; i < length; i++) {
      insere(arvore, criar_folha(&vetor_1[i]), INT);
   }

   imprimir(arvore->raiz, PRINT_INT);

   return 0;
}
