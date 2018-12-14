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

//���ֹ���  �ӵ�һ��Ԫ�ص��ᣬȻ��ֳ�2��������
int position(int array[], int low, int high)
{
	int pv = array[low];     //��׼�������Ԫ�ش�С���������Ϊ�����֣����һ����С�������ұ�һ���ִ�����
	while (low < high)
	{
		while ((low < high) && (array[high] >= pv))
		{
			high--;               //�Ȼ�׼��ʱ��high�����ƶ�
		}
		swap05(array, low, high);

		while ((low < high) && (array[low] <= pv))
		{
			low++;            
		}
		swap05(array, low, high);
	}
	//���ػ�׼��λ��
	return low;
}

void QSort(int array[], int low, int high)
{
	if (low < high)
	{
		int pivot = position(array, low, high);
		//�ݹ�
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
