#include "dll.hpp"
#include "game.hpp"
#include "singly_list.hpp"
#include "stack.hpp"
#include "uno.hpp"
#include "colorfunc.hpp"
#include <time.h>

/* Color scheme:
    red = 0
    blue = 1
    yellow = 2
    green = 3

    Special Cards:
    black = 4 (switch color && +4)

  Cards Scheme:
    0 ~ 9 = Normal Cards
    10 = Block Cards (@)
    11 = Reverse Cards (%)
    12 = +2 Cards (+2)
    13 = Switch Color (SC)
    14 = +4 && Switch Color Card (+4 SC)
*/



int main() {
  int shuffle=0;
  stack red, blue, yellow, green, main_deck, special;
  stack *all_stacks[6] = {&red, &blue, &yellow, &green, &main_deck, &special};
  stack *deck_pointer[1] = {&main_deck};
  stack table; 

  srand(time(NULL));
  init_mult_stacks(all_stacks, 6);

  create_cards(&red, 0);
  create_cards(&blue, 1);
  create_cards(&yellow, 2);
  create_cards(&green, 3);
  create_special(&special, 4);
  randomize_color_deck(all_stacks, 5); 

  random_decks(&red, &blue, &green, &yellow, &special, &main_deck);

  while(shuffle==0) shuffle=rand()%60;

  for(int i=0; i< shuffle; i++) randomize_color_deck(deck_pointer, 1);
  printf("Game start\n");
  game_on(main_deck);

  return 0;
}