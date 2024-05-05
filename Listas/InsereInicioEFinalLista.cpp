#include <stdio.h>

void insereInicioLista(No **lista, int valor){ //lista recebe o endere�o do ponteiro (duplo apontamento)
	No *novo;
	
	novo = (No *)malloc(sizeof(No)); //atribuindo ponteiro para o endere�o onde foi alocada mem�ria para a quantidade pedida
	novo->dado = valor; // atribuindo � propriedade dado o valor recebido
	
	if(listaEstaVazia(*lista) == 1){
		novo->proximo = NULL; // se for o �ltimo item da lista, o ponteiro para o pr�ximo ser� nulo
	} else {
		novo->proximo = *lista; // atribuindo ao ponteiro para o pr�ximo valor o ponteiro do in�cio da lista
	}
	
	*lista = novo; // substitui o ponteiro do endere�o de mem�ria do in�cio para o ponteiro para o endere�o de mem�ria do ponteiro novo
}

void insereFinalLista(No **lista, int valor){
	No *novo;
	No *aux = *lista;
	
	novo = (No *)malloc(sizeof(No));
	novo->dado = valor;
	novo->proximo = NULL; 
	
	if(listaEstaVazia(*lista) == 1)
		aux->proximo = NULL;	
	
	while(aux->proximo != NULL)
		aux = aux->proximo; //encontra o �ltimo n�
	
	aux->proximo = novo; //substitui aux pelo novo n�
	return;	
}
