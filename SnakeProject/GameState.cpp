#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <iostream>
#include <ctime>
#include "Snake.h"
#include "Apple.h"
#include "Highscore.h"
#include <string>

int main()
{

	srand(static_cast<unsigned int>(time(0)));

	sf::RenderWindow window(sf::VideoMode(500, 500), "Shenners Snake Game!");
	/*sf::Texture txt;
	txt.loadFromFile("background1.jpg");
	sf::Sprite background(txt);*/
	
	
	
	/*sf::RectangleShape line(sf::Vector2f(100,5));
	line.setFillColor(sf::Color::White);*/

	//snake kroppen
	Snake snakeBody;
	//låter snaken börja i mitten av rutan
	//snakeBody.setStartPosition(sf::Vector2f(250, 250));

	//äpple
	sf::Texture appleTexture;
	appleTexture.loadFromFile("ApplePic.png");
	Apple apple(appleTexture, sf::Vector2f(20, 20));

	//riktning
	sf::Vector2f snakeDir = { 0,0 };
	sf::Clock clock;
	std::string disableReverseMove;

	//highscore
	Highscore scoreSheet;

	while (window.isOpen())
	{

		sf::Event event;
		float currentTime;
		currentTime = clock.restart().asSeconds();

		while (window.pollEvent(event))
		{

			if (event.type == sf::Event::Closed)
			{
				window.close();
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			{
				if (disableReverseMove != "Right") {

					disableReverseMove = "left";
					snakeDir = { -1, 0 };

				}
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			{
				if (disableReverseMove != "left") {

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
					snakeDir = { 0, -1};

				}
			}
					
		}

		if (snakeBody.EatingApple(apple))
		{
			apple.RandomPosition();
			snakeBody.newSize(10);
			scoreSheet.setScore(1);
			scoreSheet.ToString();
		}

		if (snakeBody.wallCollision() == true) {

			system("pause");
		}
		if (snakeBody.collision() == true)
		{
			std::cin.get();
		}

		snakeBody.move(snakeDir, currentTime);
		window.clear();
	/*	window.draw(background);*/
		window.draw(scoreSheet);
		window.draw(snakeBody);
		window.draw(apple);
		window.display();


	

	}
	return 0;
}