#include <stdio.h>
#include <locale.h>
#include "operacoes.c"

int main(){
	No* lista;
	
	setlocale(LC_ALL, "");
	
	iniciarLista(&lista);
	
	if(pesquisaElemento(lista, 1) != NULL)
		printf("Funcionou!\n");
	else
		printf("Num deu :(\n");
		
	imprimirLista(lista);
	insereInicioLista(&lista, 1);
	
	if(pesquisaElemento(lista, 1) != NULL)
		printf("Funcionou!\n");
	else
		printf("Num deu :(\n");

	insereFinalLista(&lista, 2);
	imprimirLista(lista);	
	insereFinalLista(&lista, 5);
	imprimirLista(lista);
//	imprimirLista(lista);
//	insereInicioLista(&lista, 2);
//	insereInicioLista(&lista, 3);
//	imprimirLista(lista);
//	insereFinalLista(&lista, 4);
//	insereFinalLista(&lista, 5);
//	imprimirLista(lista);
//	insereInicioLista(&lista, 6);
//	imprimirLista(lista);
//	removeInicioLista(&lista);
//	removeFinalLista(&lista);
//	imprimirLista(lista);
//	removeInicioLista(&lista);
//	imprimirLista(lista);
	
	if(pesquisaElemento(lista, 1) != NULL){
		printf("Valor encontrado!\n");
	} else {
		printf("Valor não encontrado!\n");
	}
	
	insereListaOrdenado(&lista, 4);
	imprimirLista(lista);
	insereListaOrdenado(&lista, 3);
	imprimirLista(lista);
	removeEspecifico(&lista, 3);
	imprimirLista(lista);
	removeEspecifico(&lista, 4);
	imprimirLista(lista);
	esvaziaLista(&lista);
//	imprimirLista(lista);
	
	return 0;
}
