#include <stdio.h>


int main(){

 float notas[5];
 float media;
 float total = 0;

 for(int i = 0; i < 5; i++){
     
     printf("Insira a %d nota: ", i + 1);
     scanf("%f", &notas[i]);

 }

 for(int i = 0; i < 5; i++){
     
      total += notas[i];
 }
   
 media = total / 5;

 printf("A média é: %.2f", media);

}
