#include <stdio.h>

int main(void){
	int i = 1234;
	
	printf("valor de i = %d\n", i);
	printf("endereço de memória (&i) de i: %p", (void *) &i); 
	//casting é uma garantia que será recebido o valor do tipo necessário
	//portanto, não é necessário um casting para receber o resultado esperado
	
	return 0;
}
