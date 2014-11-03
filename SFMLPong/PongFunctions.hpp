#ifndef PONG_FUNCTIONS_HPP
#define PONG_FUNCTIONS_HPP

#include <SFML/Graphics.hpp>
#include <string>

void ballReset(sf::CircleShape &ball, sf::RenderWindow &window);
char ballOffScreen(sf::CircleShape &ball, sf::RenderWindow &window);
void ballScore(char scorer, int& rscore, int& bscore);
char ballHasCollided(sf::CircleShape &ball, sf::RenderWindow &window, sf::RectangleShape &pad1, sf::RectangleShape &pad2);

#endif