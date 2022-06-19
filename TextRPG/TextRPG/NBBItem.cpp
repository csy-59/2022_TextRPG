#include "NBBItem.h"

NBB_Item::NBB_Item()
{
	SetName("NBB");
	SetInfo("¢¾+1.8, S -5");
	SetPrice(8);
}

std::string NBB_Item::UseItem(Player* player)
{
	player->AddStress(-5);

	std::string result = "¢¾ +" + 
		std::to_string(player->GotCured(1.8f)) + "  S -5";
	return result;
}
