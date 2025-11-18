#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "../include/arquivos.h"
#include "../include/utils.h"
#include "../include/ordenacao.h"

#define REPETICOES 1000

int main() {
    int tamanho;
    int* dadosOriginais = lerDados("dados.txt", &tamanho);

    if (!dadosOriginais) return 1;

    int* vetor = malloc(tamanho * sizeof(int));
    double tempos[REPETICOES];

    for (int i = 0; i < REPETICOES; i++) {

        copiarVetor(vetor, dadosOriginais, tamanho);

        clock_t inicio = clock();

        // CHAME AQUI O ALGORITMO DE ORDENAÇÃO

        // exemplo: selectionSort(vetor, tamanho);

        clock_t fim = clock();

        tempos[i] = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
    }

    salvarCSV("resultados.csv", tempos, REPETICOES);

    free(vetor);
    free(dadosOriginais);

    printf("Execução finalizada. Resultados salvos em resultados.csv\n");
    return 0;
}
