#include "Monster1.h"
#include <iostream>
using namespace std;

void Monster1::PrintInfo()
{
	cout << "-------------------" << endl;
	cout << "[몬스터 정보]" << "HP: " << _hp << "ATT: " << _attack << "DEF: " << _defence << endl;
	cout << "-------------------" << endl;
}
