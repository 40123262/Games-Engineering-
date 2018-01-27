#include "Player.h"
#include "Game.h"
#include "Bullet.h"
#include <iostream>

using namespace sf;
Player::Player() 
{
	_exploded = false;
	setTexture(spritesheet);
	setTextureRect({ 160,32,32,32 });
	setPosition({gameWidth/2, gameHeight-40});
}
bool Player::isPlayer()
{
	return true;
}
void Player::Update(const float &dt)
{
	if (!_exploded)
	{
		Ship::Update(dt);
		//movement
		static float fireTime = 0.0f;
		fireTime -= dt;
		float direction = 0.0f;

		if (Keyboard::isKeyPressed(Keyboard::Right))
		{
			move(100 * dt, 0);
		}
		if (Keyboard::isKeyPressed(Keyboard::Left))
		{
			move(-100 * dt, 0);
		}
		if (fireTime <= 0.0f && Keyboard::isKeyPressed(Keyboard::Space))
		{
			Bullet::Fire(getPosition(), false);
			fireTime = 0.7f;
		}
	}
	else
	{
		destructionDelay -= dt;
	}
	if (destructionDelay <= 0.0f)
	{
		setPosition({ -100,-100 });
		std::cout << "GAME OVER!" << std::endl;
	}
}
