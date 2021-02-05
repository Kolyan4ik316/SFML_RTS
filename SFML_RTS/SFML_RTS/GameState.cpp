#include "GameState.h"

GameState::GameState(std::shared_ptr<sf::RenderWindow> window)
	: 
	State(window),
	mouseManager(window)
{
	text.setFont(font);
	text.setString("Daddy would you like some sausages?");
	text.setPosition(sf::Vector2f(1280.0f / 2.0f, 720.0f / 2.0f));
	text.setOrigin(sf::Vector2f(text.getLocalBounds().width / 2.0f, text.getLocalBounds().height / 2.0f));
	player.SetPosition(sf::Vector2f(1280.0f / 2.0f, 720.0f / 2.0f));
	player.SetGoal(sf::Vector2f(1280.0f / 2.0f, 720.0f / 2.0f));
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
	mouseManager.Render(target);
}

void GameState::UpdateInput(const float& dt)
{
	if (IsFocused())
	{
		
		mouseManager.Update(dt);
		if (mouseManager.GetSelectedArea().intersects(player.GetRect().getGlobalBounds()))
		{
			player.SetSelected(true);
		}
		else
		{
			player.SetSelected(false);
		}
		if (player.IsSelected())
		{
			if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
			{
				auto mousePos = sf::Vector2f((float)sf::Mouse::getPosition(*window).x, (float)sf::Mouse::getPosition(*window).y);
				player.SetGoal(mousePos);
			}
		}
		
	}
	
}




GameState::~GameState()
{
	
}
