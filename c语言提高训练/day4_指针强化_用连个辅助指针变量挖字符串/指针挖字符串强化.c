#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//int spitString2(const char *buf1, char c, char buf2[10][30], int *count)
char ** spitString3(const char *buf1, char c, int *count)
{
	char **myp = NULL;
	char *p = NULL, *pTmp = NULL;
	int tmpCount = 0;
	int d;

	//1.初始化
	p = buf1;
	pTmp = buf1;

	//第一遍扫描求出字符count
	do
	{
		//2.检索符合条件的位置，p后移形成差值。挖取字符串
		p = strchr(p, c); //检索'c'字符的位置并返回给指针p
		if (p != NULL)
		{
			if (p - pTmp > 0)
			{
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
	//求出了字符出现要挖的次数，根据多少行分配内存
	myp = (char **)malloc(sizeof(char *) * tmpCount);
	if (myp == NULL)
	{
		return NULL;
	}

	//1.初始化
	p = buf1;
	pTmp = buf1;

	tmpCount = 0;
	do
	{
		//2.检索符合条件的位置，p后移形成差值。挖取字符串
		p = strchr(p, c); //检索'c'字符的位置并返回给指针p
		if (p != NULL)
		{
			if (p - pTmp > 0)
			{
				//精确分配每列内存
				d = p - pTmp + 1;    //字符串末尾还有个'\0'不要遗漏
				myp[tmpCount] = (char *)malloc(d * sizeof(char));
				if (myp[tmpCount] == NULL)
				{
					return NULL;
				}
				strncpy(myp[tmpCount], pTmp, p - pTmp);   //拷贝多块			
				myp[tmpCount][d - 1] = '\0';           //把第一行数据变成C风格字符串
				tmpCount++;
				//3.重新让p和pTmp达到下一次检索的条件
				pTmp = p = p + 1;

			}
		}
		else
		{
			break;
		}
	} while (*p != '\0');
	*count = tmpCount;
	return myp;
}

//三级指针作参数值
int spitString4(const char *buf1, char c, char ***myp3, int *count)
{
	char **myp = NULL;
	char *p = NULL, *pTmp = NULL;
	int tmpCount = 0;
	int d;
	int ret = 0;
	int i = 0;
	//1.初始化
	p = buf1;
	pTmp = buf1;

	//第一遍扫描求出字符count
	do
	{
		//2.检索符合条件的位置，p后移形成差值。挖取字符串
		p = strchr(p, c); //检索'c'字符的位置并返回给指针p
		if (p != NULL)
		{
			if (p - pTmp > 0)
			{
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
	//求出了字符出现要挖的次数，根据多少行分配内存
	myp = (char **)malloc(sizeof(char *) * tmpCount);
	if (myp == NULL)
	{
		ret = -1;
		goto End;
		printf("func spitString4() err:%d sizeof(char *) * tmpCount ", ret);
		//return -1;
	}
	memset(myp, 0, sizeof(char *) * tmpCount);

	//1.初始化
	p = buf1;
	pTmp = buf1;

	tmpCount = 0;
	do
	{
		//2.检索符合条件的位置，p后移形成差值。挖取字符串
		p = strchr(p, c); //检索'c'字符的位置并返回给指针p
		if (p != NULL)
		{
			if (p - pTmp > 0)
			{
				//精确分配每列内存
				d = p - pTmp + 1;    //字符串末尾还有个'\0'不要遗漏
				myp[tmpCount] = (char *)malloc(d * sizeof(char));
				if (myp[tmpCount] == NULL)
				{
					ret = -2;
					goto End;
					printf("func spitString4() err:%d sizeof(char ) * d ", ret);
					//return -2;
				}
				strncpy(myp[tmpCount], pTmp, p - pTmp);   //拷贝多块			
				myp[tmpCount][d - 1] = '\0';           //把第一行数据变成C风格字符串
				tmpCount++;
				//3.重新让p和pTmp达到下一次检索的条件
				pTmp = p = p + 1;

			}
		}
		else
		{
			break;
		}
	} while (*p != '\0');

End:          //在同意的出口处，把分配失败的空间都释放掉
	if (ret != 0)
	{
		//可以单独写成一个释放空间的函数
		if (myp == NULL)
		{
			return;
		}
		for (i = 0; i < tmpCount; i++)
		{
			if (myp[i] != NULL)             //分配二维时失败，把之前已经分配内存二维空间的释放掉
			{
				free(myp[i]);
			}
		}
		if (myp != NULL)
		{
			free(myp);
		}
	}
	else
	{
		//*count = tmpCount;
		*myp3 = myp;     //分配空间成功
	}



	return ret;
}

//多级指针避免野指针
void main03()
{
	int ret = 0, i = 0;
	char *p1 = "abcdef,acccd,";
	char cTmp = ',';
	int nCount;

	//char myArray[10][30];

	char **p = NULL;


	p = spitString3(p1, cTmp, &nCount);
	if (p == NULL)
	{
		printf("func spitString2() err :%d \n", ret);
		return ret;
	}

	for (i = 0; i < nCount; i++)
	{
		printf("%s\n", p[i]);
	}

	for (i = 0; i < nCount; i++)
	{
		free(p[i]);
	}
	free(p);

	system("pause");
	return;
}

void main()
{
	int ret = 0, i = 0;
	char *p1 = "abcdef,acccd,";
	char cTmp = ',';
	int nCount;

	//char myArray[10][30];

	char **p = NULL;


	ret = spitString4(p1, cTmp, &p, &nCount);
	if (ret != 0)
	{
		printf("func spitString4() err :%d \n", ret);
		return ret;
	}

	for (i = 0; i < nCount; i++)
	{
		printf("%s\n", p[i]);
	}

	for (i = 0; i < nCount; i++)
	{
		free(p[i]);
	}
	free(p);

	system("pause");
	return;
}