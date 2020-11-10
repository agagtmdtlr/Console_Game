#pragma once
#include "stdafx.h"
#include "Card.h"



Card::Card(int cost, string name, BattleField * field)
	:nCost(cost), nCostOrigin(cost), strName(name),battleFieldOfCard(field),isDelete(false)
{}









