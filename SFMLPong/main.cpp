#include "BallFunctions.hpp"
#include "AIFunctions.hpp"
#include "SFML/Audio.hpp"

int main()
{
	// Window Setup
	sf::RenderWindow window(sf::VideoMode(900, 500), "SFMLPong");

	// Shape Setup
	sf::RectangleShape shape1(sf::Vector2f(15, 75));
	shape1.setFillColor(sf::Color::Red);
	shape1.setPosition(30, 175);

	sf::RectangleShape shape2(sf::Vector2f(15, 75));
	shape2.setFillColor(sf::Color::Blue);
	shape2.setPosition(855, 175);

	sf::RectangleShape midLine(sf::Vector2f(5, 500));
	midLine.setFillColor(sf::Color::White);
	midLine.setPosition(448, 0);

	sf::RectangleShape ball(sf::Vector2f(10, 10));
	ball.setFillColor(sf::Color::White);
	ball.setPosition(450, 250);

	// Text setup
	sf::Font scoreFont;
	scoreFont.loadFromFile("retganon.ttf");

	sf::Text rText("00", scoreFont);
	rText.setCharacterSize(30);
	rText.setStyle(sf::Text::Bold);
	rText.setColor(sf::Color::White);
	rText.setPosition(418, 0);

	sf::Text bText("00", scoreFont);
	bText.setCharacterSize(30);
	bText.setStyle(sf::Text::Bold);
	bText.setColor(sf::Color::White);
	bText.setPosition(462, 0);

	// Sound setup
	sf::SoundBuffer collBuff;
	collBuff.loadFromFile("Beep2.wav");
	sf::Sound collSound;
	collSound.setBuffer(collBuff);

	sf::SoundBuffer scoreBuff;
	scoreBuff.loadFromFile("Beep1.wav");
	sf::Sound scoreSound;
	scoreSound.setBuffer(scoreBuff);

	// Various Necessities
	sf::Clock dT;
	float ballVelFt = 300.f;
	sf::Vector2f ballVel(-ballVelFt, ballVelFt);
	float aiSpeed = 175.f;
	int rscore = 0, bscore = 0;

	while (window.isOpen()) // Mainloop
	{
		if (rscore == 10 || bscore == 10) // Check if game over
		{
			window.close();
			break;
		}

		sf::Time deltaTime = dT.getElapsedTime(); // Get elapsed time since last frame
		dT.restart(); // Restart for next calculation

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		// Ball Updates
		char result = ballOffScreen(ball, window);
		char result2 = ballHasCollided(ball, window, shape1, shape2);

		if (result != 'n')
		{
			scoreSound.play();
			ballScore(result, rscore, bscore, rText, bText);
			ballReset(ball, window);
		}
		else if (result2 != 'n')
		{
			collSound.play();
			ballCollide(ballVel, result2, shape1, shape2, ball);
		}

		ball.move(ballVel * deltaTime.asSeconds());

		// Paddle Updates

		sf::Vector2f pad1pos = shape1.getPosition();

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && pad1pos.y > 0)
			shape1.move(0, -0.1f);
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && pad1pos.y < 425.f)
			shape1.move(0, 0.1f);

		//aiMove(shape2, ball, aiSpeed * deltaTime.asSeconds());

		// Uncomment the above function call and comment out the below code to enable AI

		sf::Vector2f pad2pos = shape2.getPosition();

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && pad2pos.y > 0)
			shape2.move(0, -0.1f);
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && pad2pos.y < 425.f)
			shape2.move(0, 0.1f);

		// Screen updates
		
		window.clear();
		window.draw(shape1);
		window.draw(shape2);
		window.draw(midLine);
		window.draw(ball);
		window.draw(rText);
		window.draw(bText);
		window.display();
	}

	return 0;
}