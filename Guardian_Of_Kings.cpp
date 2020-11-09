#pragma once
#include "stdafx.h"
#include "Guardian_Of_Kings.h"
#include "BattleField.h"



Guardian_Of_Kings::Guardian_Of_Kings()
{
}

Guardian_Of_Kings::Guardian_Of_Kings(BattleField * field)
	:Creature(field, 6, "왕의 수호자", 5, 6, 1, false, false)
{
}

Guardian_Of_Kings::~Guardian_Of_Kings()
{
}

void Guardian_Of_Kings::FirstSkill()
{
	int turn = battleFieldOfCard->nPlayerTurn % 2;
	Creature * user = dynamic_cast<Creature *>(battleFieldOfCard->User[turn]);
	user->SetShield(6);
}

void Guardian_Of_Kings::detail()
{
	Creature::detail();
	cout << "내 영웅의 생명력을 6 회복 시킵니다." << endl;
}
