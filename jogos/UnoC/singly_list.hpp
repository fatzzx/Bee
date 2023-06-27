#ifndef SINGLY_LIST_TEST_H
#define SINGLY_LIST_TEST_H
#include <stdio.h>
#include "dll.hpp"

using namespace std;


typedef struct node {
  deck info;
  struct node *next;
} singly_list;

singly_list *init_singly() {
  return NULL;
}

int is_empty_singly(singly_list *list) {
  if (list == NULL)
    return 1;
  return 0;
}

singly_list *alloc_memory() {
  return (singly_list *)malloc(sizeof(singly_list));
}

int insert_node(singly_list **list, deck new_data) {
  singly_list *new_node, *current_node;
  new_node = alloc_memory();

  if (new_node == NULL)
    return 0;

  new_node->info = new_data;
  new_node->next = NULL;

  if (is_empty_singly(*list)) {
    *list = new_node;
  } else {
    current_node = *list;
    while (current_node->next != NULL) {
      current_node = current_node->next;
    }
    current_node->next = new_node;
  }

  return 1;
}

int ordered_insert(singly_list **list, deck new_data) {
  singly_list *previous_node, *current_node, *new_node;

  new_node = alloc_memory();
  previous_node = init_singly();
  current_node = *list;

  if (new_node == NULL)
    return 0;

  new_node->info = new_data;
  new_node->next = NULL;

  if (current_node == NULL) {
    *list = new_node;
    return 1;
  }

  while (current_node != NULL && new_data.number > current_node->info.number) {
    previous_node = current_node;
    current_node = current_node->next;
  }

  if (previous_node == NULL){
    *list = new_node;
  } else {
    previous_node->next = new_node;
  }

  new_node->next = current_node;
  return 1;
}

int remove_node(singly_list **list, deck to_remove) {
  singly_list *previous_node, *current_node;
  previous_node = init_singly();
  current_node = *list;

  while (current_node != NULL && current_node->info.number != to_remove.number && current_node->info.color != to_remove.color) {
    previous_node = current_node;
    current_node = current_node->next;
  }

  if (current_node == NULL)
    return 0;
  if (previous_node == NULL) {
    *list = current_node->next;
  } else {
    previous_node->next = current_node->next;
  }

  free(current_node);
  current_node = NULL;
  return 1;
}

void print_singly(singly_list *list) {
  singly_list *current_node;
  current_node = list;
  while (current_node != NULL) {
    printf("Number: %d, Color: %d\n", current_node->info.number, current_node->info.color);
    current_node = current_node->next;
  }
}

singly_list *search_singly(singly_list *list, deck to_find) {
  singly_list *current_node;
  current_node = list;

  while (current_node != NULL && (current_node->info.number != to_find.number || current_node->info.color != to_find.color)) {
    current_node = current_node->next;
  }

  return current_node;
}

int size_singly(singly_list *list) {
  if (list == NULL)
    return 0;

  int counter = 0;
  singly_list *current_node;
  current_node = list;

  while (current_node != NULL) {
    counter++;
    current_node = current_node->next;
  }
  return counter;
}

#endif