#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;

/*
函数模板不允许自动类型转换
普通函数能够进行自动类型转换
*/

/*
	1.函数模板可以像普通函数一样被重载
	2.C++编译器优先考虑普通函数
	3.如果函数模板可以产生一个更好的匹配，那么选择模板
	4.可以通过空模板参数列表的语法限定编译器通过模板匹配
*/
int Max(int a, int b)
{
	cout << "int Max(int a, int b)" << endl;
	return a > b ? a : b;
}

template <typename T>
T Max(T a, T b)
{
	cout << "T Max(T a, T b)" << endl;
	return a > b ? a : b;
}

/*
函数模板机制：
			编译器并不是把函数模板处理成可以处理任何类型的函数
			而是代替我们程序员完成了工作，从函数模板通过具体类型产生不同的函数
			编译器编译器对函数模板进行二次编译
			第一次在声明的地方对模板代码本身进行编译
			第二次在调用的地方对参数替换后的代码进行编译
*/
template <typename T>
T Max(T a, T b, T c)
{
	cout << "T Max(T a, T b, T c)" << endl;
	return Max(Max(a, b), c);
}

int main()
{
	int a = 1;
	int b = 2;
	cout << Max(a, b) << endl;            //当模板函数与普通函数都符合调用时，优先选择普通函数
	cout << Max<>(a, b) << endl;          //当显示使用模板函数时，就使用<>类型列表
	cout << Max(3.0, 4.0) << endl;        //如果函数模板产生更好的匹配 使用函数模板
	cout << Max(5.0, 6.0, 7.0) << endl;   //函数模板重载
	cout << Max('a', 100) << endl;        //调用普通函数，可以隐式转换类型


	system("pause");
	return 0;
}