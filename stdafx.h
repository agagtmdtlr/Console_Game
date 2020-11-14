#pragma once
#include <iostream>
#include <string>
#include <ctime>
#include <Windows.h>
#include <vector>

using namespace std;

#define DeckSetting 40
#define HandMax 5
#define FieldMax 5
#define SecretMax 3


enum class EVENT
{
	BEGIN,
	DRAW,
	USE,
	FIELD,
	ATTACK,
	DAMAGE,
	HEAL,
	NONE,
	DESTROY,
	END
};

template <typename T>
T InputVariable(T val)
{
	while (1)
	{
		cin >> val;
		if (cin.fail())
		{
			cout << "error input type please retry : ";
			cin.clear();
			cin.ignore(10, '\n');
		}
		else return val;
	}
	
}