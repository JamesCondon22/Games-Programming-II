#pragma once
#include <SDL.h>

class Animation
{
	class State* current;
	class State* previous;
public:
	Animation();
	void setCurrent(State* s);
	void setPrevious(State* s);
	State* getCurrent();
	State* getPrevious();
	void idle(SDL_Rect &destRect);
	void jumping(SDL_Rect &destRect);
	void climbing(SDL_Rect &destRect);

};
