#include "Entity.h"
Entity::Entity()
{
	sprite.setSize(sf::Vector2f(50.0f, 50.0f));
	sprite.setFillColor(sf::Color::White);
	sprite.setOrigin(sf::Vector2f(sprite.getLocalBounds().width / 2.0f, sprite.getLocalBounds().height / 2.0f));
	pos = {};
}
void Entity::Update(const float& dt)
{
	pos += dir * movementSpeed * dt;
	sprite.setPosition(pos);
}
void Entity::Render(sf::RenderTarget* target)
{
	target->draw(sprite);
}
void Entity::Move(const float& dt, const float& dir_x, const float& dir_y)
{
	sprite.move(sf::Vector2f(dir_x * movementSpeed * dt, dir_y * movementSpeed * dt));
}
void Entity::SetPosition(const sf::Vector2f& pos_in)
{
	pos = pos_in;
}
Entity::~Entity()
{

}

void Entity::LoadTexture(std::string name, sf::IntRect rect)
{
	if (!texture.loadFromFile(name, rect))
	{
		std::string error = std::string("Error with loading texture! " + name);
		loadedTexture = false;
		throw(std::exception(error.c_str()));
	}
	//sprite.setTexture(texture);
	loadedTexture = true;
}
void Entity::LoadTextureFromImage(sf::Image& image, sf::IntRect rect)
{
	if (!texture.loadFromImage(image, rect))
	{
		std::string error = std::string("Error with loading texture! ");
		throw(std::exception(error.c_str()));
	}
	//sprite.setTexture(texture);
}

void Entity::SetDirection(const sf::Vector2f& dir_in)
{
	dir = dir_in;
}

const sf::Vector2f Entity::GetPosition() const
{
	return pos;
}
