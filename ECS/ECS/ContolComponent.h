#pragma once

#include "Component.h"

/// <summary>
/// Control Component.
/// </summary>
class ControlComponent : public Component {
public:
	ControlComponent() { id = 3; };

	enum DirectionState {
		Idle,
		Left,
		Right,
		Up,
		Down
	};

	void changeState(DirectionState state) {
		m_currentGameState = state;
	};

	DirectionState m_currentGameState = DirectionState::Right;
};
