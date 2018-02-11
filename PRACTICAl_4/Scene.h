#pragma once
#include "EntityManager.h"
#include <SFML/Graphics.hpp>

class  Scene
{
public:
	Scene() = default;

	virtual ~Scene() = default;
	virtual void update(double dt);
	virtual void render();
	virtual void load() = 0;
	std::vector<std::shared_ptr<Entity>> &getEnts() { return _ents.list; };
protected:
	EntityManager _ents;
};