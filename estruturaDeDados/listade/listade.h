#ifndef listade_h
#define listade_h

#include <stdio.h>
#include <stdlib.h>
typedef int tp_item;

typedef struct tp_no_aux{
    tp_item info;
    struct tp_no_aux *ant;
    struct tp_no_aux *prox;
}tp_no;

typedef struct{
    tp_no *ini;
    tp_no *fim;
}tp_listade;

tp_listade *inicializa_listade(){
    tp_listade *lista=(tp_listade*) malloc(sizeof(tp_listade));
    lista->ini=NULL;
    lista->fim=NULL;
    return lista;
}
tp_no *aloca(){
    tp_no* pt;
    pt=(tp_no*) malloc(sizeof(tp_no));
    return pt;
}
int insere_listade_no_fim(tp_listade *lista, tp_item e){
    tp_no *novo;
    novo=aloca();
    if(!novo) return 0;
    novo->info=e;
    if((lista->ini==NULL )&&(lista->fim==NULL)){
        novo->prox=NULL;
        novo->ant=lista->fim;
        lista->fim->prox=novo;
    }
    else {
        novo->prox=NULL;
        novo->ant=lista->fim;
        lista->fim->prox=novo;
        lista->fim=novo;
    }
    return 1;
}

void imprime_listade(tp_listade *lista, int ordem){
    tp_no *atu;
    switch(ordem){
        case 1:atu=lista->ini;
        while(atu!=NULL){
            printf("%d", atu->info);
            atu=atu->prox;
        }
        break;
        case 2: atu=lista->fim;
        while(atu!=NULL){
            printf("%d", atu->info);
            atu=atu->ant;
        }
        break;
        default: printf("codigo invalido");
    }
    printf("\n");
}
int remove_listade(tp_listade *lista, tp_item e){
	tp_no *atu;
	atu=lista->ini;
	while((atu!=NULL) &&(atu->info!=e)){
		atu=atu->prox;
		if(atu==NULL) return 0;
		if(lista->ini==lista->fim){
			lista->ini=atu->prox;
			lista->ini=lista->fim=NULL;
			}
	else{
		if(lista->fim==atu){
			lista->fim=atu->ant;
			atu->ant->prox=NULL;
		}
		else{
			atu->prox->ant=atu->ant;
			atu->ant->prox=atu->prox;
		    }
	    }
	}
}

#endif