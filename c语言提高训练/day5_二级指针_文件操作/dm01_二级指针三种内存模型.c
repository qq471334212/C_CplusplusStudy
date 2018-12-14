#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int sort(char **myp1/*in*/, int num1, char(*myp2)[30], int num2, char ***myp3, int *num3)
{
	int i = 0, j = 0, k = 0;
	int tempLen = 0;
	char **p3 = NULL;
	//char **tmpP = NULL;
	p3 = (char **)malloc((num1 + num2) * sizeof(char *) );   //�ڴ�ռ���װ����ָ��

	if (p3 == NULL)
	{
		return -1;
	}
	//����һ���ڴ��ֵ������ȥ
	for (i = 0; i < num1; i++)
	{
		tempLen = strlen(myp1[i]) + 1;   //���ݳ��ȷ����ڴ�
		p3[i] = (char *)malloc(tempLen * sizeof(char));
		if (p3[i] == NULL)
		{
			return -2;
		}
		strcpy(p3[i], myp1[i]);
	}

	for (j = 0; j < num2; j++)
	{
		tempLen = strlen(myp2[j]) + 1;   //���鳤��+1
		p3[i] = (char *)malloc(tempLen * sizeof(char));
		if (p3[i] == NULL)
		{
			return -3;
		}
		strcpy(p3[i], myp2[j]);
		i++;
	}
	//����
	tempLen = num1 + num2;

	//��Ӹ���
	*num3 = tempLen;
	*myp3 = p3;
	return 0;
}

void mySort(char **p,int length)
{
	char **tmpP = NULL;
	int i , j;
	for (i = 0; i < length; i++)
	{
		for (j = i + 1; j < length; j++)
		{
			if (strcmp(p[i], p[j]) > 0)     //myp3[i]>mp3[j]�ͽ���
			{
				tmpP = p[i];                 //ͨ���ı�ָ��ָ������������
				p[i] = p[j];              //����**tmpPʱ��Ϊͨ����������������
				p[j] = tmpP;
			}
		}
	}
}

void sortFree(char **p, int len)
{
	if (p == NULL)
	{
		return;
	}
	for (int i = 0; i < len; i++)
	{
		free(p[i]);
	}
	free(p);
}

void sortFree01(char ***myp, int len)   //�Ѷ���ָ��ָ����ڴ������ͷŵ���ͬʱ��ӵ��޸���ʵ�ε�ֵ
{
	char **p = NULL;
	if (myp == NULL)
	{
		return;
	}
	p = *myp;             //��ԭ�ɶ���ָ��
	if (p == NULL)
	{
		return;
	}
	for (int i = 0; i < len; i++)
	{
		free(p[i]);
	}
	free(p);
	//myp�Ƕ���ָ��ʵ�εĵ�ַ
	*myp = NULL;  //��Ӹ�ֵ��ָ����ڵ��������
}
int main()
{
	int ret = 0;
	char *p1[] = { "aaaaaa","cccccc","bbbbbbbb" };
	char buf2[10][30] = { "1111111","333333","2222222222" };
	char **p33 = NULL;
	int len1, len2, len3, i = 0;
	len1 = sizeof(p1) / sizeof(*p1);
	len2 = 3;
	ret = sort(p1, len1, buf2, len2, &p33, &len3);
	if (ret != 0)
	{
		printf("func sort() err: %d \n", ret);
	}

	mySort(p33, len3);

	for (i = 0; i < len3; i++)
	{
		printf("%s\n",p33[i]);
	}
	system("pause");
	return ret;
}