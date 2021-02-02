#include "GameState.h"

GameState::GameState(std::shared_ptr<sf::RenderWindow> window)
	: 
	State(window)
{
	text.setFont(font);
	text.setString("Daddy would you like some sausages?");
	text.setPosition(sf::Vector2f(1280.0f / 2.0f, 720.0f / 2.0f));
	text.setOrigin(sf::Vector2f(text.getLocalBounds().width / 2.0f, text.getLocalBounds().height / 2.0f));
}

void GameState::Update(const float& dt)
{
	
	UpdateInput(dt);
	
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
		text.setOrigin(sf::Vector2f(text.getLocalBounds().width / 2.0f, text.getLocalBounds().height / 2.0f));
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			EndState();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			text.setPosition(sf::Vector2f(text.getPosition().x, text.getPosition().y - (60.0f * dt)));
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			text.setPosition(sf::Vector2f(text.getPosition().x, text.getPosition().y + (60.0f * dt)));
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			text.setPosition(sf::Vector2f(text.getPosition().x - (60.0f * dt), text.getPosition().y));
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			text.setPosition(sf::Vector2f(text.getPosition().x + (60.0f * dt), text.getPosition().y));
		}
		if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
		{
			player.SetPosition((float)sf::Mouse::getPosition(*window).x, (float)sf::Mouse::getPosition(*window).y);
		}
	}
	
}




GameState::~GameState()
{
	
}
