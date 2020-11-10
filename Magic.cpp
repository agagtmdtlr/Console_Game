#pragma once
#include "stdafx.h"
#include "Magic.h"

Magic::Magic()
{
}

Magic::Magic(BattleField * field, int cost, string name, int power)
	:Card(cost,name,field),nPower(power)
{
}

Magic::~Magic()
{
}

void Magic::Use()
{
	int turn = battleFieldOfCard->nPlayerTurn % 2;
	if (battleFieldOfCard->cost[turn] >= nCost)
	{
		battleFieldOfCard->cost[turn] -= nCost; // 코스트 소모
		cout << "=================================" << endl;
		cout << "==" << strName << "를(을) 사용합니다==" << endl;
		cout << "=================================" << endl;
		this->FirstSkill();
		SetDelete(true);
	}
	else
	{
		cout << "=================================" << endl;
		cout << "==가지고 있는 코스트가 부족합니다.==" << endl;
		cout << "=================================" << endl;
	}
	Sleep(1000);
}

void Magic::FirstSkill()
{
}

void Magic::Info()
{
	cout << strName << "|" << nCost << "|" << nPower;
}

void Magic::detail()
{
	cout << "이름 : " << strName << endl
		<< "코스트 : " << nCost << endl
		<< "파워 : " << nPower << endl;
}
