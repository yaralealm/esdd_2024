#include <stdio.h>
#include "MyString.h"

struct MyString
{
    char string; 
};

T_String create(char* text){
    T_String text;

    text = malloc(sizeof(struct MyString)); 

    if(text != NULL){
        text->str = *text; 
    }
 
}

int length(T_String str){
    int tam = 0;

    if (str != NULL)
    {
     
    while (str != '\0')
    {
        tam++;
    }
    return tam; 

    }

    return -1; 
}

void destroy(T_String str){
    free(str); 
}

T_String toUpper(T_String str){
    if (str != NULL)
    {
      while (str != '\0')
      {
        toUpper(str); 
        return str; 
      }
        
    }
    return NULL; 
    
}
T_String toLower(T_String str){
        if (str != NULL)
    {
      while (str != '\0')
      {
        toLower(str); 
        return str; 
      }
        
    }
    return NULL; 

}

char charAt(T_String str, int index){
  char caractere; 

if (index < length(str)){


  caractere = str[index]; 
  
    return caractere; 
    }else{
    return '\0'; 
    }
}

int indexOf(T_String str, char c){
    for (int i = 0; i < length(str); i++)
    {
        if (c == str[i])
        {
            return i; 
        }
        
    }

    return -1; 
    
}