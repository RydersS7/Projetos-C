//Busca sequêncial de elementos do vetor

#include <stdio.h>

int busca_sequencial(int v[], int tam, int elemento) {
    for (int i = 0; i < tam; i++) {
        if (v[i] == elemento) {
            return i; 
        }
    }
    return -1;
}

int main() {
    int v[5];
    int elemento, posicao;

    for (int i = 0; i < 5; i++) {
        printf("Preencha o vetor de 5 posições: ");
        scanf("%d", &v[i]);
    }

    printf("Digite um dos números que você digitou para achar sua posição: ");
    scanf("%d", &elemento);


    posicao = busca_sequencial(v, 5, elemento);


    if (posicao != -1) {
        printf("O elemento %d foi encontrado na posição %d.\n", elemento, posicao);
    } else {
        printf("O elemento %d não foi encontrado no vetor.\n", elemento);
    }

    return 0;
}
