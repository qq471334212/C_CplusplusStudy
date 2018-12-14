#include<iostream>
using namespace std;

//��Computer��� �� ���峧�� ���� �����

//�������Ϊ�����ṩ�ӿ�
class HardDisk
{
public:
	virtual void work() = 0;
};
class Memory
{
public:
	virtual void work() = 0;
};
class Cpu
{
public:
	virtual void work() = 0;
};
class Computer
{
public:
	Computer(HardDisk *h, Memory *m, Cpu *c)
	{
		m_h = h;
		m_m = m;
		m_c = c;
	}
	//HardDisk
	//Memory
	//Cpu
	void work()
	{
		m_h->work();
		m_m->work();
		m_c->work();
	}
private:
	HardDisk * m_h;
	Memory   *m_m;
	Cpu      *m_c;
};

//���峧��
class IntelCpu:public Cpu
{
public:
	virtual void work()
	{
		cout << "Intel����Cpu,��������" << endl;
	}
};

class WDHardDisk :public HardDisk
{
public:
	virtual void work()
	{
		cout << "�������ݳ���Ӳ��,��������" << endl;
	}
};

class KinstonMemory :public Memory
{
public:
	virtual void work()
	{
		cout << "��ʿ�ٳ����ڴ�,��������" << endl;
	}
};
int main3()
{
	HardDisk *harddisk = NULL;
	Memory *memory = NULL;
	Cpu *cpu = NULL;
	harddisk = new WDHardDisk;
	memory = new KinstonMemory;
	cpu = new IntelCpu;

	Computer *myComputer = new Computer(harddisk, memory, cpu);
	myComputer->work();


	delete myComputer;
	delete cpu;
	delete memory;
	delete harddisk;

	system("pause");
	return 0;
}
//����A���й�����ǿ�ķ���
class A
{
public:
	void doA()
	{
	}
	void doB()
	{
	}
};
//�̳�
class B :public A
{
public:
	void doB()
	{
	}
};
//����Aע�뵽��C��
class C
{
public:
	C(A *a)       
	{
	}
	void setA(A *a)
	{
		this->a = a;
	}
	void doC()
	{
	}
private:
	A * a;
};
//java ,aop������