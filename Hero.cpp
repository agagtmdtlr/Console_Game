#pragma once
#include "stdafx.h"
#include "Hero.h"

Hero::Hero()
{
}

Hero::Hero(BattleField * field, int cost, string name, int power, int shield, int attcount, bool agro, bool holy, bool hide, Weapon * weapon)
	: Creature(field, cost, name, power, shield, attcount, agro, holy, hide),
	weapon(weapon)
{
}


Hero::~Hero()
{
}

void Hero::Use()
{
	int turn = battleFieldOfCard->nPlayerTurn % 2;
	
	if (battleFieldOfCard->cost[turn] >= nCost)
	{
		battleFieldOfCard->cost[turn] -= nCost; // 코스트 소모
		cout << "=================================" << endl;
		cout << "==" << strName << "를(을) 소환합니다==" << endl;
		cout << "=================================" << endl;
		
		if (isSilence == false)
			FirstSkill();

		Card * beforeHero = battleFieldOfCard->User[turn];
		battleFieldOfCard->User[turn] = this;
		delete beforeHero;
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

void Hero::FirstSkill()
{
	int turn = battleFieldOfCard->nPlayerTurn % 2;
	Hero * beforeHero = (Hero *)battleFieldOfCard->User[turn];
	
	// 이전 영웅이 착용한 무기를 물려받음
	weapon = beforeHero->GetWeapon();
	// 이전 영웅 무기 해제
	beforeHero->SetWeapon(nullptr);
	
}

int Hero::GetPower()
{
	int nTotalPower = nPower;
	if (weapon != nullptr)
		nTotalPower += weapon->GetPower();
	return nTotalPower;
}

int Hero::GetAttackCount()
{
	return Creature::GetAttackCount();
}

void Hero::SetAttackCount(int val)
{
	nAttackCount += val;
	if (weapon != nullptr) // 공격시 착용 무기 내구도도 떨어짐
		weapon->SetDurability(val);
	// 무기 파괴시 영웅 공격횟수 초기화
	if (weapon->GetDelete() == true)
		// 2 cnt weapon destroy when use 1cnt
		// hero org cnt 1 but we att 1
		// 2 - 1 - 1 = 0;
		// 2 cnt weapon destroy when use 2cnt
		// hero org cnt 1 but we att 2
		// 2 - 2 - 1  = - 1		
		nAttackCount = nAttackCount - nAttackCountOrigin;		
		nAttackCountTurn = nAttackCountOrigin;
}
