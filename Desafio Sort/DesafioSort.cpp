#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

void bubbleSort(int *vetor, int tamanhoVetor){
	int I, aux, troca = 1;
	while(troca){
		troca = 0;
		for(I = 0; I < (tamanhoVetor-1); I++){
			if(vetor[I] > vetor[I+1]){
				aux = vetor[I];
				vetor[I] = vetor[I+1];
				vetor[I+1] = aux;
				troca = 1;
			}
		}
	}
}

void insertSort(int *vetor, int tamanhoVetor){
	int posicaoNumeroAtual, posicaoNumeroAnterior, aux;
	
	for(posicaoNumeroAtual = 1; posicaoNumeroAtual < tamanhoVetor; posicaoNumeroAtual++){
		aux = vetor[posicaoNumeroAtual];
		for(posicaoNumeroAnterior = posicaoNumeroAtual-1; (posicaoNumeroAtual < tamanhoVetor) && (aux < vetor[posicaoNumeroAnterior]); posicaoNumeroAnterior--){
			vetor[posicaoNumeroAnterior+1] = vetor[posicaoNumeroAnterior];
		}
		vetor[posicaoNumeroAnterior+1] = aux;
	}
}

void selectSort(int *vetor, int tamanhoVetor){
	int posicaoNumeroAtual, posicaoProximoNumero, menorNumero, aux;
	
	for(posicaoNumeroAtual = 0; posicaoNumeroAtual < tamanhoVetor - 1; posicaoNumeroAtual++){
		menorNumero = posicaoNumeroAtual;
		
		for(posicaoProximoNumero = posicaoNumeroAtual+1; posicaoProximoNumero < tamanhoVetor; posicaoProximoNumero++){
			
			if(vetor[posicaoProximoNumero]<vetor[menorNumero]){
				menorNumero = posicaoProximoNumero;
			}
		}
		
		if(menorNumero != posicaoNumeroAtual){
			aux = vetor[posicaoNumeroAtual];
			vetor[posicaoNumeroAtual] = vetor[menorNumero];
			vetor[menorNumero] = aux;
		}
	}
}

int main(){
	int I, vetorBubble[10000], vetorInsert[10000], vetorSelect[10000], random, numeroMaximo = 10000;
	clock_t inicio, fim;
	double duracao;
	
	setlocale(LC_ALL, "");
	for(I = 0; I <= numeroMaximo; I++){
		random = rand();
		vetorInsert[I] = random;
		vetorBubble[I] = random;
		vetorSelect[I] = random;
	}
	
	inicio = clock();
	bubbleSort(vetorBubble, 10000);
	fim = clock();
	
	printf("Bubble Sort: ");
	duracao = fim - inicio;
	printf("\nDuração: %f", (duracao * 1000 / CLOCKS_PER_SEC));
	
	inicio = clock();
	insertSort(vetorInsert, 10000);
	fim = clock();
	
	printf("\nInsert Sort: ");
	duracao = fim - inicio;
	printf("\nDuração: %f", (duracao * 1000 / CLOCKS_PER_SEC));
	
	inicio = clock();
	selectSort(vetorSelect, 10000);
	fim = clock();
	
	printf("\nSelect Sort: ");
	duracao = fim - inicio;
	printf("\nDuração: %f", (duracao * 1000 / CLOCKS_PER_SEC));	
}
