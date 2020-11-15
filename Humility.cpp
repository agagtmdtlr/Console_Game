#pragma once
#include "stdafx.h"
#include "Humility.h"

Humility::Humility()	
{
}

Humility::Humility(BattleField * field)
	:Magic(field, 1, "겸손", 0)
{
}

void Humility::Info()
{
	cout << strName << "|" << nCost;
}

void Humility::FirstSkill()
{

	// 실제로 타케팅 가능한 하수인이 존재하는지 확인하기
	vector<Card *> selectList[2];
	int targetSum[2] = { 0,0 };
	for (int i = 0; i < 2; i++)
	{
		selectList[i].reserve(FieldMax);
		for (int j = 0; j < battleFieldOfCard->cardsOfField[i].size(); j++)
		{
			Creature * creature = (Creature *)battleFieldOfCard->cardsOfField[i][j];

			if(creature->GetThisCardUser() != nThisCardUserNumber)
			{
				if (creature->GetMagicTargeted() == true &&
					creature->GetInvincibility() == false)
				{
					selectList[i].push_back(creature);
					targetSum[i]++;
				}					
			}
			else
			{
				selectList[i].push_back(creature);
				targetSum[i]++;
			}				
		}		
	}
	if (targetSum[0] + targetSum[1] <= 0) return;

	// 필드에 하수인이 존재하므로 선택을 수행한다.
	int selectNum;
	int fieldNum = 0;
	if (selectList[0].size() > 0 && selectList[1].size() > 0)
	{
		cout << "필드를 선택하시오(0.내 필드  1.상대 필드)" << endl;
		fieldNum = InputVariable<int>(fieldNum);
		fieldNum = (fieldNum + nThisCardUserNumber) % 2;
		selectNum = SelectCard(&selectList[fieldNum]);
	}
	else
	{
		if (targetSum[nThisCardUserNumber] > 0) // 내필드에서 선택
		{
			fieldNum = nThisCardUserNumber;
			selectNum = SelectCard(&selectList[fieldNum]);
			
		}			
		else // 적 필드에서 선택
		{
			fieldNum = 1 - nThisCardUserNumber;
			selectNum = SelectCard(&selectList[fieldNum]);
		}
	}
	Creature * enemy = dynamic_cast<Creature *>(selectList[fieldNum][selectNum]);
	enemy->SetPower(-(enemy->GetPower() - 1));
}
