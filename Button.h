#ifndef Button_H_
#define Button_H_
#include<SDL.h>
class Button{
public:
    Button();
    bool Checkinside(SDL_Event *e);
    void Setpos(int x, int y);
    void Show(SDL_Renderer *amme);
private:
    int posx, posy;
};
#endif

