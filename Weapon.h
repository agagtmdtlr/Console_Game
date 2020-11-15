#pragma once
#include "Card.h"
#include "Hero.h"


class Weapon :
	public Card
{
private:
	int equiptedPlayer;

	int nAttackCount;

	int nPower;
	int nPowerOrigin;

	int nDurability;
	int nDurabilityOrigin;	
public:
	Weapon() {};
	Weapon(		
		BattleField * field,
		int cost, string name,
		int power, int durability,
		int attcount
	);

	Weapon(
		int userNumber,
		BattleField * field,
		int cost, string name,
		int power, int durability,
		int attcount
	);

	virtual ~Weapon();	

	virtual void SetDelete(bool val) override;
	

	virtual int GetPower() { return nPower; }
	virtual void SetPower(int val) { nPower += val; }

	virtual int GetDurability() { return nDurability; }
	virtual void SetDurability(int val) 
	{
		nDurability += val; 
		if (nDurability <= 0)
		{
			SetDelete(true);	
		}
	}

	virtual int GetAttackCount() { return nAttackCount; }
	
	virtual int GetPowerOrigin() { return nPowerOrigin; }
	virtual int GetDurabilityOrigin() { return nDurabilityOrigin; }

	virtual void Use() override;
	
	inline virtual void FirstSkill() {};
};

