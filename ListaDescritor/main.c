#include <stdio.h>
#include <stdlib.h>

typedef struct nolista{
int info;
struct nolista*prox;
}NoLista;

typedef struct descritor{
//ponteiros para nó lista
  NoLista*prim;
  NoLista*ult;
  int n;
}Descritor;


Descritor criarLista(){
  Descritor l;
  l.prim = l.ult = NULL;
  
  //l. prim = NULL;
  // l.ult = NULL;
  //mesma coisa
  
  l.n = 0;

  return l;
}

int estaVazia (Descritor*l){
  return (l->n==0);
}

void inserirElementoInicio (Descritor*l, int v){
  NoLista*novo=(NoLista*)malloc(sizeof(NoLista));

  if(novo!=NULL){
    novo->info=v;
    novo->prox=l->prim;
    l->prim=novo;

    if(l->n==0){
      l->ult=novo;
    }
      

    l->n++;
  }
}

 void inserirElementoFim(Descritor*l, int v){
   NoLista*novo=(NoLista*)malloc(sizeof(NoLista));

   if(novo!=NULL){   
      novo->info=v;
      novo->prox=NULL;

     if(l->ult!=NULL){
       l->ult->prox=novo;
       l->ult=novo;
     }

     else{
       l->prim=novo;
       l->ult=novo;
     }

     l->n++;
   }

 }

void imprimeLista(Descritor*l){
  if (!estaVazia(l)){
    for(NoLista *p = l->prim; p!=NULL; p=p->prox){
      printf("%d\n", p->info);
    }
  }

  else {
    printf("Esta Vazia");
  }
}

void removeElemento(Descritor*l, int v){
  NoLista*p,*ant=NULL;

  if(!estaVazia(l)){
    for (p = l->prim; p!=NULL && p->info!=v; p=p->prox){
      ant = p;
    }

    if (p==NULL)
      printf("Elemento não encontrado");
    

    else{
      if(ant==NULL){
        l->prim=p->prox;

      if (l->prim==NULL)
        l->ult=NULL;
      
        }
      
      else{
        ant->prox=p->prox;
        
          if(ant->prox==NULL)
            l->ult=ant;
      }
      
    }

    l->n--;
    free(p);
  }
}

int maiores (Descritor*l, int n){
  NoLista*p;
  int count = 0;

  if (!estaVazia(l)){
    for( p = l->prim; p!=NULL; p = p->prox){
      if(p->info > n)
        count++;
    }
  }

  else{
    printf("vazia");
    return 0;
  }

  return count;
}

// NoLista* ultimo(Descritor* l) {
//   if (!estaVazia(l)) {
//     return l->ult; // Retorna diretamente o último nó
//   } else {
//     printf("Lista vazia\n");
//     return NULL;
//   }
// }

int compara (Descritor *l1, Descritor*l2){
  NoLista* p1, *p2;

  if (l1->n != l2->n) { // se os N é diferente, logo sabemos que não são iguais
      return 0;
  }

  else{
    for (p1 = l1->prim, p2 = l2->prim; p1 != NULL && p2!=NULL; p1 = p1->prox, p2=p2->prox){
      if (p1->info != p2->info)
        return 0;
    }
  }

  return 1;
}

int main(void) {
  Descritor lista = criarLista();

  estaVazia(&lista);

  inserirElementoInicio(&lista, 2);
  inserirElementoInicio(&lista, 4);
  inserirElementoInicio(&lista, 8);
  inserirElementoInicio(&lista, 10);
  inserirElementoInicio(&lista, 12);
  inserirElementoInicio(&lista, 14);

  imprimeLista(&lista);

  inserirElementoFim(&lista,6);

  printf("\n");
  
  imprimeLista(&lista);

  removeElemento(&lista, 4);

  printf("\n");

  imprimeLista(&lista);

   printf("\n");

  //  NoLista * r = ultimo(&lista);
  
  // printf("Ponteiros: %d", r); 

  int result = maiores(&lista, 2);

  printf("%d", result);
  
  return 0;
}