#include "Snake.h"


Snake::Snake()
{
	bodyParts = new sf::RectangleShape[10];
	this->tailLength = 10.0f;
	this->tailWidth = 10.0f;
	this->count = 3;
	for (int i = 0; i < 3; i++) {
	/*	
		if (count == capacity) {

		}*/
		bodyParts[i].setSize({ tailLength,tailWidth });
		bodyParts[i].setFillColor(sf::Color::White);
		bodyParts[i].setPosition({ 250+(i*(tailWidth + 1)),250 });
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

void Snake::move(sf::Vector2f direction)
{
	
	auto temp = bodyParts[0].getPosition();
	bodyParts[0].move(direction);
	for (int i = 1; i < count; i++) {
		
		auto temp2 = bodyParts[i].getPosition();
		bodyParts[i].setPosition(temp);
		temp = temp2;
	}
		
	
}

void Snake::setStartPosition(sf::Vector2f startPos)
{
	//snakeBody.setPosition(startPos);
	/*bodyParts[0].setPosition(startPos);*/
}

void Snake::newSize(float tailIncrement)
{

	/*tailLength = tailLength + tailIncrement;
	snakeBody.setSize({ tailLength,10.0f });*/
	bodyParts[count].setSize({tailLength,tailWidth});
	bodyParts[count].setFillColor(sf::Color::White);
	bodyParts[count].setPosition(bodyParts[count - 1].getPosition());
	count++;

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

	for (int i = 0; i <count; i++)
	{
		temp[i] = bodyParts[i];
	}


	delete[] bodyParts;
	bodyParts = temp;
}
