#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void printfArray(int array[], int len)
{
	int i = 0;
	for (i = 0; i < len; i++)
	{
		printf("%d  ", array[i]);
	}
	printf("\n");
}


void swap01(int array[], int i, int k)
{
    int tmp;
	tmp = array[i];
	array[i] = array[k];
	array[k] = tmp;
}

//从小到大排列
void SelectionSort(int array[], int len)     //O(n*n)
{
	int i = 0;
	int j = 0;
	int k = -1;
	
	for (i = 0; i < len; i++)
	{
		k = i;     //寻找最小位置的下标
		for (j = i + 1; j < len; j++)
		{
			if (array[j] < array[k])    
			{
				k = j;
			}
		}
		swap01(array, i, k);   //交换当前位置与最小坐标位置
	}

	//for (i = 0; i < len; i++)
	//{
	//	for (j = i + 1; j < len; j++)
	//	{
	//		if (array[j] > array[k])
	//		{
	//			int tmp;
	//			tmp = array[i];
	//			array[i] = array[j];
	//			array[j] = tmp;
	//		}
	//	}
	//}


}


void main01()
{
	int array[] = { 12,5,433,253 };
	int len = sizeof(array) / sizeof(*array);

	printfArray(array, len);
	SelectionSort(array, len);
	printfArray(array, len);
	system("pause");
	return;
}
