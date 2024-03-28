#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
 
typedef struct {
    int ra;
    float n1;
	float n2;
	float media;
} Aluno;
 
/* ********************************************* */
/* ***  conta o número de linhas do arquivo  *** */
/* ***           (número de alunos)          *** */
/* ********************************************* */
int getQuantidadeAlunos() {

    FILE *arqAlunos;
    Aluno alu;
    int n = 0;

    if ((arqAlunos = fopen("A05ordenadoRA.txt", "r")) == NULL) {
        printf("Problemas para abrir o arquivo de dados!\n");
        exit(1);
    }

    while (! feof(arqAlunos)) {
        fscanf(arqAlunos, "%d", &alu.ra);
        fscanf(arqAlunos, "%f", &alu.n1);
        fscanf(arqAlunos, "%f", &alu.n2);
        n++;
    }

    fclose(arqAlunos);

    return n;

} 

/* ********************************************* */
/* ***     preenche o vetor de submissoes    *** */
/* ***       a partir do arquivo texto       *** */
/* ********************************************* */
void preencheVetor (Aluno *v, int n) {

    FILE *arqAlunos;
    Aluno alu;
    int i;

    arqAlunos = fopen("A05ordenadoRA.txt", "r");
    if (arqAlunos == NULL){
    	printf("Problemas com o arquivo de entrada de dados");
    	exit(1);    	
	}

    for (i = 0; i < n; i++) {

        fscanf(arqAlunos, "%d", &alu.ra);
        fscanf(arqAlunos, "%f", &alu.n1);
        fscanf(arqAlunos, "%f", &alu.n2);
        alu.media = (alu.n1 + alu.n2) / 2;
        
        v[i] = alu;
    }

    fclose(arqAlunos);

} 

int pesquisaSequencial(Aluno *vetorAlunos, int indiceInicio, int indiceFinal, int valorProcurado){
	int indiceMeio;
	
	indiceMeio = (indiceInicio + indiceFinal) / 2;
	if(vetorAlunos[indiceMeio].ra == valorProcurado){
		return indiceMeio;
	}
	
	if(indiceInicio > indiceFinal){
		return -1;
	}
	
	if(valorProcurado > vetorAlunos[indiceMeio].ra){
		pesquisaSequencial(vetorAlunos, indiceMeio+1, indiceFinal, valorProcurado);
	} else {
		pesquisaSequencial(vetorAlunos, 0, indiceMeio-1, valorProcurado);
	}
}

void imprimeDados(Aluno *alunos, int indiceAluno){
	printf("\nAluno: %d", alunos[indiceAluno].ra);
	printf("\nNota N1: %.1f", alunos[indiceAluno].n1);
	printf("\nNota N2: %.1f", alunos[indiceAluno].n2);
	printf("\nNota Média: %.1f", alunos[indiceAluno].media);
	printf("\nPosição no Array: %d", indiceAluno);
}

/* ********************************************* */
/* ***          código principal             *** */
/* ********************************************* */
int main () {
    Aluno *vet;
    int ra;
    int n;
    int indiceRetornado;

    n = getQuantidadeAlunos();                  // descobre a quantidade de alunos
    vet = (Aluno*) malloc (n * sizeof(Aluno));  // aloca o vetor vet
    preencheVetor(vet, n);                   // preenche o vetor a partir do arquivo texto de entrada
	
    printf("\nDigite o RA do aluno: ");
    scanf("%d", &ra);  // entra com o RA do aluno a ser pesquisada

    indiceRetornado = pesquisaSequencial(vet, 0, n, ra);   // pesquisa pelos dados da última submissão da equipe 
    imprimeDados(vet, indiceRetornado); 	  // imprime os dados do aluno

    printf("\n");
    return 0;
}


