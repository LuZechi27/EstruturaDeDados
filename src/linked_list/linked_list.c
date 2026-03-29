#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

typedef struct node {
    int value;
    struct node *next;
} Node;

typedef struct list {
    Node *beginning;
    Node *end;
} List;

List *create_list() {
    List *list = (List *) malloc(sizeof(List));
    if (list) {
        list->beginning = NULL;
        list->end = NULL;
    }
    return list;
}

bool is_empty(List *list) {
    return list->beginning == NULL;
}

bool insert_beginning(List *list, int value) {
    Node *node = (Node *) malloc(sizeof(Node));
    if (node == NULL) {
        return false;
    }
    bool empty = is_empty(list);

    node->value = value;
    node->next = list->beginning;
    list->beginning = node;

    if (empty)
        list->end = node;

    return true;
}

bool insert_after(List *list, int value, int insert_value) {
    Node *temp = list->beginning;
    while (temp != NULL && temp->value != insert_value) {
        temp = temp->next;
    }

    if (temp == NULL) {
        return false;
    }

    Node *node = (Node *) malloc(sizeof(Node));
    if (node == NULL) {
        return false;
    }
    node->value = value;
    node->next = temp->next;
    temp->next = node;

    if (temp == list->end) {
        list->end = node;
    }
    return true;
}

bool insert_end(List *list, int value) {
    Node *node = (Node *) malloc(sizeof(Node));
    if (node == NULL) {
        return false;
    }
    printf("node != null");
    
    node->value = value;
    node->next = NULL;

    if (is_empty(list))
        list->beginning = node;
    else
        list->end->next = node;

    list->end = node;

    return true;
}

bool remove_item(List *list, int value) {
    if (is_empty(list)) return false;
    
    Node *temp1 = list->beginning;
    Node *temp2 = NULL;

    while (temp1 != NULL && temp1->value != value) {
        temp2 = temp1;
        temp1 = temp1->next;
    }
    if (temp1 == NULL) return false;

    if (temp1 == list->beginning) {
        list->beginning = list->beginning->next;
        if (list->beginning == NULL) list->end = NULL;
    }
    else if (temp1 == list->end) {
        temp2->next = NULL;
        list->end = temp2;
    }
    else temp2->next = temp1->next;

    free(temp1);
    return true;
}

void print_list(List *list) {
    if (is_empty(list))
        printf("Lista vazia.\n");
    else {
        Node *node = list->beginning;
        while (node != NULL) {
            printf("\n%d", node->value);
            node = node->next;
        }
    }
}

void free_list(List *list) {
    if (list == NULL) return;

    Node *node = list->beginning;
    while (node != NULL) {
        Node *next = node->next;
        free(node);
        node = next;
    }
    free(list);
}
