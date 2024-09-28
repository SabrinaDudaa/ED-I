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

Produto* novoProduto() {
  Produto* prod = (Produto*)malloc(sizeof(Produto));


  printf("Digite o nome do produto:\t");
  getchar();
  scanf("%49[^\n]",prod->nome);
  printf("Digite a descricao do produto:\t");
  getchar();
  scanf("%49[^\n]",prod->desc);
  printf("Digite a quantidade no estoque:\t");
  scanf("%d",&prod->quant);

  return prod;
}

//Função que vai ser usada no vendaProduto
Produto* vendProduto(){
  Produto* prod = (Produto*)malloc(sizeof(Produto));
  int y;
  
  printf("Digite o ID do Produto:\t");
  scanf("%d",&prod->id);
  printf("Digite a quantidade vendida:\t");
  scanf("%d",&y);

  if(y < 0){
    printf("quantidade invalida.\n");
    free(prod);
    vendProduto();
  }
  else{
    prod->quant = y;
    return prod;
  }
}

Produto* editaDesc(){
  Produto* prod = (Produto*)malloc(sizeof(Produto));

  printf("Digite o ID do Produto:\t");
  scanf("%d",&prod->id);
  getchar();
  printf("Digite a nova descricao do produto:\t");
  scanf("%49[^\n]",prod->desc);

  return prod;
}

Produto* leProduto(int id,char nome[MAX],char desc[MAX],int qtde) {
  Produto* prod = (Produto*)malloc(sizeof(Produto));

  strcpy(prod->nome, nome);
  strcpy(prod->desc, desc);
  prod->quant=qtde;
  prod->id=id;

  return prod;
}