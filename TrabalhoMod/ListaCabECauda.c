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

typedef struct molista{
  struct produto info;  
  struct molista *prox;
}Molista;

typedef struct lista{
  Molista *cab;
  Molista *cau;
}Lista;


Lista criaVazia(){

Lista l;
l.cab = (Molista *)malloc(sizeof(Molista));
l.cau = (Molista *)malloc(sizeof(Molista));

l.cab->prox = l.cau;
l.cau->prox = NULL;

return l;
}

int estarVazia(Lista* l){
  return (l->cab->prox == l->cau);
}

void insereOrdenadoProd(Lista*l, Produto* v){ //vai receber a função novoProduto
  Molista *ult=l->cab;
  Molista*novo=(Molista*)malloc(sizeof(Molista));


  if(novo!=NULL){
    novo->info = *v;
    novo->prox = l->cau;

    for (; ult->prox != l->cau; ult = ult->prox);
    ult->prox = novo;
  }

  else{
    printf("Nao foi possivel alocar");
  }
}


void imprimeProduto(Lista*l) {
  Molista*p;

  if(!estarVazia(l)){
    for(p=l->cab->prox; p!=l->cau; p=p->prox){
       Produto prod = p->info;
      printf("%d:\t %s\t -- \t%s. qtde:%d\n",prod.id, prod.nome, prod.desc, prod.quant);
    }
  }

  else{
    printf("\nNenhum produto cadastrado");
  }

}

void removerProduto(Lista*l){
  Molista*ant=l->cab;
  Molista*p;
  int x;
  printf("Digite o ID do produto:\t");
  scanf("%d",&x);

  for(p=l->cab->prox;p!=l->cau && p->info.id != x;p=p->prox){
    ant=p;
  }

  if (p==l->cau){
    printf("Produto nao encontrado");
  }
  else{
    ant->prox=p->prox;
    free(p);
  }
}



void editaDescProduto(Lista*l,Produto*v) {
  Molista*p;

  for(p=l->cab->prox;p!=l->cau && p->info.id != v->id;p=p->prox);

  if(p==l->cau){
    printf("Produto nao encontrado.");
  }
  else{
   strcpy(p->info.desc,v->desc);
  }
}


void vendaProduto(Lista*l, Produto*v) {
  Molista*p;
  int sub;


  for(p=l->cab->prox;p!=l->cau && p->info.id != v->id;p=p->prox){}

  if (p==l->cau){
    printf("Produto nao encontrado.");
  }

  else{
     sub = p->info.quant - v->quant ; //sub = quantiadade em estoque - quantidade vendida 

    if(sub < 0){
      printf("Nao ha o suficiente em estoque.");
    }

    else{
      p->info.quant = sub;
    }
  }
}