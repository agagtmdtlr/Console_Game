#pragma once
#include "Creature.h"
class Argent_Protecter :
	public Creature
{
public:
	Argent_Protecter();
	Argent_Protecter(BattleField * field);
	~Argent_Protecter();

	virtual void FirstSkill() override;
	virtual void detail() override;
};

