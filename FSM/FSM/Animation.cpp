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
void Animation::idle()
{
	current->idle(this);
}

void Animation::jumping()
{
	current->jumping(this);
}

void Animation::climbing()
{
	current->climbing(this);
}