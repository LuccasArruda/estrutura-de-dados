#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int ra;
    char nome[40];
    int idade;
} aluno;

int main() {
    int quantidadeAlunos;
    aluno *a;
    
    printf("Quantos alunos deseja cadastrar? ");
    scanf("%d", &quantidadeAlunos);
    
    // Alocando mem�ria para o array de alunos
    a = (aluno *)malloc(quantidadeAlunos * sizeof(aluno));
    printf("Tamanho de aluno: %d\n", sizeof(aluno));
    printf("Tamanho alocado para %d alunos: %d\n", quantidadeAlunos, (quantidadeAlunos * sizeof(aluno)));
    printf("Conte�do de malloc: %p\n", (malloc(quantidadeAlunos * sizeof(aluno))));
    printf("Convers�o de malloc para ponteiro de aluno: %p\n", ((aluno *)malloc(quantidadeAlunos * sizeof(aluno))));
    
    // Verificando se a aloca��o de mem�ria foi bem-sucedida
    if (a == NULL) {
        printf("Erro ao alocar mem�ria.");
        return 1;
    }
    
    // Lendo os dados de cada aluno
    for (int i = 0; i < quantidadeAlunos; i++) {
        printf("Digite o RA do aluno %d: ", i+1);
        scanf("%d", &a[i].ra);
        printf("Digite o nome do aluno %d: ", i+1);
        scanf("%s", a[i].nome); // N�o precisa do & aqui porque nome j� � um array
        printf("Digite a idade do aluno %d: ", i+1);
        scanf("%d", &a[i].idade);
        printf("\nEndere�o de mem�ria do aluno inserido: %p", &a[i]);
    }
    
    // Exibindo os dados dos alunos
    printf("\nDados dos alunos:\n");
    for (int i = 0; i < quantidadeAlunos; i++) {
        printf("Aluno %d:\n", i+1);
        printf("RA: %d\n", a[i].ra);	
        printf("Nome: %s\n", a[i].nome);
        printf("Idade: %d\n", a[i].idade);
    }
    
    // Liberando a mem�ria alocada
    free(a);
    
    return 0;
}

