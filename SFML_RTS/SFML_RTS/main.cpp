#include <iostream>
#include <SFML/Graphics.hpp>


int main()
{
	std::shared_ptr<sf::RenderWindow> window;
	window = std::make_shared<sf::RenderWindow>(sf::VideoMode(640, 480), "SFML Real Time Strategy", sf::Style::Close);	
	window->setFramerateLimit(60);
	window->setVerticalSyncEnabled(false);
	sf::Event sfEvent;
	while (window->isOpen())
	{
		while (window->pollEvent(sfEvent))
		{
			switch (sfEvent.type)
			{
			case sf::Event::Closed:
			{
				window->close();
			}
			break;
			case sf::Event::Resized:
			{

			}
			break;
			case sf::Event::GainedFocus:
			{

			}
			break;
			case sf::Event::LostFocus:
			{

			}
			break;
			}

		}
	}
	
	return 0;
}