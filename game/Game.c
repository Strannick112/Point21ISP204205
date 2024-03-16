//
// Created by Stanislav on 16.03.2024.
//

#include <malloc.h>
#include <stdio.h>
#include "Game.h"

void game_start(struct Game* game);
void game_play(struct Game* game);
void game__move(Deck* deck, Player* player);
void game_show_winners(struct Game* game);

Game* game_init(char names[5][6], int player_count){
    Game* game = malloc(sizeof(Game));
    game->players = calloc(player_count, sizeof(Player*));
    for(int i = 0; i < player_count; i++){
        game->players[i] = Player(names[i]);
    }
    game->_player_count = player_count;
    game->_deck = Deck();

    game->start = game_start;
    game->play = game_play;
    game->_move = game__move;
    game->show_winners = game_show_winners;

    return game;
}

void game_start(struct Game* game){
    printf("Start of the game...\n");
    for(int i = 0; i < game->_player_count; i++){
        game->players[i]->get_card(game->players[i], game->_deck->get_card(game->_deck));
    }
    printf("Started.\n");
}

void game_play(struct Game* game){
    for(int i = 0; i < game->_player_count; i++){
        game->_move(game->_deck, game->players[i]);
    }
}

void game__move(Deck* deck, Player* player){
    while(true){
        player->show(player);
        char answer = 'n';
        printf("Would you take one more? y/N");
        scanf("%c", &answer);
        fflush(stdin);
        if(answer != 'y')
            break;
        if(!player->get_card(player, deck->get_card(deck))){
            printf("Player %s is burned\n", player->name);
            player->show(player);
            break;
        }

    }
}

void game_show_winners(struct Game* game){
    Player **players = game->players;
    int max_points = players[0]->get_points(game->players[0]);
    for(int i = 1; i < game->_player_count; i++){
        int points = players[i]->get_points(players[i]);
        if(max_points < points){
            max_points = points;
        }
    }

    if(max_points == 0){
        printf("Everybody in the fire\n");
        return;
    }

    for(int i = 0; i < game->_player_count; i++){
        int points = players[i]->get_points(players[i]);
        if(max_points == points){
            printf("Player %s is winner with score %d.\n", players[i]->name, points);
            players[i]->count_of_wins++;
        }
    }
}