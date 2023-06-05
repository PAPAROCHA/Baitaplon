#include<SDL.h>
#include<SDL_image.h>
#include"SDL_utils.h"

#include<iostream>
#include"Threater.h"

Threater::Threater(int t){
    posx = 0;
    posy = 0;
    Width = 0;
    Height = 0;
    speed = 20;
    type = t;
    if( type == bird ){
        posx = random(1500,2000) + SCREEN_WIDTH;
        posy = birdy;
    }
    else if ( type == cactus ){
        posx = random(700,1200) + SCREEN_WIDTH;
        posy = ground;
    }
}

void Threater::free(){
    posx = 0;
    posy =0;
    Width = 0;
    Height = 0;
    speed = 0;
    type = 0;
    threater = nullptr;
}
void Threater::Update(SDL_Renderer* amme)
{
    if ( type == 0 ){ threater = loadTexture("cactus.jpg",amme);}
    else if ( type == 1 ){ threater = loadTexture("bird.jpg",amme);}
    SDL_Rect player;
    SDL_QueryTexture(threater,NULL, NULL, &player.w, &player.h);
    player.x = posx;
    player.y = posy;
    Width = player.w;
    Height = player.h;
    SDL_RenderCopy(amme,threater,NULL,&player);
}

void Threater::Show(SDL_Renderer* amme){
    SDL_Rect player;
    SDL_QueryTexture(threater,NULL, NULL, &player.w, &player.h);
    player.x = posx;
    player.y = posy;
    SDL_RenderCopy(amme,threater,NULL,&player);
}

void Threater::Move(int t){
    if(t%15==0) speed += bonus;
    posx -= speed;
    if (posx + Max_Width < 0)
	{
		posx = random(700,1200) + SCREEN_WIDTH;
	}
}
int Threater::GetSpeed() { return speed + bonus; }
int Threater::GetType() { return type; }
int Threater::GetPosx() { return posx; }
int Threater::GetPosy() { return posy; }
int Threater::GetWidth() { return Width; }
int Threater::GetHeight() { return Height; }



