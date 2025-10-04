//copiar uma string para outra utilizando função e ponteiro, sem biblioteca string

#include <stdio.h>


void copiar_string(char *copiarDaqui, char *colarAqui){

   while(*copiarDaqui != '\0'){

        *colarAqui = *copiarDaqui;
        colarAqui++;
        copiarDaqui++;   
   }

   *colarAqui = '\0';

}



int main(){

char string1[] = "Pao e mortadela";
char string2[20];


copiar_string(string1, string2);

printf("%s\n", string2);

}
