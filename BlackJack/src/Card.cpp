#include "Card.h"

#include <SDL/SDL.h>

const int Card::CARD_WIDTH = 80, Card::CARD_HEIGHT = 120;

Card::Card(int c)
{
    pCard = {c*CARD_WIDTH, 0, 0, 0};
    mask = {c*CARD_WIDTH-c, 0, CARD_WIDTH, CARD_HEIGHT};
}

bool Card::Intersects(int x, int y){
    if(x > pCard.x && y > pCard.y &&
     x < pCard.x + pCard.w && y < pCard.y + pCard.h){
        return true;
     }
    return false;
}
