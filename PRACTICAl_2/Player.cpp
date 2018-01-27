#include "Player.h"
#include "Game.h"

using namespace sf;
Player::Player() 
{
	setTexture(spritesheet);
	setTextureRect({ 160,32,32,32 });
	setPosition({gameWidth/2, gameHeight-40});
}
void Player::Update(const float &dt)
{
	Ship::Update(dt);
	//movement
	
	float direction = 0.0f;

	if (Keyboard::isKeyPressed(Keyboard::Right ))
	{
		move(100 * dt, 0);
	}
	if (Keyboard::isKeyPressed(Keyboard::Left))
	{
		move(-100 * dt, 0);
	}
	if (Keyboard::isKeyPressed(Keyboard::Space))
	{
		//SHOOT
	}
}
