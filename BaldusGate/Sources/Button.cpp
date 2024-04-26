#pragma warning(disable:4996)
#include <SFML/Graphics.hpp>
#include "..\Headers\Button.h"

using namespace std;
using namespace sf;

Button::Button(string t, Vector2f size, int charSize, Color bgColor, Color text_color) {

    text.setString(t);
    text.setColor(text_color);
    text.setCharacterSize(15);

    button.setSize(size);
    button.setFillColor(bgColor);
}

void Button::setFont(Font& font) {
    text.setFont(font);
}

void Button::setBackColor(Color color) {
    button.setFillColor(color);
}

void Button::setPosition(Vector2f pos) {
    button.setPosition(pos);

    float xPos = (pos.x + button.getGlobalBounds().width / 2) - (text.getGlobalBounds().width / 2);
    float yPos = (pos.y + button.getGlobalBounds().height / 2) - (text.getGlobalBounds().height / 2);
    text.setPosition({ xPos, yPos });
}

void Button::drawTo(RenderWindow& window) {
    window.draw(button);
    window.draw(text);
}

bool Button::isMouseOver(RenderWindow& window) {
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