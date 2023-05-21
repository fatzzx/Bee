#ifndef GAME_H
#define GAME_H

#include <string>
#include <iostream>
#include "uno.hpp"
#include "stack.hpp"
#include "dll.hpp"
#include "singly_listtest.hpp"

void init_deck(player *players, stack *main) {
    // Get cards from the main stack
    // and assingns to player
    deck removed;
    for (int i = 0; i < 7; i++) { // 7 cards
          pop(main, &removed);
          printf("carta %i ", i);
          players->cards[i] = removed;
    }
    printf("\n");
}

void init_players(type_dlist *players, int total, stack *main){
    char pname[60];

    for (int i = 0; i < total; i++) {
        // Select player's name
        player user;
        printf("Type %i° challenger's name: ", i+1);
        scanf("%s", pname);
      
        user.name = pname;
        init_deck(&user, main); // gets deck from stack
        insert_dlist_at_end(players, user); // Inserts
    }
}

int pit_four() { // "Cava 4"
    // Lógica pro player seguinte cavar 4
    return 1;
}

int check_special_card(int card_num) {
    // Lógica pra checar qual a carta especial
    return 1;
}

int play_card(deck *top_card, deck *new_card) {
    // Checks if selected card can be played
    if (new_card->color == 4) { // If +4
        return pit_four();
    }

    // If color matches
    if (top_card->color == new_card->color) {
        if (new_card->number > 9) { // If special card
            return check_special_card(new_card->number);
        }
        return 1; // If not special
    }

    // If number matches
    if (top_card->number == new_card->number) {
        if (new_card->number > 9) {
            return check_special_card(new_card->number);
        }
        return 1;
    }

    return 0;
}



void game_on(stack main) {
    // Main game loop 
  
    int turn = 0;
    int gaymers = 0;

    printf("How many people will play?  \n");
    scanf("%d", &gaymers);

    // Create a doubly-linked list
    type_dlist *players;
    players = start_dlist();

    // Initialize players and decks
    init_players(players, gaymers, &main);
    // Make it a circular list
    players->end->next = players->start;

    // Point to first player
    type_knot *current;
    current = players->start;

    // Plays the game until we have a winner
    while(1) {
        printf("Turn of player %s", current->info.name.c_str());
        printf("\n");
        
        turn++;
        if (turn == 10) break;
        current = current->next;
    }

    printf("\nwow");
}

void distribute_cards(stack *main_stack, singly_list **player1, singly_list **player2, singly_list **player3, singly_list **player4) {
  deck card;
  for(int i = 0; i < 7;i++){
    pop(main_stack, &card);
    insert_node(player1, card);
  }
  for(int i = 0; i < 7;i++){
    pop(main_stack, &card);
    insert_node(player2, card);
  }
  for(int i = 0; i < 7;i++){
    pop(main_stack, &card);
    insert_node(player3, card);
  }
  for(int i = 0; i < 7;i++){
    pop(main_stack, &card);
    insert_node(player4, card);
  }

}

void first_card(stack *main, stack *table){
  deck card;
  pop(main, &card);
  push(table, card);
}

void view_table(stack *table) {
    deck top_card;
    return_top(table, &top_card);
    printf("╔══════════╗\n");
    printf("║          ║\n");
    printf("║  UNO     ║\n");
    printf("║  TABLE   ║\n");
    printf("║          ║\n");
    printf("╠══════════╣\n");
    printf("║N:  %2d    ║\n", top_card.number);
    printf("║C:   %d    ║\n", top_card.color);
    printf("╚══════════╝\n");
}

void view_hand(singly_list *list) {
    singly_list *current_node;
    current_node = list;
    int cont = 1;

    printf("╔═══════════════════╗\n");
    printf("║      Player       ║\n");
    printf("╠═══════════════════╣\n");

    while (current_node != NULL) {
        printf("║ Card:   %2d        ║\n", cont);
        printf("║ Number: %2d        ║\n", current_node->info.number);
        printf("║ Color:  %2d        ║\n", current_node->info.color);
        printf("╠═══════════════════╣\n");
        current_node = current_node->next;
        cont++;
    }

    printf("╚═══════════════════╝\n");
}
void play_card_test(singly_list **list, stack *table, int position) {
    deck top_card;
    singly_list *current_node = *list;
    singly_list *prev_node = NULL;
    int count = 1;
    
    while (current_node != NULL && count < position) {
        prev_node = current_node;
        current_node = current_node->next;
        count++;
    }
    
    if (current_node == NULL) {
        printf("A posição escolhida não existe na lista!\n");
        return;
    }
    
    return_top(table, &top_card);
    
    if (current_node->info.number == top_card.number || current_node->info.color == top_card.color) {
        if (prev_node == NULL) {
            *list = current_node->next;
        } else {
            prev_node->next = current_node->next;
        }
        
        push(table, current_node->info);
        free(current_node);
        printf("Carta jogada com sucesso!\n");
    } else {
        printf("A carta escolhida não pode ser jogada!\n");
    }
}



void test_game_on(stack *main, stack *table, singly_list **player1, singly_list **player2, singly_list **player3, singly_list **player4){
  int position;
  distribute_cards(main, player1, player2, player3, player4);
  first_card(main, table);
  view_table(table);
  view_hand(*player1);
  printf("Qual carta deseja inserir\n");
  scanf("%d", &position);
  play_card_test(player1, table, position);
  view_table(table);
  view_hand(*player1);
  
  
}

#endif
