#include <SFML/Graphics.hpp>
#include <string>

void ballReset(sf::CircleShape &ball, sf::RenderWindow &window)
{
	sf::Vector2u windowSize(window.getSize());

	ball.setPosition(windowSize.x/2, windowSize.y/2);
}

char ballOffScreen(sf::CircleShape &ball, sf::RenderWindow &window)
{
	sf::Vector2f pos = ball.getPosition();
	float rad = ball.getRadius();

	if (pos.x - rad <= 0)
	{
		return 'b'; // Blue scored
	}

	else if (pos.x - rad >= window.getSize().x)
	{
		return 'r'; // Red scored
	}

	return 'n'; // No score
}

void ballScore(char scorer, int& rscore, int& bscore)
{
	if (scorer == 'r')
		rscore++;
	else if (scorer == 'b')
		bscore++;
}

char ballHasCollided(sf::CircleShape &ball, sf::RenderWindow &window, sf::RectangleShape &pad1, sf::RectangleShape &pad2)
{
	sf::Vector2f ballpos = ball.getPosition();
	sf::Vector2f pad1pos = pad1.getPosition();
	sf::Vector2f pad2pos = pad2.getPosition();
	sf::Vector2u winsize = window.getSize();

	float rad = ball.getRadius();

	if (ballpos.x - rad > 0 && ballpos.x + rad < winsize.x)
	{
		if (ballpos.y - rad <= 0) // top of screen
			return 't';
		else if (ballpos.y + rad >= winsize.y) // bottom of screen
			return 'b';

		// Test for paddles
	}

	return 'n';
}