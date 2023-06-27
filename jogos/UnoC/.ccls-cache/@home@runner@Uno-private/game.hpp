#ifndef GAME_H
#define GAME_H

#include <string>
#include <iostream>
#include <stdlib.h>
#include <map>
#include <string.h>
#include <unistd.h>
#include <array>
#include <cstdio>
#include <vector>
#include <cstring>

#include "uno.hpp"
#include "stack.hpp"
#include "dll.hpp"
#include "colorfunc.hpp"
#include "tree.hpp"

const static int START_CARDS = 7;
typedef map<int, string> dict;

void init_deck(player *players, stack *main) {
    // Get cards from the main stack
    // and assingns to player

    deck removed;
    for (int i = 0; i < START_CARDS; i++) { // 7 cards
          pop(main, &removed);
          insert_node(&players->cards, removed);
    }
    printf("\n");
}

void first_card(stack *main, stack *table){
  deck card;
  do{
    pop(main, &card);
    push(table, card);
  }while(card.number > 9);
}


void init_players(type_dlist *players, int total, stack *main){
    char pname[60];

    for (int i = 0; i < total; i++) {
        player user;
        user.cards = init_singly();
      
        printf("Type %i° challenger's name: ", i+1);
        scanf("%s", pname);      
        user.name = pname;
      
        init_deck(&user, main); // gets deck from stack
        insert_dlist_at_end(players, user);       
    }
  // fclose(file);  
}


void view_table(stack *table, dict &numbers, dict &colors) {
    deck top;
    return_top(table, &top);
    switch (top.color){
      case 0: red(); break;
      case 1: blue(); break;
      case 2: yellow(); break;
      case 3: green(); break;
      case 4: special(); break;
      }

    printf("╔══════════╗\t ╔══════════╗\t ╔══════════╗\n");
    printf("║          ║\t ║ PRESS  0 ║\t ║ PRESS -1 ║\n");
    printf("║   UNO    ║\t ║    TO    ║\t ║    TO    ║\n");
    printf("║  TABLE   ║\t ║  GET A   ║\t ║  SEARCH  ║\n");
    printf("║          ║\t ║ NEW CARD ║\t ║  CARDS   ║\n");
    printf("╠══════════╣\t ╠══════════╣\t ║          ║\n");
    printf("║N: %s║\t ║   PIT    ║\t ║    🔍    ║\n", numbers[top.number].c_str());
    printf("║C: %s ║\t ║  STACK   ║\t ║    🕵️‍♀️    ║\n", colors[top.color].c_str());
    printf("╚══════════╝\t ╚══════════╝\t ╚══════════╝\n");
    reset();
  }

int view_hand(singly_list *list, dict &numbers, dict &colors) {
    singly_list *current_node;
    current_node = list;
    int cont = 1;
    int color, number;    

    printf("╔═══════════════════╗\n");
    printf("║      Player       ║\n");
    printf("╠═══════════════════╣\n");

    while (current_node != NULL) {  
        color = current_node->info.color;
        number = current_node->info.number;

        switch (color){
          case 0: red(); break;
          case 1: blue(); break;
          case 2: yellow(); break;
          case 3: green(); break;
          case 4: special(); break;
        }

        if (cont > 9) printf("║ Id:     %d        ║\n", cont);
        else printf(         "║ Id:     %d         ║\n", cont);
        printf("║ Color:  %s    ║\n", colors[color].c_str());
        printf("║ Number: %s   ║\n", numbers[number].c_str());
        reset();
        printf("╠═══════════════════╣\n");
        current_node = current_node->next;
        cont++;
    }
    printf("╚═══════════════════╝\n");
  
  return (--cont);
}


void puts_in_tree_color(std::array<tp_arvore, 5>& tree, deck e) {
  switch (e.color) {
    case 0:
      insere_no(&(tree[0]), e);
      break;
    case 1:
      insere_no(&(tree[1]), e);
      break;
    case 2:
      insere_no(&(tree[2]), e);
      break;
    case 3:
      insere_no(&(tree[3]), e);
      break;
    case 4:
      insere_no(&(tree[4]), e);
      break;
  }
}




int play_card(singly_list **list, stack *table, int position, std::array<tp_arvore, 5>& my_tree, deck *last_card) {
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
        printf("Invalid Index!\n");
        return 0;
    }
    
    return_top(table, &top_card);

    // Checks if selected card can be played
    if (current_node->info.number == top_card.number || current_node->info.color == top_card.color || current_node->info.number == 13 || current_node->info.number == 14) {
        if (prev_node == NULL) {
            *list = current_node->next;
        } else {
            prev_node->next = current_node->next;
        }

        *last_card = current_node->info;
        push(table, current_node->info);
        puts_in_tree_color(my_tree, current_node->info);
        free(current_node);
        current_node = NULL;
        return 1;
    }
  
    printf("Invalid card!\n\n");
    return 0;
}

