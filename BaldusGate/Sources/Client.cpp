#include "..\Headers\Battle.h"
#include "..\Headers\Unit.h"
#include "..\Headers\Character.h"
#include "..\Headers\Battle.h"
#include "..\Headers\Graphics.h"
#include "..\Headers\Button.h"
#include "..\Headers\Macro.h"
#include "..\Headers\SceneManager.h"
#include "..\Headers\Scene.h"
#include <SFML/Graphics.hpp>

int main(void)
{
	//Console log
	std::cout << "Baldur's Gate" << std::endl;

	//Init Game Engine
	Game* game = Game::getInstance();

	//Main Loop
	while(game->isGameRunning()) {
		//update
		game->update();
		//render
		game->render();
	}
	return 0;
}