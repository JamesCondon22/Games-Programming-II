#include "Climbing.h"

void Climbing::idle(Animation* a, SDL_Rect &destRect)
{
	std::cout << "Going from Climbing to Idling" << std::endl;
	a->setCurrent(new Idle());
	destRect.y = 0;
	delete this;
}