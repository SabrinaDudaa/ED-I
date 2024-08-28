
#include <stdio.h>
#include <stdlib.h>

typedef struct noLista{
    int info;
    struct noLista* ant, *prox;
}NoLista;

void criarListaVazia(NoLista** l){
    *l = NULL;
}

int estaVazia(NoLista** l){
    return(*l == NULL);
}

void insereElemento(NoLista** l, int v){
    NoLista* novo = (NoLista*)malloc(sizeof(NoLista));
    if(novo != NULL){
        novo->info = v;
        novo->prox = *l;
        novo->ant = NULL;
        if (*l != NULL) {
            (*l)->ant = novo;
        }
        *l = novo;
    } else {
        printf("Não foi possível alocar memória!\n");
    }
}



NoLista* ultimoLista(NoLista** l){
    NoLista* ultimo;
    if(!estaVazia(l)){
    for(NoLista* p = *l; p!=NULL; p = p->prox){
        ultimo = p;
    }
    return ultimo;
    }else{
        printf("Lista Vazia\n");
        return NULL;
    }
}

void imprimeListaOrdemInversa(NoLista** l){
    if(!estaVazia(l)){
        NoLista* ult = ultimoLista(l);
        for(NoLista* p = ult; p !=NULL; p = p->ant){
            printf("%d\n", p->info);
        }
    }else{
        printf("Lista Vazia");
    }
}

void removerElemento(NoLista** l, int v){
    NoLista* p;
    if(!estaVazia(l)){
        // Procura o elemento
        for (p = *l; p != NULL && p->info != v; p = p->prox);

        if (p == NULL){
            printf("Elemento não encontrado\n");
        } else {
            if (p->ant != NULL) {
                p->ant->prox = p->prox;
            } else {
                // Remover o primeiro elemento
                *l = p->prox;
            }
            if (p->prox != NULL) {
                p->prox->ant = p->ant;
            }
            free(p);
        }
    } else {
        printf("Lista vazia\n");
    }
}

int soma(NoLista**l){
  NoLista*p;
  int soma;

  if(!estaVazia(l)){
    for (p = *l; p!=NULL; p = p->prox){
      if (p->ant == NULL)
        soma = p->info;

      else
        soma += p->info;
    }
    return soma;
  }

  else
    printf("Lista vazia!");
  
}

int main() {
    NoLista* lista;
    int result;
    criarListaVazia(&lista);
    insereElemento(&lista, 2);
    insereElemento(&lista, 3);
    insereElemento(&lista, 4);
    imprimeListaOrdemInversa(&lista);
  printf("\n");
  result = soma(&lista);
  printf("%d", result);
  //   removerElemento(&lista, 2);
  // printf("\n");
  //   imprimeListaOrdemInversa(&lista);
  // printf("\n");
    return 0;
}
