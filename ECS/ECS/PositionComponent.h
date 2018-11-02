#pragma once

#include "Component.h"

class PositionComponent : public Component
{
public:
	PositionComponent(float x, float y) : m_positionX(x), m_positionY(y) { id = 2; }

	float getXpos() { return m_positionX; }
	float getYPos() { return m_positionY; }
	void setPosition(float positionX, float positionY)
	{
		this->m_positionX = positionX;
		this->m_positionY = positionY;
	}
private:
	float m_positionX;
	float m_positionY;

};
