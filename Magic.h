#pragma once
#include "Card.h"
class Magic :
	public Card
{
protected:
	int nPower;
public:
	Magic();
	Magic(
		BattleField * field,
		int cost,
		string name,
		int power
	);
	virtual ~Magic();

	virtual void SetDelete(bool val)
	{
		isDelete = true;
	}
	virtual void Use() override;
	virtual void FirstSkill();
	virtual void Info() override;
	virtual void detail() override;
};

