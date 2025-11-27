#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#include "../include/arquivos.h"
#include "../include/ordenacao.h"
#include "../include/utils.h"


#define REPETICOES 1000
#define PASSO 500


int main(void) {
int tamanhoTotal;
int *dadosOriginais = NULL;


if (!ler_dados("dados.txt", &dadosOriginais, &tamanhoTotal)) {
fprintf(stderr, "Erro ao ler dados.txt\n");
return 1;
}


FILE *csv = fopen("resultados_algoritmos.csv", "w");
if (!csv) { perror("Erro ao abrir CSV"); free(dadosOriginais); return 1; }


fprintf(csv, "Bloco,Bubble,Quick,Heap\n");


for (int bloco = PASSO; bloco <= tamanhoTotal; bloco += PASSO) {
double somaBubble = 0.0, somaQuick = 0.0, somaHeap = 0.0;


for (int r = 0; r < REPETICOES; r++) {
int *copia = malloc(bloco * sizeof(int));
if (!copia) { fprintf(stderr, "malloc falhou\n"); break; }


// Bubble
copiar_vetor(copia, dadosOriginais, bloco);
clock_t ini = clock();
bubble_sort(copia, bloco);
clock_t fim = clock();
somaBubble += (double)(fim - ini) / CLOCKS_PER_SEC;


// Quick
copiar_vetor(copia, dadosOriginais, bloco);
ini = clock();
quick_sort(copia, 0, bloco - 1);
fim = clock();
somaQuick += (double)(fim - ini) / CLOCKS_PER_SEC;


// Heap
copiar_vetor(copia, dadosOriginais, bloco);
ini = clock();
heap_sort(copia, bloco);
fim = clock();
somaHeap += (double)(fim - ini) / CLOCKS_PER_SEC;


free(copia);
}


double tempoBubble = somaBubble / REPETICOES;
double tempoQuick = somaQuick / REPETICOES;
double tempoHeap = somaHeap / REPETICOES;


fprintf(csv, "%d,%.6f,%.6f,%.6f\n", bloco, tempoBubble, tempoQuick, tempoHeap);
printf("Bloco %d finalizado: bubble=%.6f quick=%.6f heap=%.6f\n", bloco, tempoBubble, tempoQuick, tempoHeap);
}


fclose(csv);
free(dadosOriginais);


printf("Arquivo resultados_algoritmos.csv gerado!\n");
return 0;
}