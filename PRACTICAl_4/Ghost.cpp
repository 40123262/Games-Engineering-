#include "Ghost.h"
using namespace sf;
using namespace std;
Ghost::Ghost() 
	:_speed(200.0f), Entity(make_unique<CircleShape>(25.0f))
{
	_shape->setFillColor(Color::Magenta);
	_shape->setOrigin(Vector2f(25.0f, 25.0f));
	_position = ls::getTilePosition({ 1,1 });
	_position.x += 50.0f;
	_position.y += 50.0f;
}

void Ghost::update(double dt)
{
	_directionTimer -= dt;
	if (_directionTimer < 0)
	{
		direction = rand() % 4;
		_directionTimer = 0.5f;
	}
	if (direction==0) {
		if (validMove(_position + Vector2f(0, -_speed * dt - 25.0f)))
			move(Vector2f(0, -_speed * dt));
	}
	else if (direction == 1) {
		if (validMove(_position + Vector2f(0, _speed * dt + 25.0f)))
			move(Vector2f(0, _speed * dt));
	}
	else if (direction == 2) {
		if (validMove(_position + Vector2f(-_speed * dt - 25.0f, 0)))
			move(Vector2f(-_speed * dt, 0));
	}
	else if (direction == 3) {
		if (validMove(_position + Vector2f(-_speed * dt + 25.0f, 0)))
			move(Vector2f(_speed * dt, 0));
	}

	Entity::update(dt);
}
bool Ghost::validMove(sf::Vector2f pos)
{
	return (ls::getTileAt(pos) != ls::WALL);
}
void Ghost::render() const
{
	Renderer::queue(_shape.get());
}

