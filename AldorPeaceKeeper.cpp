#include "stdafx.h"
#include "AldorPeaceKeeper.h"
#include "BattleField.h"

AldorPeaceKeeper::AldorPeaceKeeper(BattleField * field)
	:Creature(field,2,"알도르 평화감시단",3,3,1,false,false)
{	
}

void AldorPeaceKeeper::Attack(Card * target)
{
}

void AldorPeaceKeeper::FirstSkill(Card * target)
{
	int e_turn = (battleFieldOfCard->nPlayerTurn + 1) % 2;
	// 상대 필드에 카드가 없으면 효과 미발동
	if (battleFieldOfCard->cardsOfField[e_turn].size() == 0) return;
	int inputNum = 0;
	while (1)
	{
		cout << "적을 선택하시오 : ";
		inputNum = InputVariable<int>(inputNum);

		if (inputNum >= battleFieldOfCard->cardsOfField[e_turn].size())
		{
			cout << "다시 입력하시오" << endl;
		}
		else
		{
			break;
		}		
	}
	Creature * enemy = dynamic_cast<Creature *>(battleFieldOfCard->cardsOfField[e_turn][inputNum]);
	
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
	cout << "효과 : " << endl;
	cout << "선택한 적의 공격력을 1로 만듭니다." << endl;
}
