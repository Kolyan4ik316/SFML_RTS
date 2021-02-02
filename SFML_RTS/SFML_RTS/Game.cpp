#include "Game.h"

void Game::InitWindow()
{
	std::ifstream ifs("Configs\\window.ini");
	sf::VideoMode windowConfig(1280, 720);
	std::string windowName = "SFML Real Time Strategy";
	unsigned int frameRateLimit = 60;
	bool vsync = false;

	if (ifs.is_open())
	{
		std::getline(ifs, windowName);
		ifs >> windowConfig.width >> windowConfig.height;
		ifs >> frameRateLimit;
		ifs >> vsync;
	}
	ifs.close();
	window = std::make_shared<sf::RenderWindow>(windowConfig, windowName, sf::Style::Close);
	window->setFramerateLimit(frameRateLimit);
	window->setVerticalSyncEnabled(vsync);
}

void Game::InitStates()
{
	states.push(std::make_unique<GameState>(window));
}

void Game::QuitFromApplication()
{
}

Game::Game()
{
	InitWindow();
	InitStates();
	
}
void Game::Update()
{
	UpdateSFMLEvents();
	

	if (!states.empty())
	{
		states.top()->FocusedState(focused);
		states.top()->Update(float(clock.getElapsedTime().asMilliseconds()));

		if (states.top()->GetQuit())
		{
			states.top()->EndState();
			states.pop();
		}
	}
	else
	{
		QuitFromApplication();
		window->close();
	}
	clock.restart();
}

void Game::Render()
{
	window->clear();

	if (!states.empty())
	{
		states.top()->Render();
	}
	
	window->display();
}

void Game::UpdateSFMLEvents()
{
	while (window->pollEvent(sfEvent))
	{
		switch (sfEvent.type)
		{
		case sf::Event::Closed:
		{
			//OnDisable();
			window->close();
		}
		break;
		case sf::Event::Resized:
			//std::cout << "Size of window : width : " << evnt.size.width << ", height : " << evnt.size.height << std::endl;
		break;
		case sf::Event::GainedFocus:
		{
			focused = true;
		}
		break;
		case sf::Event::LostFocus:
		{
			focused = false;
		}
		break;
		}

	}
}

void Game::Run()
{
	//OnEnable();
	while (window->isOpen())
	{
		Update();
		Render();
	}
	
}

Game::~Game()
{
}
