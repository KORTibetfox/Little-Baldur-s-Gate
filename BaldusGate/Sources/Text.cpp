#include "..\Headers\Text.h"

CreateText::CreateText(std::string str, sf::Font font, sf::Color color, int size)
{
	text.setString(str);
	text.setFont(font);
	text.setFillColor(color);
	text.setCharacterSize(size);
	std::cout << "im here" << std::endl;
}

void CreateText::setMiddle()
{
	text.setOrigin(sf::Vector2f(text.getLocalBounds().width / 2, text.getLocalBounds().height / 2));
}

void CreateText::setPosition(sf::Vector2f pos)
{
	text.setPosition(pos);
}

void CreateText::drawTo(sf::RenderWindow& window)
{
	window.draw(text);
}

void CreateText::setString(std::string str)
{
	text.setString(str);
}

void CreateText::setOutlineColor(sf::Color color)
{
	text.setOutlineColor(color);
}

void CreateText::setBold()
{
	text.setStyle(sf::Text::Bold);
}

void CreateText::setUnderLine()
{
	text.setStyle(sf::Text::Underlined);
}