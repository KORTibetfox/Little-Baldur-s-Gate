#include "..\Headers\SceneManager.h"

SceneManager::SceneManager()
{
	MainMenu* menu = new MainMenu();
	Option* option = new Option();
	Credit* credit = new Credit();
	Quit* quit = new Quit();

	SceneList.push_back(menu);
	SceneList.push_back(option);
	SceneList.push_back(credit);
	SceneList.push_back(quit);

	//init startScene
	curScene = SceneList[SCENE::MAINMENU];
	this->switchScene(); 
}

SceneManager::~SceneManager()
{
}

void SceneManager::switchScene()
{
	if (curScene->isOpenScene())return;

	preScene = curScene;
	curScene = SceneList[curScene->nextScene];
	curScene->startScene();
}

void SceneManager::backToPreScene()
{
	curScene = preScene;
	//.
}

void SceneManager::draw(sf::RenderWindow& window)
{
	curScene->draw(window);
}

void SceneManager::event(sf::RenderWindow& window)
{
	curScene->event(window);
}
