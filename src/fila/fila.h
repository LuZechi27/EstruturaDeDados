typedef struct fila Fila;

Fila *new_queue();
int queue_is_full( Fila *f );
int queue_is_empty( Fila *f );
int enqueue( Fila *f, int valor );
int dequeue( Fila *f, int *valor );
int get_first( Fila *f, int *valor );
void show_queue( Fila *f );
void free_queue( Fila *f );
