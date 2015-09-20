#pragma once

#ifndef BUTTON_HPP
#define BUTTON_HPP

#include "SFML/Graphics.hpp"
#include "Utility.hpp"
#include <string>

class Button
{
public:

	Button();

	Button(std::string displayString, sf::Font &font, unsigned int fontSize,
		sf::Vector2f position, sf::RenderWindow *window);

	~Button();

	void draw(sf::RenderWindow *window);
	bool isClicked();
	bool isHovered();

private:

	sf::Text displayText;
	sf::Vector2f position;
	sf::RenderWindow *window;
	bool prevHovered;
};

#endif