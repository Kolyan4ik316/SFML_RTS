#include "GameState.h"

GameState::GameState(std::shared_ptr<sf::RenderWindow> window)
	: 
	State(window)
{
	text.setFont(font);
	text.setString("Dady would you like some sausages?");
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
}

void GameState::UpdateInput(const float& dt)
{
	if (IsFocused())
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			EndState();
		}
	}
	
}




GameState::~GameState()
{
	
}
