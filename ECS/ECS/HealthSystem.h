#pragma once
#include "Entity.h"
#include "HealthComponent.h"

class HealthSystem
{
	std::vector<Entity> m_entities;

public:
	HealthSystem();
	void addEntity(Entity  e);
	void update(SDL_Keycode in);
	void checkCollision();
	int index = 0;
	bool pressed = false;
	int count = 0;
};