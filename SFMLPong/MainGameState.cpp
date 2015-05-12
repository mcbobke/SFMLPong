#include "MainGameState.hpp"

void MainGameState::Initialize(sf::RenderWindow* window)
{
	// Shape Setup
	shape1 = sf::RectangleShape(sf::Vector2f(15, 75));
	shape1.setFillColor(sf::Color::Red);
	shape1.setPosition(30, 175);

	shape2 = sf::RectangleShape(sf::Vector2f(15, 75));
	shape2.setFillColor(sf::Color::Blue);
	shape2.setPosition(855, 175);

	midLine = sf::RectangleShape(sf::Vector2f(5, 500));
	midLine.setFillColor(sf::Color::White);
	midLine.setPosition(448, 0);

	ball = sf::RectangleShape(sf::Vector2f(10, 10));
	ball.setFillColor(sf::Color::White);
	ball.setPosition(450, 250);

	// Text setup
	scoreFont = sf::Font();
	scoreFont.loadFromFile("retganon.ttf");

	rText = sf::Text("00", scoreFont);
	rText.setCharacterSize(30);
	rText.setStyle(sf::Text::Bold);
	rText.setColor(sf::Color::White);
	rText.setPosition(418, 0);

	bText = sf::Text("00", scoreFont);
	bText.setCharacterSize(30);
	bText.setStyle(sf::Text::Bold);
	bText.setColor(sf::Color::White);
	bText.setPosition(462, 0);

	// Sound setup
	collBuff = sf::SoundBuffer();
	collBuff.loadFromFile("Beep2.wav");
	collSound = sf::Sound();
	collSound.setBuffer(collBuff);

	scoreBuff = sf::SoundBuffer();
	scoreBuff.loadFromFile("Beep1.wav");
	scoreSound = sf::Sound();
	scoreSound.setBuffer(scoreBuff);

	// Various Necessities
	dT = sf::Clock();
	ballVelFt = 300.f;
	ballVel = sf::Vector2f(-ballVelFt, ballVelFt);
	aiSpeed = 175.f;
	rscore = 0;
	bscore = 0;
}

void MainGameState::Update(sf::RenderWindow* window)
{
	if (rscore == 10 || bscore == 10) // Check if game over
	{
		stateManager.SetState(nullptr);
		return;
	}

	sf::Time deltaTime = dT.getElapsedTime(); // Get elapsed time since last frame
	dT.restart(); // Restart for next calculation

	sf::Event event;
	while (window->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			stateManager.SetState(nullptr);
			return;
		}
	}

	// Ball Updates
	char result = ballOffScreen(ball, *window);
	char result2 = ballHasCollided(ball, *window, shape1, shape2);

	if (result != 'n')
	{
		scoreSound.play();
		ballScore(result, rscore, bscore, rText, bText);
		ballReset(ball, *window);
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
}

void MainGameState::Render(sf::RenderWindow* window)
{
	window->clear();
	window->draw(shape1);
	window->draw(shape2);
	window->draw(midLine);
	window->draw(ball);
	window->draw(rText);
	window->draw(bText);
	window->display();
}

void MainGameState::Destroy(sf::RenderWindow* window)
{
	
}