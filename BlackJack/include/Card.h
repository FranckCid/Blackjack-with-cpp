#ifndef CARD_H
#define CARD_H

#include <SDL/SDL.h>

class Card
{
    public:
        static const int CARD_WIDTH, CARD_HEIGHT;
        SDL_Surface sCard;
        SDL_Rect pCard;
        Card();
    protected:
    private:
};

#endif // CARD_H
