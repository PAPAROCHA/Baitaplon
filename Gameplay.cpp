#include<iostream>
#include"Character.h"
#include"Threater.h"
#include"Gameplay.h"
bool Collision(Threater t, Character s){
    int lefts = s.GetPosx();
    int rights = s.GetPosx() + s.GetWidth();
    int tops = s.GetPosy();
    int bottoms = s.GetPosy() + s.GetHeight();
    int leftt = t.GetPosx();
    int rightt = t.GetPosx() + t.GetWidth();
    int topt = t.GetPosy();
    int bottomt = t.GetPosy()+ t.GetHeight();
    if ( rights > leftt && bottoms > topt && rightt > lefts && bottomt > tops) return true;
    return false;
}

