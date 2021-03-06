#include <SFML/Graphics.hpp>
#include <iostream>
#include "Invader.h"
#include "ship.h"
#include "Player.h"
#include "Game.h"
#include "Bullet.h"

using namespace sf;
using namespace std;

const Keyboard::Key controls[4] = {
	Keyboard::Left,
	Keyboard::Right,
	Keyboard::Space
};
vector<Ship*> ships;
Bullet* b;
Texture spritesheet;
Sprite invader;
void Load()
{
	if(!spritesheet.loadFromFile("res/img/invaders_sheet.png"))
	{
		cerr << "Failed to load spritesheet!" << endl;
	}
	Player* p1 = new Player();
	ships.push_back(p1);
	for (int row = 0; row < invaders_rows; row++)
	{
		auto displacement = (row % 5);
		auto rect = IntRect(0 + 32*displacement, 0 , 32, 32);
		for (int col = 0; col < invaders_columns; col++)
		{
			Vector2f pos = { 16.0f + 42.0f * col, 16.0f + 42.0f * row };
			Invader* inv = new Invader(rect, pos);
			//inv->scale({ 1.2f,1.7f });
			ships.push_back(inv);
		}
	}
	
}
void reset()
{

}
void Update(RenderWindow &window)
{
	static Clock clock;
	float dt = clock.restart().asSeconds();

	Event event;
	while (window.pollEvent(event))
	{
		if (event.type == Event::Closed)
		{
			window.close();
			return;
		}
	}

	if (Keyboard::isKeyPressed(Keyboard::Escape))
	{
		window.close();
	}
	for (auto &s : ships)
	{
		s->Update(dt);
	}
	Bullet::Update(dt);
}

void Render(RenderWindow &window)
{
	for(auto &s: ships)
		window.draw(*s);
	b->Render(window);
}

int main()
{
	RenderWindow window(VideoMode(gameWidth, gameHeight), "Space Invaders");
	Load();
	reset();
	while (window.isOpen())
	{
		window.clear();
		Update(window);
		Render(window);
		window.display();
	}
	return 0;
}