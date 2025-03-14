#include <iostream>
using namespace std;

// 오늘의 주제 : 객체지향 마무리

// 1) struct vs class

// C++에서는 struct나 class나 종이 한 장 차이이다.
// struct는 기본 접근 지정자가 public이고, class는 private이다.
// 왜 이렇게 했을까? C++은 C언어에서 파생되어 발전했기 때문에, 호환성을 지키기 위함.
// -> struct는 그냥 구조체(데이터 묶음)을 표현하는 정도
// -> class는 객체 지향 프로그래밍의 특징을 나타내는 용도

// 2) static 변수, static 함수(static = 정적 = 고정된)
class Marine
{
public:
	// 특정 마린 객체에 종속적
	int _hp;

	void TakeDamage(int damage)
	{
		_hp -= damage;
	}

	static void Test()
	{

	}

	// 특정 마린 객체와 무관
	// 마린이라는 '클래스' 자체와 연관
	static int s_attack;  // 설계도 상으로 존재
};

// static 변수는 어떤 메모리?
// 초기화 하면 .data
// 초기화 안하면 .bss
int Marine::s_attack = 0;

class Player
{
public:
	int _id;
};

// 정적 전역 객체
static int s_global = 1;

int GenerateId()
{
	// 생명주기 : 프로그램 시작/종료 (메모리에 항상 올라가 있음.)
	// 가시범위 : 함수 내부
	// 정적 지역 객체
	static int s_id = 1;

	return s_id++; 
}

int main()
{
	Marine m1;
	m1._hp = 35;
	m1.TakeDamage(10);

	Marine::s_attack = 6;
	// m1.s_attack = 6;

	Marine m2;
	m2._hp = 14;
	m2.TakeDamage(5);
	// m2.s_attack = 6;

	// 스택 아님. .data영역
	static int id = 10;
	int a = id;
	return 0;
}