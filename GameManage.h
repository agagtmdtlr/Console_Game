#pragma once
#include "BattleField.h"

enum class E_ACTION
{
	ATTACK,USE,END,SURRENDER
};

class BattleField;
class GameManage
{
public:
	BattleField * field;
	bool isQuitGame = false;
	bool isEndGame = false;
	bool isEndTurn = false;
	bool isChangeField;

	void PlayGaming();
	bool SelectAction();
};



