#include<stdio.h>

//各个子任务，类似C++的虚函数表
int myadd(int a, int b)   //任务的实现者
{
	printf("func add......\n");
	return a + b;
}

int myadd2(int a, int b)   //任务2的实现者
{
	printf("func add2......\n");
	return a + b;
}
int myadd3(int a, int b)   //任务3的实现者
{
	printf("func add3......\n");
	return a + b;
}
int myadd4(int a, int b)   //任务4的实现者
{
	printf("func add4......\n");
	return a + b;
}

typedef int(*MyTypeFuncAdd)(int a, int b);

//函数指针
//框架
int MainOp(MyTypeFuncAdd myFuncAdd)
{
	int c = myFuncAdd(5, 6);
	return c;
}
//int (*MyPointerFuncAdd)(int a, int b);   //定义一个指向某函数的指针的变量，可以作为参数
int MainOp2(int(*MyPointerFuncAdd)(int a, int b))   //任务调用者
{
	int c = MyPointerFuncAdd(5, 6);   //间接调用
	return c;
}
//间接调用
void main()
{
	myadd(1, 2);    //直接调用

	MyTypeFuncAdd myFuncAdd = myadd;
	myFuncAdd(3, 4);
	
	MainOp2(myadd);
	MainOp(myadd);

	//将任务实现者和任务调用者分开写虽然比直接写麻烦，但是好处是！！
	//在MainOp框架没有发生任何变化的情况下，可以把后来的代码调用起来，可以添加子任务
	MainOp(myadd2);     //传入函数的入口地址
	MainOp(myadd3);
	MainOp(myadd4);

	system("pause");
}