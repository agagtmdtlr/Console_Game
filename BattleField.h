#pragma once
class Card;
class Creature;
class IObserver;

class BattleField
{
public:
	Card * User[2];
	// total = 10
	vector<Card *> cardsOfDeck[2];
	// limit = 5
	vector<Card *> cardsOfHand[2];
	// limit = 3
	vector<Card *> cardsOfField[2];
	// 관찰자 리스트를 담습니다.
	vector<Card *> observers[2];
	// 사용되어진 카드 리스트
	vector<Card *> garbageCollector[2];

	Creature * arrFight[2];

	int nPlayerTurn = 0;

	int cost[2]; // 사용 가능한 코스트
	int maXCost = 11; // 보유할수 있는 코스트 한계	

	BattleField();	

	virtual void Attack(Card * myCard, Card * yourCard);	

	virtual void Draw(int turn);	

	virtual bool Choice();

	virtual void DeleteCards();

	virtual void ShowField();

	virtual void InitGame();
	
	virtual void InitTurn();

	virtual bool CheckEnd();	

	virtual bool CheckIsCanAttack(Creature * target);

	virtual void AddObserver(int turn,const Card * observer = nullptr);
	virtual void DeleteObserver(int turn,const Card * observer = nullptr);

	virtual void CallObservers(int turn, Card& card, EVENT event);
	virtual void CallObservers(int turn, Card* card, EVENT event);
};


