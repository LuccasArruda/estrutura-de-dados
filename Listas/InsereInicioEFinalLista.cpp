#include <stdio.h>

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
