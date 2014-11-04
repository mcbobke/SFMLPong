#include <PongFunctions.hpp>

int main()
{
	// Window Setup
    sf::RenderWindow window(sf::VideoMode(500, 500), "SFMLPong");

	// Shape Setup
	sf::RectangleShape shape1(sf::Vector2f(25, 75));
	shape1.setFillColor(sf::Color::Red);
	shape1.setPosition(30, 175);

	sf::RectangleShape shape2(sf::Vector2f(25, 75));
    shape2.setFillColor(sf::Color::Blue);
	shape2.setPosition(445, 175);

	sf::RectangleShape midLine(sf::Vector2f(5, 500));
	midLine.setFillColor(sf::Color::White); 
	midLine.setPosition(250, 0);

	sf::CircleShape ball(10.f); // NEED TO WRITE: ballReset function in case of score, possibly ball collision function that takes ball loc, paddle locs, screen size
	ball.setFillColor(sf::Color::White);
	ball.setOrigin(10, 10);
	ball.setPosition(250, 250);

	// Various Necessities
	sf::Clock dT;
	float VELOCITY = 200.f;
	sf::Vector2f ballVel(-VELOCITY, VELOCITY);
	int rscore = 0, bscore = 0;

    while (window.isOpen()) // Mainloop
    {
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
			ballScore(result, rscore, bscore);
			ballReset(ball, window);
		}
		else if (result2 != 'n')
		{
			// Reflection function here
		}
		else
			ball.move(ballVel * deltaTime.asSeconds());

		// Paddle Updates
		sf::Vector2f pad1pos = shape1.getPosition();
		sf::Vector2f pad2pos = shape2.getPosition();

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && pad1pos.y >= 0)
			shape1.move(0, -VELOCITY * deltaTime.asSeconds());
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && pad1pos.y <= window.getSize().y - 75)
			shape1.move(0, VELOCITY * deltaTime.asSeconds());

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && pad2pos.y >= 0)
			shape2.move(0, -VELOCITY * deltaTime.asSeconds());
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && pad2pos.y <= window.getSize().y - 75)
			shape2.move(0, VELOCITY * deltaTime.asSeconds());

		// Screen updates
        window.clear();
		window.draw(shape1);
        window.draw(shape2);
		window.draw(midLine);
		window.draw(ball);
        window.display();
    }

    return 0;
}