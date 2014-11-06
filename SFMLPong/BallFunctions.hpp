#ifndef BALL_FUNCTIONS_HPP
#define BALL_FUNCTIONS_HPP

#include <SFML/Graphics.hpp>

void ballReset(sf::RectangleShape &ball, sf::RenderWindow &window);
char ballOffScreen(sf::RectangleShape &ball, sf::RenderWindow &window);
void ballScore(char scorer, int& rscore, int& bscore, sf::Text &rText, sf::Text &bText);
char ballHasCollided(sf::RectangleShape &ball, sf::RenderWindow &window, sf::RectangleShape &pad1, sf::RectangleShape &pad2);
void ballCollide(sf::Vector2f &ballvel, char collideObj);

#endif