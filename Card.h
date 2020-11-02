#pragma once
#include "BattleField.h"

class BattleField;

class Card
{
protected:
	int nCost;	
	string strName;
	BattleField * battleFieldOfCard;
	bool isDelete = false;
public:
	Card() {};
	Card(int cost, string name, BattleField * field);

	int GetCost() { return nCost; }		
	bool GetDelete() { return isDelete; }
	void SetDelete(bool val) { isDelete = val; }
	void Use(){}
	void Info(){}
	void detail(){}
};

