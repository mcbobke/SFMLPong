#pragma once

#ifndef SCORE_HPP
#define SCORE_HPP

#include "SFML/Graphics.hpp"

class Score
{
public:

	Score();
	Score(sf::Font& font, unsigned int charSize, sf::Uint32 style, sf::Color color, float xPos, float yPos);
	void incrementScore();
	void setText();
	void drawScore(sf::RenderWindow* window);
	unsigned int getScore();

private:

	sf::Text text;
	unsigned int currentScore;
};

#endif