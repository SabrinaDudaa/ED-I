#include <stdio.h>
#include <stdlib.h>

typedef struct arvore {
  char info;
  struct arvore *esq; // subarvore a esquerda
  struct arvore *dir; // subarvore a direita
} Arvore;

Arvore *criarArvoreVazia() { return NULL; }

Arvore *criarArvore(char c, Arvore *sae, Arvore *sad) {
  Arvore *a = (Arvore *)malloc(sizeof(Arvore));

  if (a != NULL) {
    a->info = c;
    a->esq = sae;
    a->dir = sad;

    return a;
  } else
    printf("Não foi possivel alocar espaço!");
}

int estaVazia(Arvore *arv) { return (arv == NULL); }

void imprimeArvore(Arvore *arv) {

  if (!estaVazia(arv)) {
    printf("<");
    printf("<%c>", arv->info);
    imprimeArvore(arv->esq);
    imprimeArvore(arv->dir);
    printf(">");
  } else
    printf("<>");
}

Arvore *liberaArvore(Arvore *arv) {

  if (!estaVazia(arv)) {
    liberaArvore(arv->esq);
    liberaArvore(arv->dir);
    free(arv);
  }
  return NULL;
}

int pertenceArv(Arvore *arv, char c) {
  if (!estaVazia(arv)) {
    if (arv->info == c)
      return 1;

    else {
      return (pertenceArv(arv->esq, c) || pertenceArv(arv->dir, c));
    }
  }

  else
    return 0;
}

int contNos(Arvore *a) {
  if (estaVazia(a))
    return 0;

  else {
    return 1 + contNos(a->esq) + contNos(a->dir);
  }
}

int altura(Arvore *a) {

  if (estaVazia(a))
    return -1;

  else if (estaVazia(a->esq) && estaVazia(a->dir))
    return 0;

  else {
    int he = altura(a->esq);
    int hd = altura(a->dir);

    if (he > hd)
      return he + 1;

    else
      return hd + 1;
  }
}

int main(void) {
  int n, r;

  Arvore *d = criarArvore('d', criarArvoreVazia(), criarArvoreVazia());
  Arvore *b = criarArvore('b', criarArvoreVazia(), d);
  Arvore *e = criarArvore('f', criarArvoreVazia(), criarArvoreVazia());
  Arvore *f = criarArvore('e', criarArvoreVazia(), criarArvoreVazia());
  Arvore *c = criarArvore('c', e, f);
  Arvore *a = criarArvore('a', b, c);

  imprimeArvore(a);

  // liberaArvore(a);

  // imprimeArvore(a);
  printf("\n");
  // pertenceArv(a, f);

  n = contNos(a);
  printf("%d", n);

  printf("\n");
  printf("\n");

   printf("Altura da Arvore:\t");
  r = altura(a);
  printf("%d", r);

  return 0;
}