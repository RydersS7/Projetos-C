//Função com ponteiro para encontrar um elemento de uma lista concatenada

#include <stdio.h>


struct lista {

   int valor;

   struct lista *proximo;

};


struct lista *procurar_valor(struct lista *pLista, int valor){

   while(pLista != NULL){

         if(pLista->valor == valor){

              return(pLista);

         }

         else{

            pLista = pLista->proximo;
         }
    
   }

   return NULL;

}

int main(){

struct lista m1, m2, m3;
struct lista *resultado, *gancho = &m1;

int valor;

m1.valor = 5;
m2.valor = 30;
m3.valor = 10;

m1.proximo = &m2;
m2.proximo = &m3;
m3.proximo = 0;

printf("Digite o valor da pesquisa: ");
scanf("%d", &valor);

resultado = procurar_valor(gancho, valor);

if (resultado == NULL){

   printf("Valor não encontrado!");

}else{

  printf("Valor %d encontrado", resultado->valor);

}

}


