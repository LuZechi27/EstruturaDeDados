#include <stdlib.h>
#include <stdio.h>
#include "fila.h"

#define MAX_TAM 5

typedef struct fila
{
    int item[MAX_TAM];
    int inicio, fim, qtd;
} Fila;

Fila *new_fila() {
    Fila *f = (Fila*) malloc(sizeof(Fila));
    if (f != NULL) {
        f->inicio = 0;
        f->fim = -1;
        f->qtd = 0;
    }
    return f;
}

int fila_cheia(Fila *f) {
    return f->qtd == MAX_TAM;
}

int fila_vazia(Fila *f) {
    return f->qtd == 0;
}

int enfileirar(Fila *f, int valor) {
    if (fila_cheia(f)) {
        
    }
}
