#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

//put(),write()
int main21()
{
	cout << "hello" << endl;
	cout.put('h').put('e') << endl;

	const char *p = "hello itcast";
	cout.write(p, strlen(p)) << endl;
	cout.write(p, strlen(p)-4);
	system("pause");
	return 0;
}

int main22()
{
	//���Ա����
	cout << "<start>";
	cout.width(30);     //���ÿ��Ϊ30
	cout.fill('*');     //��*���
	cout.setf(ios::showbase);   //���ñ��
	cout.setf(ios::internal);
	cout << hex << 123 << "<End>" << endl;   //hex��16�������

	cout << endl;

	//ʹ�ÿ��Ʒ�
	cout << "<Start>"
		<< setw(30)
		<< setfill('*')
		<< setiosflags(ios::showbase)
		<< setiosflags(ios::internal)
		<< hex
		<< 123
		<< "<End>"
		<< endl;

	system("pause");
	return 0;
}