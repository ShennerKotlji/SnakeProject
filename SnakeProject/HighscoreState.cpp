#include "HighscoreState.h"

HighscoreState::HighscoreState()
{
	top10.ReadFromFile();
	top10.PrintTop10();
}

HighscoreState::~HighscoreState()
{
}

GameStates HighscoreState::Update(float dt, sf::RenderWindow & Window)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) {

		return GameStates::SHOW_MENU;

	}

	return GameStates::KEEPRUNNING;
}

void HighscoreState::draw(sf::RenderTarget & Target, sf::RenderStates state) const
{
	Target.draw(top10);
}
