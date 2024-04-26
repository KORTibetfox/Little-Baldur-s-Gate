#include "..\Headers\Battle.h"
#include "..\Headers\Unit.h"
#include "..\Headers\Character.h"
#include "..\Headers\Battle.h"
#include "..\Headers\Graphics.h"
#include "..\Headers\Button.h"
#include "..\Headers\Macro.h"
#include <SFML/Graphics.hpp>

int main()
{
	//log
	cout << "이 거 거 던" << endl;

	//Init Game Engine
	Game* game = Game::getInstance();
	Player* player = new Player();

	//Init Window

	RenderWindow window(VideoMode(960, 720), "Little RPG");
	window.setFramerateLimit(30); //30 Frame setting

	//font
	Font font;
	if (!font.loadFromFile("Resources/Font/HeirofLightBold.ttf")) {
		cout << "Can't Load Font" << endl; exit(0);
	}

	// init button
	Button btn_play("play", { 200, 50 }, 20, Color::White, Color::Black);

	btn_play.setPosition({ 480, 360 });
	btn_play.setFont(font);

	//text example
	Text text;
	text.setFont(font);
	text.setString("LITTLE RPG");
	text.setCharacterSize(50);
	text.setFillColor(Color::Black);
	text.setPosition(Vector2f(960 / 3, 720 / 6));
	text.setStyle(Text::Bold | Text::Underlined);

	//Sprite Image example
	Texture image1;
	if (!image1.loadFromFile("Resources/Image/fantasy_image1.jpg")) // Load Image
	{ cout << "Can't Load Image" << endl; exit(0); }

	RectangleShape background; // Set Rectangle
	background.setSize(Vector2f(960, 720));
	background.setTexture(&image1); // Must be Reference !!

	//Main Loop
	while (window.isOpen())
	{
		//Window Display
		window.clear(Color::Black);
		window.draw(background);
		window.draw(text);
		
		btn_play.drawTo(window);

		window.display();

		//Main Event
		Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
				case Event::Closed: window.close(); break;

				case Event::MouseMoved:
					if (btn_play.isMouseOver(window))
						btn_play.setBackColor(Color::Yellow);
					else
						btn_play.setBackColor(Color::White);

				case Event::KeyPressed:
				{
					switch (event.key.code)
					{
					case Keyboard::Return:
						cout << "Press Enter  !" << endl; break;

					case Keyboard::Up:
						cout << "Press Up !" << endl; break;

					case Keyboard::Down:
						cout << "Press Down !" << endl; break;

					case Keyboard::Right:
						cout << "Press Right !" << endl; break;

					case Keyboard::Left:
						cout << "Press Left !" << endl; break;

					default:
						break;
					}
				}
				break; //End of Key Select

			default:
				break;
			}
		}
		//update
		game->update();
		//render
		game->render();
	}

	return 0;
}
