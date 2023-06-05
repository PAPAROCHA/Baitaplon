#include"Character.h"
#include"SDL_utils.h"
#include<iostream>
#include<SDL_image.h>
#include<SDL.h>

using namespace std;

Character::Character()
{
    posx = 200;
    posy = ground;
    Width = 0;
    Height = 0;
    status = 0;
}

bool Character::OnGround(){
    return posy == ground;
}

void Character::Update(SDL_Renderer* amme)
{
    character = loadTexture("sonic.jpg", amme);
    SDL_Rect player;
    SDL_QueryTexture(character,NULL, NULL, &player.w, &player.h);
    Width = player.w/10;
    Height = player.h;
}

void Character::buildframe(){
    for ( int i = 0 ; i <= 9 ; i++ ){
        frame_clip[i].x = Width*i;
        frame_clip[i].y = 0;
        frame_clip[i].w = Width;
        frame_clip[i].h = Height;
    }
}

void Character::Button(SDL_Event& e)
{
	if (e.type == SDL_KEYDOWN && e.key.repeat == 0)
	{
		switch (e.key.keysym.sym)
		{
			case SDLK_SPACE:
            {
				if (OnGround())
                {
					status = jump;
				}
			}
		}
	}
}

void Character::Show(SDL_Renderer* amme, int cur)
{
    SDL_Rect player;
    SDL_QueryTexture(character,NULL, NULL, &player.w, &player.h);
    player.x = posx;
    player.y = posy;
    player.w = Width;
    SDL_RenderCopy(amme,character, &frame_clip[cur], &player);
}

void Character::Move(){
    if ( status == jump && posy == ground ){
        posy -= 400;
    }
    else if ( status == jump && posy < ground ){
        status = fall ;
    }
    if ( status == fall && posy < ground ){
        posy += 30 ;
    }
    if ( posy > ground ) posy = ground;
}

int Character::GetPosx(){return posx;}
int Character::GetHeight() { return Height;}
int Character::GetWidth(){ return Width;}
int Character::GetPosy() {return posy;}



