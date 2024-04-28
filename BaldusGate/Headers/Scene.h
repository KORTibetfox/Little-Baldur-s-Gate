#pragma once
#include "..\Headers\Macro.h"
#include "..\Headers\\Button.h"
#include "..\Headers\\Text.h"

class Scene
{
private:
	bool isOpen = false;
	virtual void loadObjects();

protected:
	sf::Font font;

public:
	Scene();
	virtual ~Scene();

	SCENE nextScene = SCENE::MAINMENU;

	//virtual methods
	virtual void draw(sf::RenderWindow& window);
	virtual void event(sf::RenderWindow& window);

	//general methods
	void startScene();
	void endScene();
	bool isOpenScene();
	//virtual void update() {};
};
                   
class MainMenu : public Scene
{
private:
	// Set Rectangle
	sf::RectangleShape background; 
	sf::Texture image1;

	// init button
	std::vector<Button*> button;
	Button* btn_play = new Button("Play", { 200, 50 }, 20, sf::Color(255,255,255,128), sf::Color(255, 255, 0, 128), sf::Color::Black);
	Button* btn_option = new Button("Option", { 200, 50 }, 20, sf::Color(255,255,255,128), sf::Color(255, 255, 0, 128), sf::Color::Black);
	Button* btn_credit = new Button("Credit", { 200, 50 }, 20, sf::Color(255,255,255,128), sf::Color(255, 255, 0, 128), sf::Color::Black);
	Button* btn_quit = new Button("Quit", { 200, 50 }, 20, sf::Color(255,255,255,128), sf::Color(255, 255, 0, 128), sf::Color::Black);

	CreateText* text = new CreateText("Baldus Gate", font, sf::Color::White, 50);

public:

	void draw(sf::RenderWindow& window) override;
	void loadObjects() override;
	void event(sf::RenderWindow& window) override;

	//void update() override;
};

class Option : public Scene
{
private:

public:

	void draw(sf::RenderWindow& window) override;
	void loadObjects() override;
	//void update() override;
};

class Credit : public Scene 
{
private:
	Button* btn_back = new Button("Back", { 200, 50 }, 20, sf::Color(255, 255, 255, 128), sf::Color(255, 255, 0, 128), sf::Color::Black);

	sf::Text text;

public:
	void draw(sf::RenderWindow& window) override;
	void loadObjects() override;
	void event(sf::RenderWindow& window) override;
	//void update() override;
};

class Quit : public Scene
{
private:

public:
	void draw(sf::RenderWindow& window) override;
	void loadObjects() override;
	// void update() override;
};