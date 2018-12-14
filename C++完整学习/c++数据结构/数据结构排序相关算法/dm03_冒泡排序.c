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
	int success = 1;   //��ʾ�����Ƿ�������ϣ� 1��ʾδ��ɣ�0��ʾ���
	for (i = 0; (i < len) && success; i++)   //�ź���Ļ�ѭ������
	{
		success = 0;   //�ȼ����������
		for (j = len - 1; j > i; j--)   //��������ð��
		{
			if (array[j] < array[j - 1])  //����Ԫ�رȽϣ���С��������
			{
				swap03(array, j, j - 1);
				success = 1;              //Ҫ������ʾ����δ���
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
