#pragma once

#include "Component.h"

class PositionComponent : Component
{
	PositionComponent() : m_positionX(100.0f), m_positionY(100.0f) { id = 2; }

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
