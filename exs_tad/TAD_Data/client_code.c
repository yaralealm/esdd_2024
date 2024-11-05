#include <stdio.h>
#include "t_date.h"

int main(int argc, char const *argv[])
{
    T_date date; 

    date = create_Date(29, 02, 2000); 

    if (date != NULL)
    {
        printf("%s \n", ptbr_date(date)); 
        printf("%s \n", usa_date(date)); 
        printf("%s \n", complete_date(date, "Araraquara")); 
    } else {
        printf("Data inválida!\n"); 
    }

    //limpando a var do main tbm alem da do heap
    destroy_date(&date); 

    date = create_Date(04, 11, 2024); 

    if (date != NULL)
    {
        printf("%s \n", ptbr_date(date)); 
        printf("%s \n", usa_date(date)); 
        printf("%s \n", complete_date(date, "Araraquara")); 
    } else {
        printf("Data inválida!\n"); 
    }

    //limpando a var do main tbm alem da do heap
    destroy_date(&date); 

    return 0;
}
