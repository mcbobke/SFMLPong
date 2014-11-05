#include "BallFunctions.hpp"

int main()
{
	// Window Setup
    sf::RenderWindow window(sf::VideoMode(750, 500), "SFMLPong");

	// Shape Setup
	sf::RectangleShape shape1(sf::Vector2f(15, 75));
	shape1.setFillColor(sf::Color::Red);
	shape1.setPosition(30, 175);

	sf::RectangleShape shape2(sf::Vector2f(15, 75));
    shape2.setFillColor(sf::Color::Blue);
	shape2.setPosition(705, 175);

	sf::RectangleShape midLine(sf::Vector2f(5, 500));
	midLine.setFillColor(sf::Color::White); 
	midLine.setPosition(375, 0);

	sf::RectangleShape ball(sf::Vector2f(10, 10)); // NEED TO WRITE: ballReset function in case of score, possibly ball collision function that takes ball loc, paddle locs, screen size
	ball.setFillColor(sf::Color::White);
	ball.setPosition(375, 250);

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
			ballCollide(ballVel, result2);
		}
		
		ball.move(ballVel * deltaTime.asSeconds());

		// Paddle Updates
		shape1.setPosition(30, sf::Mouse::getPosition(window).y - shape1.getSize().y/2);
		///// Need to add AI for 2nd paddle

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