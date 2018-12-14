#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>



int myadd(int a, int b)
{
	printf("func myadd() ...\n");
	return a + b;
}

typedef int(*MyTypeFuncAdd)(int a, int b);  //定义了一个类型

//函数指针做函数参数
//这样写
int MainOp(MyTypeFuncAdd myFuncAdd)
{
	myFuncAdd(5, 6);
	return 0;
}

int MainOp2(int(*MyTypeFuncAdd)(int a, int b))
{
	MyTypeFuncAdd(5, 6);
	return 0;
}

void main()
{
	MyTypeFuncAdd myFuncAdd = NULL;
	myadd(1, 2);          //直接点用

	myFuncAdd = myadd;    //间接调用
	myFuncAdd(3, 4);

	MainOp2(myadd);
	MainOp(myadd);

	system("pause");
	return;
}

