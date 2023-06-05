#ifndef Character_H_
#define Character_H_

#include<iostream>
#include<SDL.h>
#include<SDL_image.h>

class Character
{
public:
    bool OnGround();
    Character();
    void Update(SDL_Renderer* amme);
    void Button(SDL_Event &e);
    void Move();
    void Show(SDL_Renderer* amme, int cur);
    void buildframe();
    int GetPosx();
    int GetPosy();
    int GetWidth();
    int GetHeight();
    int LastJump = 0;
    SDL_Texture* character;
    SDL_Rect frame_clip[10];
private:
    int posx, posy;
    int Width;
    int Height;
    int status;

};
#endif
