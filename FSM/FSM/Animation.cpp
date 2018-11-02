#include "Animation.h"
#include "Idle.h"

Animation::Animation()
{
	current = new Idle();
}
void Animation::setCurrent(State* s)
{
	current = s;
}
State* Animation::getCurrent()
{
	return current;
}
void Animation::setPrevious(State* s)
{
	previous = s;
}

State* Animation::getPrevious()
{
	return previous;
}
void Animation::idle(SDL_Rect &destRect)
{
	current->idle(this, destRect);
}

void Animation::jumping(SDL_Rect &destRect)
{
	current->jumping(this, destRect);
}

void Animation::climbing(SDL_Rect &destRect)
{
	current->climbing(this, destRect);
}