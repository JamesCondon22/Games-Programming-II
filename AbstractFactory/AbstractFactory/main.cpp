#include "Character.h"
#include <vector>

int main()
{
	//A class cannot anticipate the type of objects it needs to create beforehand
	Factory* factory = new CharacterFactory;
	std::vector<Character*> characters;

	characters.push_back(factory->CreatePlayer());
	characters.push_back(factory->CreateOpponents());

	for (int i = 0; i < characters.size(); i++) {
		characters[i]->draw();
	}

	std::cin.get();

}