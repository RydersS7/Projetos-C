//intercção de vetores

#include <stdio.h>

void ler_vetor(int v[], int n) {
    for (int i = 0; i < n; i++) {
        printf("\nInsira a %d posição do vetor: ", i + 1);
        scanf("%d", &v[i]);
    }
}

void intercalar_vetor(int a[], int b[], int n) {
    printf("Intersecção: {");
    for (int i = 0; i < n; i++) {
        int repetido = 0;
        for (int j = 0; j < i; j++) {
            if (a[i] == a[j]) {
                repetido = 1;
                break;
            }
        }
        if (!repetido) {
            for (int j = 0; j < n; j++) {
                if (a[i] == b[j]) {
                    printf("%d ", a[i]);
                    break;
                }
            }
        }
    }
    printf("}");
}

int main() {
    int a[10];
    int b[10];

    printf("Elementos do vetor A: \n");
    ler_vetor(a, 10);

    printf("\nElementos do vetor B: \n");
    ler_vetor(b, 10);

    printf("\n");
    intercalar_vetor(a, b, 10);

    return 0;
}
