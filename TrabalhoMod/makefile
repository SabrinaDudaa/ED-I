all: compila executa

compila: main.o cliente.o produto.o listaencadeada.o listacabecauda.o
	gcc main.o cliente.o produto.o listaencadeada.o listacabecauda.o -o prog
main.o: main.c
	gcc -c main.c
cliente.o: Cliente.c
	gcc -c Cliente.c
produto.o: Produto.c
	gcc -c Produto.c
listaencadeada.o: ListaEncadeada.c
	gcc -c ListaEncadeada.c
listacabecauda.o: ListaCabECauda.c
	gcc -c ListaCabECauda.c
executa:
	prog.exe
clean:
	del main.o cliente.o produto.o listaencadeada.o listacabecauda.o prog.exe