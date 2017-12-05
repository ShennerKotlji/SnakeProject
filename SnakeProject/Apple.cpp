#include "Apple.h"

Apple::Apple(sf::Texture &appleTexture, sf::Vector2f size)
{
	apple.setSize(size);
	apple.setPosition(200.0f, 200.0f);
	apple.setTexture(&appleTexture);
}

void Apple::RandomPosition()
{
	int x = rand() % 500;
	int y = rand() % 500;

	apple.setPosition(sf::Vector2f(x, y));
}

void Apple::draw(sf::RenderTarget & target, sf::RenderStates state) const
{
	target.draw(apple);
}

sf::FloatRect Apple::getGlobalBounds()
{
	return apple.getGlobalBounds();
}
