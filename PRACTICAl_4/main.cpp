#include <SFML/Graphics.hpp>
#include "Pacman.h"
#include "Scene.h"
#include "levelsystem.h"
#include "SystemRenderer.h"
#include "ecm.h"
#include <memory>

using namespace sf;
using namespace std;

std::shared_ptr<Scene> gameScene;
std::shared_ptr<Scene> menuScene;
std::shared_ptr<Scene> activeScene;
void Load()
{
	gameScene.reset(new GameScene());
	menuScene.reset(new MenuScene());
	gameScene->load();
	menuScene->load();

	activeScene = menuScene;
}

void Update(RenderWindow &window)
{
	static Clock clock;
	float dt = clock.restart().asSeconds();
	activeScene->update(dt);

	Event event;
	while (window.pollEvent(event))
	{
		if (event.type == Event::Closed) {
			window.close();
			return;
		}
	}	
	if (Keyboard::isKeyPressed(Keyboard::Escape)) {
		window.close();
	}
	
}

void Render(RenderWindow &window)
{
	activeScene->render();
	//flush to screen
	Renderer::render();
}

int main()
{
	RenderWindow window(VideoMode(gameWidth, gameHeight), "Pacman");
	Renderer::initialise(window);
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