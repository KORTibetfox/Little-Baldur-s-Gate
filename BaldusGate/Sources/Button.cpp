#pragma warning(disable:4996)
#include <SFML/Graphics.hpp>
#include "..\Headers\Button.h"

Button::Button(std::string t, sf::Vector2f size, int charSize, sf::Color mainColor, sf::Color onMouseColor, sf::Color text_color) {

    text.setString(t);
    text.setColor(text_color);
    text.setCharacterSize(15);

    btn_size = size;

    button.setSize(size);
    this->mainColor = mainColor;

    button.setFillColor(mainColor);
    this->onMouseColor = onMouseColor;
}

void Button::setFont(sf::Font& font) {
    text.setFont(font);
}

void Button::setBackColor(sf::Color color) {
    button.setFillColor(color);
}

void Button::setPosition(sf::Vector2f pos) {

    text.setPosition(pos);
    pos.x -= (btn_size.x / 3);
    pos.y -= (btn_size.y / 3);

    button.setPosition(pos);
}

void Button::drawTo(sf::RenderWindow& window) {
    window.draw(button);
    window.draw(text);
}

bool Button::isMouseOver(sf::RenderWindow& window) {
    float mouse_X = sf::Mouse::getPosition(window).x;
    float mouse_Y = sf::Mouse::getPosition(window).y;

    float btnPosX = button.getPosition().x;
    float btnPosy = button.getPosition().y;

    float btn_xPos_width = button.getPosition().x + button.getLocalBounds().width;
    float btn_yPos_Height = button.getPosition().y + button.getLocalBounds().height;

    if (mouse_X < btn_xPos_width && mouse_X > btnPosX && mouse_Y < btn_yPos_Height && mouse_Y > btnPosy)
        return true;

    return false;
}

void Button::pressButton()
{
        std::cout << "Button Pressed!";   
}

sf::Color Button::getMainColor()
{
    return mainColor;
}

sf::Color Button::getOnMouseColor()
{
    return onMouseColor;
}
