//
// Created by Stanislav on 02.03.2024.
//

#include "Card.h"
#include <stdlib.h>
#include <stdio.h>

int card_get_points(struct Card* card);
void card_show(struct Card* card);

Card* card_init(Mast mast, const Rang* rang){
    Card* card = malloc(sizeof(Card));
    card->mast = mast;
    card->rang = rang;

    card->get_points = card_get_points;
    card->show = card_show;
    return card;
}

int card_get_points(struct Card* card){
    return card->rang->points;
}

void card_show(struct Card* card){
    printf("--------\n");
    printf("|%c%c    |\n", card->rang->symbol, card->mast);
    printf("|      |\n");
    printf("|      |\n");
    printf("|    %c%c|\n", card->mast, card->rang->symbol);
    printf("--------\n");
}
