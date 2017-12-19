#include "Game.h"
#include <iostream>

Game::Game()
{;
	texture.loadFromFile("background1.jpg");
	sf::Sprite(texture);
}

Game::~Game()
{
}

GameStates Game::Update(float dt, sf::RenderWindow &Window)
{

	disableReverseMove;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		if (disableReverseMove != "Right")
		{
			disableReverseMove = "left";
			snakeDir = { -1, 0 };
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		if (disableReverseMove != "left")
		{
			disableReverseMove = "Right";
			snakeDir = { 1, 0 };
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		if (disableReverseMove != "Up")
		{
			disableReverseMove = "Down";
			snakeDir = { 0, 1 };
		}
	}
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		if (disableReverseMove != "Down")
		{
			disableReverseMove = "Up";
			snakeDir = { 0, -1 };
		}
	}

	if (snake.EatingApple(apple))
	{
		apple.RandomPosition();
		snake.newSize();
		highscore.setScore(1);
		highscore.ToString();
	}

	if (snake.wallCollision() == true) {
		highscore.ReadFromFile();
		highscore.SaveToFile();
		

		return GameStates::SHOW_MENU;
	}
	if (snake.collision() == true)
	{
		highscore.ReadFromFile();
		highscore.SaveToFile();
		
		
		return GameStates::SHOW_MENU;
	
	}
	
	snake.move(snakeDir, dt);

	return GameStates::KEEPRUNNING;
}


void Game::draw(sf::RenderTarget & Target, sf::RenderStates state) const
{
	Target.draw(snake);
	Target.draw(apple);
	Target.draw(highscore);
	
}
