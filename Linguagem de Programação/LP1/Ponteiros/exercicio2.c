//soma de todos os valores em um vetor utilizando ponteiro e função

#include <stdio.h>

int somarVetor(int vetor[], int n){

   int soma = 0;
   int *ponteiro;
   int *ultimo_membro = vetor + n;
   

  for(ponteiro = vetor; ponteiro < ultimo_membro; ++ponteiro){

    soma += *ponteiro;

}

  return soma;

}


int main(void){

int vetor[10];

for(int i = 0; i < 10; i++){

  printf("Preencha a %d posição do vetor: ", i + 1);
  scanf("%d", &vetor[i]);

}

printf("A soma de todos os membros do vetor é: %d", somarVetor(vetor,10));

}

