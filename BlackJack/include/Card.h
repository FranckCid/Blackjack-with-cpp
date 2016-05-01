#ifndef CARD_H
#define CARD_H

#include <SDL/SDL.h>

class Card
{
    public:
        static const int CARD_WIDTH, CARD_HEIGHT;
        SDL_Rect pCard, mask;
        Card(int c);
        bool Intersects(int x, int y);
    protected:
    private:
};

#endif // CARD_H
