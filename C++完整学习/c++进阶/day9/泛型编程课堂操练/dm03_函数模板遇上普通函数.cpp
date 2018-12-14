#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;

//让类型参数化，方便程序员进行编码
//泛型编程
//看到template就是告诉C++编译器我要用模板泛型编程了，看到T，不要随便报错
template<typename T>
void mySwap(T &a, T &b)
{
	T c;
	c = a;
	a = b;
	b = c;
	cout << "函数模板调用" << endl;
}
void mySwap(int a, char c)
{
	cout << "a = " << a << "  " << "c = " << c << endl;
	cout << "普通函数调用" << endl;
}

int main04()
{
	int  a = 10;
	char c = 'z';
	mySwap(a, c);    //调用普通函数
	mySwap(c, a);    //调用普通函数，进行了隐式的类型转换


	mySwap(a, a);    //两种类型都要相同，才会调用函数模板，严格按照类型进行匹配，不会进行类型转换

	
	system("pause");
	return 0;
}