#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"des.h"


int main11()
{
	int ret = 0;
	char *plain = "132134664654";
	int plainLen = strlen(plain);

	char plain2[4096] = {0};
	int plainLen2 = 0;
	unsigned char cryptbuf[4096] = {0};
	int cryptLen = 0;
	//���ܹ���
	ret =  DesEnc(plain, plainLen, cryptbuf, &cryptLen);
	if (ret != 0)
	{
		printf("func DesEnc() err : %d", ret);
		return ret;
	}

	//���ܹ���
	ret = DesDec(cryptbuf, cryptLen, plain2, &plainLen2);
	if (ret != 0)
	{
		ret = -1;
		printf("func DesDec() err : %d", ret);
		return ret;
	}

	if (plainLen != plainLen2)
	{
		ret = -2;
		printf("���ĳ��Ⱥͽ��ܺ�����ĳ��Ȳ�һ����\n");
		return ret;
	}
	else {
		if (memcmp(plain2, plain, plainLen2) == 0)
		{
			printf("���ĺͽ��ܺ�����ĳ��ȣ����ݶ�һ����\n");
		}
		else
		{
			printf("�������ݺͽ��ܺ���������ݲ�һ����\n");
			ret = -3;
			return ret;
		}
	}



	//if (strcmp(plain, plain2) != 0)
	//{
	//	ret = -2;
	//	printf("���ļ��ܽ���֮�������󡣡�����");
	//}
	//else
	//{
	//	printf("������ͬ��");
	//}



	system("pause");
	return ret;  
}