void pit_card(stack *main, type_knot *player){
  // "Cava uma carta"
  deck card;
  pop(main, &card);
  insert_node(&player->info.cards, card);
  system("clear");
}


dict get_color(){  
  dict colors;
  colors[0] = "Red   ";
  colors[1] = "Blue  ";
  colors[2] = "Yellow";
  colors[3] = "Green ";
  colors[4] = "WOOOW ";

  return colors;
}

dict get_special(){
  dict special;
  for (int i = 0; i < 10; i++)
    special[i] = std::to_string(i) + "      ";
  
  special[10] = "Block  ";
  special[11] = "Reverse";
  special[12] = "CAVA 2!";
  special[13] = "Switch ";
  special[14] = "CAVA 4!";

  return special;
}

void change_color(deck *last_card, stack *table){
  int new_color = 0;
  printf("Choose a new color: \n");
  printf("red = 0\nblue = 1\nyellow = 2\ngreen = 3\n");

  if (!scanf("%d", &new_color)){
      printf("Invalid Input Detected!!!\n");
      printf("Color set to 0");
      new_color = 0;
  }

  if (new_color > 3 || new_color < 0){ 
      printf("Invalid Input Detected!!!\n");
      printf("Color set to 0");
      new_color = 0;
  }

  last_card->color = new_color;
  push(table, *last_card); 
  
}

void plus_two(type_dlist *players, stack *main) {
    type_knot *current_player = players->end;
    if (current_player == NULL) {
        return;
    }
    for (int i = 0; i < 2; i++) {
        deck card;
        pop(main, &card);
        insert_node(&current_player->info.cards, card);
    }
}


typedef struct {
  char name[60];
  int wins, cards;
} record;

void read_records(std::vector<record>& records) {
  FILE* data = fopen("uno_data.txt", "r");
  record list;

  while (fscanf(data, "%s %d %d", list.name, &list.wins, &list.cards) == 3) {
    records.push_back(list);
  }

  fclose(data);
}

void write_records(const std::vector<record>& records) {
  FILE* data = fopen("uno_data.txt", "w");

  for (const auto& rec : records) {
    fprintf(data, "%s %d %d\n", rec.name, rec.wins, rec.cards);
  }

  fclose(data);
}

int find_record_index(const std::vector<record>& records, const std::string& name) {
  for (size_t i = 0; i < records.size(); i++) {
    if (strcmp(records[i].name, name.c_str()) == 0) {
      return i;
    }
  }
  return -1;
}

void add_name(const std::string& name) {
  std::vector<record> records;
  read_records(records);

  int index = find_record_index(records, name);
  if (index != -1) {
    return;
  }

  record newrecord;
  strcpy(newrecord.name, name.c_str());
  newrecord.wins = 0;
  newrecord.cards = 0;

  records.push_back(newrecord);
  write_records(records);
}

void file_management(const std::string& name, int option) {
  add_name(name);
  std::vector<record> records;
  int index = find_record_index(records, name);

  if (index != -1) {
    if (option == 1) {
      records[index].cards++;
    } else {
      records[index].wins++;
    }
    write_records(records);
  }
}

inline void show_options(){
  printf("╔═════════════════════════╗\t╔═════════════════════════╗\n");
  printf("║ Cards Scheme:           ║\t║ Colors Scheme:          ║\n");
  printf("║ -> 0 ~ 9 = Normal Cards ║\t║                         ║\n");
  printf("║ -> 10 = Block Cards     ║\t║ -> 0 = Red              ║\n");
  printf("║ -> 11 = Reverse Cards   ║\t║ -> 1 = Blue             ║\n");
  printf("║ -> 12 = +2 Cards        ║\t║ -> 2 = Yellow           ║\n");
  printf("║ -> 13 = Switch Color    ║\t║ -> 3 = Green            ║\n");
  printf("║ -> 14 = +4 Cards        ║\t║ -> 4 = Special          ║\n");
  printf("╚═════════════════════════╝\t╚═════════════════════════╝\n");
  printf("╔══════════════════════════════════════════════════════╗\n");
  printf("║  ↩️ ↩️ ↩️  PRESS -1 AGAIN TO RETURN TO THE GAME  ↩️ ↩️ ↩️  ║\n");
  printf("╚══════════════════════════════════════════════════════╝\n");
  
}



