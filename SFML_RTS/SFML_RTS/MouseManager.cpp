#include "MouseManager.h"
MouseManager::MouseManager(std::shared_ptr<sf::RenderWindow> window)
	:
	window(window)
{

}
void MouseManager::Update(const float& dt)
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		isSelecting = true;
		auto mousePos = sf::Vector2f((float)sf::Mouse::getPosition(*window).x, (float)sf::Mouse::getPosition(*window).y);
		
		selectedArea = GetScreenRect(startMousePos, mousePos);
	}
	else
	{
		isSelecting = false;
		startMousePos.x = (float)sf::Mouse::getPosition(*window).x;
		startMousePos.y = (float)sf::Mouse::getPosition(*window).y;
	}
}

void MouseManager::Render(sf::RenderTarget* target)
{
	if (isSelecting)
	{
		sf::Vertex line[] =
		{
			sf::Vertex(sf::Vector2f(selectedArea.left, selectedArea.top)),
			sf::Vertex(sf::Vector2f(selectedArea.left, selectedArea.top + selectedArea.height)),
			sf::Vertex(sf::Vector2f(selectedArea.left + selectedArea.width, selectedArea.top)),
			sf::Vertex(sf::Vector2f(selectedArea.left + selectedArea.width, selectedArea.top + selectedArea.height)),
			sf::Vertex(sf::Vector2f(selectedArea.left, selectedArea.top)),
			sf::Vertex(sf::Vector2f(selectedArea.left + selectedArea.width, selectedArea.top)),
			sf::Vertex(sf::Vector2f(selectedArea.left, selectedArea.top + selectedArea.height)),
			sf::Vertex(sf::Vector2f(selectedArea.left + selectedArea.width, selectedArea.top + selectedArea.height))
		};

		target->draw(line, 8, sf::Lines);

	}
	
}
const sf::Rect<float> MouseManager::GetSelectedArea() const
{
	return selectedArea;
}
sf::Rect<float> MouseManager::GetScreenRect(const sf::Vector2f& startPos, const sf::Vector2f& endPos) const
{
	return sf::Rect<float>(GetSmallerVector(startPos, endPos), GetBiggerVector(endPos - startPos, startPos - endPos));
}
MouseManager::~MouseManager()
{

}

const sf::Vector2f MouseManager::GetSmallerVector(const sf::Vector2f& vec1, const sf::Vector2f& vec2) const
{
	const float x = std::min(vec1.x, vec2.x);
	const float y = std::min(vec1.y, vec2.y);
	return sf::Vector2f(x, y);
}

const sf::Vector2f MouseManager::GetBiggerVector(const sf::Vector2f& vec1, const sf::Vector2f& vec2) const
{
	const float x = std::max(vec1.x, vec2.x);
	const float y = std::max(vec1.y, vec2.y);
	return sf::Vector2f(x, y);
}
