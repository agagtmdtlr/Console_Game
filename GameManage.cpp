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
		field->InitGame();
		isEndGame = false;
		while (!isEndGame)
		{
			system("cls");
			// 게임 시작시 효과 발동
			int turn = field->nPlayerTurn % 2;
			field->CallObservers(turn,nullptr, EVENT::BEGIN);
			// 공격 가능 횟수를 초기화
			field->InitTurn();
			// 게임 시작시 효과 발동
			field->CallObservers(field->nPlayerTurn % 2,nullptr, EVENT::BEGIN);			
			// 턴 시작
			isEndTurn = false;
			// 코스트 부여
			int thisTurnCost = field->nPlayerTurn / 2 + 10;
			if (thisTurnCost > field->maXCost)
				field->cost[field->nPlayerTurn % 2] = field->maXCost;
			else
				field->cost[field->nPlayerTurn % 2] = thisTurnCost;
			// 드로우
			field->Draw(turn);
			
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
				}					
				// if exhausted of user hp end the game
				if (field->CheckEnd())
				{
					isEndGame = true;
					isEndTurn = true;
				}
					
				// to delete died creature or used cards 
				field->DeleteCards();
			}
			// 턴 끝날시 효과발동 ( ex) 타우릿산 효과 : 턴 종료시 패에 들고 있는 카드의 코스트가 1 감소합니다. )
			field->CallObservers(field->nPlayerTurn % 2, nullptr, EVENT::END);
			// 다음 유저의 턴으로 넘긴다.
			field->nPlayerTurn += 1;
		}		
	}

	delete field;
}

bool GameManage::SelectAction()
{
	int inputNum=0;
	unsigned int myCreatureIndex = 0;
	unsigned int enemyCreatureIndex = 0;
	int selectNum = 0;
	int turn = field->nPlayerTurn % 2;
	E_ACTION myAction;
	cout << "\n액션을 선택하세요(0.하수인 공격 1.패 카드 사용 2.턴을 마친다 3.항복한다)\n : ";
	inputNum = InputVariable<int>(inputNum);

	myAction = (E_ACTION)inputNum;


	switch (myAction)
	{
	case E_ACTION::ATTACK:
		

		cout << "공격할 나의 하수인을 선택하세요 : ";
		myCreatureIndex = InputVariable<unsigned int>(myCreatureIndex); // input test
		if (myCreatureIndex >= field->cardsOfField[turn].size())
			return false;
		field->cardsOfField[turn][myCreatureIndex]->detail();
		cout << "--------------------------------------------------" << endl;
		cout << "적 하수인?(0)상대 영웅?(1) : ";
		enemyCreatureIndex = InputVariable<unsigned int>(enemyCreatureIndex);
		if (enemyCreatureIndex == 1)
		{
			field->Attack(
				field->cardsOfField[turn][myCreatureIndex],
				field->User[1-turn]
			);
		}
		else
		{
			cout << "공격할 적의 하수인을 선택하세요 : ";
			enemyCreatureIndex = InputVariable<unsigned int>(enemyCreatureIndex);
			if (myCreatureIndex >= field->cardsOfField[abs(turn - 1)].size())
				return false;
			//두카드의 싸움
			field->Attack(
				field->cardsOfField[turn][myCreatureIndex],
				field->cardsOfField[1-turn][enemyCreatureIndex]
			);
		}
		
		return true;		
		break;
	case E_ACTION::USE:		
		return field->Choice();
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
