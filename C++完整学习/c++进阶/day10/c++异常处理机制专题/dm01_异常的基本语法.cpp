#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;

//�����﷨
//�����쳣֮���ǿ纯����
//�����쳣���Բ��������������׳�
//catch�쳣ʱ���������ͽ��в���

//�쳣��׽�ϸ�����ƥ��
int main01()
{
	try {
		throw 'a';
	}
	catch (int e)       //���񲻵�
	{
		cout << "�����쳣" << endl;
	}
	catch (...)    //����δ֪�����쳣
	{
		cout << "����δ֪�����쳣" << endl;
	}
	system("pause");
	return 0;
}

void divide(int x, int y)
{
	if (y == 0)
	{
		throw x;  //��int�����쳣
	}

	cout << "x/y�����" << x / y << endl;
}

void mydivide(int x, int y)
{
	divide(x, y);               //devide���쳣ʱ����ֱ������mydevide����main�б�����
}

void mydivide1(int x, int y)
{
	try {
		divide(x, y);
	}
	catch (...)    //����δ֪�����쳣
	{
		cout << "�ҽ�����devide���쳣����������������׳�" << endl;
		throw;
	}

}


int main02()
{
	try {
		/*divide(10, 2);
		divide(100, 0);*/

		//mydivide(100, 0);
		mydivide1(100, 0);
	}
	catch (int e)
	{
		cout << e << "������Ϊ0" << endl;
	}
	catch (...)    //����δ֪�����쳣
	{
		cout << "����δ֪�����쳣" << endl;
	}

	system("pause");
	return 0;
}