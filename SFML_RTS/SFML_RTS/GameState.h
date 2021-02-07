#ifndef GAMESTATE_H
#define GAMESTATE_H
#include "State.h"
#include "Entity.h"
#include "UnitSelector.h"
class GameState : public State
{
public:
	GameState(std::shared_ptr<sf::RenderWindow> window);
	void Update(const float& dt) override;
	void Render(sf::RenderTarget* target = NULL) override;
	void UpdateInput(const float& dt) override;
	virtual ~GameState();
private:
	sf::Text text;
	Entity player;
	UnitSelector unitSelector;
	sf::Vector2f mousePos;
};
#endif