#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;

class A
{
public:
	A() { cout << "无参构造函数" << endl; }
	A(int x) { 
		a = x;
		cout << "有参构造函数" << a << endl; }
	void Print()
	{
		cout << a << endl;
	}
	~A() { 
		cout << "析构函数" << a << endl; }
private:
	int a;
};

void objplay1()
{
	A a1(1), a2(2);

}

int main01()
{
	objplay1();

	system("pause");
	return 0;
}