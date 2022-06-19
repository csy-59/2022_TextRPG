#include "HansotItem.h"

Hansot_Item::Hansot_Item()
{
	SetName("ÇÑ¼Ü");
	SetInfo("¢¾+1.5, S -2");
	SetPrice(5);
}

std::string Hansot_Item::UseItem(Player* player)
{
	player->AddStress(-2);

	std::string result = "¢¾ +" + std::to_string(player->GotCured(1.5f)) + "  S -2";
	return result;
}
