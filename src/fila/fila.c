#include <stdio.h>
#include<stdlib.h>
#include "fila.h"

#define MAXTAM 5
#define ERROR 0
#define SUCCESS 

struct fila {
    int item[MAXTAM];
    int inicio, fim, qtd;
};

Fila *new_queue() {
    Fila *f = ( Fila * ) malloc( sizeof( Fila ) );
    if (f == NULL)
        return NULL;

    f->inicio = 0;
    f->fim = -1;
    f->qtd = 0;
    return f;
}

int queue_is_full( Fila *f ) {
    return f->qtd == MAXTAM;
}

int queue_is_empty( Fila *f ) {
    return f->qtd == 0;
}

// enqueue - Complexidade constante O(1)
int enqueue( Fila *f, int valor ) {
    if (filaCheia( f ))
        return ERROR;
    else {
       // f->fim++;
       // if (f->fim==MAXTAM)
       //    f->fim=0;
        f->fim = ( f->fim + 1 ) % MAXTAM;
        f->item[f->fim] = valor;
        f->qtd++;
        return SUCCESS;
    }
}

// dequeue = Complexidade constante O(1)
int dequeue( Fila *f, int *valor ) {
    if (filaVazia( f ))
        return ERROR;
    else {
        *valor = f->item[f->inicio];
        f->inicio = ( f->inicio + 1 ) % MAXTAM;
        f->qtd--;
        return SUCCESS;
    }
}

// Complexidade constante O(1)
int get_first( Fila *f, int *valor ) {
    if (filaVazia( f ))
        return ERROR;
    else {
        *valor = f->item[f->inicio];
        return SUCCESS;
    }
}

// Complexidade linear O(n)
void show_queue( Fila *f ) {
    if (filaVazia( f ))
        printf( "Fila vazia" );
    else {
        int i = f->inicio;
        for (int cont = 0;cont < f->qtd;cont++) {
            printf( "Item: %d\n", f->item[i] );
            i = ( i + 1 ) % MAXTAM;
        }
    }
}

void free_queue( Fila *f ) {
    free( f );
}
