#ifndef SDL_UTLIS_H
#define SDL_UTLIS_H

#include <SDL.h>
#include <iostream>
#include<SDL_image.h>

const int ground = 725;
const int jump = 1;
const int fall = 0;
const int bird = 1;
const int cactus = 0;
const int birdy = 500;
const int SCREEN_WIDTH = 2000;
const int SCREEN_HEIGHT = 1000;
const int Range = 1500;
const int bonus = 1;
const int Max_Width = 100;
const int box_Width = 100;
const int box_Height = 100;
using namespace std;

void initSDL(SDL_Window* &window, SDL_Renderer* &renderer,
             int SCREEN_WIDTH, int SCREEN_HEIGHT, const string &WINDOW_TITLE);
int random(int x,int y);
void logSDLError(std::ostream& os,
                 const std::string &msg, bool fatal = false);

SDL_Texture* loadTexture( string path, SDL_Renderer* renderer );

void quitSDL(SDL_Window* window, SDL_Renderer* renderer);

void waitUntilKeyPressed();

#endif
