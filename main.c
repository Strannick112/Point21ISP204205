#include <stdio.h>
#include <stdlib.h>
#include "game/Card.h"
#include "game/Deck.h"
#include "game/Hand.h"
#include "game/Game.h"

int main() {
//    Deck* deck = Deck();
//    Hand* hand = Hand();
//    hand->show(hand);
//    printf("%d\n", hand->get_points(hand));
//    hand->take_a_card(hand, deck->get_card(deck));
//    hand->show(hand);
//    hand->clear(hand);
//    hand->show(hand);
//    system("chcp 65001");
    char names[5][6] = {
        "Igor", "Masha", "Egor", "Stas", "Lila"
    };
    Game* game = Game(names, 5);
    game->start(game);
    game->play(game);
    game->show_winners(game);
    return 0;
}
