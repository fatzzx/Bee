#ifndef STACK_H
#define STACK_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <string>
//#include <windows.h>
#define TAM_MAX_DECKS 108
#define TAM_MAX_COLOR 25

typedef struct {
    int number;
    int color;
} deck;

typedef struct {
    int top;
    deck cards[TAM_MAX_DECKS];
} stack;


void init_stack(stack *pilha){
    pilha->top = -1;
}

void init_mult_stacks(stack *piles[], int n){
  for(int i = 0; i < n; i++) init_stack(piles[i]);
}

int is_hollow(stack *pilha) {
    if(pilha->top == -1){
        return 1;
    }
    return 0;
}

int is_full(stack *pilha) {
    if (pilha->top == TAM_MAX_DECKS -1) {
        printf("The stack is full.\n");
        return 1;
    }
    return 0;
}

void add_top(stack *pilha){
    pilha->top++;
}

void rm_top(stack *pilha){
    pilha->top--;
}

void push(stack *pilha, deck item){
    if (is_full(pilha))
        return;
    add_top(pilha);
    pilha->cards[pilha->top] = item;
}

void pop(stack *pilha, deck *item){
    if (is_hollow(pilha))
        return;
  
    // Remove o item do top e decrementa o top
    *item = pilha->cards[pilha->top];
    rm_top(pilha);
}

int return_top(stack *pilha, deck *item){
    if(is_hollow(pilha))
        return 0;
    *item = pilha->cards[pilha->top];
    return 1;
}

int size_of_stack(stack *pilha){
    return pilha->top + 1;
}

void print_stack(stack pilha){
    deck removed;
    printf("Position | number | color\n");
    while(is_hollow(&pilha) != 1){
        pop(&pilha, &removed);
        printf("Deck %d = %d %d\n", pilha.top + 1, removed.number, removed.color);
    }
}



void clear_stack(stack *pile){
    deck removed;
    int current_top = pile->top;
    for (int i = 0; i <= current_top; i++){
        pop(pile, &removed);
    }
}

void imprimePilha(stack *p){
  printf("A Pilha possui %d elementos:\n", p->top+1);
  for(int i = (p->top); i >= 0; i--){
    printf("%.2d de cor %d na posicao %d \n", p->cards[i].number, p->cards[i].color, i);
  }
}

void stack_to_stack(stack *source, stack *destination){
    deck removed;
    while(!is_hollow(source)){
        pop(source, &removed);
        push(destination, removed);
    }
}

#endif