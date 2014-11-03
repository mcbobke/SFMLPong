#include <SFML/Graphics.hpp>
#include <string>

void ballReset(sf::CircleShape &ball, sf::RenderWindow &window)
{
	sf::Vector2u windowSize(window.getSize());

	ball.setPosition(windowSize.x/2, windowSize.y/2);
}

char ballOffScreen(sf::CircleShape &ball, sf::RenderWindow &window)
{
	if (ball.getPosition().x <= 0)
	{
		return 'b';
	}

	else if (ball.getPosition().x >= window.getSize().x)
	{
		return 'r';
	}

	return 'n';
}

void ballScore(char scorer, int& rscore, int& bscore)
{
	if (scorer == 'r')
		rscore++;
	else if (scorer == 'b')
		bscore++;
}