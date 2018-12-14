#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//数组类型基本语法知识梳理
//定义一个数组类型
//int a[10];

//定义一个指针数组类型

//定义一个指向 数组类型的指针（数组类指针）
void main1()
{
	int a[10];         //a代表数组首元素的地址，&a代表整个数组的地址 
					   //a+1和&a+1的步长一般是不一样的

	{
		//定义一个数组类型
		typedef int(myTypeArray)[10];
		myTypeArray myArray;

	}
	{
		//定义一个指针数组类型
		typedef int(*PTypeArray)[10];  //int *p;
		PTypeArray myPArray;   //sizeof(int)*10
		myPArray = &a;

	}
	{
		//定义一个指向 数组类型的指针（数组类指针）
		int(*MyPointer)[10];   //告诉C编译器 给我分配内存
		MyPointer = &a;
	}
	system("pause");
	return;
}


//函数指针基本语法梳理
//1.如何定义一个函数类型
//2.如何定义一个函数指针类型
//3.如何定义一个 函数指针 （指向一个函数的入口地址）

int add(int a, int b)
{
	printf("func add() ...\n");
	return a + b;
}

int main2()
{
	add(1, 2);    //直接调用 //函数名就是函数入口地址

	{
		//定义一个函数类型
		typedef int (MyFuncType)(int a, int b);  //定义了一类型
		MyFuncType *myPointerFunc = NULL;        //定义了一个指针，指向定义的类型的函数

		myPointerFunc = &add;
		myPointerFunc(3, 4);

	}

	{
		//如何定义一个函数指针类型
		typedef int(*MyPointerFuncType)(int a, int b);  //int *a =NULL;
		MyPointerFuncType myPointer;
		myPointer = add;
		myPointer(5, 6);
	}

	{
		//函数指针
		int(*MyPointerFunc)(int a, int b);    //定义了一个变量
		MyPointerFunc = add;
		MyPointerFunc(7, 8);
	}
	system("pause");
	return 0;
}