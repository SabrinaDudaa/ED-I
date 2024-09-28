#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Produto.h"

#define MAX 50


typedef struct molista{
  struct produto info;  
  struct molista *prox;
}Molista;

typedef struct lista{
  Molista *cab;
  Molista *cau;
}Lista;

Lista criaVazia();

int estarVazia(Lista* l);

void insereOrdenadoProd(Lista*l, Produto* v);

void imprimeProduto(Lista*l);

void removerProduto(Lista*l);

void editaDescProduto(Lista*l,Produto*v);

void vendaProduto(Lista*l, Produto*v);