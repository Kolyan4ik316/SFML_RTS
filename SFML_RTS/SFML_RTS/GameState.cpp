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
}

void GameState::UpdateInput(const float& dt)
{
	if (IsFocused())
	{
		sf::Vector2f dir(0.0f, 0.0f);
		 
		if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
		{
			goal = sf::Vector2f((float)sf::Mouse::getPosition(*window).x, (float)sf::Mouse::getPosition(*window).y);
			//player.SetPosition((float)sf::Mouse::getPosition(*window).x, (float)sf::Mouse::getPosition(*window).y);
		}
		if (player.GetPosition().x < goal.x)
		{
			dir += sf::Vector2f(1.0f, 0.0f);
		}
		if (player.GetPosition().x > goal.x)
		{
			dir += sf::Vector2f(-1.0f, 0.0f);
		}
		if (player.GetPosition().y < goal.y)
		{
			dir += sf::Vector2f(0.0f, 1.0f);
		}
		if (player.GetPosition().y > goal.y)
		{
			dir += sf::Vector2f(0.0f, -1.0f);
		}
		player.SetDirection(dir);
	}
	
}




GameState::~GameState()
{
	
}
