#include <iostream>
#include <SDL.h>
#include "SDL_utils.h"
#include<SDL_image.h>
#include"Character.h"
#include"Threater.h"
#include"Gameplay.h"
#include"Background.h"
using namespace std;

const string WINDOW_TITLE = "Cao Duc Chung Baitaplon";
SDL_Renderer* amme;
Character Sonic;

Threater Cactus(0),CCactus(0);
Threater Bird(1);
int Loser = 0;
int main(int argc, char *argv[]) {
    SDL_Window *window;
    initSDL(window, amme, SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_TITLE);
    Cactus.Update(amme);
    Cactus.Show(amme);
    CCactus.Update(amme);
    CCactus.Show(amme);
    Bird.Update(amme);
    Cactus.Show(amme);
    Sonic.Update(amme);
    Sonic.buildframe();
    bool end = 0;
    SDL_Event e;
    int t = 0, cur = 0, ans = 0;
    SDL_RenderPresent(amme);
    while(!end){
        SDL_Delay(50);
        SDL_RenderClear(amme);
        while (SDL_PollEvent(&e) != 0)
        {
            if (e.type == SDL_QUIT)
            {
               end = 1;
            }
            Sonic.Button(e);
        }
        bkupdate(amme,t);
        Sonic.Move();
        if(Sonic.OnGround()) { cur = (cur+1)%10; }
        Cactus.Move(t);
        CCactus.Move(t);
        Bird.Move(t);
        Sonic.Show(amme,cur);
        CCactus.Show(amme);
        Cactus.Show(amme);
        Bird.Show(amme);
        if ( Collision(Cactus, Sonic) ) { break ; }
        if ( Collision(CCactus, Sonic) ) { break; }
        if ( Collision(Bird, Sonic) ) { break; }
        SDL_RenderPresent(amme);
        t+=10;
        ans+= 1;
    }
    cout << "Diem cua ban la" << ans;
    waitUntilKeyPressed();
    quitSDL(window, amme);

    return 0;
}
