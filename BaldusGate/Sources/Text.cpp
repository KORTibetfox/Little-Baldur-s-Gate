#include "..\Headers\Text.h"

CreateText::CreateText(std::string str, sf::Font* font, sf::Color color, int size)
{
	line.setString(str);
	line.setFont(*font);
	line.setFillColor(color);
	line.setCharacterSize(size);
	std::cout << "\nim in setCHaractersize" << std::endl;
}

void CreateText::setMiddle()
{
	line.setOrigin(sf::Vector2f(line.getLocalBounds().width / 2, line.getLocalBounds().height / 2));
}

void CreateText::setPosition(sf::Vector2f pos)
{
	line.setPosition(pos);
	std::cout << "\nim in setPosition" << std::endl;
}

void CreateText::setString(std::string str)
{
	line.setString(str);
}

void CreateText::setOutlineColor(sf::Color color)
{
	line.setOutlineThickness(10);
	line.setOutlineColor(color);
}

void CreateText::setBold()
{
	line.setStyle(sf::Text::Bold);
}

void CreateText::setUnderLine()
{
	line.setStyle(sf::Text::Underlined);
}

void CreateText::drawTo(sf::RenderWindow& window)
{
	window.draw(line);
}