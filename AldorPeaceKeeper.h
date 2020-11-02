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
	void FirstSkill(Card * target = NULL);
	void Use();
	void Info();
	void detail();
};

