#include "Character.h"

int main()
{
	DrawAPI* api = new DrawImpl();
	Character* character = new Player(api);
	character->Draw();
	std::cin.get();
}