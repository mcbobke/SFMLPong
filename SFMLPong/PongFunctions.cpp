#include <SFML/Graphics.hpp>
#include <string>

void ballReset(sf::RectangleShape &ball, sf::RenderWindow &window)
{
	sf::Vector2u windowSize(window.getSize());

	ball.setPosition(windowSize.x/2, windowSize.y/2);
}

char ballOffScreen(sf::RectangleShape &ball, sf::RenderWindow &window)
{
	sf::Vector2f pos = ball.getPosition();

	if (pos.x <= 0)
	{
		return 'b'; // Blue scored
	}

	else if (pos.x + 10 >= window.getSize().x)
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

char ballHasCollided(sf::RectangleShape &ball, sf::RenderWindow &window, sf::RectangleShape &pad1, sf::RectangleShape &pad2)
{
	sf::Vector2f ballpos = ball.getPosition();
	sf::Vector2f pad1pos = pad1.getPosition();
	sf::Vector2f pad2pos = pad2.getPosition();
	sf::Vector2u winsize = window.getSize();

	if (ballpos.x > 0 && ballpos.x + 10 < winsize.x)
	{
		if (ballpos.y < 0) // top of screen
			return 't';
		else if (ballpos.y + 10 > winsize.y) // bottom of screen
			return 'b';

		// red paddle
		if (ballpos.x < pad1pos.x + 15 && ballpos.x > pad1pos.x + 13 && ballpos.x + 10 > pad1pos.x &&
			((ballpos.y > pad1pos.y && ballpos.y + 10 < pad1pos.y + 75) ||
			(ballpos.y < pad1pos.y && ballpos.y + 10 > pad1pos.y) || 
			(ballpos.y > pad1pos.y && ballpos.y < pad1pos.y + 75)))
		{
			ball.setPosition(pad1pos.x + 15, ballpos.y);
			return '1';
		}

		// blue paddle
		else if (ballpos.x + 10 > pad2pos.x && ballpos.x + 10 < pad2pos.x + 2 && ballpos.x < pad2pos.x + 15 &&
			((ballpos.y > pad2pos.y && ballpos.y + 10 < pad2pos.y + 75) || 
			(ballpos.y < pad2pos.y && ballpos.y + 10 > pad2pos.y) || 
			(ballpos.y > pad2pos.y && ballpos.y < pad2pos.y + 75)))
		{
			ball.setPosition(pad2pos.x - 15, ballpos.y);
			return '2';
		}

		else
			return 'n'; // no collision
	}
}

void ballCollide(sf::Vector2f &ballVel, char collideObj)
{
	if (collideObj == 't' || collideObj == 'b')
		ballVel.y  = ballVel.y * -1;
	else if (collideObj == '1' || collideObj == '2')
		ballVel.x = ballVel.x * -1;
}