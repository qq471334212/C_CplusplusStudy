#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;

class Test
{
public:
	Test(int a, int b)
	{
		this->a = a;
		this->b = b;
		cout << "Test�๹�캯������" << endl;
	}
	~Test() { cout << "Test��������������" << endl; }
private:
	int a;
	int b;
};

//void myTest() throw(A,B,C,D)  //ֻ���׳�A,B,C,D���쳣�Լ������쳣
//void myTest() throw()         //�����׳��쳣

void myTest()                 //�����κ��쳣
{
	Test t1(1, 2), t2(3, 4);
	cout << "myTest....Ҫ�����쳣" << endl;
	throw 1;       //throw֮�����ϾͰ�t1��t2���������
}

int main12()
{
	try
	{
		myTest();
	}
	catch (int)
	{
		cout << "int �����쳣" << endl;
	}
	catch (...)
	{
		cout << "δ֪ �����쳣" << endl;
	}
	system("pause");
	return 0;
}