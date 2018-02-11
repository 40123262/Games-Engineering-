#pragma once
#include "SystemRenderer.h"
#include "Pacman.h"
#include "levelsystem.h"
#include "Player.h"
#include "Ghost.h"

using namespace sf;
using namespace std;

Font font;
MenuScene::MenuScene() {}
void MenuScene::load() {
	if (!font.loadFromFile("res/fonts/leadcoat.ttf")) {
		cout << "Cannot load font!" << endl;
	}

	if (Keyboard::isKeyPressed(Keyboard::Space)) {
		activeScene = gameScene;
	}

	text.setPosition(Vector2f((700 * 0.5f) - (text.getLocalBounds().width * 0.5f), 0));
	text.setString("Almost Pacman");
	text.setFont(font);
}

void MenuScene::update(double dt) {
	if (Keyboard::isKeyPressed(Keyboard::Space)) 
	{
		activeScene = gameScene;
	}

	Scene::update(dt);
	_ents.update(dt);
}
void MenuScene::render() {
	Scene::render();
	_ents.render();
	Renderer::queue(&text);
}

void GameScene::load()
{
	ls::loadLevelFile("res/levels/pacman.txt");
	
	_ents.list.push_back(make_shared<Player>());
	_ents.list.push_back(make_shared<Ghost>());
	_ents.list.push_back(make_shared<Ghost>());
	_ents.list.push_back(make_shared<Ghost>());
	_ents.list.push_back(make_shared<Ghost>());

}
void GameScene::update(double dt)
{
	if (Keyboard::isKeyPressed(Keyboard::Tab))
	{
		activeScene = menuScene;
	}
	_ents.update(dt);
	Scene::update(dt);
}
void GameScene::render()
{
	ls::Render(Renderer::getWindow());
	_ents.render();
	Scene::render();
}
