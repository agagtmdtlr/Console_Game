#pragma once
#include "BattleField.h"

class BattleField;

class Card
{
protected:
	int nCost;	
	string strName;
	BattleField * battleFieldOfCard;
	bool isDelete;
public:
	Card() {};	
	Card(int cost, string name, BattleField * field);
	virtual ~Card() {}

	virtual int GetCost() { return nCost; }		
	virtual bool GetDelete() { return isDelete; }
	virtual void SetDelete(bool val) { isDelete = val; }
	virtual void Use(){}
	virtual void Info(){}
	virtual void detail(){}
};

