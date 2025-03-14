#pragma once

//#include "Monster2.h"
//class Monster2;


// class는 설계도
class Player2
{
public:
	void KillMonster();

	void KillMonster2();

public:
	int _hp;
	int _attack;

	//Monster2 _target;
	Player2* _target2;
};

