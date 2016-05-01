#ifdef __cplusplus
    #include <cstdlib>
#else
    #include <stdlib.h>
#endif

#include <iostream>

#include "Card.h"

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

//Engine variables
SDL_Surface *screen=NULL;
SDL_Event event;

//Game variables
SDL_Surface *actualCard=NULL;
SDL_Rect cardPosition;

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

    screen = SDL_SetVideoMode(600,600,32,SDL_HWSURFACE);

    cardPosition = {0, 0, Card::CARD_WIDTH, Card::CARD_HEIGHT};

    if(actualCard = IMG_Load("cardz.png")){

    }else{
        std::cout << "ASD";
    }

}

void Logic(){

}

void DrawScreen(){

    SDL_BlitSurface(actualCard, &cardPosition, screen, &cardPosition);

    SDL_Flip(screen);

}

void Quit(){
    IMG_Quit();
    SDL_FreeSurface(screen);
    SDL_Quit();
}
