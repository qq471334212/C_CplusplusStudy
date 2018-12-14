#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;

//对于普通友元函数的解决方式。
//太麻烦了，因此不要滥用友元函数
template<typename T>
class Complex;          //类的前置声明
template<typename T>
Complex<T> Mysub(Complex<T> &c1, Complex<T> &c2);  //友元函数前置声明

template<typename T>
class Complex
{
	//friend Complex Mysub(Complex &c1, Complex &c2);
	friend Complex Mysub <T> (Complex &c1, Complex &c2);

	//friend ostream& operator<<(ostream &out, Complex &c);
	//在函数名后加个类型
	//基本只在左移右移使用，其他情况不要随便使用
	friend ostream& operator<< <T> (ostream &out, Complex &c);

public:
	Complex(T a, T b);
	void printCom();
	//重载复数+号
	Complex operator+(Complex &c);
	Complex operator-(Complex &c);

private:
	T a;
	T b;
};

//普通函数函数本体
template<typename T>
Complex<T>::Complex(T a, T b)
{
	this->a = a;
	this->b = b;
}

template<typename T>
void Complex<T>::printCom()
{
	cout << a << " + " << b << "i" << endl;
}

template<typename T>
Complex<T> Complex<T>::operator+(Complex<T> &c)     //写在类外面，返回类型和参数也都要具体化
{
	Complex<T> tmp(a + c.a, b + c.b);
	return tmp;
}

template<typename T>
Complex<T> Complex<T>::operator-(Complex<T> &c)     //写在类外面，返回类型和参数也都要具体化
{
	Complex<T> tmp(a - c.a, b - c.b);
	return tmp;
}
//友元函数本体
//报错
//LNK2019	无法解析的外部符号 "class std::basic_ostream<char,struct std::char_traits<char> > &
//__cdecl operator<<(class std::basic_ostream<char,struct std::char_traits<char> > &,
//class Complex<int> &)" 
//该符号在函数 _main 中被引用	

//本质是模板机制 ，摸板是两次编译生成的
//第一次生成的函数头，和第二次生成的函数头不一样

template<typename T>
ostream& operator<<(ostream &out, Complex<T> &c)
{
	out << c.a << " + " << c.b << "i" << endl;
	return out;
}
////////////////
//滥用友元函数
template<typename T>
Complex<T> Mysub(Complex<T> &c1, Complex<T> &c2)
{
	Complex<T> tmp(c1.a - c2.a, c1.b - c2.b);
	return tmp;
}

int main()
{
	Complex<int>  c1(1, 2);
	Complex<int>  c2(3, 4);
	Complex<int>  c3 = c1 + c2;
	{
		Complex<int> c4 = Mysub(c1, c2);
		cout << c4;
	}
	cout << c3;
	system("pause");
	return 0;
}