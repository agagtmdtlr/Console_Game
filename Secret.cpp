#pragma once
#include "stdafx.h"
#include "Secret.h"


Secret::Secret(BattleField * field, int cost, string name, int power)
	:Card(cost, name, field),
	nPower(power),nPowerOrigin(power)
{
}

void Secret::Use()
{
	int turn = battleFieldOfCard->nPlayerTurn % 2;	

	if (battleFieldOfCard->cost[turn] >= nCost)
	{
		Hero * hero = (Hero*)battleFieldOfCard->User[turn];
		if (hero->GetSecretSize() < 3)
			hero->SetSecretCard(this);
		else
		{
			cout << "====================================" << endl;
			cout << "== 비밀카드를 더 장착할 수 없습니다 .==" << endl;
			cout << "====================================" << endl;
			Sleep(1000);
			return;
		}			

		battleFieldOfCard->cost[turn] -= nCost; // 코스트 소모
		cout << "=================================" << endl;
		cout << "== 비밀카드 : " << strName << "를(을) 장착합니다==" << endl;
		cout << "=================================" << endl;
		FirstSkill();
		
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

void Secret::FirstSkill()
{
}
