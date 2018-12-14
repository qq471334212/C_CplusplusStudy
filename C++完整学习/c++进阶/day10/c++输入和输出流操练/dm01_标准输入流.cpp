#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;

//标准输入流api函数
int main11()
{
	char mybuf[1024] = {0};
	int myInt;
	long myLong;

	cin >> myInt;

	cin >> myLong;
	
	cin >> mybuf;       //注意点1.不能接收到空格，接收到空格停止接受

	cout << "myInt:  " << myInt << "  myLong:  " << myLong << "  mybuf:  " << mybuf << endl;

	system("pause");
	return 0;
}
//get,get(a),get(a,b,c)
int main12()
{
	/*
	char ch;
	while ((ch = cin.get()) != EOF)     //一次只能读取一个字符
	{
		cout << ch << endl;             //碰不到EOF,则程序一直从输入的缓冲区中进行阅读，阻塞在那里
	}
	*/


	char a;
	char b;
	cout << "cin.get(a)如果输入缓冲区没有数据，会造成程序阻塞" << endl;
	cin.get(a);           //一次读一个字符，链式编程
	cin.get(b);
	cout << a << b << "输入缓冲区有数据，则不会堵塞" << endl;

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

	cout << "请输入一个字符串含有多个空格aa  bbcc" << endl;
	cin >> buf1;

	cin.ignore(2);   //忽略缓存区中的两个字符

	int my = cin.peek();  //观察一下缓冲区中还有没有数据，有的话返回当前缓冲区第一个数值
	                      //里面没有的话，会阻塞
	cout << my << endl;

	//内存打包技术
	cin.getline(buf2, 256);


	cout << "buf1: " << buf1 << "   buf2: " << buf2 << endl;

	system("pause");
	return 0;
}

//putback（）
//案例：输入字符和整数分开处理
int main14()
{
	cout << "请输入字符或者整数：" << endl;
	char c = cin.get();

	if ((c >= '0') && (c <= '9'))
	{
		int n;
		cin.putback(c);
		cin >> n;
		cout << "输入整数 ：" << n << endl;
	}
	else
	{
		string str;
		cin.putback(c);   //如果前面get到的是字符，重新弹出来，放进缓冲区里
		getline(cin, str);
		cout << "输入单词: " << str << endl;
	}

	system("pause");
	return 0;
}