#ifndef Threater_H_
#define Threater_H_

#include<SDL.h>
#include<SDL_image.h>
#include"SDL_utils.h"

class Threater{
public:
    void Show(SDL_Renderer *amme);
    void free();
    Threater(int t);
    void Update(SDL_Renderer *amme);
    void Move(int v);
    int GetType();
    int GetSpeed();
    int GetPosx();
    int GetPosy();
    int GetWidth();
    int GetHeight();
private:
    int posx,posy;
    int Width,Height;
    int type;
    int speed;
    SDL_Texture* threater;
};

#endif // Threater_H_
