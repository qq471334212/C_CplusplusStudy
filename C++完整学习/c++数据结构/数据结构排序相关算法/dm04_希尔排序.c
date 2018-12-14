#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void printfArray4(int array[], int len)
{
	int i = 0;
	for (i = 0; i < len; i++)
	{
		printf("%d  ", array[i]);
	}
	printf("\n");
}

void InsertionSort1(int array[], int len)    //O(n*n)
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
			array[j + 1] = array[j];
			k = j;        //k需要插入的位置下标
		}
		array[k] = temp;  //元素插入
	}
}
//在插入法的基础上做了分组优化
void ShellSort(int array[], int len)
{
	int i = 0;
	int j = 0;
	int k = -1;
	int temp = -1;
	int gap = len;

	do
	{
		//业界标准
		gap = gap / 3 + 1;
		//当gap=1的时候就是插入法
		for (i = gap; i < len; i += gap) //O(n*1.3)
		{
			k = i;
			temp = array[k];
			for (j = i - gap; (j >= 0) && (array[j] > temp); j -= gap)
			{
				array[j + gap] = array[j];
				k = j;
			}
			array[k] = temp;
		}
	} while (gap > 1);
}

void main04()
{
	int array[] = { 12,5,433,253 };
	int len = sizeof(array) / sizeof(*array);

	printfArray4(array, len);
	ShellSort(array, len);
	printfArray4(array, len);
	system("pause");
	return;
}
