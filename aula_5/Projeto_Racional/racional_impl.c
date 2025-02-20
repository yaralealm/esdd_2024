#include "racional.h"
struct racional{
    int numerador;
    int denominador; 
};

T_Racional criarRacional(int numerador, int denominador){
    T_Racional ptr; 

    ptr = malloc(sizeof(struct racional)); 

    if (ptr != NULL)
    {
        ptr->numerador = numerador; 
        ptr->denominador = denominador; 

        if (!ehValidoRacional(ptr))
        {
            ptr->numerador = 0; 
            ptr->denominador = 1; 
        }
    }

    return ptr; 
    
} 

void destroiRacional(T_Racional racionalPtr){
    free(racionalPtr); 
}

T_Racional somaRacional(T_Racional racionalAPtr, T_Racional racionalBPtr){
    T_Racional soma; 

    soma = criarRacional(0,1); //necessario criar esp de memoria;

    soma->numerador = racionalAPtr->numerador * racionalBPtr->denominador + 
    racionalBPtr->numerador * racionalAPtr->denominador; 

    soma->denominador = racionalAPtr->denominador * racionalBPtr->denominador; 

    simplificarRacional(&soma);

    return soma; 
}

T_Racional multiplicaRacional(T_Racional racionalAPtr, T_Racional racionalBPtr){
    T_Racional ptr; 
    ptr = criarRacional(0,1); 

    ptr->numerador = racionalAPtr->numerador * racionalBPtr->numerador; 
    ptr->denominador = racionalAPtr->denominador * racionalBPtr->denominador; 

    simplificarRacional(&ptr); 

    return ptr; 
}

void imprimeRacional(T_Racional racionalPtr){
    printf("%d/%d", racionalPtr->numerador, racionalPtr->denominador); 
}

T_Racional entradaRacional(){
    int numerador, denominador; 
    scanf("%d", &numerador); 
    scanf("%d", &denominador); 
    T_Racional ptr = criarRacional(numerador,denominador); 
    return ptr; 
}

void simplificarRacional(T_Racional* racionalPtr){
    int valor_Mdc = mdc((*racionalPtr)->numerador, (*racionalPtr)->denominador); 
    (*racionalPtr)->numerador = (*racionalPtr)->numerador / valor_Mdc; 
    (*racionalPtr)->denominador = (*racionalPtr)->denominador / valor_Mdc; 
}

bool ehValidoRacional(T_Racional racionalPtr){
    return racionalPtr->denominador != 0; 
}

int mdc(int a, int b){
    int resto; 
    do
    {
        resto = a % b; 
        a = b; 
        b = resto;
    } while (resto != 0);
    return a; 
    
}