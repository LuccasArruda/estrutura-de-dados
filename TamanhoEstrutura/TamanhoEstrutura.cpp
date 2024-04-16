#include <stdio.h>

typedef struct{
	int dia;
	int mes;
	int ano;
} tempo;

int main(void){
	tempo Tempo;
	
	printf("Tamanho do atributo dia: %d\n", sizeof(Tempo.dia));
	printf("Tamanho do atributo mes: %d\n", sizeof(Tempo.mes));
	printf("Tamanho do atributo ano: %d\n", sizeof(Tempo.ano));
	printf("Tamanho da estrutura tempo: %d\n", sizeof(Tempo));
		
	return 0;
}
