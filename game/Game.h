//
// Created by Stanislav on 16.03.2024.
//

#ifndef UNTITLED35_GAME_H
#define UNTITLED35_GAME_H

#include "Player.h"
#include "Deck.h"
#define Game(names, player_count) game_init(names, player_count)

typedef struct Game{
    Player** players;
    int _player_count;
    Deck* _deck;

    void (*start)(struct Game* game);
    void (*play)(struct Game* game);
    void (*_move)(Deck* deck, Player* player);
    void (*show_winners)(struct Game* game);
} Game;

Game* game_init(char names[5][6], int player_count);

#endif //UNTITLED35_GAME_H
