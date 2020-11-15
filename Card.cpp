#pragma once
#include "stdafx.h"
#include "Card.h"



Card::Card(int cost, string name, BattleField * field)
	:nCost(cost), nCostOrigin(cost), strName(name),battleFieldOfCard(field),isDelete(false)
{
	nThisCardUserNumber = field->nPlayerTurn % 2;
}

int Card::SelectCard(vector<Card*> *pCardCategory)
{	
	int inputNum = 0;
	for (int i = 0; i < pCardCategory->size(); i++)
	{
		cout << i << " : ";
		(*pCardCategory)[i]->Info();
		cout << "\t";
	}
	cout << endl;
		
	while (1)
	{
		cout << "대상을 선택하시오 : ";
		inputNum = InputVariable<int>(inputNum);

		if (inputNum >= pCardCategory->size())
		{
			cout << "다시 입력하시오" << endl;
		}
		else
		{
			return inputNum;
		}
	}
}











