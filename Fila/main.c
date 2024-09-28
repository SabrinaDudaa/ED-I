#include <stdio.h>
#include <stdlib.h>

typedef struct noLista {
  float info;
  struct noLista *prox;
} Nolista;

typedef struct fila {
  struct noLista *ini;
  struct noLista *fim;
} Fila;

Fila *criarFila() {
  Fila *f = (Fila *)malloc(sizeof(Fila));

  f->ini = NULL;
  f->fim = NULL;

  return f;
}

int estaVazia(Fila *f) {
  return (f->ini == NULL);
  // ou return (f->fim === NULL);
}

void inserir(Fila *f, float v) {
  Nolista *novo = (Nolista *)malloc(sizeof(Nolista));

  if (novo != NULL) {
    novo->info = v;
    novo->prox = NULL;

    if (!estaVazia(f)) {
      f->fim->prox = novo;
      f->fim = novo;
    }

    else {
      f->ini = novo;
      f->fim = novo;
    }
  }

  else {
    printf("Não foi possível alocar espaço");
  }
}

void imprimeFila(Fila *f) {
  Nolista *p;

  if (!estaVazia(f)) {
    for (p = f->ini; p != NULL; p = p->prox) {
      printf("%2f\n", p->info);
    }
  }

  else {
    printf("Lista Vazia!");
  }
}

float remover(Fila *f) {

  if (!estaVazia(f)) {
    Nolista *p = f->ini;
    f->ini = p->prox;
    float v = p->info;
    free(p);
    return v;

    if(f->ini == NULL){
      f->fim = NULL;
    }
  }

  else {
    printf("Lista Vazia");
  }
}

void liberaFila(Fila*f){
  Nolista*p, *aux;

  for (p = f->ini; p!=NULL; p=aux){
    aux=p->prox;
    free(p); 
  }
  
  free(f);
}

float primeiro (Fila*f){
  return (f->ini->info);
}

void furaFila(Fila*f, float v){
  Nolista*p, *ant = NULL;

  if (!estaVazia(f)){
    for (p = f->ini; p!=NULL && p->info != v; p = p->prox){
      ant = p;
    }
      if (p == NULL){
        printf("Elemento não encontrado");
      } 

    else{
      ant->prox = p->prox;
      p->prox = f->ini;
      f->ini = p;
    }
  }

  else{
    printf("Lista vazia");
  }
}

int main(void) {
  Fila *fila = criarFila();

  estaVazia(fila);

  inserir(fila, 1.5);
  inserir(fila, 2.7);
  inserir(fila, 3.2);
  inserir(fila, 4.9);
  inserir(fila, 5.3);

  imprimeFila(fila);

  remover(fila);

  printf("\n");
  imprimeFila(fila);
  printf("\n");

  // liberaFila(fila);

  // printf("\n");
  // imprimeFila(fila);

  // Fila ** fil;
  // float result;
  // result = primeiro(fila);

  // printf("%2f", result);
  // printf("\n");
  
  furaFila(fila, 3.2);
  imprimeFila(fila);
  printf("\n");
  
  
}