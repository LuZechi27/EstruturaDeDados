#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "pile.h"

#define MAX_SIZE 5

typedef struct pile {
    int top;
    int item[MAX_SIZE];
} Pile;

Pile *create_pile() {
    Pile *p = (Pile*) malloc(sizeof(Pile));
    if (p != NULL) {
        p->top = -1;
    }
    return p;
}

bool pile_is_full(Pile *p, int size) {
    return p->top >= size - 1;
}

bool pile_is_empty(Pile *p) {
    return p->top == -1;
}

bool push(Pile *p, int value) {
    if (pile_is_full(p, MAX_SIZE)) {
        return false;
    } else {
        p->top++;
        p->item[p->top] = value;
        return true;
    }
}

bool pop(Pile *p, int *value) {
    if (pile_is_empty(p)) {
        return false;
    } else {
        *value = p->item[p->top];
        p->top--;
        return true;
    }
}

bool peek(Pile *p, int *value) {
    if (pile_is_empty(p)) {
        return false;
    } else {
        *value = p->item[p->top];
        return true;
    }
}

void destroy(Pile *p) {
    free(p);
}

void print_pile(Pile *p) {
    if (pile_is_empty(p)) {
        printf("\nPilha vazia.\n");
    } else {
        for (int i = p->top; i >= 0; i--) {
            printf("%d | ", p->item[i]);
        }
        printf("\n");
    }
}
