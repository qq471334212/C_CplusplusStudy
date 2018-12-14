#include<iostream>
using namespace std;

//让Computer框架 和 具体厂商 进行 解耦合

//各个零件为厂商提供接口
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

//定义厂商
class IntelCpu:public Cpu
{
public:
	virtual void work()
	{
		cout << "Intel厂商Cpu,工作良好" << endl;
	}
};

class WDHardDisk :public HardDisk
{
public:
	virtual void work()
	{
		cout << "西部数据厂商硬盘,工作良好" << endl;
	}
};

class KinstonMemory :public Memory
{
public:
	virtual void work()
	{
		cout << "金士顿厂商内存,工作良好" << endl;
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
//对类A进行功能增强的方法
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
//继承
class B :public A
{
public:
	void doB()
	{
	}
};
//把类A注入到类C中
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
//java ,aop切面编程