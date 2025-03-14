#include <iostream>
using namespace std;
#include "Game.h"
 
// ø¿¥√¿« ¡÷¡¶ : TextRPG #4

int main()
{
	srand((unsigned int)time(nullptr));

	Game game;
	game.Init();

	while (true)
	{
		game.Update();
	}
	return 0;
}