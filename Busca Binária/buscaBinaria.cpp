#include <stdio.h>
#include <locale.h>


void quickSort(int *vetor, int indiceInicio, int indiceFim){
	int i, j, meio, pivo, aux;

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

int buscaBinaria(int *vetor, int inicioVetor, int fimVetor, int valorProcurado){
	int indiceMeio;
	indiceMeio = (inicioVetor + fimVetor) / 2;

	if(vetor[indiceMeio] == valorProcurado){
		return indiceMeio;
	}
	
	if (inicioVetor >= fimVetor){
		return -1;
	}
	
	if(valorProcurado < vetor[indiceMeio]){
		buscaBinaria(vetor, 0, indiceMeio-1, valorProcurado);
	} else {
		buscaBinaria(vetor, indiceMeio+1, fimVetor, valorProcurado);
	}
}

int main(){
	setlocale(LC_ALL, "");
	int vetor[14] = {9, 89, 23, 54, 72, 85, 12, 32, 15, 52, 51, 40, 49, 24};
	int i;
	
	printf("vetor desordenado: \n");
	for(i = 0; i < 14; i++){
		printf("%d ", vetor[i]);
	}
	
	quickSort(vetor, 0, 14);
	
	printf("vetor ordenado: \n");
	for(i = 0; i < 14; i++){
		printf("%d ", vetor[i]);
	}
	
	printf("\nposição da chave: %d", (buscaBinaria(vetor, 0, 14, 9)));
	
	return 0;
}
