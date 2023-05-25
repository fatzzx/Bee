#include "tree.h"

int main(){
  tp_arvore a;
  a = inicializa_arvore();
  insere_no(&a, 15);
  insere_no(&a, 10);
  insere_no(&a, 17);
  insere_no(&a, 20);
  insere_no(&a, 22);
  em_ordem(a);
  
}