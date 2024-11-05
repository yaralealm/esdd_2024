#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct parking {
    int *parkingSpaces; //usar ponteiro pq nao sabemos qnts vagas são; 
    int occupiedSpaces; 
    int totalCapacity; 
}; 

typedef struct parking *T_Parking; 

T_Parking create_Parking(int capacity); 

bool enter_Parking(T_Parking parking, int carPlate); 

int exit_Parking(T_Parking parking);

void show_Parking(T_Parking parking); 

void destroy_Parking(T_Parking parking); 

//Código Cliente
int main(int argc, char const *argv[])
{
    int carPlate; 
    T_Parking garage; //criando var da struct 

    garage = create_Parking(5); 
    garage -> occupiedSpaces = 0; //isso significa QUEBRAR O TAD; 

    carPlate = 1234; 
    printf("Entrou %d -> %s\n", carPlate, enter_Parking(garage, carPlate)?"Sim":"Não"); 

    carPlate = 2345; 
    printf("Entrou %d -> %s\n", carPlate, enter_Parking(garage, carPlate)?"Sim":"Não");
    carPlate = 3456; 
    printf("Entrou %d -> %s\n", carPlate, enter_Parking(garage, carPlate)?"Sim":"Não"); 
    carPlate = 4567; 
    printf("Entrou %d -> %s\n", carPlate, enter_Parking(garage, carPlate)?"Sim":"Não"); 
    carPlate = 5678; 
    printf("Entrou %d -> %s\n", carPlate, enter_Parking(garage, carPlate)?"Sim":"Não"); 
    carPlate = 6789; 
    printf("Entrou %d -> %s\n", carPlate, enter_Parking(garage, carPlate)?"Sim":"Não"); 

    show_Parking(garage); 

    printf("Saiu %d\n", exit_Parking(garage));
    printf("Saiu %d\n", exit_Parking(garage));
    printf("Saiu %d\n", exit_Parking(garage));

    show_Parking(garage); 

    carPlate = 1234; 
    printf("Entrou %d -> %s\n", carPlate, enter_Parking(garage, carPlate)?"Sim":"Não"); 

    show_Parking(garage); 

    destroy_Parking(garage); 

    return 0;
}

T_Parking create_Parking(int capacity) {
//criando espaço de memória para o estacionamento
    T_Parking parkingPtr = NULL; //pont começa smp nulo;  

    if (capacity > 0)
    //nmr de vagas tem que ser > que 0 para fzr sentido; 
    {
        parkingPtr = malloc(sizeof(struct parking));

        if (parkingPtr != NULL)
        {
            //ponteiro apontando para os elementos do struct;
            parkingPtr->totalCapacity = capacity; 
            parkingPtr->occupiedSpaces = 0; 
            parkingPtr->parkingSpaces = malloc (sizeof(int) * capacity); //precisa alocar dinamicamente! 
            
            
            if (parkingPtr->parkingSpaces == NULL)
            {
                //se o 2° malloc nao funcionar, desocupar o espaço do xpto; 
                free(parkingPtr); 
                parkingPtr = NULL; 
            }
            
        }                                       //tam de bytes * tamanho passado (aqui no ex eh 5);                 
          
    }
    

    return parkingPtr; 
}


bool enter_Parking(T_Parking parking, int carPlate){

    bool result = false; 

    if (parking != NULL)
    {
        //verificar se a ocuoação esta menor que a capacidade; 
        if (parking->occupiedSpaces < parking->totalCapacity)
        {
            //colocando o carro na vaga vazia (que o num do occupiedSpace); 
            parking->parkingSpaces[parking->occupiedSpaces] = carPlate; 
            parking->occupiedSpaces++; 
            result = true; 
        }
        
    }
    return result; 

}

int exit_Parking(T_Parking parking){

    //tirar o primeiro e passar os outros p a vaga da frente;
    int carPlate = -1; 

    if (parking != NULL)
    {
        if (parking->occupiedSpaces > 0)
        {
            carPlate = parking->parkingSpaces[0]; 
            for (int i = 0; i < parking->occupiedSpaces - 1; i++)
            {
                parking->parkingSpaces[i] = parking->parkingSpaces[i+1]; 
            }
            parking->occupiedSpaces --; 
            
        }
        
    }
    
    return carPlate; 

}

void show_Parking(T_Parking parking){
    if (parking == NULL)
    {
        printf("Estacionamento inválido.\n");
    }else{
        printf("Estacionamento: \n"); 
        for (int i = 0; i < parking->occupiedSpaces; i++)
        {
            //imprimindo os nums das placas; 
            printf("\t->%04d\n", parking->parkingSpaces); 
        }
        
    }
    
    
}

void destroy_Parking(T_Parking parking){
    //1° destruir o r2d2 e dps o xpto; 

    free(parking->parkingSpaces); 
    free(parking); 

}