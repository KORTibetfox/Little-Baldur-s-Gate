#include "..\Headers\Character.h"
#include "..\Headers\Macro.h"

Character::Character() {}

string Character::getClassName()
{
	return this->class_name;
}

Warrior::Warrior()
{
	this->class_name = "warrior";
}

Wizard::Wizard() {
	this->class_name = "wizard";
}

Archer::Archer() {
	this->class_name = "archer";
}
