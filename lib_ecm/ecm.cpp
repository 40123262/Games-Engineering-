#include "ecm.h"

class Component
{
protected:
	Entity * const _parent;
	bool _fordeletion;
	explicit Component(Entity *const p);

public:
	Component() = delete;
	bool is_fordeletion() const;
	virtual void update(double dt) = 0;
	virtual void render() = 0;
	virtual ~Component();
};