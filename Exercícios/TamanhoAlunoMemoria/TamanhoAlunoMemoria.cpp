#include <stdio.h>
#include <locale.h>

typedef struct{
	int ra;
	char nome[30];
	int idade;
	float notaMedia;
} aluno;

int main(){
	aluno aluno1;
	
	setlocale(LC_ALL, "");
	
	printf("Informe o nome do aluno: \n");
	gets(aluno1.nome);
	printf("RA: %s\n", aluno1.nome);
	printf("Endereço de memória do nome do aluno: %p\n", &aluno1.nome);
	printf("Tamanho do nome do aluno: %d\n", sizeof(aluno1.nome));
	
	printf("Insira as informações do aluno(RA, IDADE, NOMA MEDIA): \n");
	scanf("%d %d %f", &aluno1.ra, &aluno1.idade, &aluno1.notaMedia);
	printf("RA: %d\n", aluno1.ra);
	printf("Endereço de memória do RA do aluno: %p\n", &aluno1.ra);
	printf("Tamanho do RA do aluno: %d\n", sizeof(aluno1.ra));
	
	printf("Idade: %d\n", aluno1.idade);
	printf("Endereço de memória da idade do aluno: %p\n", &aluno1.idade);
	printf("Tamanho da idade do aluno: %d\n", sizeof(aluno1.idade));
	
	printf("Nota Média: %.2f\n", aluno1.notaMedia);
	printf("Endereço de memória do nota média do aluno: %p\n", &aluno1.notaMedia);
	printf("Tamanho do nota média do aluno: %d\n", sizeof(aluno1.notaMedia));

	
	printf("Tamanho da estrutura aluno: %d", sizeof(aluno1));
	
	return 0;
}
