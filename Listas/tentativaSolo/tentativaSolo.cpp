#include <stdio.h>
#include <stdlib.h>

typedef struct _no{
	char nome[30];
	int idade;
	int numeroFila;
	_no *proximo;
} pessoa;

void iniciaFila(pessoa *fila){
	fila = NULL;
}

void adicionaPessoaFila(no *fila, pessoa novaPessoa){
	
}

int main(){
	pessoa Pessoa1;
	
	Pessoa1.idade = 20;
	Pessoa1.nome = "Carlinhos";
	Pessoa1.numeroFila = 1;
	
	iniciaFila;

	adicionaPessoaFila(&Pessoa1, Pessoa1);
	return 0;
}
