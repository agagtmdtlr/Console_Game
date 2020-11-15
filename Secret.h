#pragma once
#include "Card.h"
#include "Hero.h"

class Secret :
	public Card
{
private:
	int nPower;
	int nPowerOrigin;
public:
	Secret(){}
	Secret(
		BattleField * field,
		int cost,
		string name,
		int power
	);
	virtual void Use() override;
	virtual void FirstSkill();
};

