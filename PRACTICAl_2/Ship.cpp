#include "ship.h"
#include "Game.h"
using namespace sf;
using namespace std;

Ship::Ship() { _exploded = false; };

Ship::Ship(IntRect ir) : Sprite()
{
	_exploded = false;
	_sprite = ir;
	setTexture(spritesheet);
	setTextureRect(_sprite);
};
bool Ship::isExploded() const
{
	return _exploded;
}
void Ship::Explode()
{
	setTextureRect({128,32,32,32});
	_exploded = true;
}
void Ship::Update(const float &dt){}
bool Ship::isPlayer()
{
	return false;
}
Ship::~Ship() = default;
