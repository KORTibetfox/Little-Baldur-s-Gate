#pragma once

#include <string>

typedef struct DATA
{
	std::string name;

	short int level;
	short int exp;
	short int cur_hp; // current hp
	short int max_hp;

	short int str; // Strength
	short int dex; // Dexterity
	short int vit; // Vitality

	short int bonus_preemptive; // who first punch shit boy
	short int bonus_damage;
	short int bonus_dodge;

}Data;

class Unit
{
private:

protected:
	Data data;

public:
	Unit();

	Data getData();

	void setCurHp(int damage);
};

class Player : public Unit
{
public:
	Player();
	~Player();
};

class Mob : public Unit
{
public:
	// Common enemy
	Mob(std::string name, int level, int max_hp, int str, int dex, int vit);
	~Mob();
};
