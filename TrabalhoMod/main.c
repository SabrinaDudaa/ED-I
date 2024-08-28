#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ListaEncadeada.h"
#include "ListaCabECauda.h"

#define MAX 50

int main(void) {
  Cliente *cliente = (Cliente *)malloc(sizeof(Cliente));
  Produto* produto = (Produto*)malloc(sizeof(Produto));
  int idMain = 1, idProd = 1, cont;



  Nolista *lista;
  criarVazia(&lista);

  Lista list = criaVazia();

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

