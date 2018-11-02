#pragma once

#include "State.h"

class Idle : public State
{
public:
	Idle() {};
	~Idle() {};
	void jumping(Animation * a, SDL_Rect &destRect);
	void climbing(Animation * a, SDL_Rect &destRect);
};
