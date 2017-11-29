#include "Apple.h"

Apple::Apple(sf::Texture &appleTexture, sf::Vector2f size)
{
	apple.setSize(size);
	apple.setPosition(200.0f, 200.0f);
	apple.setTexture(&appleTexture);
}

void Apple::RandomPosition()
{
	int x = rand() % 801;
	int y = rand() % 801;;

	apple.setPosition(sf::Vector2f(x, y));
}

void Apple::draw(sf::RenderWindow & window)
{
	window.draw(apple);
}

sf::FloatRect Apple::getGlobalBounds()
{
	return apple.getGlobalBounds();
}
