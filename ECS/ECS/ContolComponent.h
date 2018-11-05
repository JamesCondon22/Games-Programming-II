#pragma once

#include "Component.h"

class ControlComponent : public Component {
public:
	ControlComponent() { id = 3; };

	enum direction {
		Idle,
		Left,
		Right,
		Up,
		Down
	};

	void changeState(direction state) {
		m_currentGameState = state;
	};

	direction m_currentGameState = direction::Idle;
};
