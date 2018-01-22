#include <SFML/Graphics.hpp>
#include <iostream>
#include "ship.h"
#include "Game.h"

using namespace sf;
using namespace std;

const Keyboard::Key controls[4] = {
	Keyboard::Left,
	Keyboard::Right,
	Keyboard::Space
};
vector<Ship *> ships;
Texture spritesheet;
Sprite invader;
void Load()
{
	if(!spritesheet.loadFromFile("res/img/invaders_sheet.png"))
	{
		cerr << "Failed to load spritesheet!" << endl;
	}
	invader.setTexture(spritesheet);
	invader.setTextureRect(IntRect(0, 0, 32, 32));

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
}

void Render(RenderWindow &window)
{
	window.draw(invader);
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