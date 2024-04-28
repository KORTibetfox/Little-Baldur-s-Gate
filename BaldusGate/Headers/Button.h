#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

class Button {

public:
    Button(std::string t, sf::Vector2f size, int charSize, sf::Color mainColor, sf::Color onMouseColor, sf::Color textColor);

    void setFont(sf::Font& font);
    void setBackColor(sf::Color color);
    void setPosition(sf::Vector2f pos);
    void drawTo(sf::RenderWindow& window);
    bool isMouseOver(sf::RenderWindow& window);
    void pressButton();

    sf::Color getMainColor();
    sf::Color getOnMouseColor();

private:
    sf::RectangleShape button;
    sf::Text text;
    sf::Vector2f btn_size;

    sf::Color mainColor;
    sf::Color onMouseColor;
};