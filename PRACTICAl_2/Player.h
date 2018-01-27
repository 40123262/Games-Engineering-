#pragma once
#include "ship.h"

class Player : public Ship
{
public:
	Player();
	bool isPlayer() override;
	void Update(const float &dt) override;
};