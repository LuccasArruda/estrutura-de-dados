#include <stdio.h>

int main(void){
	int i = 1234;
	
	printf("valor de i = %d\n", i);
	printf("endere�o de mem�ria (&i) de i: %p", (void *) &i); 
	//casting � uma garantia que ser� recebido o valor do tipo necess�rio
	//portanto, n�o � necess�rio um casting para receber o resultado esperado
	
	return 0;
}
