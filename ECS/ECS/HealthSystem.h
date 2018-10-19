#pragma once
#include "Entity.h"
#include "HealthComponent.h"

class HealthSystem
{
	std::vector<Entity> m_entities;

public:
	void addEntity(Entity e) {}
	void update() {
		std::cout << "HealthSystem update" << std::endl;
	}
};