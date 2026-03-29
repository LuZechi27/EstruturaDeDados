#include <stdbool.h>

typedef struct lista Lista;

Lista *nova_lista();
bool add_monomio(Lista *list, int coeficiente, int expoente);
double avaliar_lista(Lista *lista, double x);
void mostrar_polinomio(Lista *lista);
void liberar_lista(Lista *lista);
