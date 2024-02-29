#include <stdio.h>

int insertSort(int *vetor, int tamanhoVetor){
	int i, j, aux;
	
	for(i = 1; i < tamanhoVetor; i++){
		aux = vetor[i];
		for(j = i-1; (j >= 0 && aux<vetor[j]); j--)
			vetor[j+1] = vetor[j];
		vetor[j+1] = aux;
	}
}

int main(){
	int i, Idades[10] = {12, 32, 54, 93, 34, 1, 0, 13, 83, 91};
	
	printf("Idades Desordenadas: \n");
	while(i < 10){
		printf("%d ", Idades[i]);
		i++;
	}
	printf("\n");
	
	insertSort(Idades, 10);

	i = 0;
	printf("Idades Ordenadas: \n");
	while(i < 10){
		printf("%d ", Idades[i]);
		i++;
	}
	
	return 0;
}
