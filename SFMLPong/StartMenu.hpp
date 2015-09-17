#pragma once

#ifndef START_MENU_HPP
#define START_MENU_HPP

#include "SFML/Graphics.hpp"

class StartMenu : public GameState
{
public:

	void Initialize(sf::RenderWindow *window) override;

	void Update(sf::RenderWindow *window) override;

	void Render(sf::RenderWindow *window) override;

	void Destroy(sf::RenderWindow *window) override;

private:

};

#endif