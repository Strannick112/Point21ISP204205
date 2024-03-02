//
// Created by Stanislav on 02.03.2024.
//

#include "Deck.h"
#include <stdlib.h>

//Card* deck_get_card(Deck *_deck){
//    _deck->_index++;
//    return _deck->card;
//}

Deck* (deck_init)(){
    Deck* deck = malloc(sizeof(Deck));
    deck->_index = 0;
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 9; j++)
            deck->_deck[i * 9 + j] = Card(masts[i], &rangs[j]);
    }

Card* get_card (struct Deck* Deck) {
        if (deck->_index >= 36) {
            printf ("ERROR\n");
            exit;
        }
        return deck->_deck[deck->_index++];
    }
//    _deck->get_card = deck_get_card;
//    _deck->sort = deck_sort;
    return deck;
}
