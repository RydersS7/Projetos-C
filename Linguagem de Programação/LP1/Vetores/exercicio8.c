//separar elementos pares dos elementos ímpares

#include <stdio.h>
#include <stdlib.h>

void trocar(int v[], int i, int f){

    int aux = v[i];
    v[i] = v[f];
    v[f] = aux;

}  


void separar_pares_impares(int v[], int n){

    int i = 0;
    int f = n - 1;

    while(i < f){

        if (v[i] % 2 == 0){

             i++; 
        }

        else if(v[f] % 2 != 0){ 
            
            f--; 
        }

        else if(i < f){

        trocar(v,i,f);
            i++;
            f--;
        }
    }

}


void mostrar(int v[], int n){

    for(int i = 0; i < n; i++){

        printf(" %d ", v[i]);
    }

    printf("\n");
}


int main(int argc, char *argv[]){
   
   int v[10];
   
   for(int i = 0; i < 10; i++){

       printf("Insira a %d posição do vetor: ", i);
       scanf("%d", &v[i]);
   } 

  separar_pares_impares(v,10);
  mostrar(v,10);
  
  return 0;
}
