#include "Entity.h"

/// <summary>
/// Ai system moves Ai entities Up he screen and resets them once they are off.
/// </summary>
class AiSystem {
public:
	void addEntity(Entity en);
	void update();

private:
	vector<Entity> m_entities;
	PositionComponent* positionComp;
	
	float x = 0;
	float y = 0;
	float speed = 10;

	void checkBoundary();
	int screenWidth = 1280;
	int screenHeight = 720;

	int direction = 0;

};

