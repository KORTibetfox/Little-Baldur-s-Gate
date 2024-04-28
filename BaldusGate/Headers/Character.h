#pragma once
#include "..\Headers\Macro.h"

class Character {

private:

protected:
	std::string class_name;

public:

	Character();

	std::string getClassName();
};

class Warrior : public Character {

public:
	Warrior();
};

class Wizard : public Character {

public:
	Wizard();
};

class Archer : public Character {

public:
	Archer();
};