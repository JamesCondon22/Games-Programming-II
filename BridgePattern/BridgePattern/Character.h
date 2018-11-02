#pragma once

#include <iostream>
class DrawAPI
{
public:
	virtual void Draw() = 0;
};

class DrawImpl : public DrawAPI
{
public:
	void Draw() { std::cout << "Draw Impl" << std::endl; }
};

class Character
{
public:
	virtual void Draw() = 0;
};

class Player : public Character
{
public:
	//calls a drawApi object and assigns to member variable api
	Player(DrawAPI* api) { this->api = api; }
	void Draw() { api->Draw(); }

private:
	DrawAPI * api;
};

