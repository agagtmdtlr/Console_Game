#pragma once
#include "Card.h"


class BattleField;

class Creature :
	public Card
{
protected:
	int nPower;
	int nPowerOrigin;	

	int nShield;
	int nShieldOrigin;	

	int nAttackCount;
	int nAttackCountOrigin;

	bool isAgro; // 도발 무조건 이 대상을 우선으로 공격해야 함	
	bool isHolyShiled; // 천상의 보호막 한번의 공격을 막습니다.

public:
	Creature(){}
	Creature(
		BattleField * field,
		int cost, string name,
		int power, int shield,
		int attcount,
		bool agro, bool holy
		);
	virtual ~Creature(){}

	virtual int GetPower() { return nPower; }
	virtual void SetPower(int val) 
	{
		nPower += val; 
		if (nPower < 0) nPower = 0;
	}

	virtual int GetShield() { return nShield; }
	virtual void SetShield(int val)
	{
		nShield += val;
		if (nShield <= 0)
			isDelete = true;
	}

	virtual int GetPowerOrigin() { return nPowerOrigin; }	
	virtual int GetShieldOrigin() { return nShieldOrigin; }	

	virtual int GetAttackCount() { return nAttackCount; }
	virtual void SetAttackCount(int val) { nAttackCount += val; }

	virtual int GetAttackCountOrigin() { return nAttackCountOrigin; }
	virtual void SetAttackCountOrigin(int val) { nAttackCountOrigin += val; }
		
	virtual bool GetHolyShiled() { return isHolyShiled; }
	virtual void SetHolyShield(bool val) { isHolyShiled = val; }

	virtual bool GetAgro() { return isAgro; }
	
	
	virtual void AttackSkill(Card * target = NULL);
	virtual void FirstSkill(Card * target = NULL);
	virtual void Use() override;
	virtual void Info() override;
	virtual void detail() override;
};

