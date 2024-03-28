#include <stdio.h>
#include <locale.h>

#define TAMANHO_HASH 97
#define QTD_ALUNOS 75

int hashFunction(int key){
	int hashCode; 
	hashCode = key % TAMANHO_HASH;
	return hashCode; 
}

int main(){
	int ra, i, hashCode;
	int hashTable[TAMANHO_HASH];
	
	setlocale(LC_ALL, "");
	
	for(i = 0; i < TAMANHO_HASH; i++)
		hashTable[i] = 0;
	
	for(i = 0; i < QTD_ALUNOS; i++){
		scanf("%d", &ra);
		hashCode = hashFunction(ra);
		
		if(hashTable[hashCode] == 0)
			hashTable[hashCode] = ra;	
	}
	
	for(i = 0; i < TAMANHO_HASH; i++){
		if(hashTable[i] > 0){
			printf("\nra: %d gerou o hashcode %d", hashTable[i], i);
		}
	}
	
}
