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
		if (src[i] < src[j])         //��һ���ֱȽ�С���Ͱ��ǲ��ַ���Ŀ�ĵ�������
		{
			des[k++] = src[i++];
		}
		else
		{
			des[k++] = src[j++];
		}
	}

	while (i <= mid)      //��ǰһ���ֻ�ʣ����β��Ԫ��
	{
		des[k++] = src[i++];
	}
	while (j <= high)     //����һ���ֻ�ʣ����β��Ԫ��
	{
		des[k++] = src[j++];
	}
}

void MSort(int src[], int des[], int low, int high, int max)
{
	if (low == high)           //ֻ��һ��Ԫ�أ�ֱ�Ӹ�ֵ���
	{
		des[low] = src[low];
	}
	else                       //�ж��Ԫ�أ�������·����
	{
		int mid = (low + high) / 2;
		int * space = (int *)malloc(sizeof(int)*max);

		//�ݹ������·����·����
		//ʣ��һ��Ԫ��ʱ���ݹ黮�ֽ�����Ȼ��ʼ�鲢����
		if (space != NULL)
		{
			MSort(src, space, low, mid, max);
			MSort(src, space, mid+1, high, max);
			Merge(space, des, low, mid, high);       //�鲢�������й鲢
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
