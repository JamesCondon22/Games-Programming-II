#include "Entity.h"


class RenderSystem {
public:
	void addEntity(Entity en);
	void render(SDL_Renderer* renderer);

private:
	std::vector<Entity> m_entities;

};
