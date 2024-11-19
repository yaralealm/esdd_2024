#include <stdio.h>
#include "queue.h"

int main(int argc, char const *argv[])
{
    T_Queue fila; 

    fila = init(5); 

    printf("%s\n", enqueue(fila, 'a') ? "Entrou" : "Não entrou"); 
    printf("%s\n", enqueue(fila, 'b') ? "Entrou" : "Não entrou"); 
    printf("%s\n", enqueue(fila, 'c') ? "Entrou" : "Não entrou"); 
    printf("%s\n", enqueue(fila, 'd') ? "Entrou" : "Não entrou"); 
    printf("%s\n", enqueue(fila, 'e') ? "Entrou" : "Não entrou"); 
    printf("%s\n", enqueue(fila, 'f') ? "Entrou" : "Não entrou"); 
    printf("%s\n", enqueue(fila, 'g') ? "Entrou" : "Não entrou"); 
    printf("%s\n", enqueue(fila, 'h') ? "Entrou" : "Não entrou"); 

    while (!is_empty(fila))
    {
        dequeue(fila, &saiu); 
        printf("Saiu: ")
    }
    

    return 0;
}
