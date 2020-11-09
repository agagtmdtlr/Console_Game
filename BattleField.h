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
	vector<IObserver *> observers[2];

	int nPlayerTurn = 0;

	int cost[2]; // 사용 가능한 코스트
	int maXCost = 6; // 보유할수 있는 코스트 한계	

	BattleField();	

	virtual void Attack(Card * myCard, Card * yourCard);	

	virtual void Draw();	

	virtual bool Choice();

	virtual void DeleteCards();

	virtual void ShowField();

	virtual void Init();

	virtual bool CheckEnd();	

	virtual bool CheckIsCanAttack(Creature * target);

	virtual void AddObserver(int turn,const IObserver * observer = nullptr);
	virtual void DeleteObserver(int turn,const IObserver * observer = nullptr);

	virtual void CallObservers(int turn, Card& card, EVENT event);
	virtual void CallObservers(int turn, Card* card, EVENT event);
};


