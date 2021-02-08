#include "State.h"
State::GamePreference State::preference;
State::State(std::shared_ptr<sf::RenderWindow> window)
	:
	window(window)
{
	if (!font.loadFromFile("Resources\\arial.ttf"))
	{
		throw(std::exception("Can't find your font!"));
	}
	
}

void State::FocusedState(const bool& isFocused)
{
	focused = isFocused;
}

void State::EndState()
{
	quit = true;
}

const bool& State::GetQuit() const
{
	return quit;
}
State::~State()
{
}

const bool& State::IsFocused() const
{
	return focused;
}
