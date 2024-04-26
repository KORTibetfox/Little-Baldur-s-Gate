#pragma	once

#include "..\Headers\Battle.h"
#include "..\Headers\Graphics.h"
#include "..\Headers\Macro.h"

using namespace std;

void Battle::setFirstAttacker(Player* player, Mob* mob) // Choice Who first attack
{
	Graphics::showBattleScene(player, mob);
	Interface::diceMessage();
	Interface::WAIT();

	cout << "* select first attacker" << endl << endl;

	int player_result = Dice::rolltheDice(20) + player->getData().bonus_preemptive;
	int mob_result = Dice::rolltheDice(20) + mob->getData().bonus_preemptive;

	cout << "Your dice : " << player_result << " (+" << player->getData().bonus_preemptive << ")"
		<< " And Mob dice : " << mob_result << " (+" << mob->getData().bonus_preemptive << ")" << endl;

	if (player_result >= mob_result) {
		cout << "\nYour Turn!" << endl << endl;
		this->executeAttack(player, mob, player, mob);
	}
	else if (player_result < mob_result) {

		cout << "\nMob Turn!" << endl << endl;
		this->executeAttack(mob, player, player, mob);
	}
}

bool Battle::isDead(Player* player, Mob* mob)
{
	if (player->getData().cur_hp <= 0) {
		cout << endl << player->getData().name << " is Dead" << endl;
		return true;
	}

	if (mob->getData().cur_hp <= 0)
	{
		cout << "\n" << mob->getData().name << " is Dead" << endl;
		return true;
	}
	return false;
}

void Battle::executeAttack(Unit* attacker, Unit* defender, Player* player, Mob* mob)
{
	Graphics::showBattleScene(player, mob);
	Interface::diceMessage();
	Interface::WAIT();

	int attack_damage = Dice::rolltheDice(2, 20) + attacker->getData().bonus_damage;
	int defense_chance = Dice::rolltheDice(20) + defender->getData().bonus_dodge;


	if (attack_damage >= defense_chance) {
		cout << defender->getData().name << " get " << attack_damage << " (+" << attacker->getData().bonus_damage << ")"
			<< " damage by " << attacker->getData().name;
		defender->setCurHp(attack_damage);
		if (this->isDead(player, mob)) return;
	}

	else {
		cout << defender->getData().name << " Successe Dodge!!" << endl << attacker->getData().name << "'s result is " << attack_damage << " (+" << attacker->getData().bonus_damage << ")"
			<< " and "
			<< defender->getData().name << "'s result is " << defense_chance << " (+" << defender->getData().bonus_dodge << ")" << endl << endl;
	}

	//cout << "Atk's HP : " << attacker->getData().cur_hp << "\tDef's HP : " << defender->getData().cur_hp << endl;
	this->exchangeTurn(attacker, defender, player, mob);
}

void Battle::exchangeTurn(Unit* attacker, Unit* defender, Player* player, Mob* mob) // You are fool if you can't understand this
{

	cout << attacker->getData().name << "'s Turn!" << endl << endl;
	Unit* temp;
	temp = attacker;
	attacker = defender;
	defender = temp;

	this->executeAttack(attacker, defender, player, mob);
}


Battle::Battle(Player* player, Mob* mob)
{
	this->setFirstAttacker(player, mob);
}
