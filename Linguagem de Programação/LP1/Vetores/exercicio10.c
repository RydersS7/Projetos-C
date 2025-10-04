//somar elementos em um vetor

#include <stdio.h>


int somar_elementos(int v[], int tam) {
    int soma = 0;
    for (int i = 0; i < tam; i++) {
        soma += v[i];
    }
    return soma;
}

int main() {
    int v[10];
    
    for (int i = 0; i < 10; i++) {
        printf("Digite o número para a posição %d: ", i + 1);
        scanf("%d", &v[i]);
    }
    

    int soma = somar_elementos(v, 10);
    printf("A soma dos elementos do vetor é: %d\n", soma);
    
    return 0;
}
