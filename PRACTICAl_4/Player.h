#pragma once
#include "Entity.h"
#include "levelsystem.h"

class Player : public Entity
{
private:
	float _speed;
public:
	bool validMove(sf::Vector2f pos);
	void update(double dt) override;
	Player();
	void render(sf::RenderWindow &window) const override;
};