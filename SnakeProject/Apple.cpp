#include "Apple.h"


Apple::Apple()
{
	texture.loadFromFile("ApplePic.png");
	apple.setSize({ 20,20 });
	apple.setPosition(200.0f, 200.0f);
	apple.setTexture(&texture);
}

Apple::~Apple()
{
}

void Apple::RandomPosition()
{
	int x = rand() % 348 + 70;
	int y = rand() % 241 + 59;

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
