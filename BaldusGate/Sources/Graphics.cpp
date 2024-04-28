#include "..\Headers\Graphics.h"
#include "..\Headers\Macro.h"

void Graphics::showBattleScene(Player* player, Mob* mob)
{
	printf("[ Player ] hp : %d  / %d\n", player->getData().cur_hp, player->getData().max_hp);
	printf("[   Mob  ] hp : %d  / %d\n", mob->getData().cur_hp, mob->getData().max_hp);
}
