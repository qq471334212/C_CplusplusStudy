#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;

class A
{
public:
	A() { cout << "�޲ι��캯��" << endl; }
	A(int x) { 
		a = x;
		cout << "�вι��캯��" << a << endl; }
	void Print()
	{
		cout << a << endl;
	}
	~A() { 
		cout << "��������" << a << endl; }
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