#pragma once
#include <iostream>
/// <summary>
/// Abstract base Class
/// </summary>
class Character {
public:
		Character() {}
		virtual ~Character(){}
	virtual void draw() = 0;
};
/// <summary>
/// Concrete family 1
/// </summary>
class Player : public Character {
public:
	void draw() {
		std::cout << "Draw Player" << std::endl;
	}
};

/// <summary>
/// Concrete Family 2
/// </summary>
class Boss : public Character {
public:
	void draw() {
		std::cout << "Draw Boss" << std::endl;
	}
};
/// <summary>
/// defines methods to create all related concrete virtual products 
/// </summary>
class Factory {
public:
	virtual Character* CreatePlayer() = 0;
	virtual Character* CreateOpponents() = 0;
};
/// <summary>
/// creates concrete objects and returns 
/// </summary>
class CharacterFactory : public Factory {
public:
	Character * CreatePlayer() {
		return new Player;
	}
	Character * CreateOpponents() {
		return new Boss;
	}
};