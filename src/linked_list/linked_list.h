#include <stdbool.h>

typedef struct list List;

List *create_list();
bool insert_beginning(List *list, int value);
bool insert_after(List *list, int value, int insert_value);
bool insert_end(List *list, int value);
bool remove_item(List *list, int value);
void print_list(List *list);
void free_list(List *list);
