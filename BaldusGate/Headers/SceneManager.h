#pragma once

#include "..\Headers\Macro.h"
#include "..\Headers\Scene.h"

class SceneManager
{
private:
	// Scene Array <- menu option quit
	std::vector<Scene*> SceneList;

	Scene* curScene; // cursor Current Scene
	Scene* preScene; // cursor Previous Scene

public:
	SceneManager();
	~SceneManager();

	void switchScene();

	void backToPreScene();

	void draw(sf::RenderWindow& window);

	void event(sf::RenderWindow& window);
};