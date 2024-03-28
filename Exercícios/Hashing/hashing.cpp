#include <stdio.h>

#define QUANTIDADE_ESTADOS 27
#define TAMANHO_HASH 54

typedef struct{
	char estado[100];
	bool ocupado;
} dadosEstado;

int retornaAsciiString(char )

int main(){
	int i;
	dadosEstado estados[QUANTIDADE_ESTADOS], hashTable[TAMANHO_HASH];
	char estado[100];
	
	for(i = 0; i < TAMANHO_HASH; i++)
		hashTable[i].ocupado = false;  
	
	for(i = 0; i < QUANTIDADE_ESTADOS; i++){
		gets(estado);
		retornaAsciiString(estado);
		gets(estados[i].estado);
	}
	
	for(i = 0; i < QUANTIDADE_ESTADOS; i++){
		printf("\n%s", estados[i].estado);
	}
	
	return 0;
}
