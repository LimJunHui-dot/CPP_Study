#include <iostream>
#include <stdlib.h>
using namespace std;
#include "Player2.h"

// ������ ���� : ���漱��

int main()
{
	// Player�� �� ����Ʈ?
	// int 2�� = 2 * 4 = 8����Ʈ + sizeof(Player2*) = 12����Ʈ

	// Player2[ hp ][ attack ][  �ּ�  ]
	// sizeof(Monster2*) = 4 or 8

	Player2 p1;  // ��������(Stack)

	Player2* p2 = new Player2();  // �����Ҵ�(Heap)

	p1._target2 = p2;
	return 0;
}