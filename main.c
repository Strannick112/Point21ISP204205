#include <stdio.h>
#include "game/Card.h"

int main() {

    Card* card = Card(masts[0], &rangs[0]);

    card->show(card);

    return 0;
}
