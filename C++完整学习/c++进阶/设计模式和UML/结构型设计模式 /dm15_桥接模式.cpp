#include<iostream>
#include<string>
using namespace std;

//发动机类的抽象
class Engine
{
public:
	virtual void InstallEngine() = 0;
};

class Engine4400cc:public Engine
{
public:
	virtual void InstallEngine()
	{
	cout << "I am 4400cc Engine" << endl;
	}
};
//车类的抽象
class Car
{
public:
	Car(Engine *engine)
	{
		m_engine = engine;
	}
	virtual void InstallEngine() = 0;
protected:
	Engine * m_engine;        //让子类使用父类成员变量
};

class BMW5XCar :public Car
{
public:
	BMW5XCar(Engine *engine) :Car(engine)   //构造函数初始化列表，继承父类参数列表
	{
	
	}
	virtual void InstallEngine()
	{
		m_engine->InstallEngine();
		cout << "BMW5XCar Install Finish...." << endl;
	}
private:
};

class BMW7XCar :public Car
{
public:
	BMW7XCar(Engine *engine) :Car(engine)   //构造函数初始化列表，继承父类参数列表
	{

	}
	virtual void InstallEngine()
	{
		m_engine->InstallEngine();
		cout << "BMW7XCar Install Finish...." << endl;
	}
private:
};

void main151()
{
	Engine		*engine = NULL;
	BMW7XCar    *bmw7x = NULL;          //汽车也可以是不同类型
	                                    

	engine = new Engine4400cc;          //发动机可以是不同类型
	bmw7x = new BMW7XCar(engine);       //可以安装不同的发动机,通过关联联系在一起，发动机做汽车的构造函数的参数
	bmw7x->InstallEngine();

	delete bmw7x;
	delete engine;
}

int main15()
{
	main151();
	system("pause");
	return 0;
}