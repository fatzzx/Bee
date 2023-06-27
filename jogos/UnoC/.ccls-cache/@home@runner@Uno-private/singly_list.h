#ifndef SINGLY_LIST.H
#define SINGLY_LIST.H
#include <iostream>
using namespace std;

typedef int item;

typedef struct node {
  item info;
  struct node *next;
} singly_list;

// Returns a memory adress to a slingly linked list pointing to NULL
singly_list *init_singly() { return NULL; }

// Receives the value stored in a pointer (as a copy)
// and checks if it points to NULL
int is_empty_singly(singly_list *list) {
  if (list == NULL)
    return 1;
  return 0;
}

// Allocs the structure's size in memory
singly_list *alloc_memory() {
  return (singly_list *)malloc(sizeof(singly_list));
}

int insert_node(singly_list **list, item new_data) {
  singly_list *new_node, *current_node;
  new_node = alloc_memory();

  // If it points to NULL, no memory was allocated
  if (new_node == NULL)
    return 0;

  // Set values for the new node
  new_node->info = new_data;
  new_node->next = NULL;

  // Sets the last item on the list, to point at the new one
  if (is_empty_singly(*list)) {
    *list = new_node;  // If the first pointer is empty, it points to the new_node
  } else {
    current_node = *list;
    while (current_node->next != NULL) {
      current_node = current_node->next;
    }
    current_node->next = new_node;
  }

  return 1;
}

int ordered_insert(singly_list **list, item new_data) {
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

  while (current_node != NULL && new_data > current_node->info) {
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

int remove_node(singly_list **list, item to_remove) {
  singly_list *previous_node, *current_node;
  previous_node = init_singly();
  current_node = *list;

  // While we don't find the element...
  while (current_node != NULL && current_node->info != to_remove) {
    previous_node = current_node;
    current_node = current_node->next;
  }

  if (current_node == NULL)
    return 0;                  // Element not found
  if (previous_node == NULL) { // Removed the first element
    *list =
        current_node->next; // Make the primary pointer point to the new element
  } else {
    previous_node->next =
        current_node->next; // Make the last node point to the next
  }

  // Free the memory on removed node
  free(current_node);

  // Avoid messing up pointers
  current_node = NULL;
  return 1;
}

void print_singly(singly_list *list) {
  singly_list *current_node;
  current_node = list;
  while (current_node != NULL) {
    printf("%i \n", current_node->info);
    current_node = current_node->next;
  }

 printf("\n");
}

singly_list *search_singly(singly_list *list, item to_find) {
  singly_list *current_node;
  current_node = list;

  // While we don't find it...
  while (current_node->next != NULL && current_node->info != to_find) {
    current_node = current_node->next;
  }

  // Either returns the memory adress or NULL
  return current_node->next;
}


int size_singly(singly_list *list) {
  if (list == NULL) return 0;
  
  int counter = 0;
  singly_list *current_node;
  current_node = list;

  while (current_node != NULL){
    counter++;
    current_node = current_node->next;
  }
  return counter;
}


#endif