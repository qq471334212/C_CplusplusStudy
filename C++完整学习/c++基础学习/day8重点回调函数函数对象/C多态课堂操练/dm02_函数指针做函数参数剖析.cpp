#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>



int myadd(int a, int b)
{
	printf("func myadd() ...\n");
	return a + b;
}

typedef int(*MyTypeFuncAdd)(int a, int b);  //������һ������

//����ָ������������
//����д
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
	myadd(1, 2);          //ֱ�ӵ���

	myFuncAdd = myadd;    //��ӵ���
	myFuncAdd(3, 4);

	MainOp2(myadd);
	MainOp(myadd);

	system("pause");
	return;
}

