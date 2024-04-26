#include "..\Headers\Game.h"
#include "..\Headers\Unit.h"
#include "..\Headers\Graphics.h"
#include "..\Headers\Macro.h"

Game::Game() {}

Game::~Game()
{
}

Game* Game::getInstance() 
{
	if (instance == nullptr)
	{
		instance = new Game();
	}
	return instance;
}

void Game::update()
{
	//cout << "Game is updating now" << endl;
}

void Game::render()
{
	//cout << "Game is Rendering now" << endl;

}

Game* Game::instance = nullptr;

// End of Game Class


int Random::getRandomNumber(int range)
{
	int r = 0;
	random_device rd;
	mt19937 gen(rd());

	uniform_int_distribution<int> dis(0, range);

	return dis(rd);
}


int Dice::rolltheDice(int count, int range)
{
	int sum = 0;
	for (int i = 0; i < count; i++)
		sum += Random::getRandomNumber(range);
	return sum;
}

int Dice::rolltheDice(int range)
{
	return Random::getRandomNumber(range);
}



void Interface::WAIT()
{
	char c = _getch();
}

void Interface::diceMessage()
{
	cout << "\nTry Roll The Dice!!" << endl << endl;
}
