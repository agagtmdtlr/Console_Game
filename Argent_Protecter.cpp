#pragma once
#include "stdafx.h"
#include "Argent_Protecter.h"
#include "BattleField.h"



Argent_Protecter::Argent_Protecter()
{
}

Argent_Protecter::Argent_Protecter(BattleField * field)
	:Creature(field, 1, "여명회 파수명", 2, 2, 1, false, false, false)
{
}


Argent_Protecter::~Argent_Protecter()
{
}

void Argent_Protecter::FirstSkill()
{
	int turn = (battleFieldOfCard->nPlayerTurn) % 2;
	// 상대 필드에 카드가 없으면 효과 미발동
	if (battleFieldOfCard->cardsOfField[turn].size() == 0) return;
	int inputNum = 0;
	while (1)
	{
		cout << "아군을 선택하시오 : ";
		inputNum = InputVariable<int>(inputNum);

		if (inputNum >= battleFieldOfCard->cardsOfField[turn].size())
		{
			cout << "다시 입력하시오" << endl;
		}
		else
		{
			break;
		}
	}
	Creature * card = dynamic_cast<Creature *>(battleFieldOfCard->cardsOfField[turn][inputNum]);

	card->SetHolyShield(true);
}

void Argent_Protecter::detail()
{
	Creature::detail();
	if (isSilence)
	{
		cout << "전투의 함성 : " << endl;
		cout << "아군 하수인에게 천상의 보호막을 부여합니다." << endl;
	}
}
