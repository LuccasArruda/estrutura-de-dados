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
		printf("A lista está vazia!\n");
		return;
	}
	
	printf("lista: [");
	while(noAtual != NULL){
		printf(" %d ", noAtual->dado);
		noAtual = noAtual->proximo;
	}
	printf("]\n");
}

void insereInicioLista(No **lista, int valor){ //lista recebe o endereço do ponteiro (duplo apontamento)
	No *novo;
	
	novo = (No *)malloc(sizeof(No)); //atribuindo ponteiro para o endereço onde foi alocada memória para a quantidade pedida
	novo->dado = valor; // atribuindo à propriedade dado o valor recebido
	
	if(listaEstaVazia(*lista) == 1){
		novo->proximo = NULL; // se for o último item da lista, o ponteiro para o próximo será nulo
	} else {
		novo->proximo = *lista; // atribuindo ao ponteiro para o próximo valor o ponteiro do início da lista
	}
	
	*lista = novo; // substitui o ponteiro do endereço de memória do início para o ponteiro para o endereço de memória do ponteiro novo
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
		aux = aux->proximo; //encontra o último nó
	
	aux->proximo = novo; //substitui aux pelo novo nó
	return;	
}	

void removeInicioLista(No **lista){
	No *aux = *lista; //auxiliar recebe o ponteiro para o inicio da lista
	
	if(listaEstaVazia(*lista)){ 
		printf("A lista está vazia!\n");
		return;
	}
	
	*lista = aux->proximo; // o antigo ponteiro para o início da fila recebe o ponteiro armazenado em próximo 
	free(aux); // liberação de memória do conteúdo do ponteiro aux(antigo início) conteúdo(dado e próximo)
}

void removeFinalLista(No **lista){
	No *atual = *lista;
	No *anterior;
	
	if(listaEstaVazia(*lista)){
		printf("A Lista está vazia!\n");
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
		printf("Não é possível pesquisar em uma lista vazia!\n");
		return (No *)NULL;
	}
	
	while((noDaLista != NULL) && (noDaLista->dado != valorProcurado)){
	//tem que ser o próprio nó, pois se testarmos o noDaLista->proximo != NULL, o caso em que só existe um valor na lista será falso
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
		printf("Não é possível remover itens de uma lista vazia!\n");
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
	printf("[^^^^declaração final da função removeInicioLista^^^^]\n");
	
	printf("Lista esvaziada!\n");
	return;
}
