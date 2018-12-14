#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;

class Test
{
public:
	Test() { a = 1; cout << "无参构造函数" << endl; }
	Test(int x) {
		a = x;
		cout << "有参构造函数" << a << endl;
	}
	//赋值构造函数，用一个对象来完成另外一个对象初始化
	Test(const Test &t) {
		cout << "复制构造函数" << t.a << endl;
	}
	void Print()
	{
		cout << a << endl;
	}
	~Test() {
		cout << "析构函数" << a << endl;
	}
private:
	int a;
};

void objplay()
{
	//对象初始化和对象赋值是两个不同的概念
	//构造函数的调用方法是自动调用（按规则调用）
	//也可以显示的初始化类的属性和资源
	Test t1;       //调用无参构造函数
	Test t2(2);    //调用有参构造函数三种形式
	//Test t2=Test(2);  //直接调用构造函数会产生匿名对象
	//Test t2 = (4);
	Test t3 = t2;


}

int main02()
{
	objplay();

	system("pause");
	return 0;
}