#ifndef CHARACTER_H_
#define CHARACTER_H_

#include "SDL_utils.h"

#define JUMP 1
#define FALL 2
#define RUN	0

class Character
{
public:
	static const int JUMP_SPEED = 8;
	static const int FALL_SPEED = 8;

	Character();
	bool OnGround();

	void HandleEvent(SDL_Event& e);

	void Move();

	void Render(SDL_Rect* currentClip, SDL_Renderer *gRenderer, LTexture gCharacterTexture);

	int Xpos();

	int Ypos();

private:
	int x,y;

	int status;
};

#endif
