#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 50

//struct e nó do cliente
typedef struct cliente {
  char nome[MAX];
  int id;
} Cliente;

Cliente *criarCliente() {
  Cliente *c = (Cliente *)malloc(sizeof(Cliente));
  getchar();

  printf("Digite seu nome:\t");
  scanf("%49[^\n]", c->nome);

  return c;
}

Cliente* removeCliente(){
  Cliente *c = (Cliente*)malloc (sizeof(Cliente));
  printf("Digite o nome a ser removido: ");
  getchar();
  scanf("%49[^\n]", c->nome);

  return c;
}

Cliente *criararq(int id, char nome[MAX]) {
  Cliente *c = (Cliente *)malloc(sizeof(Cliente));
  c->id=id;
  strcpy(c->nome,nome);
  return c;
}