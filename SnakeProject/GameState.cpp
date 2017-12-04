#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <iostream>
#include <ctime>
#include "Snake.h"
#include "Apple.h"
#include "Highscore.h"

int main()
{

	srand(static_cast<unsigned int>(time(0)));

	sf::RenderWindow window(sf::VideoMode(500, 500), "Shenners Snake Game!");
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

	//highscore text
	sf::Font Candara;
	Candara.loadFromFile("Candara.ttf");
	Highscore scoreSheet(Candara);




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
				snakeDir = { -1, 0 };
				/*snakeBody.move({ -12, 0 },0);*/
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			{
				snakeDir = { 1, 0 };
				/*snakeBody.move({ 12, 0 },0);*/
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			{
				snakeDir = { 0, 1};
				/*snakeBody.move({ 0, 12 },0);*/
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			{
				snakeDir = { 0, -1};
			/*	snakeBody.move({ 0, -12 }, 0);*/
			}

		}

		if (snakeBody.EatingApple(apple))
		{
			apple.RandomPosition();
			snakeBody.newSize(10);
			scoreSheet.setScore(1);
		}

		
		snakeBody.move(snakeDir, currentTime);
		window.clear();
		window.draw(scoreSheet);
		window.draw(snakeBody);
		window.draw(apple);
		window.display();


		/*switch (event.type)
		{
		case sf::Event::Resized:
		std::cout << "New window width: " << event.size.width << "New window height: " << event.size.height << std::endl;
		break;*/

	}
	return 0;
}