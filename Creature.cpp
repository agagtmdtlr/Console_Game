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
	nPower(power), nShield(shield),
	nPowerOrigin(power), nShieldOrigin(shield),
	nAttackCount(attcount), nAttackCountOrigin(attcount),	
	isAgro(agro),isHolyShiled(holy)
{}

void Creature::Use()
{
	int turn = battleFieldOfCard->nPlayerTurn % 2;

	if (battleFieldOfCard->cost[turn] >= nCost)
	{
		battleFieldOfCard->cost[turn] -= nCost; // 코스트 소모
		cout << "=================================" << endl;
		cout << "==" << strName << "를(을) 소환합니다==" << endl;
		cout << "=================================" << endl;
		this->FirstSkill();
		battleFieldOfCard->cardsOfField[turn].push_back(new Creature(*this));
		isDelete = true;
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

void Creature::FirstSkill(Card * target)
{
	return;
}

void Creature::Info()
{
	cout << strName << "|" << nCost << "|" << nPower << "|" << nShield;
	if (isAgro) cout << "|★";
	else cout << "|X";
	if (isAgro) cout << "|♥";
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







