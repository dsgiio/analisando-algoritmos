#include <stdio.h>
#include "../include/utils.h"

void copiarVetor(int* destino, int* origem, int tamanho) {
    for (int i = 0; i < tamanho; i++)
        destino[i] = origem[i];
}


