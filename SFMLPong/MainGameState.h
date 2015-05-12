#include "GameState.h"

class MainGameState : public GameState
{
public:
	MainGameState();

	~MainGameState();

	void Initialize(sf::RenderWindow *window);

	void Update(sf::RenderWindow *window);

	void Render(sf::RenderWindow *window);

	void Destroy(sf::RenderWindow *window);
};