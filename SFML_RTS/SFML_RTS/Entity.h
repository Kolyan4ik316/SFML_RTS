#pragma once
#include "State.h"
class Entity
{
public:
	Entity();
	virtual void Update(const float& dt);
	virtual void Render(sf::RenderTarget* target);
	virtual void Move(const float& dt, const float& dir_x, const float& dir_y);
	virtual void SetPosition(const sf::Vector2f& pos_in);
	virtual void LoadTexture(std::string name, sf::IntRect rect);
	virtual void LoadTextureFromImage(sf::Image& image, sf::IntRect rect);
	virtual void SetDirection(const sf::Vector2f& dir_in);
	virtual const sf::Vector2f GetPosition() const;
	virtual ~Entity();
protected:
	sf::Texture texture;
	//sf::Sprite sprite;
	sf::Vector2f dir;
	sf::Vector2f pos;
	sf::RectangleShape sprite;
	float movementSpeed = 60;
	bool loadedTexture = false;
private:

};

