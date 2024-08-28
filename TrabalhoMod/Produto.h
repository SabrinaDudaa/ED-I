#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 50

typedef struct produto{
  char nome[MAX];
  char desc [MAX];
  int id;
  int quant;
}Produto;

Produto* novoProduto();

Produto* vendProduto();

Produto* editaDesc();
