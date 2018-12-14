#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void printfArray3(int array[], int len)
{
	int i = 0;
	for (i = 0; i < len; i++)
	{
		printf("%d  ", array[i]);
	}
	printf("\n");
}

void swap03(int array[], int i, int k)
{
	int tmp;
	tmp = array[i];
	array[i] = array[k];
	array[k] = tmp;
}

void BubbleSort(int array[], int len)     //O(n*n)
{
	int i = 0;
	int j = 0;
	int success = 1;   //表示数组是否排序完毕， 1表示未完成，0表示完成
	for (i = 0; (i < len) && success; i++)   //排好序的话循环跳出
	{
		success = 0;   //先假设排序完毕
		for (j = len - 1; j > i; j--)   //从右向左冒泡
		{
			if (array[j] < array[j - 1])  //相邻元素比较，从小到大排序
			{
				swap03(array, j, j - 1);
				success = 1;              //要交换表示排序未完成
			}
		}
	}

}

void main03()
{
	int array[] = { 12,5,433,253 };
	int len = sizeof(array) / sizeof(*array);

	printfArray3(array, len);
	BubbleSort(array, len);
	printfArray3(array, len);
	system("pause");
	return;
}
