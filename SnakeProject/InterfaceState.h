#pragma once
#define INTERFACESTATE_H
#include <SFML\Graphics.hpp>

enum class GameStates
{

	EXIT = 0,
	START_GAME = 1,
	SHOW_HIGHSCORE = 2,
	KEEPRUNNING = 3,
	SHOW_MENU = 4

};
class InterfaceState : public sf::Drawable
{
public:

	virtual ~InterfaceState() {}
	virtual GameStates Update(float dt,sf::RenderWindow &Window) = 0;
	

};
