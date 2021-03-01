#include "State.h"
State::GamePreference State::preference;
State::State(std::shared_ptr<sf::RenderWindow> window)
	:
	window(window)
{
	std::string path = "Resources\\arial.ttf";
	if (!font.loadFromFile(path.c_str()))
	{
		std::string error = "Can't find font " + path;
		throw(std::exception(error.c_str()));
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
