#include "queue.h"

struct queue{
    T_Info* elements; //necessario ter alocação dinâmica pois não sabemos a quantidade certa para inicializar; 
    int size; 
    int last;  
};

T_Queue init(int maxSize){ //o init vai passar a quantidade de elementos; 
    if (maxSize < 1)
    {
        return NULL; 
    }

    T_Queue queue = malloc(sizeof(struct queue)); 

    if (queue != NULL)
    {
        queue->last = -1; 
        queue->size = maxSize; 
        queue->elements = malloc(sizeof(T_Info) * queue->size); //criando o vetor de dentro do struct queue; 
        if (queue->elements == NULL)
        {
            free(queue); 
            queue = NULL; 
            //se não tiver espaço no vetor; 
        }
        
    }
    
   return queue; 
    
} 

void destroy(T_Queue queue){
    free(queue->elements); 
    free (queue); 
}

bool is_full(T_Queue queue){
    if (queue != NULL)
    {
        return queue->last == queue->size; 
    }else{
        return false; 
    }
    
}

bool is_empty(T_Queue queue){
    if (queue != NULL)
    {
        return queue->last == -1; 
    }else{
        return false; 
        }
    }

bool enqueue(T_Queue queue, T_Info element){

    if (queue == NULL)
    {
        return false; 
    }

    if (is_full(queue))
    {
        return false; 
    }

    queue->last += 1;
    queue->elements(queue->last) = element; 
    return true;  
        
    }

bool dequeue (T_Queue queue, T_Info* elemento){
    if (queue == NULL)
    {
        return false; 
    }
    
    if (is_empty(queue))
    {
        return false; 
    }
    
    *elemento = queue->elements[0]; 

    for (int i = 0; i < queue->size; i++)
    {
        queue->elements[i] = queue->elements[i+1]; 
    }
    queue->last -= 1; 
    return true; 
}
