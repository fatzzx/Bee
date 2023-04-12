#ifndef BARALHO_H
#define BARALHO_H
#include <stdio.h>
#include "stack.h"
#include <stdlib.h>
#include <time.h>


// Normal Cards
void create_cards(stack *my_deck, int cor)
{
    deck cards[TAM_MAX_COLOR];
    cards[0].number = 0;
    cards[0].color = cor;

    for (int i = 1; i <= 9; i++)
    {
        cards[i].number = i;
        cards[i].color = cor;
    }

    for (int i = 1; i <= 9; i++)
    {
        cards[i + 9].number = i;
        cards[i + 9].color = cor;
    }
    // Reverse
    for (int i = 1; i <= 2; i++)
    {
        cards[i + 18].number = 10;
        cards[i + 18].color = cor;
    }
    // Block
    for (int i = 1; i <= 2; i++)
    {
        cards[i + 20].number = 11;
        cards[i + 20].color = cor;
    }
    // +2
    for (int i = 1; i <= 2; i++)
    {
        cards[i + 22].number = 12;
        cards[i + 22].color = cor;
    }

    // Push color to stack
    for (int i = 0; i < TAM_MAX_COLOR; i++)
    {
        push(my_deck, cards[i]);
    }
}

// Special Cards
void create_special(stack *my_deck)
{
    deck cards[8];

    for (int i = 0; i <= 3; i++)
    {
        cards[i].number = 13;
        cards[i].color = 4;
    }

    for (int i = 4; i < 8; i++)
    {
        cards[i].number = 14;
        cards[i].color = 4;
    }

    // Pushing Special Cards to Main Stack
    for (int i = 0; i < 8; i++)
    {
        push(my_deck, cards[i]);
    }
}

void randomize_color_deck(stack *piles[], int n)
{ // stack*color
    for (int i = 0; i < n; i++)
    {
        stack *color = piles[i];
        stack aux1, aux2, aux3, aux4;
        deck card;

        stack *all_stacks[4] = {&aux1, &aux2, &aux3, &aux4};
        init_mult_stacks(all_stacks, 4);

        srand(time(NULL));

        while (!is_hollow(color))
        {
            int random_number = rand() % 4;
            switch (random_number)
            {
            case 0:
                pop(color, &card);
                push(&aux1, card);
                break;

            case 1:
                pop(color, &card);
                push(&aux2, card);
                break;

            case 2:
                pop(color, &card);
                push(&aux3, card);
                break;

            case 3:
                pop(color, &card);
                push(&aux4, card);
                break;
            }
        }
        stack_to_stack(&aux1, color);
        stack_to_stack(&aux2, color);
        stack_to_stack(&aux3, color);
        stack_to_stack(&aux4, color);
    }
}

void random_decks(stack *red, stack *blue, stack *green, stack *yellow, stack *special, stack *maindeck)
{
    deck card;
    srand(time(NULL));

    while (!is_hollow(red) && !is_hollow(blue) && !is_hollow(yellow) && !is_hollow(green) && !is_hollow(special))
    {

        int random_number = rand() % 5;
        switch (random_number)
        {
        case 0:
            if (!is_hollow(red))
            {
                pop(red, &card);
                push(maindeck, card);
            }
            break;

        case 1:
            if (!is_hollow(blue))
            {
                pop(blue, &card);
                push(maindeck, card);
            }
            break;

        case 2:
            if (!is_hollow(green))
            {
                pop(green, &card);
                push(maindeck, card);
            }
            break;

        case 3:
            if (!is_hollow(yellow))
            {
                pop(yellow, &card);
                push(maindeck, card);
            }
            break;

        case 4:
            if (!is_hollow(special))
            {
                pop(special, &card);
                push(maindeck, card);
            }
            break;
        }
    }

    while (!is_hollow(red))
    {
        pop(red, &card);
        push(maindeck, card);
    }
    while (!is_hollow(blue))
    {
        pop(blue, &card);
        push(maindeck, card);
    }
    while (!is_hollow(green))
    {
        pop(green, &card);
        push(maindeck, card);
    }
    while (!is_hollow(yellow))
    {
        pop(yellow, &card);
        push(maindeck, card);
    }
    while (!is_hollow(special))
    {
        pop(special, &card);
        push(maindeck, card);
    }
}

void getsPlayerName(int numOfPlayers, char players[][60])
{
    for (int i = 0; i < numOfPlayers; i++)
    {
        printf("Qual o nome do jogador %d\n", i + 1);
        scanf(" %[^\n]s", players[i]);
    }
    for (int i = 0; i < numOfPlayers; i++)
    {
        printf("Bem vindo jogador %s\n", players[i]);
    }
}

#endif