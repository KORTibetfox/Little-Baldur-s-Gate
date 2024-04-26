#pragma once
#include "Game.h"
#include "Unit.h"

class Battle
{
private:

	void setFirstAttacker(Player* player, Mob* mob); // Choice Who first attack

	bool isDead(Player* player, Mob* mob);

	void executeAttack(Unit* attacker, Unit* defender, Player* player, Mob* mob);

	void exchangeTurn(Unit* attacker, Unit* defender, Player* player, Mob* mob); // You are fool if you can't understand this

public:

	Battle(Player* player, Mob* mob);
};