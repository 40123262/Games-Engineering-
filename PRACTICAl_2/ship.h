#pragma once
#include <SFML/Graphics.hpp>

class Ship : public sf::Sprite
{
protected:
	sf::IntRect _sprite;
	bool _exploded;
	Ship();
public:
	float destructionDelay = 0.5f;
	bool isExploded() const;
	virtual void Explode();
	virtual bool isPlayer();
	explicit Ship(sf::IntRect ir);

	virtual ~Ship() = 0;

	virtual void Update(const float &dt);
};
