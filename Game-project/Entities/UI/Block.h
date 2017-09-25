#pragma once

#include "UI.h"
#include "../../Components/Sprite.h"
#include "../../Components/Transform.h"

namespace game { namespace entities {

using namespace components;

class Block : public UI
{
public:
	Block(int _x, int _y);
	~Block();

	void setup() override;
	void update() override;
	const std::string getName() const override;
	int getCurrentState() const override;

	const enum state : int { IDLE, SIZE = 1 };

private:
	static const std::string name;

	state currentState;

	int x;
	int y;
};

} }

