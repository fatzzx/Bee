#include "uno.hpp"
#include "stack.hpp"
#include "game.hpp"
#include "dll.hpp"
#include "singly_listtest.hpp"

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
  stack red, blue, yellow, green, main, special;
  stack *all_stacks[6] = {&red, &blue, &yellow, &green, &main, &special};
  stack *main_deck[1] = {&main};
  stack table;
  init_stack(&table);
  singly_list *player1 = init_singly(), *player2 = init_singly(), *player3 = init_singly(), *player4 = init_singly();





  
  init_mult_stacks(all_stacks, 6);
  
  create_cards(&red, 0);
  create_cards(&blue, 1);
  create_cards(&yellow, 2);
  create_cards(&green, 3);
  create_special(&special, 4);

  randomize_color_deck(all_stacks, 5);
  
  random_decks(&red, &blue, &green, &yellow, &special, &main);

  randomize_color_deck(main_deck, 1);
  randomize_color_deck(main_deck, 1);
  randomize_color_deck(main_deck, 1);
  //print_stack(main);
  //distribute_cards(main_deck[0], &player1, &player2, &player3, &player4);
  
  test_game_on(&main, &table, &player1, &player2, &player3, &player4);


  //printf("Game start\n");
  //game_on(main);
  
  /*
  print_cards(main);
  
  Self-explanatory named function.
  This function needs windows.h lib! 
  This lib's include statement is commented in "stack.hpp"
  We commented it out due to the linux environment
  */

  
  
  return 0;
}