//
// Created by Stanislav on 16.03.2024.
//

#include <malloc.h>
#include <stdio.h>
#include "Player.h"

bool player_get_card(struct Player* player, Card* card);
void player_show (struct Player* player);
void player_clear (struct Player* player);
int player_get_points (struct Player* player);

Player* player_init(char* name){
    Player* player = malloc(sizeof(Player));
    player->hand = Hand();
    player->name = name;
    player->count_of_wins = 0;

    player->get_card = player_get_card;
    player->show = player_show;
    player->clear = player_clear;
    player->get_points = player_get_points;

    return player;
}

bool player_get_card(struct Player* player, Card* card){
    return player->hand->take_a_card(player->hand, card);
}

void player_show (struct Player* player ){
    printf("Player %s:\n", player->name);
    return player->hand->show(player->hand);
}

void player_clear (struct Player* player ){
    return player->hand->clear(player->hand);
}

int player_get_points (struct Player* player ){
    return player->hand->get_points(player->hand);
}
