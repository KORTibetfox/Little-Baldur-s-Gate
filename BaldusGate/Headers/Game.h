#pragma once
//Game Manager : Singleton Pattern

class Game
{
private:
	Game();
	~Game();
	static Game* instance;

public:

	static Game* getInstance();

	void update();

	void render();
};

//Utility

namespace Random
{
	int getRandomNumber(int range);
}

namespace Dice
{
	int rolltheDice(int count, int range);

	int rolltheDice(int range);
}

namespace Interface
{
	void WAIT();

	void diceMessage();
}
