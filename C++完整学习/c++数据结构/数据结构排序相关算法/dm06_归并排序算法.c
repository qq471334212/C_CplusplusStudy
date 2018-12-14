#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void printfArray6(int array[], int len)
{
	int i = 0;
	for (i = 0; i < len; i++)
	{
		printf("%d  ", array[i]);
	}
	printf("\n");
}

void swap06(int array[], int i, int k)
{
	int tmp;
	tmp = array[i];
	array[i] = array[k];
	array[k] = tmp;
}

void Merge(int src[], int des[], int low, int mid, int high)
{
	int i = low;
	int j = mid + 1;
	int k = low;
	while ((i <= mid) && (j <= high))
	{
		if (src[i] < src[j])         //那一部分比较小，就把那部分放在目的的数组中
		{
			des[k++] = src[i++];
		}
		else
		{
			des[k++] = src[j++];
		}
	}

	while (i <= mid)      //若前一部分还剩几个尾部元素
	{
		des[k++] = src[i++];
	}
	while (j <= high)     //若后一部分还剩几个尾部元素
	{
		des[k++] = src[j++];
	}
}

void MSort(int src[], int des[], int low, int high, int max)
{
	if (low == high)           //只有一个元素，直接赋值输出
	{
		des[low] = src[low];
	}
	else                       //有多个元素，进行两路划分
	{
		int mid = (low + high) / 2;
		int * space = (int *)malloc(sizeof(int)*max);

		//递归进行两路，两路划分
		//剩下一个元素时，递归划分结束，然后开始归并操作
		if (space != NULL)
		{
			MSort(src, space, low, mid, max);
			MSort(src, space, mid+1, high, max);
			Merge(space, des, low, mid, high);       //归并函数进行归并
		}
		free(space);
	}

}

void mergeSort(int array[], int len)
{
	MSort(array, array, 0, len - 1, len);
}

void main()
{
	int array[] = { 12,5,433,253 };
	int len = sizeof(array) / sizeof(*array);

	printfArray6(array, len);
	mergeSort(array, len);
	printfArray6(array, len);
	system("pause");
	return;
}
