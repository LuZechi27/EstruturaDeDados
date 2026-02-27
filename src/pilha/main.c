#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "pile.h"

int main() {
    Pile *pile = create_pile();
    if (pile == NULL) {
        perror("Erro ao alocar pilha.\n");
        return 1;
    }

    for (int i = 10; i <= 60; i = i + 10) {
        if (push(pile, i) == false) {
            printf("Erro ao empilhar.\n");
        } else {
            printf("Empilhado com sucesso.\n");
        }
    }

    int value;
    peek(pile, &value);
    printf("topo: %d\n", value);
    
    printf("\nPilha: ");
    print_pile(pile);

    for (int i = 0; i < 3; i++) {
        if (pop(pile, &value) == false) {
            printf("Erro ao desempilhar.\n");
        } else {
            printf("poped %d\n", value);
        }
    }

    printf("\nPilha: ");
    print_pile(pile);

    for (int i = 0; i < 3; i++) {
        if (pop(pile, &value) == false) {
            printf("Erro ao desempilhar. Pilha vazia.\n");
        } else {
            printf("poped %d\n", value);
        }
    }

    printf("\nPilha: ");
    print_pile(pile);

    destroy(pile);
    return 0;
}
