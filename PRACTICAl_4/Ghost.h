#pragma once
#include "Entity.h"
#include "levelsystem.h"

class Ghost : public Entity
{
private:
	float _speed;
	int direction = 0;
	float _directionTimer = 0.5f;
public:
	bool validMove(sf::Vector2f pos);
	void update(double dt) override;
	Ghost();
	void render() const override;
};