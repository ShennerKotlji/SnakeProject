#pragma once
#include "Highscore.h"
#include "InterfaceState.h"

class HighscoreState : public InterfaceState
{

public:
	HighscoreState();
	~HighscoreState();
	GameStates Update(float dt, sf::RenderWindow &Window);
	void draw(sf::RenderTarget & Target, sf::RenderStates state) const;


private:
	Highscore top10;
};
