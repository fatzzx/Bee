#include "listase.h"
#include <stdio.h>

int main(void) {
  tp_listase *lista, *lista2;
  lista = inicializa_listase();
  lista2 = inicializa_listase();
  if (listase_vazia(lista)) {
    printf("Vazia\n");
  }
  for(int i = 10; i < 50; i+=10){
    insere_listase_no_fim(&lista, i);
    insere_listase_no_fim(&lista2, i);
  }
 
  if(checagem_igual(lista, lista2)){
    printf("IGUAL\n");
  }
   imprime_listase(lista2);
  return 0;
}