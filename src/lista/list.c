#include <stdlib.h>
#include <stdio.h>
#include "list.h"

#define MAX_SIZE 5

typedef struct list {
    int item[MAX_SIZE];
    int amount;
} List;

List *new_list() {
    List *list = (List *) malloc(sizeof(List));
    if (list) {
        list->amount = 0;
    }
    return list;
}

int is_full(List *list) {
    return list->amount == MAX_SIZE;
}

int is_empty(List *list) {
    return list->amount == 0;
}

int insert(List *list, int value, int position) {
    if (is_full(list))
        return ERROR;
    if (position < 0 || position > list->amount)
        return ERROR;

    for (int i = list->amount; i > position; i--)
        list->item[i] = list->item[i - 1];

    list->item[position] = value;
    list->amount++;

    return SUCCESS;
}

int remove_item(List *list, int position, int *removed_value) {
    if (is_empty(list))
        return ERROR;

    if (position < 0 || position >= list->amount)
        return ERROR;

    *removed_value = list->item[position];
    for (int i = position; i < list->amount - 1; i++) {
        list->item[i] = list->item[i + 1];
    }
    list->amount--;

    return SUCCESS;
}

int search(List *list, int value, int *position) {
    if (is_empty(list))
        return ERROR;

    for (int i = 0; i < list->amount; i++)
        if (list->item[i] == value) {
            *position = i;
            return SUCCESS;
        }
}

void free_list(List *list) {
    free(list);
}

void show_list(List *list) {
    if (is_empty(list))
        printf("lista vazia");
    else {
        for (int i = 0; i < list->amount; i++)
            printf("\nItem: %d", list->item[i]);

        printf("\n");
    }
}
