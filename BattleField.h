#pragma once


class Card;

class BattleField
{
public:

	Card * User[2];

	// total = 10
	vector<Card*> cardsOfDeck[2];
	// limit = 5
	vector<Card*> cardsOfHand[2];
	// limit = 3
	vector<Card*> cardsOfField[2];

	int nPlayerTurn = 0;

	int cost[2]; // 사용 가능한 코스트
	int maXCost = 6; // 보유할수 있는 코스트 한계	

	BattleField();

	void Attack(Card * myCard, Card * yourCard);	

	void Draw();	

	void Choice(Card * card);

	void DeleteCards();

	void ShowField();

	void Init();

	bool CheckEnd();	
};


