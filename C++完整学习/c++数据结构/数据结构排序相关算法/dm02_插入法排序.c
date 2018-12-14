#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void printfArray2(int array[], int len)
{
	int i = 0;
	for (i = 0; i < len; i++)
	{
		printf("%d  ", array[i]);
	}
	printf("\n");
}

void InsertionSort(int array[], int len)    //O(n*n)
{
	int i = 0; 
	int j = 0;
	int k = -1;     //记录要插入的下标
	int temp = -1;  //要插入的值

	for (i = 1; i < len; i++)   //要空出来的位置，从1开始空
	{
		k = i;
		temp = array[k];
		for (j = i - 1; (j >= 0) && (array[j] > temp); j--)  //0到i-1这些数字 满足条件时后移
		{
			array[j+1] = array[j];
			k = j;        //k需要插入的位置下标
		}
		array[k] = temp;  //元素插入
	}
}

void main02()
{
	int array[] = { 12,5,433,253 };
	int len = sizeof(array) / sizeof(*array);

	printfArray2(array, len);
	InsertionSort(array, len);
	printfArray2(array, len);
	system("pause");
	return;
}
