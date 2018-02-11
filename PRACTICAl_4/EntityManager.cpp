#include "EntityManager.h"
#include "Player.h"
#include "SystemRenderer.h"

using namespace std;
using namespace sf;
std::vector<std::shared_ptr<Entity>> list;
void EntityManager::update(const double dt)
{
	for (auto e : list)
	{
		e->update(dt);
	}
}
void EntityManager::render()
{
	for (auto &e : list)
	{
		e->render();
	}
}