#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;

template<typename T>
class A
{
public:
	A(T a = 0)
	{
		this->a = a;
	}
	void printA()
	{
		cout << "a : " << a << endl;
	}
protected:
	T a;
};

//��ģ��������ʱ����Ҫ���廯�����࣬C++��������Ҫ֪�������������;�����ʲô����
//==��Ҫ֪��������ռ���ڴ��С�Ƕ��٣�ֻ���������͹̶���������֪����η����ڴ�
class B :public A<int>   //ע���1
{
public:
	B(int a = 10, int b = 20) :A<int>(a) { this->b = b; }   //ע���2.���ø����вι��캯��
	void printB()
	{
		cout << "a : " << a << "  " << "b : " << b << endl;
	}
private:
	int b;
};

//������������������
template<typename T>
class C :public A<T>
{
public:
	C(T c, T a) :A<T>(a) {
		this->c = c;
	}
	void printC()
	{
		cout << "c : " << c << endl;
	}
private:
	T c;
};
int main03()
{
	C<int> c1(1, 2);
	c1.printC();
	system("pause");
	return 0;
}

int main02()
{
	B b1(1, 2);
	b1.printB();
	system("pause");
	return 0;
}

//C++������Ҫ�������࣬���Ա��� ҪA<int> &a
void useA(A<int> &a)  //��ģ������������
{
	a.printA();
}

int main01()
{
	A<int> a1(1);    //��ģ����Ҫ�������;��廯
	a1.printA();
	useA(a1);
	system("pause");
	return 0;
}