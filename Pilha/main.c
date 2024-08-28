#include <stdio.h>
#include <stdlib.h>

typedef struct noLista{
float info;
struct noLista *prox;
}NoLista;

typedef struct pilha{
struct noLista*prim;
}Pilha;

Pilha* criarPilha(){
  Pilha*p = (Pilha*) malloc (sizeof(Pilha));

  p->prim = NULL;

  return p;
}

int estaVazia(Pilha*p){
  return (p->prim == NULL);
}

void push (Pilha*p, float v){
  NoLista*novo=(NoLista*)malloc(sizeof(NoLista));

  if (novo!=NULL){
    novo->info = v;
    novo->prox = p->prim;
    p->prim = novo;
  }

  else
    printf("espaço não alocado");
}

void imprimePilha(Pilha*p){
  NoLista * q;

  if(!estaVazia(p)){
    for (q = p->prim; q != NULL; q = q->prox)
      printf("%2f\n", q->info);
  }

  else
    printf("Lista vazia");
}


float pop (Pilha*p){
  if(!estaVazia(p)){
    NoLista* q = p->prim;
    p->prim = q->prox;
    float v = q ->info;
    free(q);
    return v; //retornar o elemento retirado
  }

  else
    printf("Pilha vazia");
}

void liberaPilha(Pilha*p){
  NoLista*t, *aux;
    for (t = p->prim; t != NULL; t = aux){
      aux = t->prox;
      free(t);
    }
  free(p);
}

float verTopo (Pilha*p){
  if (!estaVazia(p)){
    return p->prim->info;
  }

  else
    printf("Lista Vazia");
}

int main(void) {
  Pilha * pilha = criarPilha();

  push (pilha, 3.5);
  push (pilha, 4.6);
  push (pilha, 5.7);

  imprimePilha(pilha);

  liberaPilha(pilha); 

  imprimePilha(pilha);
  
  return 0;
}