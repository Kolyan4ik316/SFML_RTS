#include "Game.h"
State::GamePreference Game::prefernce = { sf::VideoMode(1280, 720), 60, false };
void Game::InitWindow()
{
	std::string path = "Configs\\window.ini";
	std::ifstream ifs(path.c_str());
	std::string windowName = "SFML Real Time Strategy";

	if (ifs.is_open())
	{
		std::string tempStr;
		while (!ifs.eof())
		{
			ifs >> tempStr;
			if (!tempStr.compare("[Window_Width]"))
			{
				ifs >> prefernce.windowConfig.width;
			}
			if (!tempStr.compare("[Window_Height]"))
			{
				ifs >> prefernce.windowConfig.height;
			}
			if (!tempStr.compare("[Frame_limit]"))
			{
				ifs >> prefernce.frameRateLimit;
			}
			if (!tempStr.compare("[Vsync]"))
			{
				ifs >> prefernce.vsync;
			}
			if (!tempStr.compare("[Window_Name]"))
			{
				windowName.clear();
				while (getline(ifs, tempStr))
				{
					windowName += tempStr;
				}
			}
		}
	}
	else
	{
		//if not exist creating new file in same path
		std::ofstream ofs;
		ofs.open(path.c_str());
		if (ofs.is_open())
		{
			//Writing variables
			ofs << "[Window_Width]\n"
				<< prefernce.windowConfig.width << "\n"
				<< "[Window_Height]\n"
				<< prefernce.windowConfig.height << "\n"
				<< "[Frame_limit]\n"
				<< prefernce.frameRateLimit << "\n"
				<< "[Vsync]\n"
				<< prefernce.vsync << "\n"
				<< "[Window_Name]\n"
				<< windowName.c_str() << "\n";
		}
		else
		{
			// if can't create
			std::string error = "Unknown error while writing to file " + path;
			throw(std::exception(error.c_str()));
		}
		ofs.close();
	}
	ifs.close();
	window = std::make_shared<sf::RenderWindow>(prefernce.windowConfig, windowName, sf::Style::Close);
	window->setFramerateLimit(prefernce.frameRateLimit);
	window->setVerticalSyncEnabled(prefernce.vsync);
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
		states.top()->Update(float(clock.getElapsedTime().asSeconds()));

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
