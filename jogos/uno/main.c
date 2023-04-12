//Autores -> Felipe Farias, Breno Moreira, Leonardo Andrade, Gustavo Cruz, Luca Breda
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "uno.h"
#include "stack.h"

/* Color scheme:
  red = 0
  blue = 1
  yellow = 2
  green = 3

  Special Cards:
  black = 4 (switch color && +4)
*/

/*
Cards Scheme:
  0 ~ 9 = Normal Cards
  10 = Block Cards (@)
  11 = Reverse Cards (%)
  12 =  +2 Cards (+2)
  13 = Switch Color (SC)
  14 = +4 && Switch Color Card (+4 SC)
*/

int main()
{

  printf("Deu Certo! \n");
  stack red, blue, yellow, green, main, special;

  stack *all_stacks[6] = {&red, &blue, &yellow, &green, &main, &special};
  stack *main_deck[1] = {&main};
  int numOfPlayers;
  printf("Qual o numero de jogadores\n");
  scanf("%d", &numOfPlayers);
  char players[numOfPlayers][60];
  getsPlayerName(numOfPlayers, players);

  init_mult_stacks(all_stacks, 6);

  create_cards(&red, 0);
  create_cards(&blue, 1);
  create_cards(&yellow, 2);
  create_cards(&green, 3);
  create_special(&special);
  print_stack(special);

  randomize_color_deck(all_stacks, 5);
  // randomize_color_deck(&red);
  // randomize_color_deck(&blue);
  // randomize_color_deck(&green);
  // randomize_color_deck(&yellow);
  // randomize_color_deck(&special);

  random_decks(&red, &blue, &green, &yellow, &special, &main);

  randomize_color_deck(main_deck, 1);
  randomize_color_deck(main_deck, 1);
  randomize_color_deck(main_deck, 1);
  print_stack(main);

  print_colorful_stack_in_cards_style(main);

  // Self explanatory named function.
  // This function needs windows.h lib!
  return 0;
}