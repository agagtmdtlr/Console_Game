#pragma once
#include "stdafx.h"
#include "BattleField.h"
#include "Card.h"
#include "Creature.h"
#include "AldorPeaceKeeper.h"

BattleField::BattleField()	
{
	for (int i = 0; i < 2; i++)
		User[i] = new Creature(this, 0, "Player" + i, 0, 5, 0, false, false);
	cardsOfDeck->reserve(10);
	cardsOfDeck->reserve(5);
	cardsOfDeck->reserve(5);
}

void BattleField::Attack(Card * myCard, Card * yourCard)
{
	Creature * mine = (Creature *)myCard;
	Creature * your = (Creature *)yourCard;

	if (mine->GetAttackCount() == 0)
		return;

	// 공격전 사용 가능 효과 발동
	mine->AttackSkill(your);
	your->AttackSkill(mine);

	// 천상의 보호막 있으면 데미지 안받음
	mine->SetAttackCount(-1);

	if (mine->GetHolyShiled() == false)
		mine->SetShield(-(your->GetPower()));
	else
		mine->SetHolyShield(false);

	if (your->GetHolyShiled() == false)
		your->SetShield(-(mine->GetPower()));
	else
		your->SetHolyShield(false);

	// 공격후 사용 가능 효과 발동
	mine->AttackSkill(your);
	your->AttackSkill(mine);
}

void BattleField::Draw()
{
	int turn = nPlayerTurn % 2;

	// 덱이 비었을 경우
	if (cardsOfDeck[turn].empty())
	{
		cout << "남아 있는 카드가 없어 드로우를 못합니다" << endl;
		Sleep(1000);
		return;
	}

	// 덱이 비지 않았을 경우
	Card* card = cardsOfDeck[turn].back();	
	cardsOfDeck[turn].pop_back();	
	if (cardsOfHand[turn].size() >= 5)
	{
		cout << "보유할 수 있는 카드가 한계입니다." << endl
			<< "드로우한 카드를 삭제합니다." << endl;
	}
	else
		cardsOfHand[turn].push_back(card);
	Sleep(1000);
}

bool BattleField::Choice()
{
	
	int turn = nPlayerTurn % 2;
	int inputNum = 0;
	int SelectNum;

	cout << "사용할 카드를 선택하시오 : ";
	inputNum = InputVariable<int>(inputNum); // input
	SelectNum = inputNum;

	if (SelectNum >= cardsOfHand[turn].size())
		return false;
	cout << "===========================" << endl;
	cout << "======   카드 설명 :  ======" << endl;
	cout << "===========================" << endl;
	cardsOfHand[turn][SelectNum]->detail();
	cout << "정말 사용하시겠습니까(Yes.1 No.0) : ";
	inputNum = InputVariable<int>(inputNum); // input

	if (inputNum == 1)
	{
		Card * card = cardsOfHand[turn][SelectNum];		
		cardsOfHand[turn][SelectNum]->Use();
		return true;
	}
	else if (inputNum == 0)
		return false;
	else
	{
		cout << "잘못 입력하셨습니다." << endl;
		return false;
	}
		
	
}

void BattleField::DeleteCards()
{
	int i = 0;
	for (int turn = 0; turn < 2; turn++)
	{
		i = 0;
		while (1)
		{
			if (i >= cardsOfDeck[turn].size())
				break;
			if (cardsOfDeck[turn][i]->GetDelete() == true)
			{
				delete cardsOfDeck[turn][i];
				cardsOfDeck[turn].erase(cardsOfDeck[turn].begin() + i);
			}
			else
			{
				i++;
			}
		}

		i = 0;
		while (1)
		{
			if (i >= cardsOfHand[turn].size())
				break;
			if (cardsOfHand[turn][i]->GetDelete() == true)
			{
				delete cardsOfHand[turn][i];
				cardsOfHand[turn].erase(cardsOfHand[turn].begin() + i);
			}
			else
			{
				i++;
			}
		}

		i = 0;
		while (1)
		{
			if (i >= cardsOfField[turn].size())
				break;
			if (cardsOfField[turn][i]->GetDelete() == true)
			{
				delete cardsOfField[turn][i];
				cardsOfField[turn].erase(cardsOfField[turn].begin() + i);
			}
			else
			{
				i++;
			}
		}
	}
	
}

void BattleField::ShowField()
{
	int turn = nPlayerTurn % 2;
	int e_turn = 1 - turn;
	Creature * myPlayerBody =dynamic_cast<Creature *>(User[turn]);
	Creature * enemyPlayerBody = dynamic_cast<Creature *>(User[e_turn]);

	cout << "PLAYER" << turn << " TURN" << endl;
	cout << "\t\t상대 체력 : " << enemyPlayerBody->GetShield() << endl;
	cout << "현재 상대의 덱에 남은 카드 수 : " 
		<< cardsOfDeck[e_turn].size() << endl;
	cout << "상대 패 : ";
	for (int i = 0; i < cardsOfHand[e_turn].size(); i++)
		cout << " ■ ";
	cout << endl;
	cout << "상대 필드 : ";
	for (int i = 0; i < cardsOfField[e_turn].size(); i++)
	{
		cardsOfField[e_turn][i]->Info();
		cout << "\t";
	}
	cout << "\n================================================" << endl;
	
	cout << "내 필드 : ";
	for (int i = 0; i < cardsOfField[turn].size(); i++)
	{
		cardsOfField[turn][i]->Info();
		cout << "\t";
	}
	cout << endl;
	cout << "내 패 : ";
	for (int i = 0; i < cardsOfHand[turn].size(); i++)
	{
		cardsOfHand[turn][i]->Info();
		cout << "\t";
	}
	cout << endl;
	cout << "현재 나의 덱에 남은 카드 수 : "
		<< cardsOfDeck[turn].size() << endl;
	cout << "\t\t나의 체력 : " << myPlayerBody->GetShield() << endl;
	cout << "남은 코스트 : " << cost[turn];
		


}

void BattleField::Init()
{
	nPlayerTurn = 0;
	// 유저 정보 초기화
	for (int i = 0; i < 2; i++)
	{
		cost[i] = 0;
		delete User[i];
		User[i] = new Creature(this, 0, "Player" + i, 0, 5, 0, false, false);
	}

	// 안에 자료 비우기
	for (int i = 0; i < 2; i++)
	{		
		for (int j = 0; j < cardsOfField[i].size(); j++)
		{
			delete cardsOfField[i][j];
		}
		cardsOfField[i].clear();

		for (int j = 0; j < cardsOfDeck[i].size(); j++)
		{
			delete cardsOfDeck[i][j];
		}
		cardsOfDeck[i].clear();

		for (int j = 0; j < cardsOfHand[i].size(); j++)
		{
			delete cardsOfHand[i][j];
		}
		cardsOfHand[i].clear();		
	}	

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			cardsOfDeck[i].push_back(new AldorPeaceKeeper(this));
		}
	}
}

bool BattleField::CheckEnd()
{
	for (int i = 0; i < 2; i++)
	{
		if (User[i]->GetDelete() == true)
		{
			system("cls");
			Sleep(1000);
			cout << "아니! 이럴수가!" << endl;
			Sleep(1000);
			cout << "PLAYER" << (i + 1) % 2 << "의 승리입니다 축하합니다!!!" << endl;
			Sleep(500);
			cout << "게임을 종료합니다" << endl;
			return true;
		}
	}
	return false;
}
