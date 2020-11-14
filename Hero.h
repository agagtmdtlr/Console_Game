#pragma once
#include "Creature.h"
#include "Weapon.h"
#include "Magic.h"

class Hero :
	public Creature
{
private :
	Weapon * weapon;
	vector<Magic *> secret;
public:
	Hero();
	Hero(
		BattleField * field,
		int cost, string name,
		int power, int shield,
		int attcount,
		bool agro, bool holy,
		bool hide, Weapon * weapon = nullptr
	);
	~Hero();

	virtual void Use() override;
	virtual void FirstSkill() override;

	
	virtual int GetPower() override; // 영웅과 무기 같이 계산

	virtual int GetAttackCount() override;
	virtual void SetAttackCount(int val) override;	
		
	virtual Weapon * GetWeapon() { return weapon; }
	virtual void SetWeapon(Weapon * val) 
	{ 
		weapon = val;
		if(weapon != nullptr)
			nAttackCountTurn = weapon->GetAttackCount();
	}
	
};

