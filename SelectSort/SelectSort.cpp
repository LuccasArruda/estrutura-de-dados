#include <stdio.h>

int selectSort(int *vetor, int tamanhoVetor){
	int menor, aux, i, j;
	for(i = 0; i < tamanhoVetor - 1; i++){
		menor = i;
		for(j = i+1; j < tamanhoVetor; j++){
			if(vetor[j] < vetor[menor]){
				menor = j;
			}
		}
		
		if(menor != i){
			aux = vetor[i];
			vetor[i] = vetor[menor];
			vetor[menor] = aux;
		}
	}
}

int main(){
	int i, Idades[10] = {26, 87, 90, 76, 63, 12, 32, 17, 89, 10};
	
	printf("Idades desordenadas: \n");
	while(i < 10){
		printf("%d ", Idades[i]);
		i++;
	}
	printf("\n");
	
	selectSort(Idades, 10);
	
	i = 0;
	printf("Idades Ordenadas: \n");
	while(i < 10){
		printf("%d ", Idades[i]);
		i++;
	}
	
	return 0;
}
