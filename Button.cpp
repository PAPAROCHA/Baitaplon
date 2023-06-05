#include"Button.h"
#include<SDL.h>
#include<iostream>
#include"SDL_utils.h"

Button::Button(){
    posx = 0;
    posy = 0;
}

bool Button::Checkinside(SDL_Event *e){
    if ( e-> type == SDL_MOUSEBUTTONDOWN || e->type == SDL_MOUSEBUTTONUP ){
        int x,y;
        SDL_GetMouseState(&x,&y);
        bool ans = true;
        if ( x < posx || x + box_Width > posx || y < posy || y > posy + box_Height ) { ans = false; }
        return true;
    }
    return false;
}

void Button::Setpos(int x, int y){
    posx = x;
    posy = y;
}

