#pragma once
#include "..\Headers\SceneManager.h"
#include "..\Headers\Unit.h"
//Game Manager : Singleton Pattern

class Game
{
private:

	sf::RenderWindow* window = new sf::RenderWindow(sf::VideoMode(WIDTH, HEIGHT), "Baldus Gate");
	SceneManager scenemanager;

	Game();
	~Game();
	static Game* instance;
	Player* player = new Player();

	void init();

public:
	static Game* getInstance();

	void update();

	void render();

	void event();

	bool isGameRunning();
};

//Utility
namespace util
{
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
}
