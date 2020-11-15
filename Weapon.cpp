#pragma once
#include "stdafx.h"
#include "Weapon.h"




Weapon::Weapon(BattleField * field, int cost, string name, int power, int durability, int attcount)
	: Card(cost, name, field),
	nPower(power), nPowerOrigin(power),
	nDurability(durability), nDurabilityOrigin(durability),
	nAttackCount(attcount)
{
}

Weapon::Weapon(int userNumber, BattleField * field, int cost, string name, int power, int durability, int attcount)
	: Card(cost,name,field),
	nPower(power), nPowerOrigin(power),
	nDurability(durability), nDurabilityOrigin(durability),
	nAttackCount(attcount)
{
	nThisCardUserNumber = userNumber;
}

Weapon::~Weapon()
{
}

void Weapon::SetDelete(bool val)
{
	Card::SetDelete(val);

	if (isDelete == true)
	{
		// 해당 무기를 장착하고 있는 유저의 공격관련(횟수) 초기화 해준다.
		Hero * hero = (Hero *)battleFieldOfCard->User[nThisCardUserNumber];
		hero->ReleaseWeapon();
	}
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


