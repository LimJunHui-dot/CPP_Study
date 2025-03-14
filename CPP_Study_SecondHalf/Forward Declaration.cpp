#include <iostream>
#include <stdlib.h>
using namespace std;
#include "Player2.h"

// 오늘의 주제 : 전방선언

int main()
{
	// Player는 몇 바이트?
	// int 2개 = 2 * 4 = 8바이트 + sizeof(Player2*) = 12바이트

	// Player2[ hp ][ attack ][  주소  ]
	// sizeof(Monster2*) = 4 or 8

	Player2 p1;  // 지역변수(Stack)

	Player2* p2 = new Player2();  // 동적할당(Heap)

	p1._target2 = p2;
	return 0;
}