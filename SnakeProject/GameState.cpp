#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>

int main()
{

	srand(static_cast<unsigned int>(time(0)));

	//sf::RenderWindow window(sf::VideoMode(400, 400), "SFML works!");
	//sf::RectangleShape line(sf::Vector2f(100,5));
	//line.setFillColor(sf::Color::White);

	//while (window.isOpen())
	//{
	//	sf::Event event;
	//	while (window.pollEvent(event))
	//	{
	//		if (event.type == sf::Event::Closed)
	//		{
	//			window.close();
	//		}
	//		
	//		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) 
	//		{
	//			line.move(-1, 0);
	//		}

	//		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	//		{
	//			line.move(1, 0);
	//		}

	//		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	//		{
	//			line.move(0, 1);
	//			//line.rotate(90);

	//		}

	//		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	//		{
	//			line.move(0, -1);
	//			//line.rotate(270);
	//		}
	//	}

	//	window.clear();
	//	window.draw(line);
	//	window.display();
	//}

	return 0;
}