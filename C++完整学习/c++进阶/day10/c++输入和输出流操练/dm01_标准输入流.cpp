#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;

//��׼������api����
int main11()
{
	char mybuf[1024] = {0};
	int myInt;
	long myLong;

	cin >> myInt;

	cin >> myLong;
	
	cin >> mybuf;       //ע���1.���ܽ��յ��ո񣬽��յ��ո�ֹͣ����

	cout << "myInt:  " << myInt << "  myLong:  " << myLong << "  mybuf:  " << mybuf << endl;

	system("pause");
	return 0;
}
//get,get(a),get(a,b,c)
int main12()
{
	/*
	char ch;
	while ((ch = cin.get()) != EOF)     //һ��ֻ�ܶ�ȡһ���ַ�
	{
		cout << ch << endl;             //������EOF,�����һֱ������Ļ������н����Ķ�������������
	}
	*/


	char a;
	char b;
	cout << "cin.get(a)������뻺����û�����ݣ�����ɳ�������" << endl;
	cin.get(a);           //һ�ζ�һ���ַ�����ʽ���
	cin.get(b);
	cout << a << b << "���뻺���������ݣ��򲻻����" << endl;

	cin.get(a).get(b);
	cout << a << b << endl;
	system("pause");
	return 0;
}

//getline()
int main13()
{
	char buf1[256] = { 0 };
	char buf2[256] = { 0 };

	cout << "������һ���ַ������ж���ո�aa  bbcc" << endl;
	cin >> buf1;

	cin.ignore(2);   //���Ի������е������ַ�

	int my = cin.peek();  //�۲�һ�»������л���û�����ݣ��еĻ����ص�ǰ��������һ����ֵ
	                      //����û�еĻ���������
	cout << my << endl;

	//�ڴ�������
	cin.getline(buf2, 256);


	cout << "buf1: " << buf1 << "   buf2: " << buf2 << endl;

	system("pause");
	return 0;
}

//putback����
//�����������ַ��������ֿ�����
int main14()
{
	cout << "�������ַ�����������" << endl;
	char c = cin.get();

	if ((c >= '0') && (c <= '9'))
	{
		int n;
		cin.putback(c);
		cin >> n;
		cout << "�������� ��" << n << endl;
	}
	else
	{
		string str;
		cin.putback(c);   //���ǰ��get�������ַ������µ��������Ž���������
		getline(cin, str);
		cout << "���뵥��: " << str << endl;
	}

	system("pause");
	return 0;
}