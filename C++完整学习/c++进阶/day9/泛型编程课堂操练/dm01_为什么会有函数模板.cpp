#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;

//������ҵ���߼�һ�������Ǻ����������Ͳ�һ��
void myswap2(int &a, int &b)
{
	int c = 0;
	c = a;
	a = b;
	b = c;
}

void myswap1(char &a, char &b)
{
	char c = 0;
	c = a;
	a = b;
	b = c;
}

//�����Ͳ��������������Ա���б���
//���ͱ��
//����template���Ǹ���C++��������Ҫ��ģ�巺�ͱ���ˣ�����T����Ҫ��㱨��
template<typename T>
void myswap(T &a,T &b)
{
	T c;
	c = a;
	a = b;
	b = c;
	cout << "����ģ�����" << endl;
}

//�����������
//template<typename T, typename T1>
//void myswap(T &a, T1 &b)

//����ģ��ĵ���
//1.��ʾ���� ����
//2.�Զ����� �Ƶ�
int main02()
{
	{
		int x = 10;
		int y = 20;
		myswap<int>(x, y);  //��һ�ַ�ʽ ����ģ����ʾ���� ����
		//myswap(x, y);       //�ڶ��ַ�ʽ �Զ������Ƶ�
		cout << "x= " << x << "  " << "y= " << y << endl;
	}

	{
		char a = 'x', b = 'y';
		myswap<char>(a, b);
		//myswap(a, b);
		cout << "a= " << a << "  " << "b= " << b << endl;
	}
	return 0;
}

int main01()
{
	int x = 10, y = 20;
	myswap2(x, y);
	cout << "x= " << x << "  " << "y= " << y << endl;
	{
	    char a = 'x', b = 'y';
		myswap1(a, b);
		cout << "a= " << a << "  " << "b= " << b << endl;
	}
	system("pause");
	return 0;
}