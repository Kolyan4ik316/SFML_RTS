#include "Entity.h"
Entity::Entity()
{
	sprite.setSize(sf::Vector2f(50.0f, 50.0f));
	sprite.setFillColor(sf::Color::White);
	sprite.setOrigin(sf::Vector2f(sprite.getLocalBounds().width / 2.0f, sprite.getLocalBounds().height / 2.0f));
	pos = {};
	dir = {};
}
void Entity::Update(const float& dt)
{
	if (goal != pos)
	{
		MoveToGoal();
	}
	pos += dir * movementSpeed * dt;
	sprite.setPosition(pos);
}
void Entity::Render(sf::RenderTarget* target)
{
	target->draw(sprite);
}
void Entity::SetPosition(const sf::Vector2f& pos_in)
{
	pos = pos_in;
}
Entity::~Entity()
{

}

void Entity::MoveToGoal() const
{
	sf::Vector2f temp_dir(0.0f, 0.0f);
	if (GetPosition().x < goal.x)
	{
		temp_dir += sf::Vector2f(1.0f, 0.0f);
	}
	if (GetPosition().x > goal.x)
	{
		temp_dir += sf::Vector2f(-1.0f, 0.0f);
	}
	if (GetPosition().y < goal.y)
	{
		temp_dir += sf::Vector2f(0.0f, 1.0f);
	}
	if (GetPosition().y > goal.y)
	{
		temp_dir += sf::Vector2f(0.0f, -1.0f);
	}
	dir = temp_dir;

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

void Entity::SetGoal(const sf::Vector2f& goal_in)
{
	goal = goal_in;
}

const sf::Vector2f Entity::GetGoal() const
{
	return goal;
}

const sf::Vector2f Entity::GetPosition() const
{
	return pos;
}
