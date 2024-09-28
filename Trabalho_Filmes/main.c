#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct filme {
  int id;
  int ano;
  char nome[50];
  struct noseq *seq;
} Filme;

typedef struct noseq {
  struct noseq *ant, *prox;
  struct filme info;
} noseq;

typedef struct nosip {
  struct filme info;
  struct nosip *prox;
} nosip;

typedef struct desc {
  struct nosip *prim, *ult;
  int n;
} desc;

Filme* leFilme() {
  Filme* f = (Filme*) malloc(sizeof(Filme));

  printf("Nome do filme que deseja adicionar:\n");
  scanf("%s", f->nome);

  printf("Ano do filme que deseja adicionar:\n");
  scanf("%d", &(f->ano));

  // Sequência começa vazia.
  f->seq = NULL;

  return f;
}

void alterarNome(Filme *f) {
  char aux[50];
  printf("Digite o novo nome: ");
  scanf("%[^\n]", aux);
  strcpy(f->nome, aux);
}

void alterarAno(Filme *f) {
  int auxano;
  printf("Digite o novo ano: ");
  scanf("%d", &auxano);
  f->ano = auxano;
}
int retornaAno(Filme *f) {
  int rano;
  rano = f->ano;
  return rano;
}

// Função que cria a lista
nosip *crialista() {
  nosip *l;
  l = NULL;
  return l;
}
// Função que verifica se a lista está vazia
int estaVazia(nosip **l) { return (*l == NULL); }

// Função que insere o filme na lista
void inserirFilmeOrdenado(nosip** l, Filme* f, int id) {
  nosip* novo = (nosip*) malloc(sizeof(nosip));
  nosip* p, * ant = NULL;

  for (p = *l; p != NULL && p->info.id < id; p = p->prox) {
    ant = p;
  }

  novo->info.id = f->id;
  novo->info.ano = f->ano;
  strcpy(novo->info.nome, f->nome);
  novo->info.seq = f->seq;

  if (novo != NULL) {
    if (ant == NULL) {
      novo->prox = *l;
      *l = novo;
    } else {
      novo->prox = p;
      ant->prox = novo;
    }
  } else {
    printf("Não foi possível alocar espaço!");
    exit(1);
  }
}

// Função para realiazar alteração de dados de um filme
void alterarFilme(nosip *l, int id) {
  nosip *p;
  for (p = l; p != NULL; p = p->prox) {
    if (id == p->info.id) {
      alterarAno(&p->info);
      alterarNome(&p->info);
      break;  // Adiciona o break para interromper o loop após alterar o filme
    }
  }
}

// Função que remove um filme da lista
void removerFilme(nosip **l, int id) {
  nosip *p, *ant = NULL;

  if (!estaVazia(l)) {
    for (p = *l; p != NULL && p->info.id != id; p = p->prox) {
      ant = p;
    }

    if (p == NULL) {
      printf("Filme não encontrado!!");
    } else {
      if (ant == NULL) {
        *l = p->prox;
      } else {
        ant->prox = p->prox;
        free(p);
      }
    }
  } else {
    printf("Lista vazia!\n");
  }
}

// Função que imprime um filme
void imprimirFilmes(nosip **l) {
  if (!estaVazia(l)) {
    nosip *p;
    for (p = *l; p != NULL; p = p->prox) {
      Filme f = p->info;
      printf("\n ID %d \tnome: %s ano: %d -", f.id, f.nome, f.ano);
    }
  } else {
    printf("Lista vazia!\n");
  }
}


//Parte das sequências:

void insereFilmeSequencia(nosip* l, desc* lista, int id, int *id2) {
    // encontrar o filme que inicia a sequência
    nosip* novof = NULL;
    for (nosip* p = l; p != NULL; p = p->prox) {
        if (p->info.id == id) {
            novof = p;
            break;
        }
    }

    if (novof == NULL) {
        printf("Filme de sequência não encontrado.\n");
        return;
    }

    // solicita os dados do novo filme
    
    Filme* novo_filme = leFilme();
    novo_filme->id = *id2;
    (*id2)++;

    // cria um nó para o novo filme
    noseq* novo_no = (noseq*)malloc(sizeof(noseq));
    novo_no->info = *novo_filme;
    novo_no->ant = NULL;
    novo_no->prox = NULL;

    //insere novo filme
    
    if (novof->info.seq == NULL) {
        novof->info.seq = novo_no;
    } else {
        noseq* ultimo = novof->info.seq;
        while (ultimo->prox != NULL) {
            ultimo = ultimo->prox;
        }
        ultimo->prox = novo_no;
        novo_no->ant = ultimo;
    }
   
    // atualiza a quantidade
    lista->n++;
}


