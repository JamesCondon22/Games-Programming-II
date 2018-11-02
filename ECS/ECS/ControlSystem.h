#include "Entity.h"

/// <summary>
/// Control system moves any entities attached in the direction the button is pressed.
/// </summary>
class ControlSystem {
public:
	void addEntity(Entity en);
	void control(SDL_Keycode in);
	void update();

private:
	vector<Entity> m_entities;
	//components
	PositionComponent* positionComp;
	ControlComponent* controlComp;
	
	float x = 0;
	float y = 0;
	float speed = 5;

	void checkBoundary();
	int screenWidth = 1280;
	int screenHeight = 720;

};
