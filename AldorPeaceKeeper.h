#pragma once
#include "Creature.h"

class BattleField;

class AldorPeaceKeeper :
	public Creature
{
private:
public:
	AldorPeaceKeeper(BattleField * field);
	virtual ~AldorPeaceKeeper(){}

	virtual void Attack(Card * target = NULL);
	virtual void FirstSkill () override;
	virtual void Use() override;
	virtual void Info() override;
	virtual void detail() override;
};

