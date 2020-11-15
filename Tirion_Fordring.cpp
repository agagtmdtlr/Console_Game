#pragma once
#include "stdafx.h"
#include "Tirion_Fordring.h"
#include "BattleField.h"
#include "Weapon.h"
#include "Hero.h"

Tirion_Fordring::Tirion_Fordring()
{	
}

Tirion_Fordring::Tirion_Fordring(BattleField * field)
	:Creature(field, 7, "티리온 폴드링", 6, 6, 1, true, true, false)
{
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
	cout << "5/3 파멸의 인도자를 장착합니다." << endl;
	Sleep(1500);
	/*battleFieldOfCard->cardsOfField[nThisCardUserNumber].push_back(
		new Creature(
			battleFieldOfCard, 2, "파멸의 인도자", 5, 3, 1, false, false, false));*/
	
	Hero * hero = (Hero *)battleFieldOfCard->User[nThisCardUserNumber];
	hero->SetWeapon(
		new Weapon(
			nThisCardUserNumber,
			battleFieldOfCard, 2, "파멸의 인도자", 5, 3, 1)
	);
	
	cout << "end" << endl;
	system("pause");
}
