#include <iostream>
using namespace std;

// 오늘의 주제 : 캐스팅(타입 변환)

class Player
{
public:
	virtual ~Player(){}
};

class Knight : public Player
{

};

class Archer : public Player
{

};

// 1) static_cast
// 2) dynamic_cast
// 3) const_cast
// 4) reinterpret_cast

void PrintName(char* str)
{
	cout << str << endl;
}

class Dog
{

};

int main()
{
	// static_cast : 타입 원칙에 비춰볼 때 상식적인 캐스팅만 허용해준다
	// 1) int <-> float
	// 2) Player* <-> Knight* (다운캐스팅)

	int hp = 100;
	int maxHp = 200;
	float ratio = static_cast<float>(hp) / maxHp;

	// 부모->자식 자식->부모
	Player* p = new Player();
	Knight* k1 = (Knight*)p;

	Knight* k = new Knight();
	Player* p2 = static_cast<Player*>(k); 

	// 부모->자식 자식->부모
	Player* p = new Knight();
	Knight* k1 = static_cast<Knight*>(p);

	// dynamic_cast : 상속 관계에서의 안정 형변환
	// RTTI(RunTime Type Information)
	// 다형성을 활용하는 방식
	// - virtual 함수를 하나라도 만들면, 객체의 메모리에 가상 함수 테이블 (vftable) 주소가 기입된다
	// - 만약 잘못된 타입으로 캐스팅을 했으면, nullptr 반환 ***********
	// 이를 이용해서 맞는 타입으로 캐스팅을 했는지 확인을 유용하다
	Knight* k2 = dynamic_cast<Knight*>(p);

	// const_cast : const를 붙이거나 떼거나~
	PrintName(const_cast<char*>("Rookiss"));

	// reinterpret_cast
	// 가장 위험하고 강력한 형태의 캐스팅
	// 're-interpret' : 다시 간주하다/ 생각하다
	// - 포인터랑 전혀 관계없는 다른 타입 변환 등
	__int64 address = reinterpret_cast<__int64>(k2);
	
	Dog* dog1 = reinterpret_cast<Dog*>(k2);

	void* p = malloc(1000);
	Dog* dog2 = reinterpret_cast<Dog*>(p);
	return 0;
}