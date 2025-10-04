//Calcular média dos elementos de um vetor

#include <stdio.h>
#include <stdlib.h>

float calcular_media(int v[], int tam){

     int soma = 0;
     
     for(int i = 0; i < tam; i++){

        soma += v[i];
     }

     return soma / tam;

}


int main (int argc, char *argv[]){

   
   int num[10];
   float media;

   
   for (int i = 0; i < 10; i++){

     printf("Insira o %d elemento do vetor: ", i + 1);
     scanf("%d", &num[i]);

   }

  media = calcular_media(num, 10);

printf("Os números digitados foram: ");

for(int i = 0; i < 10; i++){

    printf("%d ", num[i]);
}

printf("\nA media é dos elementos do vetor é:  %.2f", media);

}
