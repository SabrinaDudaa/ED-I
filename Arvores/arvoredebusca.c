#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct arvore {
  int info;
  struct arvore *esq;
  struct arvore *dir;
} Arvore;

Arvore *criarArvoreVazia() { return NULL; }

Arvore *criarArvore(int v, Arvore *sae, Arvore *sad) {
  Arvore *a = (Arvore *)malloc(sizeof(Arvore));

  if (a != NULL) {
    a->info = v;
    a->esq = sae;
    a->dir = sad;

    return a;

  } else {
    printf("Não foi possivel alocar espaço!");
    return NULL;
  }
}

int estaVazia(Arvore *arv) { return (arv == NULL); }

Arvore *busca(Arvore *a, int v) {
  if (estaVazia(a)) {
    return NULL;
  }

  else {
    if (a->info == v) // Se tiver na raiz
      return a;

    else if (v < a->info) // Se for menor que a raiz, está na esquerda
      return (busca(a->esq, v));

    else // Caso contrário, está na direita
      return (busca(a->dir, v));
  }
}

Arvore *insere(Arvore *a, int v) {
  if (estaVazia(a)) {
    a = (Arvore *)malloc(sizeof(Arvore));
    if (a != NULL) { // Criando um nó raiz.
      a->info = v;
      a->esq = NULL;
      a->dir = NULL;
    }

    else
      printf("Não foi possível alocar espaço");
  }

  else {
    if (v < a->info)
      a->esq = insere(a->esq, v);

    else // Se o valor for repetido vai ser no lado direito também.
      a->dir = insere(a->dir, v);
  }

  return a;
}

void imprime (Arvore*arv){

  if (!estaVazia(arv)){
    printf("<");
    printf("<%d>", arv->info);
    imprime(arv->esq);
    imprime(arv->dir);
    printf(">");
  }

  else
    printf("<>");
}

Arvore*remover(Arvore*a, int v){
  if(estaVazia(a))
    return NULL;

  else{
    if (v < a->info)
      a->esq = remover(a->esq, v);

    else if (v > a->info)
      a->dir = remover(a->dir, v);

    else{
      if(a->esq == NULL && a->dir == NULL){
        free(a);
        a = NULL;
      }

      else if (a->esq == NULL){
        Arvore*temp = a->dir;
        free(a);
        a = temp;
      }

      else if (a->dir == NULL){
        Arvore*temp = a->esq;
        free(a);
        a = temp;
      }
        
      else{
        Arvore*temp = a->esq;
        while (temp->dir != NULL){
          temp = temp->dir;
        }

        a->info = temp->info;
        temp->info = v;

        a->esq = remover(a->esq, v);
      }
    }

    return a;
  }
}

int impares (Arvore*a){
  int n = 0;
  if (estaVazia(a))
    return 0;

  else if (a->info%2 != 0)
    n = 1;
  
  return n + (impares(a->esq))+(impares(a->dir));
}

int pares (Arvore*a){
  int n = 0;

  if(estaVazia(a))
    return 0;

  else if (a->info%2 == 0)
    n = 1;

  return n + (pares(a->esq))+(pares(a->dir));
}

int somar (Arvore*a){
  int n = 0;

  if(estaVazia(a))
    return 0;

  else{
    n = a->info;
    return n + (somar(a->esq))+(somar(a->dir));
  }
}

int contNos(Arvore *a) {
  if (estaVazia(a))
    return 0;

  else {
    return 1 + contNos(a->esq) + contNos(a->dir);
  }
}

Arvore* menor (Arvore* a){
  if (estaVazia(a))
    return NULL;

  else if (estaVazia(a->esq))
    return a;

  else
    return menor(a->esq);
}

Arvore* maior (Arvore*a){
  if (estaVazia(a))
    return NULL;

  else if (estaVazia(a->dir))
    return a;

  else
    return maior(a->dir);
}

void Balancear (Arvore*a){
  if (!estaVazia(a)){
    int m = contNos(a->esq);
    int n = contNos(a->dir);
    Arvore* men, *mai;

    if (n >= m+2){
      a->esq = insere(a->esq, a->info);
      men = menor(a->dir);
      a->info = men->info;
      a->dir = remover(a->dir, men->info);
    }

    else if (m >= n+2){
      a->dir = insere(a->dir, a->info);
      mai = maior(a->esq);
      a->info = mai->info;
      a->esq = remover(a->esq, mai->info);
    }
  }
}

int qtdeFolhas(Arvore* a){
  if (estaVazia(a))
    return 0;


    if (estaVazia(a->esq) && estaVazia(a->dir))
      return 1;

        return qtdeFolhas(a->esq) + qtdeFolhas(a->dir);

  
}

int main(void) {

  Arvore *a = criarArvore(9, criarArvoreVazia(), criarArvoreVazia());
  int count, count2, folha, soma, menor;

  a = insere(a, 6);
  a = insere(a, 3);
  a = insere(a, 7);
  a = insere(a, 12);
  a = insere(a, 11);
  a = insere(a, 15);
  a = insere(a, 13);

  imprime(a);

  printf("\n");
  printf("\n");

  // a = remover(a, 9);

  // imprime(a);

  count = impares(a);
  printf("%d", count);

  printf("\n");

  count2 = pares(a);
  printf("%d", count2);

   printf("\n");

  soma = somar(a);
  printf("%d", soma);
  
  printf("\n");

 folha = qtdeFolhas(a);
  printf("%d", folha);

  // m = maior(a);
  // printf("%d", m);

  return 0;
}