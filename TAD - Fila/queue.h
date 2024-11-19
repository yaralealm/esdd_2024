#include <stdlib.h>
#include <stdbool.h>

typedef struct queue* T_Queue; 

typedef char T_Info; 

T_Queue init(int maxSize); //

//void init(T_Queue queue, int size); //muda o valor do ponteiro

bool is_full(T_Queue queue); 

bool is_empty(T_Queue queue);

bool enqueue(T_Queue queue, T_Info* elemento);//devolve um boolean se ele conseguiu ou nao retirar e devolve o elemento com o ponteiro;

// T_Queue dequeue(T_Queue queue); // retorna o elemento retirado; 