#include <stdio.h>
#include <stdlib.h>

typedef struct noLista {
  int info;
  struct noLista *prox;
} Nolista;

typedef struct lista {
  Nolista *cab;
  Nolista *cau;
} Lista;

Lista criarVazia() {
  Lista l;
  l.cab = (Nolista *)malloc(sizeof(Nolista));
  l.cau = (Nolista *)malloc(sizeof(Nolista));

  l.cab->prox = l.cau;
  l.cau->prox = NULL;

  return l;
}

int estaVazia(Lista *l) { return (l->cab->prox == l->cau); }

void inserirElementoInicio(Lista *l, int v) {
  Nolista *novo = (Nolista *)malloc(sizeof(Nolista));

  if (novo != NULL) {
    novo->info = v;
    novo->prox = l->cab->prox;
    l->cab->prox = novo;
  }

  else {
    printf("Não foi possível alocar espaço");
  }
}

void imprimeLista(Lista *l) {

  if (!estaVazia(l)) {
    for (Nolista *p = l->cab->prox; p != l->cau; p = p->prox) {
      printf("%d\n", p->info);
    }
  }

  else {
    printf("Esta Vazia");
  }
}

void inserirElementoFim(Lista *l, int v) {
  Nolista *ult = l->cab;
  Nolista *novo = (Nolista *)malloc(sizeof(Nolista));

  if (novo != NULL) {
    novo->info = v;
    novo->prox = l->cau;
    for (; ult->prox != l->cau; ult = ult->prox) {
    }
    ult->prox = novo;
  }

  else{
    printf("Lista Vazia");
  }
}

void removeElemento(Lista*l, int v){
  Nolista*ant=l->cab;
  Nolista*p;

  for(p = l->cab->prox; p!=l->cau && p->info!=v; p=p->prox){
    ant = p;
  }

  if(p==l->cau){
    printf("Elemento não encontrado");
  }
  else{
    ant->prox=p->prox;
    free(p);
  }
}

Nolista* ultimo(Lista*l){
  Nolista* p;

  if(!estaVazia(l)){
    for(p = l->cab->prox; p->prox != l->cau; p = p->prox);
    return p;
  }
  else{
    printf("Lista vazia");
    return NULL;
  }
}

int maiores(Lista*l, int n){
  Nolista*p; 
  int count = 0;

  if (!estaVazia(l)){
    for (p = l->cab->prox; p!= l->cau; p= p->prox){
      if (p->info > n)
        count++;
    }
  }

  else{
    printf("Esta Vazia!");
    return 0;
  }
  return count;
}

Lista* separa (Lista*l, int n){
  Nolista*p, *ant = NULL;
  Lista* nova = (Lista*) malloc (sizeof(Lista));

    if (!estaVazia(l)){
      for (p = l->cab->prox; p!=l->cau && p->info!=n; p = p->prox){
        ant = p;
      }

      if (p == l->cau){
        return NULL;
      }
       

      else{
        nova->cab = p;
        nova->cau = l->cau;

        ant->prox = l->cau;

        return nova;  
      }
    }

  else
    printf("Lista vaiza");
}

int main(void) {

  Lista lista = criarVazia();

  estaVazia(&lista);

  inserirElementoInicio(&lista, 2);
  inserirElementoInicio(&lista, 4);
  inserirElementoInicio(&lista, 6);

  imprimeLista(&lista);

  inserirElementoFim(&lista, 8);

  printf("\n");

  imprimeLista(&lista);

  Nolista **r = ultimo(&lista);
  //vai imprimir o ultimo ponteiro
  printf("Ponteiros: %d", *r); 

  printf("\n");

  int result = maiores(&lista, 2);
  printf("%d", result);

  return 0;
}