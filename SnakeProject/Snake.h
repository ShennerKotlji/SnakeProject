#pragma once
#include <SFML\Graphics.hpp>
#include "Apple.h"

class Snake : public sf::Drawable
{

public:
	Snake();
	~Snake();

	
	void draw(sf::RenderTarget & target, sf::RenderStates state) const;
	void move(sf::Vector2f direction, float currentTime);

	void newSize(float tailLength);
	bool collision() const;
	bool wallCollision();
	sf::FloatRect getGlobalBounds();
	bool EatingApple(Apple apple);

private:

	void Expand();
	float tailLength;
	float tailWidth;
	sf::RectangleShape *bodyParts;
	int count;
	int capacity;
	float moveTimer;

	
	

};
