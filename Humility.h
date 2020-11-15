#pragma once
#include "Creature.h"
#include "Magic.h"


class Humility :
	public Magic
{
public:
	Humility();
	Humility(
		BattleField * field		
	);

	virtual void Info() override;
	virtual void FirstSkill() override;
};

