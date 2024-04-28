#pragma once

#include "..\Headers\Macro.h"

class CreateText
{
private:
    sf::Text line;

public:
    CreateText(std::string str, sf::Font *font, sf::Color color, int size);

    void setMiddle();
    void setPosition(sf::Vector2f pos);
    void drawTo(sf::RenderWindow& window);
    void setString(std::string str);

    void setOutlineColor(sf::Color color);

    void setBold();
    void setUnderLine();
};