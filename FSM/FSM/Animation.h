#pragma once


class Animation
{
	class State* current;
	class State* previous;
public:
	Animation();
	~Animation();
	void setCurrent(State* s);
	void setPrevious(State* s);
	State* getCurrent();
	State* getPrevious();
	void idle();
	void jumping();
	void climbing();

};
