#pragma once
#include "stdafx.h"
#include "Creature.h"
#include "BattleField.h"

Creature::Creature(
	BattleField * field,
	int cost, string name,
	int power, int shield,
	int attcount, 
	bool agro, bool holy)
	:Card(cost, name,field),
	nPower(power), nShield(shield), nPreviouShield(shield), nMaxShield(shield),
	nPowerOrigin(power), nShieldOrigin(shield),
	nAttackCount(0),nAttackCountTurn(attcount), nAttackCountOrigin(attcount),	
	isAgro(agro),isHolyShiled(holy),isSilence(false)
{}

void Creature::SetShield(int val)
{
	if (isHolyShiled && val < 0)
	{
		isHolyShiled = false;
		return;
	}
	// 이전 체력을 변경.
	nPreviouShield = nShield;

	// 데미지 계산
	int result = nShield + val;
	// 최대 체력을 넘어갈수 가 없다.
	if (result > nMaxShield) result = nMaxShield;
	
	if (result != nShield)
	{
		EVENT event;
		if (result < nShield)
			event = EVENT::DAMAGE;
		// 기존 체력 보다 올라가야 회복으로 판정된다.
		else if (result > nShield)
			event = EVENT::HEAL;		
		// 현재 체력을 변경
		nShield = result;
		ExcuteObserver(event);
	}

	if (nShield <= 0)
		SetDelete(true);
}

void Creature::Use()
{
	int turn = battleFieldOfCard->nPlayerTurn % 2;

	if (battleFieldOfCard->cost[turn] >= nCost)
	{
		battleFieldOfCard->cost[turn] -= nCost; // 코스트 소모
		cout << "=================================" << endl;
		cout << "==" << strName << "를(을) 소환합니다==" << endl;
		cout << "=================================" << endl;
		if(isSilence == false)
			FirstSkill();
		battleFieldOfCard->cardsOfField[turn].push_back(this);
		Card::Use();
	}
	else
	{
		cout << "=================================" << endl;
		cout << "==가지고 있는 코스트가 부족합니다.==" << endl;
		cout << "=================================" << endl;
	}
	Sleep(1000);
}

void Creature::AttackSkill(Card * target)
{
	return;
}

void Creature::FirstSkill()
{
	return;
}

void Creature::Info()
{
	cout << strName << "|" << nCost << "|" << nPower << "|" << nShield;
	if (isAgro) cout << "|★";
	else cout << "|X";
	if (isHolyShiled) cout << "|♥";
	else cout << "|X";
}

void Creature::detail()
{
	cout << "이름 : " << strName << endl
		<< "코스트 : " << nCost << endl
		<< "파워 : " << nPower << endl
		<< "체력 : " << nShield << endl;
	cout << "어그로 : ";
	if (isAgro) cout << "보유" << endl;
	else cout << "없음" << endl;
	cout << "천상의 보호막 : ";
	if (isHolyShiled) cout << "보유" << endl;
	else cout << "없음" << endl;
}








