#pragma once

#ifndef START_MENU_HPP
#define START_MENU_HPP

#include "GameStateManager.hpp"
#include "Button.hpp"

class StartMenu : public GameState
{
public:

	void Initialize(sf::RenderWindow *window) override;

	void Update(sf::RenderWindow *window) override;

	void Render(sf::RenderWindow *window) override;

	void Destroy(sf::RenderWindow *window) override;

private:

	sf::Font font;
	sf::Text titleText;
	Button startButton;
	Button quitButton;
};

#endif