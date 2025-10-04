//função para inverter o vetor

#include <stdio.h>
#include <stdlib.h>


void inverter(int v[], int tam){

     int i = 0;
     int f = tam-1;

     while(i < f){

      trocar(v,i,f);

      i++; f--; 

     }

}


void trocar(int v[], int i, int f){

     int aux = v[i];
     v[i] = v[f];
     v[f] = aux;

}


void mostrar(int v[], int tam){

    printf("Conteúdo do Vetor: ");
    for(int i = 0; i < tam; i++){

    printf(" %d", v[i]);

  }

 printf("\n");

}

int main(int argc, char *argv[]){

int v[10];
int i = 0;

while(i < 10){

printf("Preencha a %d posição do vetor: ", i);
scanf("%d", &v[i]);

i++;

}

mostrar(v, 10);
inverter(v, 10);
mostrar(v,10);

}
