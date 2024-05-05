/*
	==============
	ARQUIVO HEADER
    ==============	
*/

#ifndef LISTA_H
#define LISTA_H

// estrutura de n�
typedef struct _no{
	int dado;
	struct _no *proximo;
} No;

// declara��o das fun��es (opera��es) da lista

void iniciarLista(No **); 
//duplo apontamento � utilizado como conting�ncia caso o endere�o mude
//necess�rio quando a estrutura pode mudar
int listaEstaVazia(No *);

void imprimirLista(No *);
void insereInicioLista(No **, int);
void insereFinalLista(No **, int);

void removeInicioLista(No **);
void removeFinalLista(No **);

#endif


