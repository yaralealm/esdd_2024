#include <stdlib.h>

typedef struct date *T_date; 

T_date create_Date(int day, int month, int year); 

char* ptbr_date(T_date date); //char ponteiro é uma string!

char* usa_date(T_date date); 

char* complete_date(T_date date, char* location); 

void destroy_date(T_date* date); 



