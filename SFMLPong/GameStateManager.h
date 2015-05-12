#include "SFML/Graphics.hpp"
#include "GameState.h"

class GameStateManager
{
public:
	GameStateManager();

	void SetState(GameState* state);

	void SetWindow(sf::RenderWindow* window);

private:
	GameState* state;

	sf::RenderWindow* window;
};