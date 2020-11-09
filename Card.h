#pragma once
#include "IObserver.h"
#include "BattleField.h"
class BattleField;

class Card
	: public IObserver
{
protected:
	int nCost;	
	string strName;
	// 카드 효과 발생시 필드를 직접 제어
	BattleField * battleFieldOfCard;	
	// 관찰자 목록
	bool isDelete;
public:
	Card() {};	
	Card(int cost, string name, BattleField * field);
	virtual ~Card() 
	{
		ExcuteObserver(EVENT::DIE);
	}

	virtual int GetCost() { return nCost; }		
	virtual void SetCost(const int val) 
	{ 		
		nCost += val; 
		if (nCost < 0) nCost = 0;
	}
	virtual bool GetDelete() { return isDelete; }
	virtual void SetDelete(bool val)
	{
		isDelete = val; 
	}

	virtual void Use()
	{
		ExcuteObserver(EVENT::FIELD);
	}
	virtual void Info(){}
	virtual void detail(){}

	virtual void onNotify(const Card& card, EVENT event) {}
	virtual void onNotify(const Card* card, EVENT event) {}

	virtual void ExcuteObserver(EVENT event)
	{
		int turn = battleFieldOfCard->nPlayerTurn % 2;
		for (int i = 0; i < battleFieldOfCard->observers[turn].size(); i++)
			battleFieldOfCard->observers[turn][i]->
			onNotify(*this, event);
	}
};

