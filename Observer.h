#pragma once
#include "Card.h"
class Card;
class Observer
{
public:
	virtual ~Observer(){}
	virtual void onNotify(const Card& card) = 0;
};

