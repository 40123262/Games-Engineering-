#pragma once
#include "ship.h"

class Player : public Ship
{
public:
	Player();
	void Update(const float &dt) override;
};