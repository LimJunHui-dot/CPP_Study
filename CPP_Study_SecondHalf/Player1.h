#pragma once
#include "Creature.h"

enum PlayerType
{
	PT_Knight = 1,
	PT_Archer = 2,
	PT_Mage = 3
};


class Player1 : public Creature
{
public:
	Player1(int playerType) : Creature(CT_PLAYER), _playerType(playerType)
	{
		
	}

	virtual ~Player1()
	{

	}

	virtual void PrintInfo();

protected:
	int _playerType;
};

class Knight : public Player1
{
public:
	Knight() : Player1(PT_Knight)
	{
		_hp = 150;
		_attack = 10;
		_defence = 5;
	}
};

class Archer : public Player1
{
public:
	Archer() : Player1(PT_Archer)
	{
		_hp = 80;
		_attack = 15;
		_defence = 3;
	}
};

class Mage : public Player1
{
public:
	Mage() : Player1(PT_Mage)
	{
		_hp = 50;
		_attack = 25;
		_defence = 0;
	}
};

