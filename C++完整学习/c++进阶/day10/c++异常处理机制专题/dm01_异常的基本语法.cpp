#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;

//基本语法
//发生异常之后，是跨函数的
//捕获到异常可以不处理，继续向上抛出
//catch异常时，按照类型进行捕获

//异常捕捉严格按类型匹配
int main01()
{
	try {
		throw 'a';
	}
	catch (int e)       //捕获不到
	{
		cout << "捕获异常" << endl;
	}
	catch (...)    //其他未知类型异常
	{
		cout << "其他未知类型异常" << endl;
	}
	system("pause");
	return 0;
}

void divide(int x, int y)
{
	if (y == 0)
	{
		throw x;  //抛int类型异常
	}

	cout << "x/y结果：" << x / y << endl;
}

void mydivide(int x, int y)
{
	divide(x, y);               //devide抛异常时，会直接跳过mydevide，在main中被捕获
}

void mydivide1(int x, int y)
{
	try {
		divide(x, y);
	}
	catch (...)    //其他未知类型异常
	{
		cout << "我接受了devide的异常，不处理继续向上抛出" << endl;
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
		cout << e << "被除数为0" << endl;
	}
	catch (...)    //其他未知类型异常
	{
		cout << "其他未知类型异常" << endl;
	}

	system("pause");
	return 0;
}