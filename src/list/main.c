#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main() {
    List *list = new_list();
    if (!list) {
        printf("Não foi possível criar a lista");
        return 1;
    }

    insert(list, 10, 0);
    insert(list, 20, 1);
    insert(list, 30, 0);
    insert(list, 40, 3);

    show_list(list);
    printf("\n");

    int index = -1;
    search(list, 20, &index);
    printf("Valor encontrado na pos: %d \n", index);

    free_list(list);
    return 0;
}
