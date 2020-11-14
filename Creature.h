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
	int nPreviouShield;
	int nMaxShield;
	int nShieldOrigin;	

	int nAttackCount; // 현재 남은 공격 횟수
	int nAttackCountTurn; // 턴마다 주어지는 공격횟수
	int nAttackCountOrigin;	 // 초기 생성 공격횟수

	bool isAgro; // 도발 무조건 이 대상을 우선으로 공격해야 함
	/*
	어그로는 어떻게 구현하면 어그로가 아닌 상대를 공격하지 못하게 막을 수
	있을까요?
	*/
	bool isHolyShiled; // 천상의 보호막 한번의 공격을 막습니다.

	bool isSilence;

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

	virtual void InitStat()
	{
		Card::InitStat();
		nShield = nShieldOrigin;
		nPower = nPowerOrigin;
		nAttackCount = nAttackCountOrigin;
		isAgro = false;
		isHolyShiled = false;
	}

	virtual int GetPower() { return nPower; }
	virtual void SetPower(int val) 
	{		
		nPower += val; 
		if (nPower < 0) nPower = 0;		
	}

	virtual void SetDelete(bool val)
	{
		Card::SetDelete(val);
	}

	virtual int GetShield() { return nShield; }
	virtual void SetShield(int val);	

	virtual int GetPreviousShield() { return nShield; }

	virtual int GetMaxShield() { return nMaxShield; }
	
	virtual void SetMaxShield(int val)// 최대 체력 증가
	{ 
		nMaxShield += val;
		// 3 / 5 -> 3 / 5-3=2 
		// 2-3=-1 -> 3+(-1) = 2;
		nShield += nMaxShield - nShield;
	}

	virtual int GetPowerOrigin() { return nPowerOrigin; }	
	virtual int GetShieldOrigin() { return nShieldOrigin; }	

	virtual int GetAttackCount() { return nAttackCount; }
	virtual void SetAttackCount(int val) { nAttackCount += val; }

	virtual int GetAttackCountTurn() { return nAttackCountTurn; }
	virtual void SetAttackCountTurn(int val) { nAttackCountTurn += val;	}

	virtual int GetAttackCountOrigin() { return nAttackCountOrigin; }
	virtual void SetAttackCountOrigin(int val) { nAttackCountOrigin += val; }
		
	virtual bool GetHolyShiled() { return isHolyShiled; }
	virtual void SetHolyShield(bool val) { isHolyShiled = val; }

	virtual bool GetAgro() { return isAgro; }	
	
	virtual bool GetSilence() { return isSilence; }
	virtual void SetSilence(bool val)
	{
		isSilence = val;
		if (isSilence)
			InitStat();
	}

	virtual void AttackSkill(Card * target);
	virtual void FirstSkill();
	virtual void Use() override;
	virtual void Info() override;
	virtual void detail() override;	
	
};

