#include "BallFunctions.hpp"
#include "AIFunctions.hpp"
#include "SFML/Audio.hpp"
#include "GameStateManager.hpp"
#include "MainGameState.hpp"

GameStateManager stateManager;

int main()
{
	// Window Setup
	sf::RenderWindow window(sf::VideoMode(900, 500), "SFMLPong");

	// State Setup
	stateManager.SetWindow(&window);

	stateManager.SetState(new MainGameState());

	// Update loop
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
				break;
			}
		}

		if (!stateManager.stateExists())
		{
			window.close();
			break;
		}

		stateManager.UpdateState();
		stateManager.RenderState();
	}

	return 0;
}