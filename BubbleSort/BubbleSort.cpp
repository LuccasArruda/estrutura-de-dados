#include <stdio.h>

int bubbleSort(int *vetor, int tamanhoVetor){
	int i, aux, troca = 1;
	while(troca){
		troca = 0;
		for (i = 0; i < tamanhoVetor - 1; i++){
			if(vetor[i] > vetor[i+1]){
				aux = vetor[i];
				vetor[i] = vetor[i+1];
				vetor[i+1] = aux;
				troca = 1;
			}
		}
	}
}

int main(){
	int i, Idades[10] = {12, 3, 1, 63, 52, 74, 32, 13, 24, 90};
	
	printf("Idades desordenadas: \n");
	while(i < 10){
		printf("%d\n", Idades[i]);
		i++;
	}
	
	bubbleSort(Idades, 10);
	
	i = 0;
	printf("Idades Ordenadas: \n");
	while(i < 10){
		printf("%d\n", Idades[i]);
		i++;
	}
	
	return 0;
}
