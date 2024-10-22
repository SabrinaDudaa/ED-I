#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main(void) {
  NoLista *lista;
  NoLista* lista2;
  NoLista* conca;

  criarLista(&lista);

  insereOrdenado(&lista, 4);
  insereOrdenado(&lista, 2);
  insereOrdenado(&lista, 3);

  imprimeElementos(&lista);

  buscaElemento(&lista, 2);

  removeElemento(&lista, 1);

  printf("\n");

  imprimeElementos(&lista);

  liberaLista(&lista);

  printf("\n");

  imprimeElementos(&lista);

  printf("\n");

  insereOrdenado(&lista, 2);
  insereOrdenado(&lista, 4);
  insereOrdenado(&lista, 1);
  insereOrdenado(&lista, 6);
  insereOrdenado(&lista, 8);
  insereOrdenado(&lista, 10);

  imprimeElementos(&lista);

  printf("\n");

  int result = contaElementos(&lista);
  printf("Numero de elementos: %d", result);

  printf("\n");

  NoLista **r = ultimo(&lista);
  //vai imprimir o ultimo ponteiro
  printf("Ponteiros: %d", *r); 
   printf("\n");
  
  int maior = Maiores(&lista, 1);
  printf("Numero de elementos: %d", maior);

  
  
  return 0;
}