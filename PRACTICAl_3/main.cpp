#include <SFML/Graphics.hpp>
#include "Game.h"
#include "Player.h"
#include "levelsystem.h"

using namespace sf;
using namespace std;

Player* player;
void Load()
{
	ls::loadLevelFile("res/levels/maze.txt");
	for (size_t y = 0; y < ls::getHeight(); ++y) {
		for (size_t x = 0; x < ls::getWidth(); ++x) {
			cout << ls::getTile({ x, y });
		}
		cout << endl;
	}
	player = new Player();
}

void Update(RenderWindow &window)
{
	static Clock clock;
	float dt = clock.restart().asSeconds();

	Event event;
	while (window.pollEvent(event))
	{
		if (event.type == Event::Closed) {
			window.close();
			return;
		}
	}
	
	player->update(dt);
}

void Render(RenderWindow &window)
{
	ls::Render(window);
	player->render(window);
}

int main()
{
	RenderWindow window(VideoMode(gameWidth, gameHeight), "Maze game");
	Load();

	while (window.isOpen())
	{
		window.clear();
		Update(window);
		Render(window);
		window.display();
	}
	return 0;
}