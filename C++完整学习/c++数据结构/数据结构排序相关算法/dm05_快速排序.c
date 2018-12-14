#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void printfArray5(int array[], int len)
{
	int i = 0;
	for (i = 0; i < len; i++)
	{
		printf("%d  ", array[i]);
	}
	printf("\n");
}


void swap05(int array[], int i, int k)
{
	int tmp;
	tmp = array[i];
	array[i] = array[k];
	array[k] = tmp;
}

//划分过程  从第一个元素当轴，然后分成2个子序列
int position(int array[], int low, int high)
{
	int pv = array[low];     //基准，以这个元素大小，将数组分为两部分，左边一部分小于它，右边一部分大于它
	while (low < high)
	{
		while ((low < high) && (array[high] >= pv))
		{
			high--;               //比基准大时，high向左移动
		}
		swap05(array, low, high);

		while ((low < high) && (array[low] <= pv))
		{
			low++;            
		}
		swap05(array, low, high);
	}
	//返回基准的位置
	return low;
}

void QSort(int array[], int low, int high)
{
	if (low < high)
	{
		int pivot = position(array, low, high);
		//递归
		QSort(array, low, pivot - 1);
		QSort(array, pivot + 1, high);
	}
}

void QucikSort(int array[], int len)
{
	QSort(array, 0, len - 1);
}
void main05()
{
	int array[] = { 12,5,433,253 };
	int len = sizeof(array) / sizeof(*array);

	printfArray5(array, len);
	QucikSort(array,len);
	printfArray5(array, len);
	system("pause");
	return;
}
