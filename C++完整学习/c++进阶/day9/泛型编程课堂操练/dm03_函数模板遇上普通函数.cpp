#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;

//�����Ͳ��������������Ա���б���
//���ͱ��
//����template���Ǹ���C++��������Ҫ��ģ�巺�ͱ���ˣ�����T����Ҫ��㱨��
template<typename T>
void mySwap(T &a, T &b)
{
	T c;
	c = a;
	a = b;
	b = c;
	cout << "����ģ�����" << endl;
}
void mySwap(int a, char c)
{
	cout << "a = " << a << "  " << "c = " << c << endl;
	cout << "��ͨ��������" << endl;
}

int main04()
{
	int  a = 10;
	char c = 'z';
	mySwap(a, c);    //������ͨ����
	mySwap(c, a);    //������ͨ��������������ʽ������ת��


	mySwap(a, a);    //�������Ͷ�Ҫ��ͬ���Ż���ú���ģ�壬�ϸ������ͽ���ƥ�䣬�����������ת��

	
	system("pause");
	return 0;
}