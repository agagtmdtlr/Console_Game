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
	Creature(
		BattleField * field,
		int cost, string name,
		int power, int shield,
		int attcount,
		bool agro, bool holy
		);

	int GetPower() { return nPower; }
	void SetPower(int val) { nPower += val; }

	int GetShield() { return nShield; }
	void SetShield(int val)
	{
		nShield += val;
		if (nShield <= 0)
			isDelete = true;
	}

	int GetPowerOrigin() { return nPowerOrigin; }
	void SetPowerOrigin(int val) { nPowerOrigin += val; }

	int GetShieldOrigin() { return nShieldOrigin; }
	void SetShieldOrigin(int val) { nShieldOrigin += val; }

	int GetAttackCount() { return nAttackCount; }
	void SetAttackCount(int val) { nAttackCount += val; }

	int GetAttackCountOrigin() { return nAttackCountOrigin; }
	void SetAttackCountOrigin(int val) { nAttackCountOrigin += val; }
		
	bool GetHolyShiled() { return isHolyShiled; }
	void SetHolyShield(bool val) { isHolyShiled = val; }

	bool GetAgro() { return isAgro; }
	
	void Use();
	void AttackSkill(Card * target = NULL);
	void FirstSkill(Card * target = NULL);
	void Info() {}
	void detail();
};

