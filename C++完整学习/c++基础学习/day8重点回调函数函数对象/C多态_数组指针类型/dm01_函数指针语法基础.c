#include<stdio.h>

//数组类型基本语法梳理
//定义一个数组类型
//int a[10];

//定义一个指针数组类型

//定义一个指向 数组类型的指针 即数组类指针

void main1()
{
	int a[10];    //a代表的是数组首个元素的地址，&a代表的是整个数组的地址，a+1和&a+1的步长可能不一样
	              //此处a+1步长4，即int类型内存长度，&a+1步长40

	{
		//定义一个数组类型
		typedef int(myTypeArray)[10];
		myTypeArray myArray;
		myArray[0] = 10;

	}

	{
	  //定义一个指针数组类型
		typedef int(*PTypeArray)[10];
		PTypeArray myPArray;  //sizeof(int) *10 步长为40
		myPArray = &a;
		(*myPArray)[0] = 20;
		printf("a[0]:%d \n", a[0]);
	}

	{ 
	 //定义一个指向 数组类型的指针
		int(*myPointer)[10];   //是一个变量,分配内存
		myPointer = &a;
		(*myPointer)[0] = 40;
		printf("a[0]:%d \n", a[0]);
	}
	system("pause");
	return;
}


//函数指针知识梳理

//如何定义一个函数类型

//如何定义一个函数指针类型

//如何定义一个函数指针 （指向一个函数的入口地址）

int add(int a, int b)
{
	printf("func add......\n");
	return a + b;
}

void main2()
{
	add(1, 2);    //直接调用  //函数名就是函数的入口地址
	
	//定义一个函数类型
	{
		typedef int(MyFuncType)(int a, int b);  //定义了一个类型
		MyFuncType *myPointerFunc = NULL;       //定义了一个指针，指向某一种类的函数
		myPointerFunc = &add;
		myPointerFunc(3, 4);     //间接调用

		myPointerFunc = add;  //也成功，C逐渐完善，兼容历史版本
	}

	{
	//定义一个函数指针类型
		typedef int(*myPointerFuncType)(int a, int b);   //int *a=NULL;
		myPointerFuncType myPointerFunc;   //定义一个指针
		myPointerFunc = add;
		myPointerFunc(5, 6);
	}

	//函数指针
	{
		int(*myPointerFunc)(int a, int b);   //定义了一个变量
		myPointerFunc = add;
		myPointerFunc(7, 8);
	}
	system("pause");
}