#pragma once
#define GAME_H
#include "InterfaceState.h"
#include "Snake.h"
#include "Highscore.h"


class Game : public InterfaceState
{

public:
	Game();
	~Game();
	GameStates Update(float dt, sf::RenderWindow &Window);
	void draw(sf::RenderTarget & Target, sf::RenderStates state) const;


private:
	Snake snake;
	Apple apple;
	Highscore highscore;
	sf::Vector2f snakeDir = { 0,0 };
	sf::Texture texture;
	std::string disableReverseMove;



};


