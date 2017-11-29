#pragma once
#define APPLE_H
#include <SFML\Graphics.hpp>


class Apple
{

public:
	Apple(sf::Texture &appleTexture, sf::Vector2f size);
	void RandomPosition();
	void draw(sf::RenderWindow & window);

	sf::FloatRect getGlobalBounds();
	



private:
	sf::RectangleShape apple;
	
	


};



