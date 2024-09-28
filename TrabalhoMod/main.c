#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ListaEncadeada.h"
#include "ListaCabECauda.h"

#define MAX 50



int extraitexto(FILE* f, Nolista** lista) {
    char buffer[MAX];
    int ultid = 0; // Valor inicial para indicar que nenhum ID foi lido

    while (fgets(buffer, sizeof(buffer), f) != NULL) {
        //printf("Lendo linha: %s", buffer); // Depuração

        int id;
        char name[MAX];

        // Usar sscanf para analisar a linha
        if (sscanf(buffer, "%d: %49[^\n]", &id, name) == 2) {
           // printf("Dados lidos - ID: %d, Nome: %s\n", id, name); // Depuração

            Cliente* cliente = criararq(id, name);
            if (cliente != NULL) {
                insereOrdenado(lista, cliente);
                // Se insereOrdenado não faz uma cópia, não deve liberar aqui
                // free(cliente);
            } else {
                fprintf(stderr, "Erro ao criar cliente\n");
            }
            if(id>ultid)
            ultid = id; // Atualizar o último ID lido
        } else {
            fprintf(stderr, "Formato da linha não corresponde ao esperado: %s", buffer);
        }
    }

    return ultid; // Retornar o último ID lido
}
void salvaCli(Nolista* l) {
    FILE *f = fopen("cliente.txt", "w");
  
    Nolista* p = l;
    while (p != NULL) {
        fprintf(f, "%d:\t%s\n", p->inf.id, p->inf.nome);
        p = p->prox;
    }

    fclose(f);
}

int extraitextop(FILE* f, Lista* lista) {
    char buffer[MAX];
    int ultid = 0;  // Para armazenar o último ID lido

    while (fgets(buffer, sizeof(buffer), f) != NULL) {
        // printf("Lendo linha: %s", buffer); // Depuração

        int id;
        char nome[MAX];
        char desc[MAX];
        int quant;

        // Ler a linha no formato esperado: id: nome -- descricao qtde:quantidade
        if (sscanf(buffer, "%d:\t%49[^\t]\t--\t%49[^\t]\tqtde:%d\n", &id, nome, desc, &quant) == 4) {
            // printf("Dados lidos - ID: %d, Nome: %s, Descrição: %s, Quantidade: %d\n", id, nome, desc, quant);
            Produto *produto = leProduto(id, nome, desc, quant);
            insereOrdenadoProd(lista, produto);
            ultid = id;
        } else {
            fprintf(stderr, "Formato da linha não corresponde ao esperado: %s", buffer);
        }
    }

    return ultid;  // Retornar o último ID lido
}

void salvaPro(Lista *l) {
    FILE *f = fopen("produto.txt", "w");

    if (f == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    Molista *q = l->cab->prox;

    while (q != NULL && q != l->cau ) {
        if (q->info.id != 0 && q->info.nome[0] != '\0' && q->info.desc[0] != '\0') {
            fprintf(f, "%d:\t%s\t--\t%s\tqtde:%d\n", q->info.id, q->info.nome, q->info.desc, q->info.quant);
        }
        q = q->prox;
    }

    fclose(f);
}


int main(void) {
  Cliente *cliente = (Cliente *)malloc(sizeof(Cliente));
  Produto* produto = (Produto*)malloc(sizeof(Produto));
  
  FILE* f = fopen("cliente.txt", "r");
  FILE* p = fopen("produto.txt", "r");
  
  Nolista *lista;
  criarVazia(&lista);
  Lista list = criaVazia();
  
  int idMain = extraitexto(f,&lista)+1, cont, idAnterior=0;
  int idProd = extraitextop(p,&list)+1;
  fclose(f);
  fclose(p);

  do {
    printf("\n----------------MENU------------------:\n");
    printf("1 - Cadastrar novo cliente\n");
    printf("2 - Remover Cliente\n");
    printf("3 - Imprimir clientes\n");
    printf("4 - Cadastrar novo produto\n");
    printf("5 - Remover produto\n");
    printf("6 - Imprimir produtos\n");
    printf("7 - Editar descricao de produtos\n");
    printf("8 - Registrar venda de produto\n");
    printf("9 - Sair\n");
    printf("--------------------------------------:\n");
    printf("Escolha uma opcao:\t \n");
    printf("\n");
    scanf("%d", &cont);

    switch (cont) {
    case 1: {
      cliente = criarCliente();
      cliente->id = idMain;
      idMain++;

      insereOrdenado(&lista, cliente);
      break;
    }
    case 2: {
      cliente = removeCliente();
      removerCliente(&lista, cliente);
      break;
    }
    case 3: {
      printf("\nAqui esta a lista de clientes:\n");
      imprimeCliente(&lista);
      break;
    }
    case 4: {
      produto = novoProduto();
      produto->id = idProd;
      idProd++;
      insereOrdenadoProd(&list, produto);
      break;
    }
    case 5: {
       removerProduto(&list);
      break;
    }

    case 6: {
      imprimeProduto(&list);
      break;
    }

    case 7: {
      produto=editaDesc();
      editaDescProduto(&list,produto);
      break;
    }

    case 8: {
      produto = vendProduto();
      vendaProduto(&list, produto);
      break;
    }

    case 9:{
      salvaCli(lista);
      salvaPro(&list);
      break;
    }
    default: {
      printf("\nOpcao invalida!\n");
      break;
    }
    }
  } while (cont != 9);

  return 0;
}

