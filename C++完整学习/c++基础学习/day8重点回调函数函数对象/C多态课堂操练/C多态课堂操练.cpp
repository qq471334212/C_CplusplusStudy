#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//�������ͻ����﷨֪ʶ����
//����һ����������
//int a[10];

//����һ��ָ����������

//����һ��ָ�� �������͵�ָ�루������ָ�룩
void main1()
{
	int a[10];         //a����������Ԫ�صĵ�ַ��&a������������ĵ�ַ 
					   //a+1��&a+1�Ĳ���һ���ǲ�һ����

	{
		//����һ����������
		typedef int(myTypeArray)[10];
		myTypeArray myArray;

	}
	{
		//����һ��ָ����������
		typedef int(*PTypeArray)[10];  //int *p;
		PTypeArray myPArray;   //sizeof(int)*10
		myPArray = &a;

	}
	{
		//����һ��ָ�� �������͵�ָ�루������ָ�룩
		int(*MyPointer)[10];   //����C������ ���ҷ����ڴ�
		MyPointer = &a;
	}
	system("pause");
	return;
}


//����ָ������﷨����
//1.��ζ���һ����������
//2.��ζ���һ������ָ������
//3.��ζ���һ�� ����ָ�� ��ָ��һ����������ڵ�ַ��

int add(int a, int b)
{
	printf("func add() ...\n");
	return a + b;
}

int main2()
{
	add(1, 2);    //ֱ�ӵ��� //���������Ǻ�����ڵ�ַ

	{
		//����һ����������
		typedef int (MyFuncType)(int a, int b);  //������һ����
		MyFuncType *myPointerFunc = NULL;        //������һ��ָ�룬ָ��������͵ĺ���

		myPointerFunc = &add;
		myPointerFunc(3, 4);

	}

	{
		//��ζ���һ������ָ������
		typedef int(*MyPointerFuncType)(int a, int b);  //int *a =NULL;
		MyPointerFuncType myPointer;
		myPointer = add;
		myPointer(5, 6);
	}

	{
		//����ָ��
		int(*MyPointerFunc)(int a, int b);    //������һ������
		MyPointerFunc = add;
		MyPointerFunc(7, 8);
	}
	system("pause");
	return 0;
}