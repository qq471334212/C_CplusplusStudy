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
	int k = -1;     //��¼Ҫ������±�
	int temp = -1;  //Ҫ�����ֵ

	for (i = 1; i < len; i++)   //Ҫ�ճ�����λ�ã���1��ʼ��
	{
		k = i;
		temp = array[k];
		for (j = i - 1; (j >= 0) && (array[j] > temp); j--)  //0��i-1��Щ���� ��������ʱ����
		{
			array[j+1] = array[j];
			k = j;        //k��Ҫ�����λ���±�
		}
		array[k] = temp;  //Ԫ�ز���
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
