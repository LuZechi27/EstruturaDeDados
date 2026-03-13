#define SUCCESS 1
#define ERROR 0

typedef struct list List;

List *new_list();
int is_full(List *list);
int is_empty(List *list);
int insert(List *list, int value, int position);
int remove_item(List *list, int position, int *removed_value);
int search(List *list, int value, int *position);
void free_list(List *list);
void show_list(List *list);
