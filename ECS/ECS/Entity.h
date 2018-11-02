#ifndef ENTITY_H
#define ENTITY_H

#include "Component.h"
#include "HealthComponent.h"
#include "PositionComponent.h"
#include "ContolComponent.h"
#include <vector>
#include <algorithm>
#include <SDL.h>

using namespace std;

/// <summary>
/// innnterface for entities.
/// entitys shared variables
/// </summary>
class Entity {
public:
	int id;

	Entity() {};
	virtual ~Entity() {};

	void addComponent(Component* c) { m_components.push_back(c); }
	void removeComponenet(Component* c) {
		//m_components.erase(std::remove(m_components.begin(), m_components.end(), c), m_components.end());
	};
	vector<Component*> getComponents() { return m_components; }

	int getWidth() { return width; };
	int getHeight() { return height; };
	SDL_Color getColor() { return m_color; };
private:
	vector<Component*> m_components;

protected:
	int width = 100;
	int height = 100;
	SDL_Color m_color;

};

/// <summary>
/// player class overwrites id and color.
/// </summary>
class Player : public Entity {
public:
	Player() { id = 1; m_color = { 255, 0, 0, 255 }; };
};

/// <summary>
/// Red class overwrites id and color.
/// </summary>
class Cat : public Entity {
public:
	Cat() { id = 2; m_color = { 255, 255, 0, 255 }; };

};

/// <summary>
/// Green class overwrites id and color.
/// </summary>
class Alien : public Entity {
public:
	Alien() {
		id = 3; m_color = { 0, 255, 0, 255 };
	};
};

/// <summary>
/// Pink class overwrites id and color.
/// </summary>
class Dog : public Entity {
public:
	Dog() { id = 4; m_color = { 0, 0, 200, 255 }; };
};

#endif // !ENTITY_H

