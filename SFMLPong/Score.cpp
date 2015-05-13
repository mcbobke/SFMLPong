#include "Score.hpp"

Score::Score()
{
}

Score::Score(sf::Font& font, unsigned int charSize, sf::Uint32 style, sf::Color color, float xPos, float yPos)
{
	currentScore = 0;
	text = sf::Text("00", font, charSize);
	text.setStyle(style);
	text.setColor(color);
	text.setPosition(xPos, yPos);
}

void Score::incrementScore()
{
	currentScore += 1;
}

void Score::setText()
{
	text.setString("0" + std::to_string(currentScore));
}

void Score::drawScore(sf::RenderWindow* window)
{
	window->draw(text);
}

unsigned int Score::getScore()
{
	return currentScore;
}