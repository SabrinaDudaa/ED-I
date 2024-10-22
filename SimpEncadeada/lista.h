#include <stdio.h>
#include <stdlib.h>


typedef struct noLista {
  int info;
  struct noLista *prox; // vai apontar para outro no da lista
} NoLista;

void criarLista(NoLista **l);

int estaVazia(NoLista **l);

void insereElemento(NoLista **l, int v);

void imprimeElementos(NoLista **l);

int buscaElemento(NoLista **l, int v);

void removeElemento(NoLista **l, int v);

void liberaLista(NoLista **l);

void insereOrdenado(NoLista **l, int v);

int contaElementos(NoLista **l);

int retornaPonteiro(NoLista **l);