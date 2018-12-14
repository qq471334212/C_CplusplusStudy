#include<iostream>
#include<list>
using namespace std;

//���ܲ���
class Strategy
{
public:
	virtual void crypt() = 0;
};

//�ԳƼ��ܣ��ٶȿ죬���ܴ����ݿ��ļ����ص㣺���ܽ�����Կ����һ���ģ������ڰ�ȫ����
class Aes:public Strategy
{
public:
	virtual void crypt()
	{
		cout << "use Aes crypt algorithm......." << endl;
	}
};

//�ǶԳƼ��ܣ��ٶ���������ǿ�ȸߣ���ȫ�Ժã��ص㣺������Կ�ͽ�����Կ��һ�� ��Կ�ԣ���Կ �� ˽Կ��
class Des :public Strategy
{
public:
	virtual void crypt()
	{
		cout << "use Des crypt algorithm......." << endl;
	}
};

class Context
{
public:
	void SetStrategy(Strategy * strategy)
	{
		m_strategy = strategy;
	}

	void myOperator()
	{
		m_strategy->crypt();
	}
private:
	Strategy * m_strategy;
};

int main22()
{
	//1.�ͻ�д��ҵ���߼�
	//Des *des = new Des;
	//des->crypt();
	//delete des;

	//2.�ͻ�����Խ����
	Strategy *strategy = NULL;

	strategy = new Des;
	Context *context = new Context;
	context->SetStrategy(strategy);
	context->myOperator();

	delete strategy;
	delete context;
	system("pause");
	return 0;
}