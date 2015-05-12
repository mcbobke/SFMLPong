#include "GameStateManager.h"

GameStateManager::GameStateManager()
{
	this->state = nullptr;
}

void GameStateManager::SetState(GameState* state)
{
	if (state != nullptr)
	{
		this->state->Destroy(this->window);
	}

	this->state = state;

	if (state != nullptr)
	{
		this->state->Initialize(this->window);
	}
}

void GameStateManager::SetWindow(sf::RenderWindow* window)
{
	this->window = window;
}
