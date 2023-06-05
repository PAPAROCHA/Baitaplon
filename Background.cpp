#include<SDL.h>
#include<SDL_image.h>
#include"Background.h"
#include"SDL_utils.h"

void bkupdate(SDL_Renderer* amme, int &time){
    if ( time > 2000 ) time = 0;
    SDL_Texture *background = IMG_LoadTexture(amme, "background.jpg");
    SDL_Rect player, player1;
    SDL_QueryTexture(background,NULL, NULL, &player.w, &player.h);
    SDL_QueryTexture(background,NULL, NULL, &player1.w, &player1.h);
    player.x = time;
    player.y = 0;
    player1.x = 0;
    player1.y = 0;
    player1.h = SCREEN_HEIGHT;
    SDL_RenderCopy(amme, background, &player, &player1);
}
