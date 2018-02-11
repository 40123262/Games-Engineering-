#include "Player.h"
#include "SystemRenderer.h"
using namespace sf;
using namespace std;
Player::Player() 
	:_speed(200.0f), Entity(make_unique<CircleShape>(25.0f))
{
	_shape->setFillColor(Color::Yellow);
	_shape->setOrigin(Vector2f(25.0f, 25.0f));
	_position = ls::getStart();
}

void Player::update(double dt)
{
	if (Keyboard::isKeyPressed(Keyboard::W)) {
		if (validMove(_position + Vector2f(0, -_speed * dt - 25.0f)))
			move(Vector2f(0, -_speed * dt));
	}
	if (Keyboard::isKeyPressed(Keyboard::S)) {
		if (validMove(_position + Vector2f(0, _speed * dt + 25.0f)))
			move(Vector2f(0, _speed * dt));
	}
	if (Keyboard::isKeyPressed(Keyboard::A)) {
		if (validMove(_position + Vector2f(-_speed * dt - 25.0f, 0)))
			move(Vector2f(-_speed * dt, 0));
	}
	if (Keyboard::isKeyPressed(Keyboard::D)) {
		if (validMove(_position + Vector2f(-_speed * dt + 25.0f, 0)))
			move(Vector2f(_speed * dt, 0));
	}

	Entity::update(dt);
}
bool Player::validMove(sf::Vector2f pos)
{
	return (ls::getTileAt(pos) != ls::WALL);
}
void Player::render() const
{
	Renderer::queue(_shape.get());
}

