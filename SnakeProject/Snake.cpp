#include "Snake.h"
#include <iostream>


Snake::Snake()
{
	this->moveTimer = 0.25f;
	this->capacity = 10;
	bodyParts = new sf::RectangleShape[capacity];
	this->tailLength = 10.0f;
	this->tailWidth = 10.0f;
	this->count = 3;
	for (int i = 0; i < count; i++)
	{
		bodyParts[i].setSize({ tailLength,tailWidth });
		bodyParts[i].setFillColor(sf::Color::Blue);
		bodyParts[i].setPosition({ 250 + (i*(tailWidth + 1)),250 });
	}
}

Snake::~Snake()
{
}

void Snake::draw(sf::RenderTarget & target, sf::RenderStates state) const
{
	for (int i = 0; i < count; i++) {
		target.draw(bodyParts[i]);
	}
	//target.draw(snakeBody);
}

void Snake::move(sf::Vector2f direction, float currentTime)
{
	if (moveTimer <= 0) {


		auto temp = bodyParts[0].getPosition();
		
		bodyParts[0].move(sf::Vector2f(direction.x * 12, direction.y * 12));
		if (bodyParts[0].getPosition() != temp) {

			for (int i = 1; i < count; i++)
			{

				auto temp2 = bodyParts[i].getPosition();
				bodyParts[i].setPosition(temp);
				temp = temp2;

			}
		}


		moveTimer = 0.10f;
	}
	else {

		moveTimer = moveTimer - currentTime;
	}
}

void Snake::newSize()
{
	if (count == capacity) {

		Expand();
	}

	bodyParts[count].setSize({ tailLength,tailWidth });
	bodyParts[count].setFillColor(sf::Color::Blue);
	bodyParts[count].setPosition(bodyParts[count - 1].getPosition());
	count = count + 1;
}

bool Snake::collision() const
{
	bool crasch = false;
	for (int i = 1; i < count; i++) {

		if (bodyParts[0].getGlobalBounds().intersects(bodyParts[i].getGlobalBounds())) {

			crasch = true;
		}
	}
	return crasch;
}

bool Snake::wallCollision()
{

	sf::Vector2f position(bodyParts[0].getPosition());
	float x = position.x;
	//std::cout << "x: " << x << std::endl;

	float y = position.y;
	//std::cout << "y: " << y << std::endl;
	bool outOfWindow = false;
	if (500 < x || 500 < y)
	{
		outOfWindow = true;
	}
	if (x < 0 || y < 0) {

		outOfWindow = true;
	}

	return outOfWindow;
}

sf::FloatRect Snake::getGlobalBounds()
{
	return bodyParts[0].getGlobalBounds();
}

bool Snake::EatingApple(Apple apple)
{
	bool eating = false;

	if (bodyParts[0].getGlobalBounds().intersects(apple.getGlobalBounds())) {

		eating = true;
	}

	return eating;
}

void Snake::Expand()
{
	capacity = capacity * 10;
	sf::RectangleShape* temp = new sf::RectangleShape[capacity];

	for (int i = 0; i < count; i++)
	{
		temp[i] = bodyParts[i];
	}


	delete[] bodyParts;
	bodyParts = temp;
}
