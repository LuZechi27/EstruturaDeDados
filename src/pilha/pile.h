#include <stdbool.h>

typedef struct pile Pile;

Pile *create_pile();
bool pile_is_full(Pile *p, int size);
bool pile_is_empty(Pile *p);
bool push(Pile *p, int value);
bool pop(Pile *p, int *value);
bool peek(Pile *p, int *value);
void destroy(Pile *p);

void print_pile(Pile *p);
