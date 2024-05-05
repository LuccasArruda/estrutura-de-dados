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
bool listaEstaVazia(No *);

void imprimeLista(No *);
void insereInicioLista(No **, int);
void insereFinalLista(No **, int);

void removeInicioLista(No **);
void removeFinalLista(No **);

#endif


