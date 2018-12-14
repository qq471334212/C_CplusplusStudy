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
	int k = -1;     //��¼Ҫ������±�
	int temp = -1;  //Ҫ�����ֵ

	for (i = 1; i < len; i++)   //Ҫ�ճ�����λ�ã���1��ʼ��
	{
		k = i;
		temp = array[k];
		for (j = i - 1; (j >= 0) && (array[j] > temp); j--)  //0��i-1��Щ���� ��������ʱ����
		{
			array[j + 1] = array[j];
			k = j;        //k��Ҫ�����λ���±�
		}
		array[k] = temp;  //Ԫ�ز���
	}
}
//�ڲ��뷨�Ļ��������˷����Ż�
void ShellSort(int array[], int len)
{
	int i = 0;
	int j = 0;
	int k = -1;
	int temp = -1;
	int gap = len;

	do
	{
		//ҵ���׼
		gap = gap / 3 + 1;
		//��gap=1��ʱ����ǲ��뷨
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
