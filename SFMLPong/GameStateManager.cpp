#include "GameStateManager.hpp"

GameStateManager::GameStateManager()
{
	this->state = nullptr;
}

void GameStateManager::SetState(GameState* state)
{
	if (this->state != nullptr)
	{
		this->state->Destroy(this->window);

		delete this->state;
	}

	this->state = state;

	if (this->state != nullptr)
	{
		this->state->Initialize(this->window);
	}
}

void GameStateManager::SetWindow(sf::RenderWindow* window)
{
	this->window = window;
}

void GameStateManager::UpdateState()
{
	if (this->state != nullptr)
		state->Update(this->window);
}

void GameStateManager::RenderState()
{
	if (this->state != nullptr)
		state->Render(this->window);
}

bool GameStateManager::stateExists()
{
	return state != nullptr;
}