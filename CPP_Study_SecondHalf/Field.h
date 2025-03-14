#pragma once

class Player1;
class Monster1;

class Field
{
public:
	Field();
	~Field();

	void Update(Player1* player);
	void CreateMonster();

	void StartBattle(Player1* player);
private:
	Monster1* _monster;
};

