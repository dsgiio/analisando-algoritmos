#include <stdlib.h>
#include "../include/utils.h"


void copiar_vetor(int *dest, const int *orig, int n) {
for (int i = 0; i < n; i++) dest[i] = orig[i];
}