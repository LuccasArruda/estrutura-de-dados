#include <stdio.h>

void merge(int *vetor, int tamanhoVetor){
	int meio, i, j, k;
	int vetorAux[tamanhoVetor];
	
	meio = tamanhoVetor / 2;
	i = 0;
	j = meio;
	k = 0;
	
	//comparação entre vetores divididos
	while(i < meio && j < tamanhoVetor){
		if(vetor[i] <= vetor[j]){
			vetorAux[k] = vetor[i];
			k++;
			i++;
		}
		else{
			vetorAux[k] = vetor[j];
			k++;
			j++;
		}
	}
	
	//ordenando valores no vetor aux
	if(i == meio){
		while(j < tamanhoVetor){
			vetorAux[k] = vetor[j];
			k++;
			j++;
		}
	}else{
		while(i < meio){
			vetorAux[k] = vetor[i];
			k++;
			i++;
		}
	}	
	
	//atribuir para o vetor original
	for(i = 0; i < tamanhoVetor; i++){
		vetor[i] = vetorAux[i];
	}
}

void mergeSort(int *vetor, int tamanhoVetor){
	int meio;
	if(tamanhoVetor>1){
		meio = tamanhoVetor / 2;
		//chamadas recursivas
		mergeSort(vetor, meio); //lado esquerto
		mergeSort(vetor + meio, tamanhoVetor - meio); //lado direito	
	}
	merge(vetor, tamanhoVetor);		
}

int main(){
	int vetor[10] = {12, 65, 89, 30, 43, 13, 9, 1, 61, 78};
	int i;
	
	printf("vetor desordenado:\n");
	for(i = 0; i < 10; i++){
		printf("%d ", vetor[i]);
	}
	
	mergeSort(vetor, 10);
	
	printf("vetor ordenado:\n");
	for(i = 0; i < 10; i++){
		printf("%d ", vetor[i]);
	}
	
	return 0;
}

