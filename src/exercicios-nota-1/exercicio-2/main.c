#include <stdio.h>
#include <stdlib.h>
#include "polynomial.h"

void limpar_tela() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

int main() {
    Lista *polinomio = nova_lista();
    if (polinomio == NULL) {
        printf("erro ao iniciar o polinomio.");
        exit(EXIT_FAILURE);
    }

    printf("Digite o polinomio (coeficiente <<enter>> expoente <<enter>> ..., coeficiente = 0 para finalizar): ");
    int coeficiente;
    int expoente;
    do {
        scanf("%d%d", &coeficiente, &expoente);
        add_monomio(polinomio, coeficiente, expoente);
    } while (coeficiente != 0 && expoente != 0);

    mostrar_polinomio(polinomio);

    printf("Informe o valor de x: ");
    double x;
    scanf("%lf", &x);

    printf("Valor da equação: %.2lf\n", avaliar_lista(polinomio, x));

    liberar_lista(polinomio);
}
