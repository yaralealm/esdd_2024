#include "t_date.h"
#include <stdbool.h>
#include <stdio.h>


struct date {
    int day; 
    int month; 
    int year;
}

int days_in_month(int month, int year); //nao faz parte do TAD, por isso fica aqui; 
bool is_leap_year(int year); 
char* month_in_full(int month); 



T_date create_Date(int day, int month, int year){
    T_date ptr = NULL; 

    if (year >= 1000 && year <= 3000)
    {
        if (month >=1 && month <= 12)
        {
            //usando a função days_in_month para saber qts dias tem o mes que foi passado
            if (day > 0 && day <= days_in_month(month, year))
            {
                //criando espaço de memoria p o struct date
                ptr = malloc(sizeof(struct date)); 
                if (ptr != NULL)
                {
                    ptr->day = day; 
                    ptr->month = month; 
                    ptr->year = year; 
                }
                

            }
            
        }
        
    }
    

    return ptr; 
}

char* ptbr_date(T_date date){
    //contando dia, mes e ano + \n da 11, por isso 12 por precaução; 
    char* str = malloc( sizeof (char) * 12); 
    if (str == NULL)
    {
        return NULL; 
    }

    //imprimindo num arquivo:
    sprintf(str, "%02d/%02d/%04d", date->day, date->month, date->year); 
    return str; 

}

char* usa_date(T_date date){
    //contando dia, mes e ano + \n da 11, por isso 12 por precaução; 
    char* str = malloc( sizeof (char) * 12); 
    if (str == NULL)
    {
        return NULL; 
    }

    //imprimindo num arquivo:
    sprintf(str, "%02d-%02d-%04d", date->month, date->day, date->year); 
    return str; 
}

char* complete_date(T_date date, char* location){
    char* str = malloc ( sizeof (char) * 64); 

    if (str != NULL)
    {
        sprintf(str, "%s, %02d de %s de %04d.", location, date->day, 
        month_in_full(date->month), date->year); 
    }
    return str; 
}

void destroy_date(T_date* date){
//apagar o endereço do ponteiro que aponta para os dados no heap e não só o conteúdo da var do heap;

free(*date); 
*date = NULL; 

}

int days_in_month(int month, int year){
    int days = 0; 

    switch (month)
    {
    case 1: 
    case 3:
    case 5:
    case 7:
    case 8: 
    case 10: 
    case 12: 
        days = 31; 
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        days = 30; 
        break;
    case 2: 
        days = is_leap_year(year) ? 29 : 28; 
        break;
    }

    return days; 
}

bool is_leap_year(int year){
    return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0; 
}

char* month_in_full(int month){
    char* str = malloc ( sizeof (char) * 16); 
    if (str == NULL)
    {
        return NULL; 

        if (month == 1)
        {
            strcpy(str, "janeiro"); 
        }else if (month == 2)
        {
            strcpy(str, "fevereiro"); 

        }else if (month == 3)
        {
            strcpy(str, "março"); 

        }else if (month == 4)
        {
            strcpy(str, "abril"); 

        }else if (month == 5)
        {
            strcpy(str, "maio"); 

        }else if (month == 6)
        {
            strcpy(str, "junho"); 

        }else if (month == 7)
        {
            strcpy(str, "julho"); 

        }else if (month == 8)
        {
            strcpy(str, "agosto"); 

        }else if (month == 2)
        {
            strcpy(str, "fevereiro"); 

        }else if (month == 2)
        {
            strcpy(str, "fevereiro"); 

        }else if (month == 2)
        {
            strcpy(str, "fevereiro"); 

        }else if (month == 2)
        {
            strcpy(str, "fevereiro"); 

        }else{
            
        }
        
        
    }
    return str; 
    
}