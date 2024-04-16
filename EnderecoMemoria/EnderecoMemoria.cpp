#include <stdio.h>

int main(void){
	int i = 1234;
	
	printf("valor de i = %d\n", i);
	printf("endereço de memória (&i) de i: %d", (void *) &i);
	
	return 0;
}
