#include <iostream>
using namespace std;

// ������ ���� : ���� ���� vs ���� ����

class Pet
{
public:
	Pet()
	{
		cout << "Pet()" << endl;
	}

	~Pet()
	{
		cout << "~Pet()" << endl;
	}

	Pet(const Pet& pet)
	{
		cout << "Pet(const Pet&)" << endl;
	}
};

class Player
{
public:
	Player()
	{
		cout << "Player()" << endl;
	}

	// ���� ������
	Player(const Player& player)
	{
		cout << "Player(const Player&)" << endl;
		_level = player._level;
	}

	Player& operator=(const Player& player)
	{
		cout << "operator=(const Player&)" << endl;
		_level = player._level;
		return *this;
	}

public:
	int _level = 0;
	 
};

class Knight : public Player
{
public:
	Knight()
	{
		
	}

	Knight(const Knight& knight) : Player(knight), _pet(knight._pet)
	{
		cout << "Knight(const Knight&)" << endl;
		
		_hp = knight._hp;
		_stamina = knight._stamina;
	}

	Knight& operator == (const Knight& knight)
	{
		cout << "operator=(const Knight&)" << endl;

		Player::operator=(knight);
		_pet = knight._pet;

		_hp = knight._hp;
		return *this;
	}

	~Knight()
	{

	}


public:
	int _hp = 100;
	int _stamina = 100;
	Pet _pet;
};


int main()
{
	Pet* pet = new Pet();


	Knight knight; // �⺻ ������
	knight._hp = 200;
	knight._level = 99;

	Knight knight2 = knight;  // ���� ������
	// Knight knight3(knight);

	Knight knight3; // �⺻ ������
	knight3 = knight; // ���� ���� ������

	// [���� ������] + [���� ���� ������]
	// �� �� �� ������ָ� �����Ϸ� '�Ͻ�������' ������ش�.

	// �߰� ���) �����Ϸ��� �˾Ƽ� �� ������ش�?
	// �����ϼ���~ ���� ���� �Ѿ���? << NO

	// [ ���� ���� Shallow Copy ]
	// �ɹ� �����͸� ��Ʈ�� ������ '�Ȱ���' ����(�޸� ���� ���� �״�� ����)
	// �����ʹ� �ּҰ� �ٱ��� -> �ּҰ��� �Ȱ��� ���� -> ������ ��ü�� ����Ű�� ���°� ��
	// Stack : Knight1 [hp 0x1000]   ->  Heap 0x1000 Pet [    ]
	// Stack : Knight2 [hp 0x1000] 
	// Stack : Knight3 [hp 0x1000]

	// [ ���� ���� Deep Copy ]
	// �ɹ� �����Ͱ� ����(�ּ�) ���̶��, �����͸� ���� ������ش�. ( ���� ��ü�� �����ϴ� ������ ���� ���� ����)
	// �����ʹ� �ּҰ� �ٱ��� -> ���ο� ��ü�� ���� -> ������ ��ü�� ����Ű�� ���°� ��.
	// Stack : Knight1 [hp 0x1000]   ->  Heap 0x1000 Pet [    ]
	// Stack : Knight2 [hp 0x1000]   ->  Heap 0x2000 Pet [    ]
	// Stack : Knight3 [hp 0x1000]   ->  Heap 0x3000 Pet [    ]

	// ����)
	// - �Ͻ��� ���� ������ Steps
	// 1) �θ� Ŭ������ ���� ������ ȣ��
	// 2) �ɹ� Ŭ������ ���� ������ ȣ��
	// 3) �ɹ��� �⺻ Ÿ���� ��� �޸� ����(���� ���� Shallow Copy)
	// - ����� ���� ������ Steps
	// 1) �θ� Ŭ������ �⺻ ������ ȣ��
	// 2) �ɹ� Ŭ������ �⺻ ������ ȣ��
	
	// - �Ͻ��� ���� ���� ������ Steps
	// 1) �θ� Ŭ������ ���� ���� ������ ȣ��
	// 2) �ɹ� Ŭ������ ���� ���� ������ ȣ��
	// 3) �ɹ��� �⺻ Ÿ���� ��� �޸� ����(���� ���� Shallow Copy)
	// - ����� ���� ���� ������ Steps
	// 1) �˾Ƽ� ���ִ°� ����

	// �� �̷��� ȥ���������?
	// ��ü�� '����'�Ѵٴ� ���� �� ��ü�� ������ ��ġ��Ű���� ��
	// ���� �⺻������ ���� ����(Shallow Copy)


	return 0;
}