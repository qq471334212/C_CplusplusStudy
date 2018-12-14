#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;

void printBuf(const char *p)
{
	//p[0] = 'a';   //会报错，const属性变量不允许被修改

	char *p1 = NULL;
	//使用者要清楚知道，变量转换前后的类型
	//const char*类型==》char*类型
	p1 = const_cast<char *>(p);     //要确保p所指向的内存空间，确实能修改
	p1[0] = 'a';    //不报错
	cout << p << endl;
}
int main()
{
	const char *p = "lakshdlka";  //不能使用const_cast进行修改
	//printBuf(p);                //报错
	char buf[] = "shdabxciyasi";
	printBuf(buf);
	system("pause");
	return 0;
}


class Tree
{
public:
};

class Animal
{
public:
	virtual void cry() = 0;

};

class Dog :public Animal
{
public:
	virtual void cry()
	{
		cout << "狗wang wang!" << endl;
	}

	void doHome()
	{
		cout << "看家！" << endl;
	}

};

class Cat :public Animal
{
public:
	virtual void cry()
	{
		cout << "猫 miao miao!" << endl;
	}

	void doWork()
	{
		cout << "抓鼠！" << endl;
	}

};

void playObj(Animal *base)
{
	base->cry();    //1.有继承 2.有虚函数重写 3.有父类指针指向子类对象 ==》发生多态
	//能识别子类对象
	//dynamic_cast    运行时类型识别
	Dog *pDog = dynamic_cast<Dog*>(base);
	if (pDog != NULL)      //传进来不是Dog，则不执行
	{
		pDog->doHome();
	}

	Cat *pCat = dynamic_cast<Cat*>(base);   //父类对象==》子类对象 ，，父类向下转型
	if (pCat != NULL)
	{
		pCat->doWork();
	}
}
int main02()
{
	Dog d1;
	Cat c1;

	Animal *pBase = NULL;
	pBase = &d1;
	pBase = static_cast<Animal*>(&d1);   //C++编译器在运行时，进行类型检查

	//强制类型转换
	pBase = reinterpret_cast<Animal*>(&d1);

	{
		Tree t1;
		//pBase = static_cast<Animal*>(&t1);        //报错
		pBase = reinterpret_cast<Animal*>(&t1);

	}

	playObj(&d1);
	playObj(&c1);
	system("pause");
	return 0;
}

int main01()
{
	double dpi = 3.1415926;
	int num1 = (int)dpi;  //C类型转换
	int num2 = static_cast<int>(dpi); //C++静态类型转换

	//int num3 = dpi;    //隐式类型转换，会有warning，均可使用static_cast

	char t[10] = "yh";
	int *t1 = NULL;
	//t1 = t;
	//t1 = static_cast<int*>(t);   //不能转指针类型，使用static_cast，编译器编译时，会做类型检查，有错误会报错
	t1 = reinterpret_cast<int*>(t);
	cout << "t: " << t << endl;
	cout << "t1: " << t1 << endl;  //首地址
	system("pause");
	return 0;
}