
#pragma once
#include "..\Headers\Macro.h"

using namespace std;

class Character {

private:

protected:
	string class_name;

public:

	Character();

	string getClassName();
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