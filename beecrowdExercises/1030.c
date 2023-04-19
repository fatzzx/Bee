#include <stdio.h>

typedef int type_item;

typedef struct type_knot{
    type_item info;
    struct type_knot *next;
}type_sll;

type_sll * start_sll(){
    return NULL;
}
int empty_sll(type_sll *list){
    if(list==NULL) return 1;
    return 0;
}

type_sll * alloc_sll(){
    type_sll *new_knot;
    new_knot=(type_sll*) malloc (sizeof(type_sll));
    return new_knot;
}

int insert_sll_at_end(type_sll **list, type_item item){
    type_sll *new_knot, *current;

    new_knot=alloc_sll();

    if(new_knot==NULL) return 0;

    new_knot->info = item;
    new_knot->next = NULL;

    if(empty_sll(*list))
        *list = new_knot;
    else {
        current = *list;
        while(current->next!=NULL)
            current=current->next;
        current->next=new_knot;
    }
    return 1;
}

int lenght_sll(type_sll *list){
    int counter=0;
    type_sll *current;
    current=list;

    while(current!=NULL){
        counter++;
        current=current->next;
    }
    return counter;
}

void print_sll(type_sll *list){
    type_sll *current;
    current = list;
    
    while (current!=NULL){
        printf("%d   ", current->info);
        current=current->next;
    }
}

void remove_elementos_com_salto(type_sll **lista, int salto){
    int cont=lenght_sll(*lista)-1, conta=0;
    // transforma em circulo
    type_sll *first;

    first = *lista;
    while(first->next!=NULL)
        first=first->next;

    first->next = *lista;

    // remove com os saltos
    type_sll *current, *previous;
    int contador;

    current=*lista;
    previous=NULL;

    while(conta++!=cont){
        contador=0;
        while(contador++!=salto){
            previous=current;
            current=current->next;
        }

        if(previous==NULL) *lista = current->next;
        else previous->next = current->next;

        free(current);
        current=current->next;
    }
    current=NULL;

    // tira do circulo
    first=*lista;
    first->next=NULL;
}


int main () {

  type_sll *l;
  l = start_sll(); 

  insert_sll_at_end(&l, 1);
  insert_sll_at_end(&l, 2);
  insert_sll_at_end(&l, 3);
  insert_sll_at_end(&l, 4);
  insert_sll_at_end(&l, 5);
  insert_sll_at_end(&l, 6);    
  insert_sll_at_end(&l, 7);
  remove_elementos_com_salto(&l, 2);
  print_sll(l);
  

  return 0;
}