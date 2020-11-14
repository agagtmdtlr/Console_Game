#pragma once
#include "stdafx.h"
#include "Weapon.h"
#include "Hero.h"


Weapon::Weapon(BattleField * field, int cost, string name, int power, int durability, int attcount)
	: Card(cost,name,field),
	nPower(power), nPowerOrigin(power),
	nDurability(durability), nDurabilityOrigin(durability),
	nAttackCount(attcount)
{
	
}

Weapon::~Weapon()
{
}

void Weapon::Use()
{
	int turn = battleFieldOfCard->nPlayerTurn % 2;

	if (battleFieldOfCard->cost[turn] >= nCost)
	{
		battleFieldOfCard->cost[turn] -= nCost; // 코스트 소모
		cout << "=================================" << endl;
		cout << "== 무기 : " << strName << "를(을) 장착합니다==" << endl;
		cout << "=================================" << endl;
		FirstSkill();
		Hero * hero = (Hero*)battleFieldOfCard->User[turn];		
		hero->SetWeapon(this); // 영웅에게 무기 장착	
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


