#include "SFML/Graphics.hpp"

class GameState
{
public:
	GameState();

	virtual ~GameState();

	virtual void Initialize(sf::RenderWindow* window);

	virtual void Update(sf::RenderWindow *window);

	virtual void Render(sf::RenderWindow *window);

	virtual void Destroy(sf::RenderWindow *window);
};