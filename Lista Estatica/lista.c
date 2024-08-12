#include <stdio.h>
#include <stdlib.h>
#define max 10


typedef struct lista {
  int itens[max];
  int n;
} Lista;

Lista *criarLista() {
  /* retorna um ponteiro para uma lista vazia */
  /* precisa iniciar o n como 0 para ser vazia */

  Lista *l = (Lista *)malloc(sizeof(Lista));

  /* sizeof retorna o espaço em bytes que Lista ocupada, espaço suficente para
   * armazenar os itens e n de uma lista */

  /* malloc aloca espaço coloca entre () */

  /* espaço suficiente para uma lista
  alocar espaço para uma nova lista */

  l->n = 0;

  /* colocar 0 em n */
  /* para acessar intens de uma lista, precisa acessar o ponteiro*/

  return l;

  /*retorna o endereço */
}

int estaVazia(Lista *l) {

  if (l->n == 0) {
    return 1;
  } else {
    return 0;
  }

  /* pode também usar return (l->n == 0) */
}

int estaCheia(Lista *l) {
  if (l->n == max) {
    return 1;
  }

  else {
    return 0;
  }
}

void inserirElemento(Lista *l, int v) {
  /* *l por referencia e v por valor */

  /* verificar se a lista não está cheia */
  if (!estaCheia(l)) {
    l->itens[l->n] = v;
    l->n++;
  }

  else {
    printf("Lista cheia");
  }
}

void imprimeLista(Lista *l) {
  if (!estaVazia(l)) {
    for (int i = 0; i < l->n; i++) {
      printf("%d\n", l->itens[i]);
    }
  }

  else {
    printf("Lista Vazia");
  }
}

void removeElemento(Lista *l, int i) {
  if (i < 0 || i > l->n) {
    printf("Posição inválida");
  }

  else if (!estaVazia(l)) {
    for (int j = i; j < l->n; j++) {
      /* i = posição que vai ser removida
      e quando i = n, vai ser removido o último elemento
      então l->itens[i] = l->itens[i+1] pq o i+1 é o próximo elemento
      */
      l->itens[j-1] = l->itens[j];
    }
  }

  l->n--;
  printf("Valor removido");
}
