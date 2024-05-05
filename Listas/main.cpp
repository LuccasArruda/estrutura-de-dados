#include <stdio.h>
#include "operacoes.c"

int main(){
	No* lista;
	
	iniciarLista(&lista);
	
	imprimirLista(lista);
	insereInicioLista(&lista, 1);
	imprimirLista(lista);
	insereInicioLista(&lista, 4);
	insereInicioLista(&lista, 6);
	imprimirLista(lista);
	insereFinalLista(&lista, 8);
	insereFinalLista(&lista, 3);
	imprimirLista(lista);
	insereInicioLista(&lista, 43);
	imprimirLista(lista);
	removeInicioLista(&lista);
	removeFinalLista(&lista);
	imprimirLista(lista);
	removeInicioLista(&lista);
	imprimirLista(lista);
	
	return 0;
}
