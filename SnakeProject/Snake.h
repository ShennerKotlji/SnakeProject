#pragma once
#include <SFML\Graphics.hpp>
#include "Apple.h"

class Snake
{

public:
	Snake(sf::Vector2f defaultSize);

	~Snake();

	//void Update(float dt);
	void Draw(sf::RenderWindow &window);
	void move(sf::Vector2f direction);
	void setStartPosition(sf::Vector2f startPos);

//	void newSize();

	bool EatingApple(Apple apple);

private:

	sf::RectangleShape snakeBody;
	int speed;
	





};
