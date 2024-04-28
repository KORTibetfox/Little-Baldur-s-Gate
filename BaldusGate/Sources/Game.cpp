#include "..\Headers\Game.h"
#include "..\Headers\Unit.h"
#include "..\Headers\Graphics.h"
#include "..\Headers\Macro.h"

Game::Game() {}

Game::~Game()
{
}

void Game::init()
{
	window->setFramerateLimit(30); //30 Frame setting
}

Game* Game::getInstance() 
{
	if (instance == nullptr)
	{
		instance = new Game();
		instance->init();
	}
	return instance;
}

void Game::update()
{
	event();
	scenemanager.switchScene();
}

void Game::render()
{
	window->clear(sf::Color::Black);
	scenemanager.draw(*window);
	window->display();
}

void Game::event()
{
	scenemanager.event(*window);
}

bool Game::isGameRunning() 
{
	return window->isOpen();
}

Game* Game::instance = nullptr;

// End of Game Class

int util::Random::getRandomNumber(int range)
{
	int r = 0;
	std::random_device rd;
	std::mt19937 gen(rd());

	std::uniform_int_distribution<int> dis(0, range);

	return dis(rd);
}

int util::Dice::rolltheDice(int count, int range)
{
	int sum = 0;
	for (int i = 0; i < count; i++)
		sum += util::Random::getRandomNumber(range);
	return sum;
}

int util::Dice::rolltheDice(int range)
{
	return util::Random::getRandomNumber(range);
}

void util::Interface::WAIT()
{
	char c = _getch();
}

void util::Interface::diceMessage()
{
	std::cout << "\nTry Roll The Dice!!" << std::endl;
}