void search_card(const std::array<tp_arvore, 5>& tree) {
  int number;
  int color;
  deck e;
  system("clear");
  while (true) {
    show_options();
    printf("Which number card do you want to look for?\n");
    scanf("%d", &number);
    if (number == -1){
      system("clear");
      break;
    }

    printf("Which color card do you want to look for?\n");
    scanf("%d", &color);
    e.number = number;
    e.color = color;
    
    switch (color) {
      case 0:
        if (busca_no(tree[0], e) != NULL) {
          printf("The card has already been played\n");
        } else {
          printf("The card has never been played\n");
        }
        break;
      
      case 1:
        if (busca_no(tree[1], e) != NULL) {
          printf("The card has already been played\n");
        } else {
          printf("The card has never been played\n");
        }
        break;
      
      case 2:
        if (busca_no(tree[2], e) != NULL) {
          printf("The card has already been played\n");
        } else {
          printf("The card has never been played\n");
        }
        break;
      
      case 3:
        if (busca_no(tree[3], e) != NULL) {
          printf("The card has already been played\n");
        } else {
          printf("The card has never been played\n");
        }
        break;
      
      case 4:
        if (busca_no(tree[4], e) != NULL) {
          printf("The card has already been played\n");
        } else {
          printf("The card has never been played\n");
        }
        break;
    }

    sleep(2);
    system("clear");
  }
}


void game_on(stack main) {
    // Player data
    int gaymers = 0;
    int position = -1;

    // Card data
    deck last_card;
    int max_cards;
    int reverse = -1;
    int block = 0;

    // Tree
    tp_arvore red, blue, yellow, green, special_tree;
  
    std::array<tp_arvore, 5> all_trees = {red, blue, yellow, green, special_tree};
  
    for (int i = 0; i < all_trees.size(); i++) {
      all_trees[i] = inicializa_arvore();  
    }  
    
    dict special, colors;
    special = get_special();
    colors = get_color();

    stack table;
    init_stack(&table);

    printf("How many people will play?  \n");
    scanf("%d", &gaymers);

    if (gaymers < 2){
      printf("Uno should be played by 2 or more people \n");
      printf("Number os players changed to 2 \n");
      gaymers = 2;
    } else if (gaymers > 4){
      printf("Too many people \n");
      printf("Number os players changed to 4 \n");
      gaymers = 4;
    }
  
    // Create a doubly-linked list
    type_dlist *players;
    players = start_dlist();
    init_players(players, gaymers, &main);
    
    // Make player's list circular
    players->end->next = players->start;
    players->start->previous = players->end;

    // Point to first player
    type_knot *current;
    current = players->start; 

    // Plays the game until we have a winner
    first_card(&main, &table);
    while(1) { // Main game loop
      
        system("clear");
      
        while (1){ // Secondary loop for drawing cards
          view_table(&table, special, colors);

          printf("\nTurn of player");
          printf(" %s\n\n", current->info.name.c_str());
          
          max_cards = view_hand(current->info.cards, special, colors);
          printf("Choose card id\n");
          
          if (!scanf("%d", &position)){
            printf("Invalid Input Detected!!!\n");
            printf("ABORTING\n");
            return;
          }

          if (position > max_cards){
            printf("invalid card position!\n");    
            continue;
          }
          
          // If pos == 0, draw a card
          if (position ==  0){
            pit_card(&main, current);
            continue; // Cavar até poder jogar
          } else if (position == -1){
            search_card(all_trees);
            continue;
            
          } 

          // In case the card cannot be played, repeat the turn
          if(!play_card(&current->info.cards, &table, position, all_trees, &last_card))
            continue;

          // Checks for special cards
          if (last_card.number == 10) block = 1;
          if (last_card.number == 11) reverse *= -1;  
          
          if (last_card.number == 12){
            if (reverse == -1){
              pit_card(&main, current->next);
              pit_card(&main, current->next);
            } else {              
              pit_card(&main, current->previous);
              pit_card(&main, current->previous);
            }
          } 
          
          if (last_card.number == 13) change_color(&last_card, &table);  
          if (last_card.number == 14){
            if (reverse == -1){
              change_color(&last_card, &table); 
              for(int i = 0; i < 4; i++) pit_card(&main, current->next);              
            } else {
              change_color(&last_card, &table); 
              for(int i = 0; i < 4; i++) pit_card(&main, current->previous);              
            }
          } 
          
          break;          
        }
        file_management(current->info.name, 1);
      
        // Checks for winner
        if (current->info.cards == NULL){
          printf("Player %s ", current->info.name.c_str());
          printf("wins!");
          file_management(current->info.name, 2);
          break;
        }

        if (block == 1 && reverse == -1) {
          current = current->next->next;
          block = 0;
        } else if (block == 1 && reverse == 1){
          current = current->previous->previous;
          block = 0;
        } else if (block == 0 && reverse == 1){
          current = current->previous;
        } else if (block == 0 && reverse == -1){
          current = current->next;
        }
    }
    printf("\n\n\t  WOOW!\n\tCongrats!");
}

#endif