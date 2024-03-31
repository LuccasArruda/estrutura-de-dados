#include <stdio.h>
#include <locale.h>

#define QUANTIDADE_ESTADOS 27
#define TAMANHO_HASH 97

typedef struct{
	char estado[100];
	int ocupado;
} dadosEstado;

int retornaHash(char nomeEstado[100]){
	int valorNomeEstado = 0, i = 0;
	for(i; i < 100; i++){
		valorNomeEstado += (int)(nomeEstado[i]);	
	}
	return (valorNomeEstado % 97);
}

int main(){
	int i, colisoes = 0, indiceTabelaHash;
	dadosEstado hashTable[TAMANHO_HASH];
	char estado[100];
	
	setlocale(LC_ALL, "");
	
	for(i = 0; i < TAMANHO_HASH; i++){
		hashTable[i].ocupado = 0;  
	}
	
	
	for(i = 0; i < QUANTIDADE_ESTADOS; i++){
		gets(estado);
		printf("Estado: %s", estado);
		indiceTabelaHash = retornaHash(estado);
		printf("\n%d - ", indiceTabelaHash);
		
		if(hashTable[indiceTabelaHash].ocupado == 0){
			hashTable[indiceTabelaHash].estado[100] = estado[100];
			hashTable[indiceTabelaHash].ocupado = 1;	
		} else {
			colisoes++;	
		}
	}
	
	for(i = 0; i < TAMANHO_HASH; i++){
		if(hashTable[i].ocupado == 1){
			printf("\n[%d] - ocupado", i);
		} else {
			printf("\n[%d] - livre", i);
		}
	}
	
	printf("\ncolisões: %d", colisoes);
	
	return 0;
}
