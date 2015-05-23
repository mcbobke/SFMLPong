#pragma once

#ifndef MAIN_GAME_STATE_HPP
#define MAIN_GAME_STATE_HPP

#include "GameStateManager.hpp"
#include "BallFunctions.hpp"
#include "AIFunctions.hpp"
#include "SFML/Audio.hpp"
#include "Score.hpp"

class MainGameState : public GameState
{
public:

	void Initialize(sf::RenderWindow *window) override;

	void Update(sf::RenderWindow *window) override;

	void Render(sf::RenderWindow *window) override;

	void Destroy(sf::RenderWindow *window) override;

private:

	sf::RectangleShape shape1;
	sf::RectangleShape shape2;
	sf::RectangleShape midLine;
	sf::RectangleShape ball;

	sf::Font scoreFont;
	Score rScore;
	Score bScore;

	sf::SoundBuffer collBuff;
	sf::Sound collSound;
	sf::SoundBuffer scoreBuff;
	sf::Sound scoreSound;

	float ballVelFt;
	sf::Vector2f ballVel;
	sf::Clock dT;
	float aiSpeed;
};

#endif