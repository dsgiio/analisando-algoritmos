#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "../include/arquivos.h"


int ler_dados(const char *nome, int **vetor, int *tamanho) {
FILE *f = fopen(nome, "r");
if (!f) return 0;


// lê todo o arquivo para buffer (aceita números separados por vírgula, espaço, nova linha)
if (fseek(f, 0, SEEK_END) != 0) { fclose(f); return 0; }
long sz = ftell(f);
if (sz < 0) { fclose(f); return 0; }
fseek(f, 0, SEEK_SET);


char *buf = malloc((size_t)sz + 1);
if (!buf) { fclose(f); return 0; }


size_t read = fread(buf, 1, (size_t)sz, f);
buf[read] = '\0';
fclose(f);


int capacidade = 1000;
*vetor = malloc(capacidade * sizeof(int));
if (!*vetor) { free(buf); return 0; }


int count = 0;
char *p = buf;


while (*p) {
// pula separadores
while (*p && (isspace((unsigned char)*p) || *p == ',')) p++;
if (!*p) break;


char *endptr;
long val = strtol(p, &endptr, 10);
if (p == endptr) break; // não conseguiu parsear


if (count >= capacidade) {
capacidade *= 2;
int *tmp = realloc(*vetor, capacidade * sizeof(int));
if (!tmp) { free(*vetor); free(buf); return 0; }
*vetor = tmp;
}


(*vetor)[count++] = (int)val;
p = endptr;
}


free(buf);
*tamanho = count;
return 1;
}