#ifndef COLORFUNC_H
#define COLORFUNC_H
#include <stdio.h>
#include "game.hpp"

void red () {
  printf("\033[1;31m");
}

void yellow () {
  printf("\033[1;33m");
}

void green () {
  printf("\033[0;32m");
}

void blue () {
  printf("\033[0;34m");
}

void special () {
  printf("\033[0;35m");
}


void reset () {
  printf("\033[0m");
}



#endif