Filme* bucarId(nosip* l, int id) {
    nosip* p;
    for (p = l; p != NULL; p = p->prox) {
        if (p->info.id == id) {
            return &(p->info);
        }
    }
    return NULL;  // se o filme não for encontrado
}

void imprimirSequenciaFilmes(nosip* l, int id) {
  nosip* primeiro = NULL;

  // filme que inicia a sequência
  for (nosip* p = l; p != NULL; p = p->prox) {
    if (p->info.id == id) {
      primeiro = p;
      break;
    }
  }

  if (primeiro == NULL) {
    printf("Filme de sequência não encontrado.\n");
    return;
  }


  // impressão
 printf("Sequência de filmes:\n");
  noseq* p = primeiro->info.seq;
  Filme f2 = primeiro->info;
  printf("ID: %d\tNome: %s\tAno: %d\n", f2.id, f2.nome, f2.ano);
  while (p!=NULL) {
    Filme f = p->info;
    printf("ID: %d\tNome: %s\tAno: %d\n", f.id, f.nome, f.ano);
    p = p->prox;
  }
}

void removerFilmeSequencia(nosip* l, int id) {
  nosip* primeiro = NULL;

  // Encontra o filme que inicia a sequência
  for (nosip* p = l; p != NULL; p = p->prox) {
    if (p->info.id == id) {
      primeiro = p;
      break;
    }
  }

  if (primeiro == NULL) {
    printf("Filme de sequência não encontrado.\n");
    return;
  }

  // Imprime a sequência de filmes
  printf("Sequência de filmes:\n");
  noseq* p = primeiro->info.seq;
  while (p != NULL) {
    Filme f = p->info;
    printf("ID: %d\tNome: %s\tAno: %d\n", f.id, f.nome, f.ano);
    p = p->prox;
  }

  // pedindo o id
  int id_rem;
  printf("Digite o ID do filme que deseja remover: ");
  scanf("%d", &id_rem);

  // procurando
  noseq* rem = NULL;
  for (noseq* p = primeiro->info.seq; p != NULL; p = p->prox) {
    if (p->info.id == id_rem) {
      rem = p;
      break;
    }
  }

  if (rem == NULL) {
    printf("Filme não encontrado na sequência.\n");
    return;
  }

  // removendo
  if (rem->ant == NULL) {
    // é o primeiro da sequência
    primeiro->info.seq = rem->prox;
    if (rem->prox != NULL) {
      rem->prox->ant = NULL;
    }
  } else {
    // não é o primeiro da sequência
    rem->ant->prox = rem->prox;
    if (rem->prox != NULL) {
      rem->prox->ant = rem->ant;
    }
  }
  
  free(rem); // liberação
  printf("Filme removido da sequência.\n");

}


