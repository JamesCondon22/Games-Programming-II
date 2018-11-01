#pragma once
#include "Entity.h"
#include "HealthComponent.h"

class HealthSystem
{
	std::vector<Entity> m_entities;

public:
	HealthSystem();
	void addEntity(Entity  e);
	void update();
	
};