#include "Invader.h"
#include "Game.h"
#include <iostream>
using namespace sf;


bool Invader::direction = true;
float Invader::speed = 50.0f;
//bool first = true;
//time_t start = time(0);

Invader::Invader() : Ship() {};

Invader::Invader(IntRect ir, Vector2f pos) : Ship(ir)
{
	setOrigin(16, 16);
	setPosition(pos);
}

void Invader::Update(const float &dt)
{
	Ship::Update(dt);
/*	if (difftime(time(0), start)>=1.0f)
	{
		std::cout << difftime(time(0), start) << std::endl;
		start = time(0);
		if (!first)
			this->setTextureRect(IntRect( 0, 0, 32, 32));
		else
			this->setTextureRect(IntRect(32, 0, 32, 32));
		first = !first;
		
	}*/
	move(dt * (direction ? 1.0f : -1.0f) * speed, 0);

	if ((direction && getPosition().x > gameWidth - 16) || (!direction && getPosition().x < 16))
	{
		direction = !direction;
		for(auto &s : ships)
		s->move(0, 24);
	}
	
}


