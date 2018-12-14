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
	//类成员函数
	cout << "<start>";
	cout.width(30);     //设置宽度为30
	cout.fill('*');     //用*填充
	cout.setf(ios::showbase);   //设置标记
	cout.setf(ios::internal);
	cout << hex << 123 << "<End>" << endl;   //hex以16进制输出

	cout << endl;

	//使用控制符
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