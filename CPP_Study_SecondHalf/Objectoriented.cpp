#include <iostream>
using namespace std;

// 오늘의 주제 : 객체 지향의 시작

// 데이터 + 가공(로직, 동작)
// 객체지향 = 객체
// 객체란? 플레이어, 몬스터, GameRoom

// Knight를 설계해보자
// - 속성(데이터): hp, attack, position(y, x)
// - 기능(동작): Move, Attack, Die

// 오늘의 주제 : 생성자와 소멸자
// [생성자(Constructor)와 소멸자(Destructor)]
// 이 중에서 굉장히 특별한 함수 2종이 있는데. 바로 [시작]과 [끝]을 알리는 함수들
// - 시작(탄생) -> 생성자(여러 개 존재 가능)
// - 끝(소멸) -> 소멸자(오직 1개만)

// [암시적(implicit) 생성자]
// 생성자를 명시적으로 만들지 않으면,
// 아무 인자도 받지 않는 [기본 생성자]가 컴파일러에 의해 자동으로 만들어짐
// -> 그러나 우리가 명시적(Explicit)으로 아무 생성자 하나 만들면,
// 자동으로 만들어지던 [기본 생성자]는 더 이상 만들어지지 않음!

// 오늘의 주제 : 상속성

// 객체지향(OOP Object Oriented Programming)
// - 상속성
// - 은닉성
// - 다형성

struct StatInfo
{
    int hp;
    int attack;
    int defence;
};

// 메모리

// [ [ Player ] ]
// [   knight   ]

// 상속(lnheritance) ? 부모 -> 자식에게 유산을 물려주는 것

// 생성자(N) / 소멸자(1)

// 생성자는 탄생을 기념해서 호출되는 함수?
// - Knight를 생성하면 -> Player의 생성자? Knight의 생성자?
// -> 솔로몬의 선택! 그냥 둘다 호출하기!

// GameObject
// - Creature
// -- Player, Monster, Npc, Pet
// - Projectile
// -- Arrow, Fireball
// - Env

// Item
// - Weapon
// -- Sword, Bow
// - Armor
// -- Helmet, Boots, Armor
// - Consumable
// -- Potion, Scroll

class Player
{
public:
    Player()
    {
        _hp = 0;
        _attack = 0;
        _defence = 0;
        cout << "Player() 기본 생성자 호출" << endl;
    }

    ~Player()
    {
        cout << "~Player() 소멸자 호출" << endl;
    }


    void Move(){ cout << "Player Move 호출" << endl; }
    void Attack() { cout << "Player Attack 호출" << endl; }
    void Die(){ cout << "Player Die 호출" << endl; }
public:
    int _hp;
    int _attack; 
    int _defence; 
};

// class는 일종의 설계도
class Knight : public Player
{
public:
    // 재정의 : 부모님의 유산을 거부하고 새로운 이름으로 만든?
    void Move() { cout << "Knight Move 호출" << endl; }
    // [1] 기본 생성자(인자가 없음)
    Knight()
    {
        /*
        선(먼저)처리 영역
        - 여기서 Player() 생성자를 호출
        */
        _stamina = 100;
        cout << "Knight() 기본 생성자 호출" << endl;

        _hp = 100;
        _attack = 10;
        _posX = 0;
        _posY = 0;
    }

    // [2] 복사 생성자(자기 자신의 클래스 참조 타입을 인자로 받음)
    // (일반적으로 '똑같은' 데이터를 지닌 객체가 생성되길 기대한다.
    Knight(const Knight& knight)
    {
        _hp = knight._hp;
        _attack = knight._attack;
        _posX = knight._posX;
        _posY = knight._posY;
    }

    //// [3] 기타 생성자
    
    // 이 중에서 인자를 1개만 받는 [기타 생성자]를
    // [타입 변환 생성자]라고 부르기도 함

    // 명시적인 용도로만 사용할 것!
    explicit Knight(int hp)
    {
        cout << "Knight(int) 기본 생성자 호출" << endl;
        _hp = hp;
        _attack = 10;
        _posX = 0;
        _posY = 0;
    }

    Knight(int hp, int attack, int posX, int posY)
    {
        _hp = hp;
        _attack = attack;
        _posX = posX;
        _posY = posY;
    }


    // 소멸자
    ~Knight()
    {
        cout << "~Knight() 기본 소멸자 호출" << endl;
    }
    /*
    후(나중에)처리 영역
    - 여기서 ~Playewr() 소멸자를 호출
    */
    // 맴버 함수 선언
    void Move(int y, int x);
    void Attack();
    void Die()
    {
        _hp = 0;
        this->_hp = 1;
        cout << "Die" << endl;
    }


public:
    // 맴버 변수
    int _hp;
    int _attack;
    int _posY;
    int _posX;

public:
    int _stamina;
};

class Mage : public Player
{
public:
    void Move(){}
    void Attack(){}
    void Die(){}
public:
    StatInfo _statinfo;
public:
    int _mp;

};

void Move(Knight* knight, int y, int x)
{
    knight->_posY = y;
    knight->_posX = x;
}

void Knight::Move(int y, int x)
{
    _posY = y;
    _posX = x;
    cout << "Move" << endl;
}

void Knight::Attack()
{
    cout << "Attack : " << _attack << endl;
}

// Instantiate 객체를 만든다!
int main()
{
    Knight k1(100);
    // k1._hp = 100;   
    k1._attack = 10;
    k1._posY = 0;
    k1._posX = 0;

    Knight k2(k1);  // 복사 생성자
    Knight k3 = k1; // 복사 생성자

    Knight k4; // 생성자
    k4 = k1;  // 복사
    // Move(&k1, 2, 2);

    k1.Move(2, 2);
    k1.Attack();
    k1.Die();

    // 암시적 형변환 -> 컴파일러가 알아서 바꿔치기
    int num = 1;

    float f = (float)num;  // 명시적 < 우리가 코드로 num을 float 바구니에 넣으라고 주문하고 있음
    double d = num;        // 암시적 << 별말 안했는데 컴파일러가 알아서 처리하고 있음

    Knight k;
    k.Move();
    // k.Player::Move();
    return 0;
}

