#include "lista.h"
#include <stdio.h>
#include <stdlib.h>
void iniciarLista(No **lista){
	*lista = NULL;
}

int listaEstaVazia(No *lista){
	if(lista == NULL){
		return 1;
	}
	
	return 0;
}

void imprimirLista(No *lista){
	No *noAtual = lista;
	if (listaEstaVazia(lista) == 1){
		printf("A lista est� vazia!\n");
		return;
	}
	
	printf("lista: [");
	while(noAtual != NULL){
		printf(" %d ", noAtual->dado);
		noAtual = noAtual->proximo;
	}
	printf("]\n");
}

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

void removeInicioLista(No **lista){
	No *aux = *lista; //auxiliar recebe o ponteiro para o inicio da lista
	
	if(listaEstaVazia(*lista)){ 
		printf("A lista est� vazia!\n");
		return;
	}
	
	*lista = aux->proximo; // o antigo ponteiro para o in�cio da fila recebe o ponteiro armazenado em pr�ximo 
	free(aux); // libera��o de mem�ria do conte�do do ponteiro aux(antigo in�cio) conte�do(dado e pr�ximo)
}

void removeFinalLista(No **lista){
	No *atual = *lista;
	No *anterior;
	
	if(listaEstaVazia(*lista)){
		printf("A Lista est� vazia!\n");
		return;
	}
	
	while(atual->proximo != NULL){
		anterior = atual;
		atual = atual->proximo;
	}
	
	if(atual == *lista)
		*lista = NULL;
	else
		anterior->proximo = NULL;
		
	free(atual);
	return;
}

No * pesquisaElemento(No *lista, int valorProcurado){
	No *noDaLista = lista;
	
	if(listaEstaVazia(lista) == 1){
		printf("N�o � poss�vel pesquisar em uma lista vazia!\n");
		return (No *)NULL;
	}
	
	while((noDaLista != NULL) && (noDaLista->dado != valorProcurado)){
	//tem que ser o pr�prio n�, pois se testarmos o noDaLista->proximo != NULL, o caso em que s� existe um valor na lista ser� falso
		noDaLista = noDaLista->proximo;
	}
	
	if(noDaLista->dado != valorProcurado)
		return (No *)NULL;
	
	return noDaLista;
}

void insereListaOrdenado(No **lista, int valor){
	No *aux = *lista;
	No *anterior = *lista;
	No *novoValor;

	novoValor = (No *)malloc(sizeof(No));
	novoValor->dado = valor;
	novoValor->proximo = NULL;
	
	if(listaEstaVazia(*lista) == 1){
		*lista = novoValor;
		return;
	}
	
	while(aux->dado < valor && aux != NULL){
		printf("valor atual: %d\n", aux->dado);
		anterior = aux;
		aux = aux->proximo;
	} 
//	printf("anterior: %d\n", anterior->dado);
//	printf("valor: %d\n", aux->dado);

	if(aux == *lista){
		insereInicioLista(lista, valor);
		return;
	}	
	
	if(aux == NULL){
		insereFinalLista(lista, valor);
		return;
	}
	
	anterior->proximo = novoValor;
	novoValor->proximo = aux;
	return;
}

void removeEspecifico(No **lista, int valor){
	No *atual = *lista;
	No *anterior = *lista;
	
	if(listaEstaVazia(*lista) == 1){
		printf("N�o � poss�vel remover itens de uma lista vazia!\n");
		return;
	}
	
	while(atual->dado != valor && atual != NULL){
		anterior = atual;
		atual = atual->proximo;
	}
	
	if(atual == *lista){
		removeInicioLista(lista);
		return;
	}
	
	if(atual->proximo == NULL){
		removeFinalLista(lista);
		return;
	}
	
	printf("Anterior->proximo: %p\n", anterior->proximo);
	printf("Atual->proximo: %p\n", atual->proximo);
	anterior->proximo = atual->proximo;
	free(atual);
	return;
}

void esvaziaLista(No **lista){
	No *anterior = *lista;
	
	while(*lista != NULL){
		anterior = *lista;
		*lista = anterior->proximo;
		removeInicioLista(lista);
	}
	printf("[^^^^declara��o final da fun��o removeInicioLista^^^^]\n");
	
	printf("Lista esvaziada!\n");
	return;
}
