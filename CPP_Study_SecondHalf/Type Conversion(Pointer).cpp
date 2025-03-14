#include <iostream>
using namespace std;

// ������ ���� : Ÿ�� ��ȯ(������)
class Knight
{
public:
	int _hp = 0;
};

class Item
{
public:
	Item()
	{
		cout << "Item()" << endl;
	}

	Item(int itemType) : _itemType(itemType)
	{
		cout << "Item(int itemType)" << endl;
	}

	Item(const Item& item)
	{
		cout << "Item(const Item&)" << endl;
	}

	virtual ~Item()
	{
		cout << "~Itme()" << endl;
	}

	void Test()
	{
		cout << "Test item" << endl;
	}

public:
	int _itemType = 0;
	int _itemDbld = 0;

	char dummy[4096] = {};  // �̷� ���� ������� ���� �������
};

enum ItemType
{
	IT_WEAPON = 1,
	IT_ARMOR = 2,
};

class Weapon : public Item
{
public:
	Weapon() : Item(IT_WEAPON)
	{
		
		cout << "Weapon()" << endl;
		_damage = rand() % 100; 
	}

	~Weapon()
	{
		cout << "~Weapon()" << endl;
	}

	virtual void Test()
	{
		cout << "Test Weapon" << endl;
	}
public:
	int _damage = 0;
};

class Armor : public Item
{
public:
	Armor() : Item(IT_ARMOR)
	{
		cout << "Armor()" << endl;
	}

	~Armor()
	{
		cout << "~Armor()" << endl;
	}

public:
	int _defence = 0;
};

void TestItem(Item* item)
{

}

void TestItemPtr(Item* item)
{
	item->Test();
}

int main_TypeConversion()
{
	// ����
	{
		// Stack [ type(4) dbid(4) dummy(4096) ]
		Item item;

		// Stack [ �ּ�(4~8) ] -> Heap �ּ� [ type(4) dbid(4) dumy(4096) ]
		Item* item2 = new Item();

		// �޸� ����(Memory Leak) -> ���� ���� �޸𸮰� �پ�� Crash
		delete item2;

	}

	// �迭
	{
		cout << "--------------------------" << endl;

		// ��¥ �������� 100�� �ִ� ��(���� �޸𸮿� �ö�� �ִ�)
		Item item3[100] = {};

		cout << "---------------------------" << endl;

		// �������� ��¥ 100�� �������?
		// �������� ����Ű�� �ٱ��ϰ� 100��. ���� �������� 1���� ���� ���� ����.
		Item* item4[100] = {};
		
	}

	// �������� ���� Ŭ���� ������ ������ ��ȯ �׽�Ʈ
	{
		// Stack[ �ּ� ] -> Heap [ _ho(4) ]
		Knight* knight = new Knight();

		// �Ͻ������δ� NO
		// ��������δ� OK

		// Stack [ �ּ� ]
		//Item* item = (Item*)knight;
		//item->_itemDbld = 1;

		delete knight;
	}

	// �θ� -> �ڽ� ��ȯ �׽�Ʈ
	{
		Item* item = new Item();

		// [ [ Item ]    ]
		// [     _damage ]
		//Weapon* weapon = (Weapon*)item;
		//weapon->_damage = 10;

		delete item;
	}

	// �ڽ� -> �θ� ��ȯ �׽�Ʈ
	{
		// [ [ Item ]    ]
		// [     _damage ]
		Weapon* weapon = new Weapon();

		// �Ͻ������ε� �ȴ�!
		Item* item = weapon;

		TestItemPtr(item);

		delete weapon;
	}

	// ��������� Ÿ�� ��ȯ�� ���� �׻� �׻� �����ؾ� �Ѵ�!
	// �Ͻ������� �� ���� �����ϴ�?
	// -> ��� �Ͻ������� Ÿ�� ��ȯ(ĳ����)�� �� �ϸ� �Ǵ� �� �ƴѰ�?

	Item* inventory[20] = {};

	srand((unsigned int)time(nullptr));

	for (int i = 0; i < 20; i++)
	{
		int randValue = rand() % 2;  // 0~1
		switch (randValue)
		{
		case 0:
			inventory[i] = new Weapon();
			break;
		case 1:
			inventory[i] = new Armor();
			break;
		}
	}

	for (int i = 0; i < 20; i++)
	{
		Item* item = inventory[i];
		if (item == nullptr)
			continue;

		if (item->_itemType == IT_WEAPON)
		{
			Weapon* weapon = (Weapon*)item;
			cout << "Weapon Damage : " << weapon->_damage << endl;
		}
	}

	// ********************** �ſ� �ſ� �ſ� �߿� ************************
	for (int i = 0; i < 20; i++)
	{
		Item* item = inventory[i];
		if (item == nullptr)
			continue;

		delete item;
	}

	// [���]
	// - ������ vs �Ϲ� Ÿ�� : ���̸� ��������
	// - ������ ������ Ÿ�� ��ȯ(ĳ����)�� �� ���� �ſ� �ſ� �����ؾ� �Ѵ�!!
	// - �θ�~�ڽ� ���迡�� �θ� Ŭ������ �Ҹ��ڿ��� ����� ���� virtual�� ������!!!

	return 0;
}