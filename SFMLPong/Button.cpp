#include "Button.hpp"

Button::Button()
{

}

Button::Button(std::string displayString, sf::Font &font, unsigned int fontSize,
	sf::Vector2f position, sf::RenderWindow *window)
	: displayText(displayString, font, fontSize), position(position), 
	window(window), prevHovered(false)
{
	sf::FloatRect bounds = displayText.getLocalBounds();
	//displayText.setOrigin(bounds.width / 2, bounds.height / 2);
	displayText.setPosition(position.x, position.y);
	displayText.setColor(sf::Color::White);
}

Button::~Button()
{

}

void Button::draw(sf::RenderWindow *window)
{
	window->draw(displayText);
}

bool Button::isClicked()
{
	if (isHovered() == true && sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		return true;
	}
	else
		return false;
}

bool Button::isHovered()
{
	sf::Vector2i mousePos = sf::Mouse::getPosition(*window);
	sf::Vector2f textPos = displayText.getPosition();
	sf::FloatRect textBounds = displayText.getLocalBounds();

	if (isInside(textPos.x, textPos.x + 50, textPos.y, 
		textPos.y + 50, mousePos.x, mousePos.y))
	{
		if (prevHovered == false)
		{
			prevHovered = true;
			displayText.setColor(sf::Color::Blue);
		}
		return true;
	}
	else
	{
		if (prevHovered == true)
		{
			prevHovered = false;
			displayText.setColor(sf::Color::White);
		}
		return false;
	}
}