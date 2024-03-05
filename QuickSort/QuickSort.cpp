#include <stdio.h>

void quickSort(int *vetor, int indiceInicio, int indiceFim){
	int i, j, meio, pivo, aux;

	//iteração e troca
	i = indiceInicio;
	j = indiceFim;
	meio = (indiceFim + indiceInicio) / 2;
	pivo = vetor[meio];
	
	while(i <= j){
		while((vetor[i] < pivo) && (i < indiceFim))
			i++;
		
		while((vetor[j] > pivo) && (j > indiceInicio))
			j--;
			
		if(i <= j){
			aux = vetor[i];
			vetor[i] = vetor[j];
			vetor[j] = aux;
			
			i++;
			j--;
		}
	}
	
	//reordenação
	if (j > indiceInicio)
		quickSort(vetor, indiceInicio, j);
	
	if (i < indiceFim)
		quickSort(vetor, i, indiceFim);
}

int main(){
	int vetor[11]  = {12, 32, 54, 1, 3, 98, 100, 20, 73, 11, 43};
	int i, tamanhoVetor = 11;
	
	printf("desordenado:\n");
	for(i = 0; i < tamanhoVetor; i++){
		printf("%d ", vetor[i]);
	}
	
	quickSort(vetor, 0, tamanhoVetor - 1);
	
	printf("\nordenado:\n");
	for(i = 0; i < tamanhoVetor; i++){
		printf("%d ", vetor[i]);
	}
	
	return 0;
}

