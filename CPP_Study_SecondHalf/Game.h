#pragma once
#include "Player1.h"

class Player;
class Field;

class Game
{
public:
	Game();
	~Game();

	void Init();
	void Update();

	void CreatePlayer();

private:
	// Player1 _player;

	// [ 4 ~ 8 ]  --- >> [        ]
	Player1* _player;
	Field* _field;
};

