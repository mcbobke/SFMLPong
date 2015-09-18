#pragma once

#ifndef BUTTON_HPP
#define BUTTON_HPP

#include "SFML/Graphics.hpp"
#include <string>

class Button
{
public:

	Button(std::string displayString, sf::Font &font, unsigned int fontSize,
	sf::Vector2f buttonSize, sf::RenderWindow *window);

	virtual ~Button();

protected:

	sf::Text displayText;
	sf::Vector2f buttonSize;
	sf::RenderWindow *window;
};

#endif