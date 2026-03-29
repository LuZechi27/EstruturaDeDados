#include <stdlib.h>
#include <stdio.h>
#include "polynomial.h"

typedef struct mono {
    int coeficiente;
    int expoente_literal;
    struct mono *prox;
} Monomio;

typedef struct lista {
    Monomio *inicio;
    Monomio *fim;
} Lista;

Lista *nova_lista() {
    Lista *poly = (Lista *) malloc(sizeof(Lista));
    if (poly) {
        poly->inicio = NULL;
        poly->fim = NULL;
    }
    return poly;
}

bool esta_vazio(Lista *lista) {
    return lista->inicio == NULL;
}

bool add_monomio(Lista *lista, int coeficiente, int expoente) {
    Monomio *mono = (Monomio *) malloc(sizeof(Monomio));
    if (mono == NULL) return false;

    mono->coeficiente = coeficiente;
    mono->expoente_literal = expoente;
    mono->prox = NULL;

    if (esta_vazio(lista)) {
        lista->inicio = mono;
    }
    else {
        lista->fim->prox = mono;
    }
    lista->fim = mono;

    return true;
}

double elevar(double base, int expoente) {
    if (expoente == 0) return 1;

    double resultado = base;
    for (int i = 1; i < expoente; i++) {
        resultado *= base;
    }
    return resultado;
}

double avaliar_lista(Lista *lista, double x) {
    double resultado = 0;

    Monomio *mono = lista->inicio;
    while (mono != NULL) {
        resultado += mono->coeficiente * elevar(x, mono->expoente_literal);
        mono = mono->prox;
    }
    return resultado;
}

void mostrar_polinomio(Lista *lista) {
    if (esta_vazio(lista)) {
        printf("polinomio_vazio");
    }
    else {
        Monomio *temp = lista->inicio;
        while (temp != NULL) {
            printf("+ (%dx^%d) ", temp->coeficiente, temp->expoente_literal);
            temp = temp->prox;
        }
        printf("\n");
    }
}

void liberar_lista(Lista *lista) {
    if (lista == NULL) return;

    Monomio *mono = lista->inicio;
    while (mono != NULL) {
        Monomio *prox = mono->prox;
        free(mono);
        mono = prox;
    }
    free(lista);
}
