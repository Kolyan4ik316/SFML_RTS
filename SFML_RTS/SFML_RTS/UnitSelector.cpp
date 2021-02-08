#include "UnitSelector.h"
UnitSelector::UnitSelector(std::shared_ptr<sf::RenderWindow> window)
	:
	window(window)
{

}
void UnitSelector::Update(const float& dt)
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

void UnitSelector::Render(sf::RenderTarget* target)
{
	if (isSelecting)
	{
		std::vector<sf::Vertex> lines;
		for (float i = 0.0f; i < 5.0f; i += 1.0f)
		{
			sf::Vertex line[] =
			{
				sf::Vertex(sf::Vector2f(selectedArea.left + i, selectedArea.top)),
				sf::Vertex(sf::Vector2f(selectedArea.left + i, selectedArea.top + selectedArea.height)),
				sf::Vertex(sf::Vector2f(selectedArea.left + selectedArea.width - i, selectedArea.top )),
				sf::Vertex(sf::Vector2f(selectedArea.left + selectedArea.width - i, selectedArea.top + selectedArea.height )),
				sf::Vertex(sf::Vector2f(selectedArea.left, selectedArea.top + i)),
				sf::Vertex(sf::Vector2f(selectedArea.left + selectedArea.width, selectedArea.top + i)),
				sf::Vertex(sf::Vector2f(selectedArea.left, selectedArea.top + selectedArea.height - i)),
				sf::Vertex(sf::Vector2f(selectedArea.left + selectedArea.width, selectedArea.top + selectedArea.height - i))
			};
			for (unsigned int j = 0; j < 8; j++)
			{
				lines.push_back(line[j]);
			}	
		}
		target->draw(lines.data(), lines.size(), sf::Lines);

	}
	
}
const sf::Rect<float> UnitSelector::GetSelectedArea() const
{
	return selectedArea;
}
void UnitSelector::ResetSelectedArea()
{
	selectedArea = { FLT_MAX, FLT_MAX, 0.0f, 0.0f };
}
sf::Rect<float> UnitSelector::GetScreenRect(const sf::Vector2f& startPos, const sf::Vector2f& endPos) const
{
	return sf::Rect<float>(GetSmallerVector(startPos, endPos), GetBiggerVector(endPos - startPos, startPos - endPos));
}
UnitSelector::~UnitSelector()
{

}

const sf::Vector2f UnitSelector::GetSmallerVector(const sf::Vector2f& vec1, const sf::Vector2f& vec2) const
{
	const float x = std::min(vec1.x, vec2.x);
	const float y = std::min(vec1.y, vec2.y);
	return sf::Vector2f(x, y);
}

const sf::Vector2f UnitSelector::GetBiggerVector(const sf::Vector2f& vec1, const sf::Vector2f& vec2) const
{
	const float x = std::max(vec1.x, vec2.x);
	const float y = std::max(vec1.y, vec2.y);
	return sf::Vector2f(x, y);
}
