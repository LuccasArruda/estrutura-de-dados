#include <stdio.h>
#include <locale.h>

int buscaSequencial(int *vetor, int tamanhoVetor, int chave){
	int i = 0;
	while((i < tamanhoVetor) && (chave != vetor[i]))
		i++;
		
	if(i == tamanhoVetor){
		return -1;
	}else{
		return i;
	}
}

int main(){
	setlocale(LC_ALL, "");
	int vetor[14] = {9, 89, 23, 54, 72, 85, 12, 32, 15, 52, 51, 40, 49, 24};
	
	printf("posição da chave: %d", (buscaSequencial(vetor, 15, 51)));
	
	return 0;
}
