#include "Bullet.h"
#include "Game.h"
using namespace sf;
using namespace std;

unsigned char Bullet::bulletPointer;
Bullet Bullet::bullets[256];
Bullet::Bullet()
{
	setTexture(spritesheet);
	_mode = false;
}
void Bullet::Render(sf::RenderWindow &window)
{
	for (Bullet &b : bullets)
	{
		window.draw(b);
	}
}
void Bullet::Fire(const sf::Vector2f &pos, const bool mode)
{
	bullets[bulletPointer].setPosition(pos);
	bullets[bulletPointer]._mode = mode;
	if(!mode)
		bullets[bulletPointer].setTextureRect({ 32,32,32,32 });
	else
		bullets[bulletPointer].setTextureRect({ 64,32,32,32 });
	bulletPointer++;
}
void Bullet::Update(const float &dt)
{
	for (Bullet &b : bullets)
	{
		b._Update(dt);
	}
}
void Bullet::_Update(const float &dt)
{
	if (getPosition().y < -32 || getPosition().y > gameHeight + 32)
	{
		return;
	}
	else
	{
		move(0, dt * 200.0f * (_mode ? 1.0f : -1.0f));
		const FloatRect boundingBox = getGlobalBounds();

		for (auto s : ships)
		{
			if (!_mode && s->isPlayer())
				continue;
			if (_mode && !s->isPlayer())
				continue;
			if (!s->isExploded() && s->getGlobalBounds().intersects(boundingBox))
			{
				s->Explode();
				setPosition(-100, -100);
				return;
			}
		}

	}
}