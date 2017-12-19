#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <iostream>
#include <ctime>
#include "Snake.h"
#include "Apple.h"
#include "Highscore.h"
#include "Game.h"
#include "Menu.h"
#include <string>
#include "HighscoreState.h"

int main()
{

	srand(static_cast<unsigned int>(time(0)));
	
	sf::RenderWindow window(sf::VideoMode(500, 500), "Shenners Snake Game!");
	sf::Texture txt;
	txt.loadFromFile("background1.jpg");
	sf::Sprite background(txt);

	sf::Clock clock;
	InterfaceState* Istate = new Menu();

	while (window.isOpen())
	{
		sf::Event event;
		float currentTime;
		currentTime = clock.restart().asSeconds();


		while (window.pollEvent(event))
		{
			
			float xpos = sf::Mouse::getPosition(window).x;
			float ypos = sf::Mouse::getPosition(window).y;

		/*	std::cout << "x: " << xpos << std::endl;
			std::cout << "y: " << ypos << std::endl;*/

			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}
		Highscore a;

		GameStates State = Istate->Update(currentTime,window);
		window.clear();
		/*window.draw(background);*/
		window.draw(*Istate);
		window.display();


		switch (State)
		{
		case GameStates::EXIT:
			window.close();
			break;
		case GameStates::START_GAME:
			delete Istate;
			window.clear();
			Istate = new Game();
			break;
		case GameStates::SHOW_HIGHSCORE:
			delete Istate;
			Istate = new HighscoreState();
			break;
		case GameStates::SHOW_MENU:
			delete Istate;
			window.clear();
			Istate = new Menu();
			break;

		}
	}

	delete Istate;
	return 0;
}

/*switch (event.type)
{

case sf::Event::Resized:
std::cout << "New window width: " << event.size.width << "New window height: " << event.size.height << std::endl;
break;
case sf::Event::Resized:
std::cout << "New window width: " << event.size.width << "New window height: " << event.size.height << std::endl;
break;
}
*/