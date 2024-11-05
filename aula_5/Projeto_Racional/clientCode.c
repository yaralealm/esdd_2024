#include "racional.h"


int main()
{
    T_Racional soma, number, media; 
    int n=0; 
    char continuar; 
    soma = criarRacional(0,1); //soma está valendo 0; 

    do
    {
        printf("Digite um valor: "); 
        number = entradaRacional(); 
        soma = somaRacional(soma, number); //soma = soma+number; 
        destroiRacional(number); 

        printf("Digite S se deseja continuar."); 
        scanf("%c", &continuar); 

        n+=1; 
    } while (continuar=='s' || continuar=='S');
    
    number = criarRacional(1,n); 
    media = multiplicaRacional(soma, number); 
    printf("Média: "); 
    imprimeRacional(media); 
    printf("\n\n"); 

    destroiRacional(soma); 
    destroiRacional(number);
    destroiRacional(media); 
    return 0;
}
