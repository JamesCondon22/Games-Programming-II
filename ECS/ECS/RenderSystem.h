#include "Entity.h"

/// <summary>
/// Draws any entites attached to the screen.
/// </summary>
class RenderSystem {
public:
	void addEntity(Entity en);
	void render(SDL_Renderer* renderer);

private:
	std::vector<Entity> m_entities;

};
