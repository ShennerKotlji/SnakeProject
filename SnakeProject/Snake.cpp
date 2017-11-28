#include "Snake.h"


Snake::Snake(sf::Vector2f defaultSize)
{
	
	snakeBody.setSize(defaultSize);
	snakeBody.setFillColor(sf::Color::White);
}

Snake::~Snake()
{
}

void Snake::Draw(sf::RenderWindow & window)
{
	window.draw(snakeBody);
}

void Snake::move(sf::Vector2f direction)
{
	snakeBody.move(direction);
}

void Snake::setStartPosition(sf::Vector2f startPos)
{
	snakeBody.setPosition(startPos);
}

//void Snake::newSize()
//{
//	int incrementTail; 5.0f;
//	snakeBody.setSize({incrementTail,2.0f });
//	incrementTail = incrementTail + 1.0f;
//	
//
//}

bool Snake::EatingApple(Apple apple)
{
	bool eating = false;
	if (snakeBody.getGlobalBounds().intersects(apple.getGlobalBounds())) {

		eating = true;
	}

	return eating;
}
