#pragma once
#include "State.h"
#include "Entity.h"
#include "MouseManager.h"
class GameState : public State
{
public:
	GameState(std::shared_ptr<sf::RenderWindow> window);
	void Update(const float& dt) override;
	void Render(sf::RenderTarget* target = nullptr) override;
	void UpdateInput(const float& dt) override;
	virtual ~GameState();
private:
	sf::Text text;
	Entity player;
	MouseManager mouseManager;
	sf::Vector2f mousePos;
};