#pragma once
#include "stdafx.h"
#include "AldorPeaceKeeper.h"
#include "BattleField.h"

AldorPeaceKeeper::AldorPeaceKeeper(BattleField * field)
	:Creature(field,2,"알도르 평화감시단",3,3,1,false,false,false)
{	
}

void AldorPeaceKeeper::Attack(Card * target)
{
}

void AldorPeaceKeeper::FirstSkill()
{
	int e_turn = 1 - nThisCardUserNumber;
	// 상대 필드에 카드가 없으면 효과 미발동
	
	// 필드가 비어 있음
	if (battleFieldOfCard->cardsOfField[e_turn].size() <= 0) return;

	vector<Card *> selectList;
	selectList.reserve(FieldMax);

	// 실제로 타케팅 가능한 하수인이 존재하는지 확인하기
	for (int i = 0; i < battleFieldOfCard->cardsOfField[e_turn].size(); i++)
	{
		Creature * creature = (Creature *)battleFieldOfCard->cardsOfField[e_turn][i];
		if (creature->GetMagicTargeted() == true && creature->GetInvincibility() == false)
			selectList.push_back(creature);
	}
	if (selectList.size() <= 0) return;

	cout << "적의 하수인 필드" << endl;		
	int selectNum = SelectCard(&selectList); // 카드 선택
	
	Creature * enemy = dynamic_cast<Creature *>(selectList[selectNum]);
	enemy->SetPower(-(enemy->GetPower()-1));
}

void AldorPeaceKeeper::Use()
{
	Creature::Use();
}

void AldorPeaceKeeper::Info()
{
	Creature::Info();
}

void AldorPeaceKeeper::detail()
{
	Creature::detail();
	cout << "전투의 함성 : " << endl;
	cout << "선택한 적의 공격력을 1로 만듭니다." << endl;
}
