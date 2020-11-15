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
}

void Hero::SetWeapon(Weapon * val)
{
	if (weapon != nullptr)// 무기 장착하기전에 이미 장비되어 있다면 바꿔 낀다.
	{
		weapon->SetDelete(true); // 기존무기를 해제하고 쓰레기통으로 보낸다.
		battleFieldOfCard->garbageCollector[nThisCardUserNumber].push_back(weapon);
		weapon = nullptr;
	}
	weapon = val;
	// 무기가 장착 됬으므로 영웅의 공격횟수를 무기에 맞춘다.
	if (weapon != nullptr)
	{
		nAttackCountTurn = weapon->GetAttackCount();
		nAttackCount = nAttackCountTurn;
	}
}
