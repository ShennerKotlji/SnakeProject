#pragma once
#include <SFML\Graphics.hpp>
#include "Apple.h"

class Snake : public sf::Drawable
{

public:
	Snake();
	~Snake();

	void Update(float dt);
	void draw(sf::RenderTarget & target, sf::RenderStates state) const;
	void move(sf::Vector2f direction);
	void setStartPosition(sf::Vector2f startPos);

	void newSize(float tailLength);

	bool EatingApple(Apple apple);

private:
	//sf::RectangleShape snakeBody;
	void Expand();
	float tailLength;
	float tailWidth;
	sf::RectangleShape *bodyParts;
	int count;
	int capacity;

	
	

};
