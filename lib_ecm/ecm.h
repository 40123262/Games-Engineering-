#pragma once
#include "maths.h"
#include <algorithm>
#include <memory>
#include <typeindex>
#include <vector>

class Component;

class Entity
{
protected:
	std::vector<std::shared_ptr<Component>> _components;
	sf::Vector2f _position;
	float _rotation;
	bool _alive;
	bool _visible;
	bool _fordeletion;
public:
	Entity();
	virtual ~Entity();
	virtual void update(double dt);
	virtual void render();

	const sf::Vector2f &getPosition() const;
	void setPosition(const sf::Vector2f &_position);
	bool is_fordeletion() const;
	float getRotation() const;
	void setRotation(float _rotation);
	bool isAlive() const;
	void setAlive(bool _alive);
	void setForDelete();
	bool isVisible() const;
	void setVisible(bool _visible);
};

