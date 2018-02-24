#pragma once
#include "SystemRenderer.h"
#include "Pacman.h"
#include "levelsystem.h"
#include "cmp_sprite.h"
#include "cmp_actor_movement.h"

using namespace sf;
using namespace std;
const int GHOSTS_COUNT = 4;
Font font;
MenuScene::MenuScene() {}
void MenuScene::load() {
	if (!font.loadFromFile("res/fonts/leadcoat.ttf")) {
		cout << "Cannot load font!" << endl;
	}

	if (Keyboard::isKeyPressed(Keyboard::Space)) {
		activeScene = gameScene;
	}

	text.setPosition(Vector2f((600 * 0.5f) - (text.getLocalBounds().width * 0.5f), 0));
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
vector<shared_ptr<Entity>> ghosts;
shared_ptr<Entity> player;

void GameScene::respawn()
{
	_ents.list[0]->setPosition(ls::findTiles(ls::START)[0]);
	auto ghost_spawns = ls::findTiles(ls::ENEMY);
	for (int i = 1; i < _ents.list.size(); ++i) {
		_ents.list[i]->setPosition(ghost_spawns[rand() % ghost_spawns.size()]);
	}

}
void GameScene::load()
{
	ls::loadLevelFile("res/levels/pacman.txt", 25.0f);

	auto pl = make_shared<Entity>();
	auto mp = pl->addComponent<PlayerMovementComponent>();
	mp->setSpeed(100.0f);

	auto s = pl->addComponent<ShapeComponent>();
	s->setShape<sf::CircleShape>(10.0f);
	s->getShape().setFillColor(Color::Yellow);
	s->getShape().setOrigin(10.0f, 10.0f);
	s->getShape().setPosition({ 100.0f, 100.0f});
	_ents.list.push_back(pl);
	player = pl;

	const sf::Color ghost_cols[]{{ 208, 62, 25 },
								 { 219, 133, 28 },
								 { 70, 191, 238 },
								 { 234, 130, 229 } };

	Vector2f pos = Vector2f{ 300.0f, 300.0f };
	for (int i = 0; i < GHOSTS_COUNT; ++i) {
		auto ghost = make_shared<Entity>();
		ghost->addComponent<EnemyAIComponent>();

		auto s = ghost->addComponent<ShapeComponent>();
		s->setShape<sf::CircleShape>(10.0f);
		s->getShape().setFillColor(ghost_cols[i % 4]);
		s->getShape().setOrigin(Vector2f(10.f, 10.f));

		_ents.list.push_back(ghost);
		ghosts.push_back(ghost);
		pos += Vector2f(70.0f, 0);
	}
	
	respawn();
}
void GameScene::update(double dt)
{
	if (Keyboard::isKeyPressed(Keyboard::Tab))
	{
		activeScene = menuScene;
	}
	_ents.update(dt);
	for (auto &g : ghosts) 
	{
		if (length(g->getPosition() - player->getPosition()) < 30.0f) 
		{
			std::cout << "Game over!" << std::endl;
			respawn();
		}
	}
	Scene::update(dt);
}
void GameScene::render()
{
	ls::Render(Renderer::getWindow());
	_ents.render();
	Scene::render();
}
