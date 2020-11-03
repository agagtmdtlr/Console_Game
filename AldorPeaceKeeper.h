#pragma once
#include "Creature.h"

class BattleField;

class AldorPeaceKeeper :
	public Creature
{
private:
public:
	AldorPeaceKeeper(BattleField * field);
	void Attack(Card * target = NULL);
	virtual void FirstSkill (Card * target = NULL) override;
	virtual void Use() override;
	virtual void Info() override;
	virtual void detail() override;
};

