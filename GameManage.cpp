#pragma once
#include "stdafx.h"
#include "GameManage.h"
#include "Card.h"


void GameManage::PlayGaming()
{
	field = new BattleField;
	
	isQuitGame = false;	
	while (!isQuitGame)
	{		
		field->Init();
		isEndGame = false;
		while (!isEndGame)
		{
			system("cls");
			int thisTurnCost = field->nPlayerTurn / 2 + 3;
			if (thisTurnCost > field->maXCost)
				field->cost[field->nPlayerTurn % 2] = field->maXCost;
			else
				field->cost[field->nPlayerTurn % 2] = thisTurnCost;
			field->Draw();
			isEndTurn = false;
			while (!isEndTurn)
			{
				system("cls");
				field->ShowField();
				// if Active changed the field refresh field output
				isChangeField = SelectAction();
				if (isChangeField)
				{
					system("cls");
					field->ShowField();
					Sleep(1000);
				}
					
				// if exhausted of user hp end the game
				if (field->CheckEnd())
				{
					isEndGame = true;
					break;
				}
				// to delete died creature or used cards 
				field->DeleteCards();
				//system("pause");
			}
			// 다음 유저의 턴으로 넘긴다.
			field->nPlayerTurn += 1;
		}		
	}

	delete field;
}

bool GameManage::SelectAction()
{
	int inputNum;
	int turn = field->nPlayerTurn % 2;
	E_ACTION myAction;
	cout << "\n액션을 선택하세요(0.하수인 공격 1.패 카드 사용 2.턴을 마친다 3.항복한다)\n : ";
	cin >> inputNum;

	myAction = (E_ACTION)inputNum;


	switch (myAction)
	{
	case E_ACTION::ATTACK:
		unsigned int myCreatureIndex;
		unsigned int enemyCreatureIndex;
		cout << "공격할 나의 하수인을 선택하세요 : ";
		cin >> myCreatureIndex;
		if (myCreatureIndex >= field->cardsOfField[turn].size())
			return false;
		cout << "적 하수인?(0)상대 영웅?(1) : ";
		cin >> enemyCreatureIndex;
		if (enemyCreatureIndex == 1)
		{
			field->Attack(
				field->cardsOfField[turn][myCreatureIndex],
				field->User[abs(turn -1)]
			);
		}
		else
		{
			cout << "공격할 적의 하수인을 선택하세요 : ";
			cin >> enemyCreatureIndex;
			if (myCreatureIndex >= field->cardsOfField[abs(turn - 1)].size())
				return false;
			//두카드의 싸움
			field->Attack(
				field->cardsOfField[turn][myCreatureIndex],
				field->cardsOfField[abs(turn - 1)][enemyCreatureIndex]
			);
		}
		
		return true;		
		break;
	case E_ACTION::USE:
		int selectNum;
		cout << "패에서 사용할 카드를 선택하세요 : " ;
		cin >> selectNum;
		if (selectNum >= field->cardsOfHand[turn].size())
			return false;
		field->cardsOfHand[turn][selectNum]->Use();
		return true;
		break;
	case E_ACTION::END:
		isEndTurn = true;
		return false;
		break;
	case E_ACTION::SURRENDER:
		field->User[turn]->SetDelete(true);
		cout << "PLAYER" << turn << "이 항복했습니다." << endl;
		cout << "좋은 승부였다." << endl;
		Sleep(2000);
		return false;
		break;
	default:
		return false;
		break;		
	}
	


}
