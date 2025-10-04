//encontrar o segundo maior elemento de um vetor utilizando função

#include <stdio.h>
#include <stdlib.h>
 
int encontra(int vetor[], int tam){
 
    int maior = 0;
    int two_maior = 0;
 
    for(int i=0; i<tam; i++){
        if(vetor[i] >= maior){
            two_maior = maior;
            maior = vetor[i];
        }
        else if(vetor[i] >= two_maior){
            two_maior = vetor[i];
        }
    }
 
    return maior;
}
 
int main(int argc, int *argv[]){
 
    int lista[] = { 1 , 3, 4, 2};
    int tam = 4;
 
    printf("O segundo maior elemento é: %d", encontra(lista, 4));
 
}
