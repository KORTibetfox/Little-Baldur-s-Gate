#pragma once
#include "..\Headers\Unit.h"
#include "..\Headers\Macro.h"

Unit::Unit()
{
	// All Units must have below indexes
	this->data.level = 1;
	this->data.exp = 0;
	this->data.cur_hp = 200;
	this->data.max_hp = 200;
	this->data.str = 8;
	this->data.dex = 8;
	this->data.vit = 8;

}

Data Unit::getData()
{
	return data;
}

void Unit::setCurHp(int damage) { this->data.cur_hp -= damage; }

Player::Player()
{
	this->data.name = "Zeus";
	//stats
	this->data.str = 10;
	this->data.dex = 8;
	this->data.vit = 8;

	this->data.bonus_damage = int(this->data.str / 2);
	this->data.bonus_preemptive = int(this->data.dex / 2);
	this->data.bonus_dodge = int(this->data.vit / 2);
}

Player::~Player()
{
}



Mob::Mob(std::string name, int level, int max_hp, int str, int dex, int vit)
{
	this->data.name = name;
	this->data.level = level;
	this->data.cur_hp = this->data.max_hp = max_hp;
	this->data.str = str;
	this->data.dex = dex;
	this->data.vit = vit;

	this->data.bonus_damage = int(this->data.str / 2);
	this->data.bonus_preemptive = int(this->data.dex / 2);
	this->data.bonus_dodge = int(this->data.vit / 2);
}

Mob::~Mob()
{
}

