#include "Apple.h"

Apple::Apple(sf::Vector2f size)
{
	apple.setSize(size);
	apple.setFillColor(sf::Color::Red);
	/*apple.setRadius(5);
	apple.setOutlineColor(sf::Color::Red);
	apple.setOutlineThickness(1);*/
}

void Apple::RandomPosition()
{
	//har för tillfället (400,400)
	int x = rand() % 401;
	int y = rand() % 401;

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
