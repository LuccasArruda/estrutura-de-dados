#include <stdio.h>

int main(void){
	int i = 1234;
	
	printf("valor de i = %d\n", i);
	printf("endere�o de mem�ria (&i) de i: %d", (void *) &i);
	
	return 0;
}
