#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//int spitString2(const char *buf1, char c, char buf2[10][30], int *count)
int spitString2(const char *buf1, char c, char **myp/*in*/, int *count)        
{
	char *p = NULL, *pTmp = NULL;
	int tmpCount = 0;
	int d;

	//1.初始化
	p = buf1;
	pTmp = buf1;

	do
	{
		//2.检索符合条件的位置，p后移形成差值。挖取字符串
		p = strchr(p, c); //检索'c'字符的位置并返回给指针p
		if (p != NULL)
		{
			if (p - pTmp > 0)
			{
				strncpy(myp[tmpCount], pTmp, p - pTmp);   //拷贝多块
				d = p - pTmp;
				myp[tmpCount][d] = '\0';           //把第一行数据变成C风格字符串
				tmpCount++;
				pTmp = p = p + 1;

			}
		}
		else
		{
			break;
		}
	} while (*p != '\0');
	*count = tmpCount;
	return 0;
}

char ** Make2Darray(int x, int y)
{
	int i = 0;
	char **p = NULL;
	p = (char**)malloc(sizeof(char *) * x);   //相当于*array[10]
	if (p == NULL)
	{
		return;
	}
	for (i = 0; i < x; i++)
	{
		p[i] = (char *)malloc(sizeof(char) * y); //相当于 array[10][30]
	}
	return p;
}
void Free2Darray(char **p, int x)
{
	int i = 0;
	for (i = 0; i < x; i++)
	{
		free(p[i]);
	}
	free(p);
}
void main1()
{
	int ret = 0, i = 0;
	char *p1 = "abcdef,acccd,eeee,aaaa,e3eeeee,sssss,";
	char cTmp = ',';
	int nCount;
    
	//char myArray[10][30];
	
	char **p = NULL;
	p = Make2Darray(10, 30);   //手工分配内存空间

	ret = spitString2(p1, cTmp, p, &nCount);
	if (ret != 0)
	{
		printf("func spitString2() err :%d \n", ret);
		return ret;
	}

	for (i = 0; i < nCount; i++)
	{
		printf("%s\n", p[i]);
	}

	Free2Darray(p, 10);

	system("pause");
	return;
}