#include "GameState.h"

GameState::GameState(std::shared_ptr<sf::RenderWindow> window)
	: 
	State(window)
{
	text.setFont(font);
	text.setString("Daddy would you like some sausages?");
	text.setPosition(sf::Vector2f(1280.0f / 2.0f, 720.0f / 2.0f));
	text.setOrigin(sf::Vector2f(text.getLocalBounds().width / 2.0f, text.getLocalBounds().height / 2.0f));
	player.SetPosition(sf::Vector2f(1280.0f / 2.0f, 720.0f / 2.0f));
	goal = sf::Vector2f(1280.0f / 2.0f, 720.0f / 2.0f);
	player.SetGoal(goal);
}

void GameState::Update(const float& dt)
{
	
	UpdateInput(dt);
	player.Update(dt);
}

void GameState::Render(sf::RenderTarget* target)
{
	if (!target)
	{
		target = window.get();
	}
	target->draw(text);
	player.Render(target);
	sf::Vertex line[] =
	{
		sf::Vertex(sf::Vector2f(rect.left, rect.top)),
		sf::Vertex(sf::Vector2f(rect.left, rect.height)),
		sf::Vertex(sf::Vector2f(rect.width, rect.top)),
		sf::Vertex(sf::Vector2f(rect.width, rect.height)),
		sf::Vertex(sf::Vector2f(rect.left, rect.top)),
		sf::Vertex(sf::Vector2f(rect.width, rect.top)),
		sf::Vertex(sf::Vector2f(rect.left, rect.height)),
		sf::Vertex(sf::Vector2f(rect.width, rect.height))
	};

	target->draw(line, 8, sf::Lines);
}

void GameState::UpdateInput(const float& dt)
{
	if (IsFocused())
	{
		
		sf::Vector2f mousePos = sf::Vector2f((float)sf::Mouse::getPosition(*window).x, (float)sf::Mouse::getPosition(*window).y);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
		{
			player.SetGoal(mousePos);
		}

		while (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			rect.left = mousePos.x;
			rect.top = mousePos.y;

			rect.width = (float)sf::Mouse::getPosition(*window).x; 
			rect.height = (float)sf::Mouse::getPosition(*window).y;
		}
	}
	
}




GameState::~GameState()
{
	
}
