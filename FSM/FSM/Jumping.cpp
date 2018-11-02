#include "Jumping.h"


void Jumping::idle(Animation*a, SDL_Rect &destRect)
{
	std::cout << "Going from Jumping to Idling" << std::endl;
	a->setCurrent(new Idle());
	destRect.y = 0;
	delete this;
}