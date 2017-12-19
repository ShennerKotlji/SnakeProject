#pragma once
#define MENU

#include "InterfaceState.h"
#include "Highscore.h"
#include <SFML/Graphics.hpp>

class Menu : public InterfaceState , public sf::Drawable
{

public:
	Menu();
	~Menu();

	GameStates Update(float dt, sf::RenderWindow &Window);
	void draw(sf::RenderTarget & target, sf::RenderStates State) const;

	
	

private:
	sf::Font textStyle;
	sf::Text text[3];
	sf::RectangleShape textBox;
	sf::RenderWindow currentWindow;
	
	
	

};

