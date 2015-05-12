#pragma once

#ifndef GAME_STATE_MANAGER_HPP
#define GAME_STATE_MANAGER_HPP

#include "SFML/Graphics.hpp"

class GameState
{
public:

	virtual void Initialize(sf::RenderWindow* window) {}

	virtual void Update(sf::RenderWindow *window) {}

	virtual void Render(sf::RenderWindow *window) {}

	virtual void Destroy(sf::RenderWindow *window) {}
};

class GameStateManager
{
public:

	GameStateManager();

	void SetState(GameState* state);

	void SetWindow(sf::RenderWindow* window);

	void UpdateState();
	
	void RenderState();

	bool stateExists();

private:

	GameState* state;

	sf::RenderWindow* window;
};

extern GameStateManager stateManager;

#endif