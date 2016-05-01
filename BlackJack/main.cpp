#ifdef __cplusplus
    #include <cstdlib>
#else
    #include <stdlib.h>
#endif

#include <iostream>
#include <vector>
#include <time.h>

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

#include "Card.h"

//Engine variables
SDL_Surface *screen=NULL;
SDL_Event event;

//Game variables
SDL_Surface *sCard;
std::vector<Card> cards;

//Engine methods
void Load();
void Logic();
void DrawScreen();
void Quit();

int main ( int argc, char** argv )
{

    Load();

    while(1){

        SDL_PollEvent(&event);

        if(event.type == SDL_QUIT){
            break;
        }

        Logic();
        DrawScreen();

    }

    Quit();

    return 0;
}

void Load(){

    SDL_Init(SDL_INIT_EVERYTHING);
    IMG_Init(IMG_INIT_PNG);

    srand(static_cast<unsigned int>((time(0))));

    screen = SDL_SetVideoMode(600,600,32,SDL_HWSURFACE);

    sCard = IMG_Load("cardz.png");

    for(int i=0; i<13; i++){
        cards.push_back(Card(i));
    }

}

bool clicking=false;
void Logic(){

    if(event.type == SDL_MOUSEBUTTONDOWN){
        clicking = true;
    }else if(event.type == SDL_MOUSEBUTTONUP){
        clicking = false;
    }

    for(int i=0; i<cards.size(); i++){
        if(clicking){
            if(cards[i].Intersects(event.motion.x, event.motion.y)){
                cards[i].pCard.x += event.motion.xrel;
                cards[i].pCard.y += event.motion.yrel;
            }
        }
    }

}

void DrawScreen(){

    SDL_FillRect(screen, NULL, 0);

    for(int i=0; i<cards.size(); i++){
        SDL_BlitSurface(sCard, &cards[i].mask, screen, &cards[i].pCard);
    }

    SDL_Flip(screen);

}

void Quit(){
    IMG_Quit();
    SDL_FreeSurface(screen);
    SDL_Quit();
}
