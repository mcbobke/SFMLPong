#pragma once

#ifndef BALL_FUNCTIONS_HPP
#define BALL_FUNCTIONS_HPP

#include "SFML/Graphics.hpp"
#include "Score.hpp"

void ballReset(sf::RectangleShape &ball, sf::RenderWindow &window);

char ballOffScreen(sf::RectangleShape &ball, sf::RenderWindow &window);

void ballScore(char scorer, Score &rScore, Score &bScore);

char ballHasCollided(sf::RectangleShape &ball, sf::RenderWindow &window, sf::RectangleShape &pad1, sf::RectangleShape &pad2);

void ballCollide(sf::Vector2f &ballvel, char collideObj, sf::RectangleShape &paddle1, sf::RectangleShape &paddle2, sf::RectangleShape &ball);

void ballReflection(sf::Vector2f &ballVel, sf::RectangleShape &paddle, sf::RectangleShape &ball);

#endif