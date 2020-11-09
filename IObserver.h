#pragma once

class Card;
enum class EVENT;

class IObserver
{

public:
	virtual ~IObserver(){}
	virtual void onNotify(const Card& card, EVENT event) = 0;
	virtual void onNotify(const Card* card, EVENT event) = 0;
};

