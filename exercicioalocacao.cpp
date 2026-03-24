#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[50];
    float *nota;
    int num_notas;
} Aluno;

// contar o numero de linhas do arquivo para determinar quantos alunos tem
int contar_linhas(const char *notas) {
    FILE *f = fopen(notas, "r");
    if (!f) return 0; // se o arquivo nao pudeer ser aberto retorna 0

    int cont = 0;
    char c;

    while ((c = fgetc(f)) != EOF) { // lendo o arquivo para contar o numero de linhas
        if (c == '\n') cont++; // icrementa o contador quando encontrar uma nova linha 
    }

    fclose(f);
    return cont;
}

Aluno* carregar_dados(const char *notas, int *total_alunos) {
    *total_alunos = contar_linhas(notas);
    if (*total_alunos == 0) return NULL;

    
    Aluno *vetor_struct = (Aluno*) malloc((*total_alunos) * sizeof(Aluno)); // alocando o vetor de alunos

    FILE *f = fopen(notas, "r");
    char linha[512];
    int idx_alunos = 0;

    while (fgets(linha, sizeof(linha), f)) {

        int i = 0;
        int j = 0;
        int virgulas = 0;

        // contar o numero de virgulas para determinar quantas notas tem cada aluno
        while (linha[i] != '\0') { // percorrendo a linha para contar as virgulas
            if (linha[i] == ',') virgulas++; // cada virgula separa um campo
            i++;
        }

        vetor_struct[idx_alunos].num_notas = virgulas; // o numero de notas eh igual ao numero de virgulas
        vetor_struct[idx_alunos].nota = (float*) malloc(virgulas * sizeof(float)); // alocando o vetor de notas para cada aluno

        i = 0;
        j = 0;
        int campo = 0;
        char buffer[100]; 

        while (linha[i] != '\0') { // percorrendo a linha caractere por caractere para processar os campos (nome e notas)

            if (linha[i] == ',' || linha[i] == '\n' || linha[i] == '\r') { // se encontrar uma virgula ou o final da linha processa o campo
                buffer[j] = '\0'; // finaliza a string do buffer 

                if (j > 0) {
                    if (campo == 0) { 
                        strcpy(vetor_struct[idx_alunos].nome, buffer); // copia o nome do aluno para a struct
                    } else {
                        vetor_struct[idx_alunos].nota[campo - 1] = atof(buffer); // converte a string do buffer para float e armazena na struct
                    }
                    campo++;
                }

                j = 0;
            } else {
                buffer[j++] = linha[i]; // adiciona caractere ao buffer
            }

            i++;
        }

        idx_alunos++;
    }

    fclose(f);
    return vetor_struct;
}


void imprimir_relatorio(Aluno *vetor, int total) {
    float media_global = 0.0; // variavel para calcular a media global

    printf("===== RELATORIO DE NOTAS =====\n\n");

    for (int i = 0; i < total; i++) { // percorrendo o vetor de alunos para imprimir o realatorio de cada um 
       
        printf("Aluno: %s\n", vetor[i].nome);

        float soma = 0.0; // variavel para calcular a soma das notas de cada aluno
        
        // imprimindo as notas do aluno e calculando a soma para calcular a media depois
        for (int j = 0; j < vetor[i].num_notas; j++) { // percorrendo o vetor de notas
            
            printf("Nota %d: %.2f\n", j + 1, vetor[i].nota[j]);
            
            soma += vetor[i].nota[j]; // soma as notas para calcular a media
        }

        float media = soma / vetor[i].num_notas; // calcula a media do aluno
        printf("Media: %.2f\n\n", media);

        media_global += media; // acumula a media do aluno para calcular a media global
    }

    printf("Media global da turma: %.2f\n", media_global / total);
}


void liberar(Aluno *vetor_struct, int total) {
    for (int i = 0; i < total; i++) { // percorrendo o vetor de alunos 
        free(vetor_struct[i].nota); // liberando a memoria alocada para as notas de cada aluno 
    }
    free(vetor_struct); // liberando a memoria alocada para o vetor de alunos(structs)
}

int main() {
    int total_alunos;

    Aluno *dados = carregar_dados("notas.csv", &total_alunos);

    if (dados == NULL) {
        printf("Erro ao carregar dados.\n");
        return 1;
    }
    // chamando a funcao para imprimir o relatorio de notas e depois liberando a memoria alocada
    imprimir_relatorio(dados, total_alunos);
    liberar(dados, total_alunos);

    return 0;
}