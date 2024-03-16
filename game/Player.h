//
// Created by Stanislav on 16.03.2024.
//

#ifndef UNTITLED35_PLAYER_H
#define UNTITLED35_PLAYER_H

#include "Hand.h"
#define Player(name) player_init(name)

typedef struct Player{
    char *name;
    int count_of_wins;
    Hand* hand;

    bool (*get_card)(struct Player* player, Card* card);
    void (*show ) (struct Player* player );
    void (*clear ) (struct Player* player );
    int (*get_points ) (struct Player* player );

} Player;

Player* player_init(char* name);
#endif //UNTITLED35_PLAYER_H
