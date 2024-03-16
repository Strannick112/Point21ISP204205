//
// Created by Stanislav on 09.03.2024.
//

#include <malloc.h>
#include <stdio.h>
#include "Hand.h"

bool (hand_take_a_card) (struct hand* hand, Card* card  );
void (hand_show ) (struct hand* hand );
void (hand_clear ) (struct hand* hand );
int (hand_get_points ) (struct hand* hand );

Hand* (hand_init)() {
    Hand* hand = malloc(sizeof(Hand));
    hand->_cards = malloc(0);
    hand->_count = 0;
    hand->_points = 0;
    hand->take_a_card = hand_take_a_card;
    hand->show = hand_show;
    hand->clear = hand_clear;
    hand->get_points = hand_get_points;
    return hand;
}

bool hand_take_a_card(struct hand* hand, Card* card) {
    if(hand->_points == 0 && hand->_count != 0)
        return false;

    hand->_count++;
    hand->_cards = realloc(
        hand->_cards,
        sizeof(Card*) * hand->_count
    );
    if(hand->_cards == NULL){
        perror("Не хватает оперативной памяти!\n");
        exit(-1);
    }
    hand->_cards[hand->_count - 1] = card;
    hand->_points += card->get_points(card);

    if(hand->_points > 21) {
        hand->_points = 0;
        return false;
    }
    return true;
}

void hand_show (struct hand* hand ){
    for(int i = 0; i < hand->_count; i++){
        hand->_cards[i]->show(hand->_cards[i]);
    }
    printf("Points: %d\n", hand->_points);
    return;
}

void hand_clear (struct hand* hand ){
    free(hand->_cards);
    hand->_points = 0;
    hand->_count = 0;
    return;
}

int hand_get_points (struct hand* hand ){
    return hand->_points;
}