void Imp_Ant(nosip* l, int id) {
  nosip* anterior = NULL;
  noseq* p2;
  // procura o "fe" na sequencia
  for (nosip* p = l; p != NULL; p = p->prox) {
    if (p->info.id == id) {
     printf("Nao tem antecessor");
      return;
     } // if

    noseq* prim_seq = p->info.seq;
    if (prim_seq->info.id == id)
    {
      printf("Filme anterior:\n");
      printf("ID: %d\tNome: %s\tAno: %d\n", p->info.id, p->info.nome, p->info.ano);
      return;
    }
    for (p2 = p->info.seq; p2 != NULL; p2 = p2->prox){
      
      if(p2->info.id == id)
        {
        printf("Filme anterior:\n");
         printf("ID: %d\tNome: %s\tAno: %d\n", p2->ant->info.id,p2->ant->info.nome,p2->ant->info.ano);
          return;
       } // if2

    }  // for noseq

  } //for nosip

  if (p2 == NULL) {
    printf("Filme não encontrado.\n");
    return;
  }

}

  
void Imp_Suc (nosip* l, int id) {
  nosip* suc = NULL; //sucessor
  noseq* p2;
  // Encontra o filme atual na sequência
  for (nosip* p = l; p != NULL; p = p->prox) {
    
    if (p->info.id == id) {
      
     noseq* prim_seq = p->info.seq;
      

      printf("Filme sucessor:\n");
      printf("ID: %d\tNome: %s\tAno: %d\n", prim_seq->info.id,prim_seq->info.nome,prim_seq->info.ano);
      return;
     } // if

    for (p2 = p->info.seq; p2 != NULL; p2 = p2->prox){
     
      if(p2->info.id == id)
        {
            if(p2->prox != NULL)
              {
                printf("Filme sucessor:\n");
                printf("ID: %d\tNome: %s\tAno: %d\n", p2->prox->info.id,p2->prox->info.nome,p2->prox->info.ano);
                return;
              }
                else{
                    printf ("Filme sem sucessor");
                    return;
                    }
          
       } // if2
    }
  }
  
  if (p2 == NULL) {
    printf("Filme não encontrado.\n");
    return;
  }

}

int main(int argc, char *argv[]) {
  int v, auxid;
    int id=0;
  
    Filme *film;
  
      nosip *list=crialista(); //simplesmente encadeada
  
    Filme* filme = (Filme*) malloc(sizeof(Filme));
  
    Filme**fl;

    desc lista; //case 5
    lista.prim=NULL;
    lista.ult=NULL;
   
  do{
   printf ("\nEscolha a opção desejada:\n");
    printf("1 - Inserir um novo filme\n");
     printf("2 - Alterar os dados de um filme\n");
     printf("3 - Remover um filme\n");
     printf("4 - Imprimir a lista de filmes\n");
     printf("5 – Inserir sequencia de um filme\n");
     printf("6 – Imprimir sequencia de um filme\n");
     printf("7 – Remover sequencia de um filme\n");
     printf("8 – Imprimir filme que antecede um outro\n");
     printf("9 – Imprimir filme que sucede um outro\n");
     printf("10 – Sair\n");
    printf ("\n");
    scanf("%d", &v);
   switch ( v )
  { 
    case 1:
    filme = leFilme();
    filme->id = id;
    id++;
    inserirFilmeOrdenado(&list, filme, filme->id);
    break;
    
    case 2:

      printf("Informe o ID do filme:\n");
      scanf("%d", &auxid);
      
      alterarFilme(list, auxid);

      break;

    case 3:
      printf("Informe o ID do filme:\n");
      scanf("%d", &auxid);
      
      removerFilme(&list, auxid);
      

      break;

    case 4:
      imprimirFilmes(&list);

      break;
    
   
    case 5:
    printf("ID do filme que inicia a sequencia: ");
    scanf("%d", &auxid);
      
    insereFilmeSequencia(list, &lista, auxid, &id);
      
    break;

    case 6:
     
  //pedindo o id
  printf("Digite o ID do primeiro filme da sequência: ");
  scanf("%d", &auxid);
  
  imprimirSequenciaFilmes(list,auxid);
  break;
    
    case 7:
  printf("Digite o ID do primeiro filme da sequência: ");
  scanf("%d", &auxid);
  
  removerFilmeSequencia(list,auxid);

    break;
    
    case 8:
  printf("Digite o ID do filme: ");
  scanf("%d", &auxid);
      
 Imp_Ant(list, auxid);

  break;
    
    case 9:
    
  printf("Digite o ID do filme: ");
  scanf("%d", &auxid);
      
  Imp_Suc(list, auxid);

    break;
    
    case 10 :
    printf ("Programa encerrado\n");
    break;
    
    default:
      printf ("Nao existe essa opcao\n");
      
      break;
    printf ("Valor invalido!\n");
  }
    
  }while(v!=10);
  
    return 0;
}