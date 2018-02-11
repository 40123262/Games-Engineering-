#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include "Entity.h"

class  EntityManager
{
public:
	void update(double dt);
	void render();
	std::vector<std::shared_ptr<Entity>> list;
};
