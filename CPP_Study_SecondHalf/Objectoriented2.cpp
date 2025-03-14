#include <iostream>
using namespace std;

// ������ ����: ���м�

// ��ü����(OOP Object Oriented Programming)
// - ��Ӽ�
// - ���м�
// - ������

// ���м�(Data Hiding) = ĸ��ȭ(Encapsulation)
// ���� �Ǵ� ���� ����ϰ� ����ڴ�!
// - 1) ���� �����ϰ� �ǵ帮�� �ȵǴ� ���
// - 2) �ٸ� ��η� �����ϱ� ���ϴ� ���

// �ڵ���
// - �ڵ�
// - ���
// - ����
// - ��
// - ���� ���⼱

// �Ϲ� ������ ���忡�� ����ϴ� ��?
// - �ڵ�/���/��
// ���� ��(������ �ǵ�� ū�ϳ�)
// - ����,���� ���⼱

// public(������?) protected(��ȣ�޴�?) private(������?)
// - public : �������׳� ����. ���� �����ϼ���~~
// - protected : ���� �ڼյ����׸� ���
// - private : ���� ����Ҳ�! << class Car ���ο�����!

// ��� ���� ������: ���� �������� �θ���� ������ ��� ��������?
// �θ������ �������� ������ �� ���� �ڼյ����׵� �Ȱ��� ������� ���� ����
// - public: ������ ���? �θ���� ���� ���� �״��~(public -> public, protected->protected)
// - protected : ��ȣ���� ���? �� �ڼյ����׸� �����ٲ���(public -> protected, protected->protected)
// - private : �������� ���? �������� �� ���� �ڼյ����״� �ƿ� �� �����ٲ���~(public -> private, protected -> private)

class Car
{
public:   // (�ɹ�) ���� ������
	void MoveHandle(){}
	void PushPedal(){}
	void OpenDoor(){}

	void TurnKey()
	{
		//...
		RunEngine();
	}
protected:
	void DisassembleCar(){} // ���� �����Ѵ�
	void RunEngine(){} // ������ ������Ų��
	void ConnectCircuit(){} // ���⼱ ����

public:
	// �ڵ�
	// ���
	// ����
	// ��
	// ���� ���⼱
};

class SuperCar : public Car // ��� ���� ������
{
public:
	void PushRemoteController()
	{
		RunEngine();
	}
};

// 'ĸ��ȭ'
// ������ �����Ϳ� �Լ��� �������� ������� ��
class Berserker
{
public:

	int GetHp() { return _hp; }
	
	// ��� : ü���� 50���Ϸ� �������� ����Ŀ ��� �ߵ�(������)
	void SetHp(int hp)
	{
		_hp = hp;
		if (_hp < 50)
			SetBerserkerMode();
	}
	
private:
	void SetBerserkerMode()
	{
		cout << "�ſ� ������!" << endl;
	}
private:
	int _hp = 100;
};

int main()
{
	SuperCar car;
	car.PushRemoteController();
	// WOW - �ʹ� �ű���
	
	Berserker b;
	b.SetHp(20);

	return 0;
}