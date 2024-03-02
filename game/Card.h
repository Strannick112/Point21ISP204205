//
// Created by Stanislav on 02.03.2024.
//

#ifndef UNTITLED35_CARD_H
#define UNTITLED35_CARD_H
#include "Rang.h"
#include "Mast.h"
#define Card(mast, rang) card_init(mast, rang)

typedef struct Card{
    Mast mast;
    const Rang* rang;

    int (*get_points)(struct Card* card);
    void (*show)(struct Card* card);
} Card;

Card* card_init(Mast mast, const Rang* rang);

#endif //UNTITLED35_CARD_H
