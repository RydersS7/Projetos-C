//Encontrar números pares no vetor usando função

#include <stdio.h>
#include <stdlib.h>

void vetor(int v[], int tamanho)
{
    for (int i = 0; i < tamanho; i++){
        printf("Digite um número: ");
        scanf("%d", &v[i]);
    }

}

void pares(int v[], int tamanho){
     
    printf("Números pares: ");

    for (int i = 0; i < tamanho; i++){
        
         if (v[i] % 2 == 0)
         {
            printf(" %d", v[i]);
         }

    }
}


int main(){

int v[10];

vetor(v, 10);
pares(v, 10);


}
