//mostrar elementos no vetor usando função

#include <stdio.h>
#include <stdlib.h>


void mostrar_vetor(int vet[], int tamanho){
     
     for(int i = 0; i < tamanho; i++){

    printf(" %d", vet[i]);
  }

  printf("\n");
}



int main (int argc, char *argv[]){

  int v[5];

  v[0] = 10;
  v[1] = 3;
  v[2] = v[0] + v[1];
  v[3] = v[2] + 10;
  v[4] = 11;

  
  mostrar_vetor(v, 5);


  int v1[10];

  for(int i = 0; i<10; i++){

    printf("Preencha a %d posicao do vetor: ", i);
    scanf("%d", &v1[i]);

  }

  mostrar_vetor(v1, 10);

}

