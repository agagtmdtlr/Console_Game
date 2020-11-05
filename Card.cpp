#include "stdafx.h"
#include "Card.h"


Card::Card(int cost, string name, BattleField * field)
	:nCost(cost), strName(name),battleFieldOfCard(field),isDelete(false)
{}




