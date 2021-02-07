#ifndef GAME_H
#define GAME_H
#include "GameState.h"

class Game
{
private:
	void InitWindow();
	void InitStates();
	void QuitFromApplication();
public:
	Game();
	void Update();
	void Render();
	void UpdateSFMLEvents();
	void Run();
public:
	virtual ~Game();
private:
	std::stack<std::unique_ptr<State>> states;
	std::shared_ptr<sf::RenderWindow> window;
	sf::Event sfEvent;
	sf::Clock clock;

	bool focused = true;
};
#endif