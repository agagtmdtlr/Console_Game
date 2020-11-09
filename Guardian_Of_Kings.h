#pragma once
#include "Creature.h"
class Guardian_Of_Kings :
	public Creature
{
public:
	Guardian_Of_Kings();
	Guardian_Of_Kings(BattleField * field);
	~Guardian_Of_Kings();

	virtual void FirstSkill() override;
	virtual void detail() override;
};

