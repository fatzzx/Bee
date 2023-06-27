#ifndef DLL_H
#define DLL_H

// Lib for doubly-Linked-List + player struct
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>

#include "stack.hpp"
#include "singly_list.hpp"


typedef struct {
    singly_list *cards;
    std::string name;
} player;

typedef struct type_knot_ass {
    player info;
    struct type_knot_ass *previous;
    struct type_knot_ass *next;
} type_knot;

typedef struct {
    type_knot *start, *end;
} type_dlist;

type_dlist *start_dlist() {
    type_dlist *list = (type_dlist*) malloc (sizeof(type_dlist));
    list->start = list->end = NULL;
    return list;
}

type_knot *alloc() {
    type_knot *pointer;
    pointer = (type_knot*) malloc (sizeof(type_knot));
    return pointer;
}

int insert_dlist_at_end(type_dlist *list, player item) {
    type_knot *fresh;
    fresh = alloc();

    if (!fresh) return 0;

    fresh->info = item;

    if ((list->start == NULL) && (list->end == NULL)) {
        fresh->next = fresh->previous = NULL;
        list->start = list->end = fresh;
    }
    else {
        fresh->next = NULL;
        fresh->previous = list->end;
        list->end->next = fresh;
        list->end = fresh;
    }
    return 1;
}

void print_dlist(type_dlist *list, int sequence) {
    type_knot *current;
    switch(sequence) {
        case 1:
            current = list->start;
            while (current != NULL) {
                printf("%s ", current->info.name.c_str());
                current = current->next;
            }
            break;
        case 2:
            current = list->end;
            while (current != NULL) {
                printf("%s ", current->info.name.c_str());
                current = current->previous;
            }
            break;
        default:
            printf("Invalid Code\n");
    }
    printf("\n");
}

int remove_dlist(type_dlist *list, player item) {
    type_knot *current;
    current = list->start;

    while ((current != NULL) && (current->info.name != item.name)) {
        current = current->next;
    }

    if (current == NULL) return 0;

    if (list->start == list->end) {
        list->start = list->end = NULL;
    }
    else if (list->start == current) {
        list->start = current->next;
        current->next->previous = NULL;
    }
    else if (list->end == current) {
        list->end = current->previous;
        current->previous->next = NULL;
    }
    else {
        current->next->previous = current->previous;
        current->previous->next = current->next;
    }

    free(current);
    current = NULL;
    return 1;
}

type_knot* search_dll(type_dlist *list, player item) {
    type_knot *current;
    current = list->start;

    while ((current != NULL) && (current->info.name != item.name)) {
        current = current->next;
    }

    return current;
}

type_dlist* destroy_dlist(type_dlist *list) {
    type_knot *current;
    current = list->start;

    while (current != NULL) {
        list->start = current->next;
        free(current);
        current = list->start;
    }
    free(list);
    return NULL;
}

#endif
