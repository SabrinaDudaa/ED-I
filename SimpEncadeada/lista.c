#include <stdio.h>
#include <stdlib.h>

typedef struct noLista {
  int info;
  struct noLista *prox; // vai apontar para outro no da lista
} NoLista;

// primeira opção
/*
  NoLista* criarLista(){
    return NULL;
    }


  int main(void) {
    NoLista *lista = criarLista();


    return 0;
  }
  */

// segunda opção (utilizada na matéria)
void criarLista(NoLista **l) {
  *l = NULL;

  // cria uma lista vazia
}

int estaVazia(NoLista **l) {
  if (*l == NULL) {
    return 1;
  }

  else {
    return 0;
  }
}

void insereElemento(NoLista **l, int v) {
  NoLista *novo = (NoLista *)malloc(sizeof(NoLista));
  // vai armazenar espaço suficiente do tipo NoLista

  if (novo != NULL) {
    novo->info = v;
    novo->prox = *l;
    *l = novo;
  }

  else {
    printf("Não foi possível inserir elemento");
    exit(1);
  }
}

void imprimeElementos(NoLista **l) {

  if (!estaVazia(l)) {
    for (NoLista *p = *l; p != NULL; p = p->prox) {
      printf("%d\n", p->info);
    }
  }

  else {
    printf("Esta Vazia");
    // exit(1);
  }
}

int buscaElemento(NoLista **l, int v) {
  if (!estaVazia(l)) {
    for (NoLista *p = *l; p != NULL; p = p->prox) {
      if (p->info == v) {
        return p;
      }
      return NULL;
    }
  }

  else {
    printf("Esta Vazia");
    exit(1);
  }
}

void removeElemento(NoLista **l, int v) {
  NoLista *p, *ant = NULL;

  if (!estaVazia(l)) {
    for (p = *l; p != NULL && p->info != v; p = p->prox) {
      ant = p;
    }

    if (p == NULL) {
      printf("Elemento não encontrado");
    }

    else {
      if (ant != NULL) {
        ant->prox = p->prox;
      }

      else {
        *l = p->prox;
      }
      free(p);
    }
  }

  else {
    printf("Esta vazia");
    exit(1);
  }
}

void liberaLista(NoLista **l) {
  NoLista *p, *temp;

  for (p = *l; p != NULL; p = temp) {
    temp = p->prox;
    free(p);
  }

  *l = NULL;
}

void insereOrdenado(NoLista **l, int v) {
  NoLista *p, *ant = NULL;

  NoLista *novo = (NoLista *)malloc(sizeof(NoLista));
  if (novo != NULL) {

    novo->info = v;

    for (p = *l; p != NULL && p->info < v; p = p->prox)
      ant = p;

    novo->prox = p;

    if (ant == NULL)
      *l = novo;

    else
      ant->prox = novo;
  }

  else
    printf("Não foi possivel");
}

int contaElementos(NoLista **l) {
  NoLista *p;
  int c = 0;

  if (!estaVazia(l)) {
    for (p = *l; p != NULL; p = p->prox) {
      c++;
    }
    return c;
  } else {
    printf("Esta Vazia");
  }
}

int Maiores(NoLista**l, int n){
  NoLista*p;
  int count = 0; 

  if (!estaVazia(l)){
    for (p = *l; p!= NULL; p = p->prox){ 
      if(p->info > n){
        count++;
      }
    }
  }

  else{
     printf("Esta Vazia");
    return 0;
  }
   return count;
}

NoLista* ultimo(NoLista **l) {
  NoLista *p;

  if (!estaVazia(l)) {
    for (p = *l; p->prox != NULL; p = p->prox){}
    return p;
  }

  else {
    printf("Esta Vazia");
    return NULL;
  }
}

NoLista* separa(NoLista**l, int n){
  NoLista*p, *ant=NULL;
  NoLista*novo;
  
      for(p = *l; p != NULL && p->info != n; p=p->prox){
        ant = p;
         }
  
      if(p==NULL){
        printf("Elemento não encontrado");
        return NULL;
      }

      else{
        novo = p->prox;
        p->prox = NULL;

        ant->prox = NULL;

        return novo;
      }
  
}
