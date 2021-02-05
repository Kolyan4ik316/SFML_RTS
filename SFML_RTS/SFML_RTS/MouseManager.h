#pragma once
#include "SFML/Graphics.hpp"
class MouseManager
{
	MouseManager();
	virtual void Render(sf::RenderTarget* target);
	virtual ~MouseManager();
};
