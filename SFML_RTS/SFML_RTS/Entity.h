#pragma once
#include "State.h"
class Entity
{
public:
	Entity();
	virtual void Update(const float& dt);
	virtual void Render(sf::RenderTarget* target);
	virtual void SetPosition(const sf::Vector2f& pos_in);
	virtual void LoadTexture(std::string name, sf::IntRect rect);
	virtual void LoadTextureFromImage(sf::Image& image, sf::IntRect rect);
	virtual void SetGoal(const sf::Vector2f& goal_in);
	virtual const sf::Vector2f GetGoal() const;
	virtual const sf::Vector2f GetPosition() const;
	virtual const bool IsSelected() const;
	virtual void SetSelected(const bool& selected);
	virtual const sf::RectangleShape GetRect() const;
	virtual ~Entity();
protected:
	virtual void MoveToGoal() const;
	sf::Texture texture;
	//sf::Sprite sprite;
	mutable sf::Vector2f dir;
	sf::Vector2f pos;
	sf::RectangleShape sprite;
	float movementSpeed = 60;
	bool loadedTexture = false;
	sf::Vector2f goal;
	bool isSelected = false;
private:

};

