#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <iostream>
#include <ctime>
#include "Snake.h"
#include "Apple.h"

int main()
{

	srand(static_cast<unsigned int>(time(0)));

	sf::RenderWindow window(sf::VideoMode(500, 500), "Shenners Snake Game!");
	/*sf::RectangleShape line(sf::Vector2f(100,5));
	line.setFillColor(sf::Color::White);*/

	//snake kroppen
	Snake snakeBody;
	//låter snaken börja i mitten av rutan
	snakeBody.setStartPosition(sf::Vector2f(250, 250));

	//äpple
	sf::Texture appleTexture;
	appleTexture.loadFromFile("ApplePic.png");
	Apple apple(appleTexture, sf::Vector2f(20,20));
	


	while (window.isOpen())
	{

		sf::Event event;
		while (window.pollEvent(event))
		{
			/*switch (event.type)
			{
			case sf::Event::Resized:
				std::cout << "New window width: " << event.size.width << "New window height: " << event.size.height << std::endl;
				break;*/

				if (event.type == sf::Event::Closed)
				{
					window.close();
				}

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
				{
					snakeBody.move({ -12, 0 });
				}

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
				{
					snakeBody.move({ 12, 0 });
				}

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
				{
					snakeBody.move({ 0, 12 });

				}

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
				{
					snakeBody.move({ 0, -12 });
				}
			}

			if (snakeBody.EatingApple(apple))
			{
				apple.RandomPosition();
				snakeBody.newSize(10);
				//skicka till score-klassen när jag implementerat
			}

			//snakeBody.move(direction)
			window.clear();
			window.draw(snakeBody);
			window.draw(apple);
			window.display();
		
	}
	return 0;
}