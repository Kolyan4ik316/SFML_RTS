#ifndef STATE_H
#define STATE_H

#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <stack>
#include <map>

#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>


class State
{
public:
	struct GamePreference
	{
		sf::VideoMode windowConfig;
		unsigned int frameRateLimit;
		bool vsync;
	};
public:
	State(std::shared_ptr<sf::RenderWindow> window);
	virtual void Update(const float& dt) = 0;
	virtual void Render(sf::RenderTarget* target = NULL) = 0;
	virtual void UpdateInput(const float& dt) = 0;
	virtual void FocusedState(const bool& isFocused);
	virtual void EndState();
	const bool& GetQuit() const;
	virtual ~State();
protected:
	const bool& IsFocused() const;
	sf::Font font;
	std::shared_ptr<sf::RenderWindow> window;
private:
	bool quit = false;
	bool focused = true;
	static GamePreference preference;
};
#endif