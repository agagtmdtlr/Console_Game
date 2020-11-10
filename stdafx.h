#pragma once
#include <iostream>
#include <string>
#include <ctime>
#include <Windows.h>
#include <vector>

using namespace std;

enum class EVENT
{
	BEGIN,DRAW,FIELD,ATTACK,DAMAGE,HEAL,DIE,END
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