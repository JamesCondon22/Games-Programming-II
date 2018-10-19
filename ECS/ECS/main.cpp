#include "HealthSystem.h"


int main(void *)
{
	Entity player;
	HealthComponent hc; 
	player.addComponent(hc); 

	HealthSystem hs; 
	hs.addEntity(player); 

	while (true)
	{
		hs.update(); 

	}
	return 0;
}