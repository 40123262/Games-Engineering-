#include "Invader.h"
#include "Game.h"
#include "Bullet.h"
#include <iostream>
using namespace sf;


bool Invader::direction = true;
float Invader::speed = 50.0f;

Invader::Invader() : Ship() {};

Invader::Invader(IntRect ir, Vector2f pos) : Ship(ir)
{
	setOrigin(16, 16);
	setPosition(pos);
}

void Invader::Update(const float &dt)
{
	if (!_exploded)
	{
		Ship::Update(dt);

		move(dt * (direction ? 1.0f : -1.0f) * speed, 0);

		if ((direction && getPosition().x > gameWidth - 16) || (!direction && getPosition().x < 16))
		{
			direction = !direction;
			for (auto &s : ships)
			{
				if (!s->isPlayer())
					s->move(0, 24);
			}
		}
		static float firetime = 0.0f;
		firetime -= dt;
		if (firetime <= 0 && rand() % 100 == 0)
		{
			Bullet::Fire(getPosition(), true);
			firetime = 4.0f + (rand() % 60);
		}
	}
	else
	{
		destructionDelay -= dt;
	}
	if (destructionDelay <= 0.0f)
		setPosition({ -100,-100 });
		
	
	
}


