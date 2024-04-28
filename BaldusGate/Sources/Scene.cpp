#include "..\Headers\Scene.h"
#include "..\Headers\Button.h"
#include "..\Headers\Macro.h"

void MainMenu::draw(sf::RenderWindow& window)
{
	window.draw(background); // significant "order"

	for (Button* btn : button)
	{
		btn->drawTo(window);
	}
	line->drawTo(window);
}

void MainMenu::loadObjects()
{
	std::cout << "-MainMenu Graphic File Loading-";

	//Sprite Image
	if (!image1.loadFromFile("Resources/Image/fantasy_image1.jpg")) // Load Image
	{
		std::cout << "Can't Load Image" << std::endl; exit(0);
	}

	background.setSize(sf::Vector2f(WIDTH, HEIGHT));
	background.setTexture(&image1); // Must be Reference !!

	// Title Text

	// Set Center 
	//text->setMiddle();
	// 
	//pos
	line->setPosition(sf::Vector2f(WIDTH / 100 * 35, HEIGHT / 100 * 20));
	//style
	line->setBold();
	line->setUnderLine();
	line->setOutlineColor(sf::Color::Black);

	// Play Button
	btn_play->setPosition({ WIDTH / 100 * 50, HEIGHT / 100 * 50 });
	btn_play->setFont(font);

	// Option Button
	btn_option->setPosition({ WIDTH / 100 * 50, HEIGHT / 100 * 60 });
	btn_option->setFont(font);

	// Credit Button
	btn_credit->setPosition({ WIDTH / 100 * 50, HEIGHT / 100 * 70 });
	btn_credit->setFont(font);

	// Quit Button
	btn_quit->setPosition({ WIDTH / 100 * 50, HEIGHT / 100 * 80 });
	btn_quit->setFont(font);

	button.push_back(btn_play);
	button.push_back(btn_option);
	button.push_back(btn_credit);
	button.push_back(btn_quit);

	std::cout << "All object loaded !" << std::endl;
}

void MainMenu::event(sf::RenderWindow& window)
{
	//Main Event
	sf::Event event;
	while (window.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed: window.close(); break;

		case sf::Event::MouseMoved:
			for (Button* btn : button)
			{
				if (btn->isMouseOver(window))
				{
					btn->setBackColor(btn->getOnMouseColor());
				}
				else btn->setBackColor(btn->getMainColor());
			}
			break;

		case sf::Event::MouseButtonPressed:
			for (Button* btn : button)
			{
				if (btn->isMouseOver(window) && event.key.code == sf::Mouse::Left)
				{
					if (btn == btn_option)
					{
						nextScene = SCENE::OPTION;
						this->endScene();
					}

					if (btn == btn_credit)
					{
						nextScene = SCENE::CREDIT;
						this->endScene();
					}

					if (btn == btn_quit)
					{
						this->endScene();
						window.close();
					}
				}
			}
			break;

		default:
			break;
		}
	}
}

//Credit
void Credit::draw(sf::RenderWindow& window)
{
	btn_back->drawTo(window);
	window.draw(text);
}

void Credit::loadObjects()
{
	// Title Text
	text.setFont(font);
	text.setString(" - CREDIT - ");
	text.setCharacterSize(50);
	text.setFillColor(sf::Color::White);
	text.setPosition(sf::Vector2f(WIDTH / 2 - text.getCharacterSize(), HEIGHT / 100 * 20));
	text.setStyle(sf::Text::Bold | sf::Text::Underlined);
	text.setOutlineColor(sf::Color::Black);

	// Play Button
	btn_back->setPosition({ WIDTH / 100 * 50, HEIGHT / 100 * 80 });
	btn_back->setFont(font);
}

void Credit::event(sf::RenderWindow& window)
{
	//Main Event
	sf::Event event;
	while (window.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed: window.close(); break;

		case sf::Event::MouseMoved:
			if (btn_back->isMouseOver(window))
			{
				btn_back->setBackColor(btn_back->getOnMouseColor());
			}
			else btn_back->setBackColor(btn_back->getMainColor());
			break;

		case sf::Event::MouseButtonPressed:
			if (btn_back->isMouseOver(window) && event.key.code == sf::Mouse::Left)
			{
				nextScene = SCENE::MAINMENU;
				this->endScene();
			}
			break;

		default:
			break;
		}
	}
}

//Option
void Option::draw(sf::RenderWindow& window)
{
}

void Option::loadObjects()
{
}

//Quit
void Quit::draw(sf::RenderWindow& window)
{
}

void Quit::loadObjects()
{
}

//Scene
void Scene::draw(sf::RenderWindow& window)
{
}

void Scene::loadObjects()
{
}

Scene::Scene()
{
	//Load fonts
	if (!font.loadFromFile("Resources/Font/HeirofLightBold.ttf"))
	{
		std::cout << "Can't Load Font" << std::endl;
		exit(0);
	}
}

Scene::~Scene()
{
}

void Scene::event(sf::RenderWindow& window)
{
}

void Scene::startScene()
{
	this->loadObjects();
	this->isOpen= true;
}

void Scene::endScene()
{
	this->isOpen = false;
}

bool Scene::isOpenScene()
{
	return this->isOpen;
}
