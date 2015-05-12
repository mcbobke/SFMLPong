#pragma once

#ifndef MAIN_GAME_STATE_HPP
#define MAIN_GAME_STATE_HPP

#include "GameStateManager.hpp"
#include "BallFunctions.hpp"
#include "AIFunctions.hpp"
#include "SFML/Audio.hpp"

class MainGameState : public GameState
{
public:

	void Initialize(sf::RenderWindow *window);

	void Update(sf::RenderWindow *window);

	void Render(sf::RenderWindow *window);

	void Destroy(sf::RenderWindow *window);

private:

	sf::RectangleShape shape1;
	sf::RectangleShape shape2;
	sf::RectangleShape midLine;
	sf::RectangleShape ball;

	sf::Font scoreFont;
	sf::Text rText;
	sf::Text bText;

	sf::SoundBuffer collBuff;
	sf::Sound collSound;
	sf::SoundBuffer scoreBuff;
	sf::Sound scoreSound;

	int rscore;
	int bscore;
	float ballVelFt;
	sf::Vector2f ballVel;
	sf::Clock dT;
	float aiSpeed;
};

#endif