#pragma once
#define APPLE_H
#include <SFML\Graphics.hpp>


class Apple : public sf::Drawable
{

public:
	Apple();
	~Apple();
	void RandomPosition();
	void draw(sf::RenderTarget & target, sf::RenderStates state) const;

	sf::FloatRect getGlobalBounds();
	

private:
	sf::RectangleShape apple;
	sf::Texture texture;
	
	


};



