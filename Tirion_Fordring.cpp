#pragma once
#include "stdafx.h"
#include "Tirion_Fordring.h"
#include "BattleField.h"


Tirion_Fordring::Tirion_Fordring()
{	
}

Tirion_Fordring::Tirion_Fordring(BattleField * field)
	:Creature(field, 7, "티리온 폴드링", 6, 6, 1, true, true)
{
	myTurn = battleFieldOfCard->nPlayerTurn % 2;
	cout << myTurn << endl;
	system("pause");
}


Tirion_Fordring::~Tirion_Fordring()
{	
}


void Tirion_Fordring::detail()
{
	Creature::detail();
	cout << "천상의 보호막,도발," << endl
		<< "죽음의 메아리 : 5/3 파멸의 인도자를 소환합니다" << endl;
}

void Tirion_Fordring::SetDelete(bool val)
{
	cout << "delete" << endl;
	system("pause");
	Card::SetDelete(val);
	cout << "5/3 파멸의 인도자를 소환합니다." << endl;
	Sleep(1500);
	battleFieldOfCard->cardsOfField[myTurn].push_back(new Creature(battleFieldOfCard, 2, "파멸의 인도자", 5, 3, 1, false, false));
	cout << "end" << endl;
	system("pause");
}
