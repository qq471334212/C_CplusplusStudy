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
	//加密过程
	ret =  DesEnc(plain, plainLen, cryptbuf, &cryptLen);
	if (ret != 0)
	{
		printf("func DesEnc() err : %d", ret);
		return ret;
	}

	//解密过程
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
		printf("明文长度和解密后的明文长度不一样！\n");
		return ret;
	}
	else {
		if (memcmp(plain2, plain, plainLen2) == 0)
		{
			printf("明文和解密后的明文长度，内容都一样！\n");
		}
		else
		{
			printf("明文内容和解密后的明文内容不一样！\n");
			ret = -3;
			return ret;
		}
	}



	//if (strcmp(plain, plain2) != 0)
	//{
	//	ret = -2;
	//	printf("明文加密解密之后发生错误。。。。");
	//}
	//else
	//{
	//	printf("两者相同！");
	//}



	system("pause");
	return ret;  
}