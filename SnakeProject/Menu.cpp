#include "Menu.h"

Menu::Menu()
{
	
	
		textStyle.loadFromFile("georgia.ttf");

		text[0].setCharacterSize(30);
		text[0].setString("Start Game");
		text[0].setPosition(170, 120);
		text[0].setFont(textStyle);
		text[0].setFillColor(sf::Color::White);

		text[1].setCharacterSize(30);
		text[1].setString("View Top 10 highscores");
		text[1].setPosition(100,250);
		text[1].setFont(textStyle);
		text[1].setFillColor(sf::Color::White);

		text[2].setCharacterSize(30);
		text[2].setString("Exit");
		text[2].setPosition(215, 380);
		text[2].setFont(textStyle);
		text[2].setFillColor(sf::Color::White);
}

Menu::~Menu()
{
}

GameStates Menu::Update(float dt, sf::RenderWindow &Window)
{
	
	sf::Vector2i Position = sf::Mouse::getPosition(Window);
	
	
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		if (text[0].getGlobalBounds().contains(Position.x,Position.y))
		{
			return GameStates::START_GAME;
		}
		if (text[1].getGlobalBounds().contains(Position.x,Position.y))
		{
			return GameStates::SHOW_HIGHSCORE;
		}
		if (text[2].getGlobalBounds().contains(Position.x,Position.y)) {
			return GameStates::EXIT;
		}
	}

	return GameStates::KEEPRUNNING;
}

void Menu::draw(sf::RenderTarget & target, sf::RenderStates State) const
{
	
	for (int i = 0; i < 3; i++) {

		target.draw(text[i]);
	}
}

