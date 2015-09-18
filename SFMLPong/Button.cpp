#include "Button.hpp"

Button::Button(std::string displayString, sf::Font &font, unsigned int fontSize,
	sf::Vector2f buttonSize, sf::RenderWindow *window)
	: displayText(displayString, font, fontSize), buttonSize(buttonSize), window(window)
{

}