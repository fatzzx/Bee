#ifndef ARVORE_BINARIA_H
#define ARVORE_BINARIA_H
#include <stdio.h>
#include <stdlib.h>

typedef int tp_item;

typedef struct tp_no{
  struct tp_no *dir;
  struct tp_no *esq;
  tp_item info;
}tp_no;

typedef tp_no *tp_arvore;

tp_arvore inicializa_arvore(){
  return NULL;
}

int vazia(tp_arvore raiz){
  if(raiz == NULL) return 1;
  else return 0;
}

tp_no *aloca_no(){
  tp_no *no;
  no = (tp_no*)malloc(sizeof(tp_no));
  return no;
}

int insere_no(tp_arvore *raiz, tp_item e){
  tp_no *novo_no;
  tp_no *pai, *p = *raiz;
  novo_no = aloca_no();
  if(!novo_no) return 0;
  novo_no->info = e;
  novo_no->dir = NULL;
  novo_no->esq = NULL;  
  while(p != NULL){
    pai = p;
    if(e < p->info){
      p = p->esq;      
    } else p = p->dir;
  }
  if(pai!=NULL){
    if(e < pai->info) pai->esq = novo_no;
    else pai->dir = novo_no;
  } else *raiz = novo_no;
  return 1;
}

void pre_ordem(tp_arvore raiz){
  tp_no *p = raiz;
  if(p != NULL){
    printf("%d\n", p->info);
    pre_ordem(p->esq);
    pre_ordem(p->dir);
  }
}

void em_ordem(tp_arvore raiz){
  tp_no *p = raiz;
  if(p != NULL){
    em_ordem(p->esq);
    printf("%d\n", p->info);
    em_ordem(p->dir);
  }
}

void pos_ordem(tp_arvore raiz){
  tp_no *p = raiz;
  if(p != NULL){
    pos_ordem(p->esq);
    pos_ordem(p->dir);
    printf("%d\n", p->info);
  }
}








#endif