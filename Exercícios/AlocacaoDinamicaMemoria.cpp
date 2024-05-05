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
    
    // Alocando memória para o array de alunos
    a = (aluno *)malloc(quantidadeAlunos * sizeof(aluno));
    printf("Tamanho de aluno: %d\n", sizeof(aluno));
    printf("Tamanho alocado para %d alunos: %d\n", quantidadeAlunos, (quantidadeAlunos * sizeof(aluno)));
    printf("Conteúdo de malloc: %p\n", (malloc(quantidadeAlunos * sizeof(aluno))));
    printf("Conversão de malloc para ponteiro de aluno: %p\n", ((aluno *)malloc(quantidadeAlunos * sizeof(aluno))));
    
    // Verificando se a alocação de memória foi bem-sucedida
    if (a == NULL) {
        printf("Erro ao alocar memória.");
        return 1;
    }
    
    // Lendo os dados de cada aluno
    for (int i = 0; i < quantidadeAlunos; i++) {
        printf("Digite o RA do aluno %d: ", i+1);
        scanf("%d", &a[i].ra);
        printf("Digite o nome do aluno %d: ", i+1);
        scanf("%s", a[i].nome); // Não precisa do & aqui porque nome já é um array
        printf("Digite a idade do aluno %d: ", i+1);
        scanf("%d", &a[i].idade);
        printf("\nEndereço de memória do aluno inserido: %p", &a[i]);
    }
    
    // Exibindo os dados dos alunos
    printf("\nDados dos alunos:\n");
    for (int i = 0; i < quantidadeAlunos; i++) {
        printf("Aluno %d:\n", i+1);
        printf("RA: %d\n", a[i].ra);	
        printf("Nome: %s\n", a[i].nome);
        printf("Idade: %d\n", a[i].idade);
    }
    
    // Liberando a memória alocada
    free(a);
    
    return 0;
}

