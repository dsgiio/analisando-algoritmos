#include <stdio.h>
#include <stdlib.h>
#include "../include/arquivos.h"

int* lerDados(const char* nomeArquivo, int* tamanho) {
    FILE* f = fopen(nomeArquivo, "r");
    if (!f) {
        printf("Erro ao abrir %s.\n", nomeArquivo);
        return NULL;
    }

    int capacidade = 1000;
    int* vetor = malloc(capacidade * sizeof(int));
    int count = 0;

    while (fscanf(f, "%d", &vetor[count]) == 1) {
        count++;

        if (count >= capacidade) {
            capacidade *= 2;
            vetor = realloc(vetor, capacidade * sizeof(int));
        }
    }

    fclose(f);
    *tamanho = count;
    return vetor;
}

void salvarCSV(const char* nome, double* tempos, int repeticoes) {
    FILE* f = fopen(nome, "w");

    if (!f) {
        printf("Erro ao salvar CSV.\n");
        return;
    }

    fprintf(f, "Execucao,Tempo\n");

    for (int i = 0; i < repeticoes; i++) {
        fprintf(f, "%d,%lf\n", i + 1, tempos[i]);
    }

    fclose(f);
}
