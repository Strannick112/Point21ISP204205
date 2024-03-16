//
// Created by Stanislav on 02.03.2024.
//

#include "Deck.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "Mast.h"
#include "Rang.h"


Card* get_card_deck (struct Deck* deck) {
    if (deck->_index >= 36) {
        printf ("ERROR\n");
        exit;
    }
    return deck->_deck[deck->_index++];
}

void sort_deck (Deck * deck) {
    srand(time(NULL));
    Card* buff;
    deck->_index = 0;
    for (int i = 0; i < 30; i++) {
        int rnd = rand() % 36;
        buff = deck->_deck[rnd];
        int newRnd = rand() % 36;
        deck->_deck[rnd] = deck->_deck[newRnd];
        deck->_deck[newRnd] = buff;
    }
}
Deck* (deck_init)() {
    Deck *deck = malloc(sizeof(Deck));
    deck->_index = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 9; j++)
            deck->_deck[i * 9 + j] = Card(masts[i], &rangs[j]);
    }
    deck->get_card = get_card_deck;
    deck->sort = sort_deck;
    deck->sort(deck);
    return deck;
}