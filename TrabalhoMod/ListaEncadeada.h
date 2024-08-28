#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"

#define MAX 50

typedef struct Nolista {
  struct cliente inf;
  struct Nolista *prox;
} Nolista;

void criarVazia(Nolista **l);

int estaVazia(Nolista **l);

void imprimeCliente(Nolista **l);

void insereOrdenado(Nolista** l, Cliente* v);

void removerCliente(Nolista **l, Cliente* v);