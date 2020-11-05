#pragma once
#include <iostream>
#include <string>
#include <ctime>
#include <Windows.h>
#include <vector>

using namespace std;

enum class event
{
	BEGIN,END,DEAL,ATTACK,FIELD
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