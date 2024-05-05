#include <stdio.h>
#include <locale.h>

typedef struct{
	int ra;
	char nome[30];
	int idade;
	float notaMedia;
} aluno;

int main(){
	aluno alunos[5];
	int i;
	
	setlocale(LC_ALL, "");
	for(i = 0; i < 5; i++){
	    printf("Informe o nome do aluno %d: \n", (i+1));
        scanf("%s", alunos[i].nome);
        printf("Insira as informações do aluno %d (RA, IDADE, NOMA MEDIA): \n", (i+1));
	    scanf("%d %d %f", &alunos[i].ra, &alunos[i].idade, &alunos[i].notaMedia);
	}
	
	for(i = 0; i < 5; i++){
	    printf("Nome: %s\n", alunos[i].nome);
    	printf("Endereço de memória do nome do aluno: %p\n", &alunos[i].nome);
    	printf("Tamanho do nome do aluno: %d\n", sizeof(alunos[i].nome));
    	
    
    	printf("RA: %d\n", alunos[i].ra);
    	printf("Endereço de memória do RA do aluno: %p\n", &alunos[i].ra);
    	printf("Tamanho do RA do aluno: %d\n", sizeof(alunos[i].ra));
    	
    	printf("Idade: %d\n", alunos[i].idade);
    	printf("Endereço de memória da idade do aluno: %p\n", &alunos[i].idade);
    	printf("Tamanho da idade do aluno: %d\n", sizeof(alunos[i].idade));
    	
    	printf("Nota Média: %.2f\n", alunos[i].notaMedia);
    	printf("Endereço de memória do nota média do aluno: %p\n", &alunos[i].notaMedia);
    	printf("Tamanho do nota média do aluno: %d\n", sizeof(alunos[i].notaMedia));   
	}
	
	return 0;
}
