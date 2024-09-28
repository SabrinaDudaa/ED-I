# Estrutura-de-Dados-2024


# TRABALHO 01:

Você deve implementar um sistema de controle para uma loja. A sua primeira tarefa será
implementar algumas funcionalidades isoladas do programa que permitam cadastrar e manipular os
dados de clientes e produtos.

No seu programa você deve implementar os TAD Cliente e Produto, bem como uma lista simples-
mente encadeada de clientes e uma lista com cabeça e cauda de produtos. Assim, o seu projeto

deve conter pelo menos os seguintes arquivos: Cliente.h, Cliente.c, Produto.h, Produto.c, ListaEnca-
deada.h, ListaEncadeada.c, ListaCabECauda.h, ListaCabECauda.c, main.c e makefile.

Um cliente possui um identificador único (deve ser controlado pelo programa e inserido
automaticamente na estrutura criada) e nome. Um produto possui um identificador único (deve ser

controlado pelo programa e inserido automaticamente na estrutura criada), nome, descrição e quan-
tidade em estoque. Na implementação dos TAD correspondentes, você deve incluir pelo menos as

funções para criação, edição e impressão de um cliente e de um produto.
OBS: Faça os testes com esses TAD antes de continuar...
Ex: protótipo da função criar cliente: Cliente* criarCliente();

O seu programa principal deve manter as listas de clientes e de produtos. O campo info do nó da lis-
ta deve ser uma estrutura do tipo correspondente e as funções devem receber essa estrutura.

Ex: protótipo da função insere na lista encadeada: void insereOrdenado(NoLista** l, Cliente v);
A lista de clientes deve ser mantida ordenada pelo nome do cliente e a lista de produtos deve ser
mantida ordenada pelo seu identificador único.

As alterações das listas estudadas em sala de aula para atender a especificação do trabalho são de
responsabilidade dos alunos.
Implemente sua função principal (main) no arquivo main.c. Ela deve criar a lista de clientes e a lista
de produtos e, em seguida, imprimir na tela um menu com as seguintes opções:

----------------MENU------------------
1 - Cadastrar novo cliente
2 - Remover cliente
3 - Imprimir clientes
4 - Cadastrar novo produto
5 - Remover produto
6 - Imprimir produtos
7 - Editar descrição de produtos
8 - Registrar venda de produto
9 - Sair
Escolha uma opção:
-------------------------------------------
Implemente todas as funcionalidades do menu, levando em conta as seguintes considerações:
 Para cadastrar novo cliente e novo produto, deve-se criar as estruturas correspondentes e inserir
na lista correspondente.
 A busca de um cliente deve ser feita pelo nome (na opção 2).
 A busca de um produto deve ser feita pelo identificador único (tanto na opção 5, quanto nas
opções 7 e 8).
 A impressão dos clientes deve ser feita da seguinte forma: id do cliente: nome do cliente (ou
seja, um cliente por linha).
Ex: 1: Juliana Campos
2: Maria José
 A impressão dos produtos deve ser feita da seguinte forma: id do produto: nome do produto -
Descrição do produto. Qtde em estoque: x (um por linha)
Ex: 1: Agenda 2019 - Agenda da marca BBI um dia/pag. Qtde: 10
2: Caderno 60fl – Caderno brochura 60 fl. Qtde: 200
 Na opção 8, além do identificador do produto, deve-se solicitar o número de unidades vendidas
e atualizar a quantidade do produto em estoque. Ao finalizar, imprimir o produto correspondente
com esse novo valor.




#TRABALHO 02:


Dando continuidade à implementação do Trabalho 1, você deve adicionar funcionalidades para
armazenar e recuperar dados de clientes e produtos em arquivos.
Dado o menu do Trabalho 1, leve em conta as seguintes considerações:
----------------MENU------------------
1 - Cadastrar novo cliente
2 - Remover cliente
3 - Imprimir clientes
4 - Cadastrar novo produto
5 - Remover produto
6 - Imprimir produtos
7 - Editar descrição de produtos
8 - Registrar venda de produto
9 - Sair
Escolha uma opção:
-------------------------------------------
• Escolhida a opção 9 (Sair), o programa deve percorrer a lista de clientes e a lista de produtos
salvando todos os seus dados em dois arquivos (um para os clientes e outro para os produtos). Você
deve formatar os arquivos da forma que você quiser, porém deve manter os dados de forma que a
atividade de leitura dos dados (explicada a seguir) seja realizada corretamente. Pense nisso antes de
começar a fazer, pois a formatação escolhida pode facilitar ou dificultar seu trabalho.
• Ao iniciar a execução do programa, os arquivos com as informações de clientes e produtos
deverão ser lidos. O seu programa deve ler estes arquivos e montar as listas de clientes e
produtos correspondentes, ou seja, o seu programa deve ler cada cliente e cada produto dos
arquivos correspondentes e inserir na lista de clientes ou na lista de produtos mantida pelo seu
programa principal. Isso deve ser feito antes de iniciar a apresentação do menu.
OBS:

1. Na pasta enviada para a professora contendo o projeto e todos os seus arquivos,você deve incluir
os arquivos com a formatação que você escolheu, pronto para ser lido.
2. Os mesmos arquivos devem ser utilizados para leitura dos dados e para salvar os dados. Toda vez
que alguém executar o seu programa, estes arquivos serão lidos para montar as listas de clientes e
produtos. E, após a execução e alteração destas listas, elas devem ser salvas nos arquivos
novamente. Ou seja, os arquivos serão criados novamente para escrita toda vez que o programa for
finalizado.
3. Altere seu programa de forma que os ids continuem sendo gerados automaticamente e mantendo
a ordem.
