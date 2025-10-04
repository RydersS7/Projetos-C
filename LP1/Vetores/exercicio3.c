//encontrar o maior elemento em um vetor

#include <stdio.h>
#include <stdlib.h>


int encontra_maior(int v[], int n){

    int maior = v[0];

    for(int i = 1; i < n; i++){

        if (v[i] > maior){

            maior = v[i];
        }
    }

    return maior;
}

int main(int argc, int *argv[]){

    int v[10];
    int maior;
    
    for(int i = 0; i < 10; i++){

    printf("Preencha a %d posição do vetor: ", i);
    scanf("%d", &v[i]);

    }
    
    maior = encontra_maior(v, 10);

    printf("O maior elemento do vetor é: %d", maior);
 

}
