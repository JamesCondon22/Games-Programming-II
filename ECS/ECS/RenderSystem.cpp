#include "RenderSystem.h"

void RenderSystem::addEntity(Entity en)
{
	m_entities.push_back(en);
}


void RenderSystem::render(SDL_Renderer* renderer)
{
	for (Entity& entity : m_entities) {
		for (Component* comp : entity.getComponents()) {
			if (comp->id == 2) {
				SDL_Color m_color;
				m_color = entity.getColor();

				SDL_Rect m_position;
				int x = dynamic_cast<PositionComponent*>(comp)->getXpos();
				int y = dynamic_cast<PositionComponent*>(comp)->getYPos();
				int width = entity.getWidth();
				int height = entity.getHeight();
				m_position = { x, y, width, height };

				SDL_SetRenderDrawColor(renderer, m_color.r, m_color.g, m_color.b, m_color.a);
				SDL_RenderFillRect(renderer, &m_position);
				SDL_RenderDrawRect(renderer, &m_position);
			}
		}
	}
}