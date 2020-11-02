#include "stdafx.h"
#include "GameManage.h"
#include "BattleField.h"

void GameManage::PlayGaming()
{
	BattleField * field = new BattleField;
	
	bool isQuitGame = false;
	while (!isQuitGame)
	{
		field->Init();
		while (true)
		{
			system("cls");
			field->Draw();
			system("cls");
			field->ShowField();
			system("pause");
		}
	}
}
