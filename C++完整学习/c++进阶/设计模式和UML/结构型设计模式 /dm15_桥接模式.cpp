#include<iostream>
#include<string>
using namespace std;

//��������ĳ���
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
//����ĳ���
class Car
{
public:
	Car(Engine *engine)
	{
		m_engine = engine;
	}
	virtual void InstallEngine() = 0;
protected:
	Engine * m_engine;        //������ʹ�ø����Ա����
};

class BMW5XCar :public Car
{
public:
	BMW5XCar(Engine *engine) :Car(engine)   //���캯����ʼ���б��̳и�������б�
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
	BMW7XCar(Engine *engine) :Car(engine)   //���캯����ʼ���б��̳и�������б�
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
	BMW7XCar    *bmw7x = NULL;          //����Ҳ�����ǲ�ͬ����
	                                    

	engine = new Engine4400cc;          //�����������ǲ�ͬ����
	bmw7x = new BMW7XCar(engine);       //���԰�װ��ͬ�ķ�����,ͨ��������ϵ��һ�𣬷������������Ĺ��캯���Ĳ���
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