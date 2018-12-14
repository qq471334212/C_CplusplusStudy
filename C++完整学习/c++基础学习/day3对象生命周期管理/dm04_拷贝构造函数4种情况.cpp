#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;

class Test4
{
public:
	Test4() { a = 0, b = 0; cout << "无参构造函数" << endl; }
	Test4(int x) {
		a = x;
		b = 0;
		cout << "有参构造函数" << a << endl;
	}
	Test4(int x,int y) {
		a = x;
		b = y;
		cout << "有参构造函数2" << a << endl;
	}
	//赋值构造函数，用一个对象来完成另外一个对象初始化
	Test4(const Test4 &t) {
		this->a = t.a;
		this->b = t.b;
		cout << "复制构造函数" << endl;
	}
	void Print()
	{
		cout << "a: " << a << "b: " << b << endl;
	}
	~Test4() {
		cout << "析构函数" << a << endl;
	}
private:
	int a;
	int b;
};

//复制构造函数就是用一个对象去初始化另一个对象
int main()
{
	Test4 t1(1, 2);
	Test4 t0(1, 2);
	//拷贝构造函数4种形式
	//第一种
	Test4 t2 = t1;   //用t1初始化t2
	//第二种
	//Test4 t2(t1);
	t0 = t1;         //用t1给t0赋值,两者不一样
	system("pause");
	return 0;
}