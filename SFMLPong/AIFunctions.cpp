#include "SFML/Graphics.hpp"

void aiMove(sf::RectangleShape &pad, sf::RectangleShape &ball, float speed)
{
	sf::Vector2f ballpos = ball.getPosition();
	sf::Vector2f padpos = pad.getPosition();

	sf::Vector2f ballsize = ball.getSize();
	sf::Vector2f padsize = pad.getSize();

	if (ballpos.y + ballsize.y/2 < padpos.y + padsize.y/2)
		pad.move(0, -speed);
	else if (ballpos.y + ballsize.y/2 > padpos.y + padsize.y/2)
		pad.move(0, speed);
}