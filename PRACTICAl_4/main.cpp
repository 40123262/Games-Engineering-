#include <SFML/Graphics.hpp>
#include "Game.h"
#include "Player.h"
#include "Ghost.h"
#include "levelsystem.h"

using namespace sf;
using namespace std;

vector<Entity*> entities;
void Load()
{
	ls::loadLevelFile("res/levels/maze.txt");
	for (size_t y = 0; y < ls::getHeight(); ++y) {
		for (size_t x = 0; x < ls::getWidth(); ++x) {
			cout << ls::getTile({ x, y });
		}
		cout << endl;
	}
	entities.push_back(new Player());
	entities.push_back(new Ghost());
	entities.push_back(new Ghost());
	entities.push_back(new Ghost());
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
	
	for(auto s : entities)
	{
		s->update(dt);
	}
}

void Render(RenderWindow &window)
{
	ls::Render(window);
	for (auto s : entities)
	{
		s->render(window);
	}
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