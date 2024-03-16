//
// Created by Stanislav on 09.03.2024.
//

#ifndef UNTITLED35_HAND_H
#define UNTITLED35_HAND_H
#include "Card.h"
#define Hand() hand_init()

typedef struct hand
{
    Card ** _cards;
    int _points;
    int _count;
    bool (*take_a_card) (struct hand* hand, Card* card  );
    void (*show ) (struct hand* hand );
    void (*clear ) (struct hand* hand );
    int (*get_points ) (struct hand* hand );
} Hand;

Hand* (hand_init)();
#endif //UNTITLED35_HAND_H

