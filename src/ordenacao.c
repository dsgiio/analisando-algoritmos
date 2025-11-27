#include "../include/ordenacao.h"


// ---- BUBBLE ----
void bubble_sort(int *v, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (v[j] > v[j+1]) {
                int tmp = v[j]; 
                v[j] = v[j+1]; 
                v[j+1] = tmp;
            }
        }
    }
}


// ---- QUICK ----
static int particionar(int *v, int esq, int dir) {
    int pivo = v[dir];
    int i = esq - 1;

    for (int j = esq; j < dir; j++) {
        if (v[j] <= pivo) {
            i++;
            int tmp = v[i]; 
            v[i] = v[j]; 
            v[j] = tmp;
        }
    }

    int tmp = v[i+1]; 
    v[i+1] = v[dir]; 
    v[dir] = tmp;

    return i + 1;
}


void quick_sort(int *v, int esq, int dir) {
    if (esq < dir) {
        int p = particionar(v, esq, dir);
        quick_sort(v, esq, p - 1);
        quick_sort(v, p + 1, dir);
    }
}


// ---- HEAP ----
static void heapify(int *v, int n, int i) {
    int maior = i;
    int filho_esq = 2*i + 1;
    int filho_dir = 2*i + 2;

    if (filho_esq < n && v[filho_esq] > v[maior]) 
        maior = filho_esq;

    if (filho_dir < n && v[filho_dir] > v[maior]) 
        maior = filho_dir;

    if (maior != i) {
        int tmp = v[i]; 
        v[i] = v[maior]; 
        v[maior] = tmp;

        heapify(v, n, maior);
    }
}


void heap_sort(int *v, int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(v, n, i);

    for (int i = n - 1; i > 0; i--) {
        int tmp = v[0]; 
        v[0] = v[i]; 
        v[i] = tmp;

        heapify(v, i, 0);
    }
}