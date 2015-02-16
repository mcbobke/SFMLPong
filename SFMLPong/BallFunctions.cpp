#include <SFML/Graphics.hpp>
#include <string>
#include <math.h>

// TODO: Reduce the number of arguments constantly being passed to these functions every tick

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

void ballScore(char scorer, int& rscore, int& bscore, sf::Text &rText, sf::Text &bText)
{
	if (scorer == 'r')
	{
		rscore++;
		rText.setString("0" + std::to_string(rscore));
	}
	else if (scorer == 'b')
	{
		bscore++;
		bText.setString("0" + std::to_string(bscore));
	}
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
		{
			ball.setPosition(ballpos.x, 0);
			return 't';
		}
		else if (ballpos.y + 10 > winsize.y) // bottom of screen
		{
			ball.setPosition(ballpos.x, winsize.y - 10);
			return 'b';
		}

		// red paddle
		if (ballpos.x < pad1pos.x + 15 && ballpos.x > pad1pos.x + 13 && ballpos.x + 10 > pad1pos.x && // This whole line MUST be true
			((ballpos.y > pad1pos.y && ballpos.y + 10 < pad1pos.y + 75) || // These 3 lines must have 1 true
			(ballpos.y < pad1pos.y && ballpos.y + 10 > pad1pos.y) || 
			(ballpos.y > pad1pos.y && ballpos.y < pad1pos.y + 75)))
		{
			ball.setPosition(pad1pos.x + 15, ballpos.y);
			return '1';
		}

		// blue paddle
		else if (ballpos.x + 10 > pad2pos.x && ballpos.x + 10 < pad2pos.x + 2 && ballpos.x < pad2pos.x + 15 && // Same as above
			((ballpos.y > pad2pos.y && ballpos.y + 10 < pad2pos.y + 75) || 
			(ballpos.y < pad2pos.y && ballpos.y + 10 > pad2pos.y) || 
			(ballpos.y > pad2pos.y && ballpos.y < pad2pos.y + 75)))
		{
			ball.setPosition(pad2pos.x - 15, ballpos.y);
			return '2';
		}

		return 'n'; // no collision
	}
}

void ballReflection(sf::Vector2f &ballVel, sf::RectangleShape &paddle, sf::RectangleShape &ball)
{
	float paddleHeight = paddle.getSize().y;

	// Where is the middle of the ball when the ball hit the paddle? (relative to the middle of the paddle)
	float relativeIntersectY = (paddle.getPosition().y + (paddleHeight / 2)) - (ball.getPosition().y + (ball.getSize().y / 2));

	ballVel.x = -ballVel.x;

	if (relativeIntersectY < -20.f)
	{
		if (ballVel.y < 0)
			ballVel.y = -(ballVel.y + ballVel.y * -0.15);
		else
			ballVel.y = ballVel.y + ballVel.y * -0.15;
	}
	else if (relativeIntersectY >= -20.f && relativeIntersectY < 0)
	{
		ballVel.y = ballVel.y + ballVel.y * -0.05;
	}
	else if (relativeIntersectY == 0)
	{
		ballVel.y = -ballVel.y;
	}
	else if (relativeIntersectY > 0 && relativeIntersectY <= 20.f)
	{
		ballVel.y = ballVel.y + ballVel.y * 0.05;
	}
	else if (relativeIntersectY > 20.f)
	{
		if (ballVel.y > 0)
			ballVel.y = -(ballVel.y + ballVel.y * 0.15);
		else
			ballVel.y = ballVel.y + ballVel.y * 0.15;
	}
}

void ballCollide(sf::Vector2f &ballVel, char collideObj, sf::RectangleShape &paddle1, sf::RectangleShape &paddle2, sf::RectangleShape &ball)
{
	if (collideObj == 't' || collideObj == 'b')
		ballVel.y  = ballVel.y * -1;
	else if (collideObj == '1')
	{
		//ballVel.x = ballVel.x * -1; // need to replace with ballReflection after function is finished
		ballReflection(ballVel, paddle1, ball);
	}
	else if (collideObj == '2')
	{
		//ballVel.x = ballVel.x * -1;
		ballReflection(ballVel, paddle2, ball);
	}
}