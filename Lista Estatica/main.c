#include "lista.h"
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  Lista *lista = criarLista();
  estaVazia(lista);
  estaCheia(lista);

  inserirElemento(lista, 2);
  inserirElemento(lista, 3);
  inserirElemento(lista, 4);
  inserirElemento(lista, 5);

  imprimeLista(lista);
  printf("\n");
  removeElemento(lista, 1);
  printf("\n");
  imprimeLista(lista);

  return 0;
}
