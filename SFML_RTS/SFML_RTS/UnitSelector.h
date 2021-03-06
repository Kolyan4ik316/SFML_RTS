#ifndef UNITSELECTOR_H
#define UNITSELECTOR_H
#include "SFML/Graphics.hpp"
class UnitSelector
{
public:
	UnitSelector(std::shared_ptr<sf::RenderWindow> window);
	virtual void Update(const float& dt);
	virtual void Render(sf::RenderTarget* target);
	const sf::Rect<float> GetSelectedArea() const;
	void ResetSelectedArea();
	virtual ~UnitSelector();
private:
	virtual sf::Rect<float> GetScreenRect(const sf::Vector2f& startPos, const sf::Vector2f& endPos) const;
	const sf::Vector2f GetSmallerVector(const sf::Vector2f& vec1, const sf::Vector2f& vec2) const;
	const sf::Vector2f GetBiggerVector(const sf::Vector2f& vec1, const sf::Vector2f& vec2) const;
	bool isSelecting = false;
	sf::Vector2f startMousePos;
	std::shared_ptr<sf::RenderWindow> window;
	sf::Rect<float> selectedArea;
};
#endif
