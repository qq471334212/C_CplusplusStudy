#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MaxLine 2048

//获取配置项
//输入一个key，在配置文件中按行查找是否存在key配置，若存在查找该行是否有‘=’
//若两者都存在，则输出后面的value值，对value的前后空格做了舍去
int GetCfgItem(char *pFileName/*in*/, char *pKey/*in*/, char *pValue/*in*/, int *pValueLen/*in*/)
{
	int ret = 0;
	FILE *fp = NULL;
	char lineBuf[MaxLine];
	char *pTemp, *pBegin = NULL, *pEnd = NULL;
	fp = fopen(pFileName, "r");
	if (fp == NULL)
	{
		ret = -1;
		return ret;
	}
	while (!feof(fp))    //没有到文件末尾就一直循环读
	{
		memset(lineBuf, 0, sizeof(lineBuf)); //清空内存空间
		fgets(lineBuf, MaxLine, fp);
		//printf("lineBuf :%s", lineBuf);  //不需要加'\n'，fegts读出每一行自带换行符

		//pTemp = strchr(lineBuf, '=');   //如果这一行没有等号，则说明没有key与value值，可能是一行其他的语句
		//if (pTemp == NULL)
		//{
		//	continue;
		//}
		pTemp = strstr(lineBuf, pKey);
		if (pTemp == NULL)            //判断这一行有没有要读的Key
		{
			continue;
		}
		else if (*(pTemp + strlen(pKey)) == ' ')        //确保取出来的是关键字key的值，而不是key1，key2，keyMike等等
		{
			//如果有Key
			pTemp = pTemp + strlen(pKey);  //指针从 "key = value" ==> "= value"
		}
		else
		{
			continue;
		}
		
		//再判断有没有等号
		pTemp = strchr(lineBuf, '=');   //如果这一行没有等号，则说明没有key与value值，可能是一行其他的语句
		if (pTemp == NULL)
		{
			continue;
		}
		pTemp = pTemp + 1;           ////指针从 "= value" ==> " value"
		//printf("pTemp:%s", pTemp);

		/////////////////////////////////////
		//去掉前后空格,获取Value字符串的起点
		while (1)
		{
			if (*pTemp == ' ')
			{
				pTemp++;
			}
			else
			{
				pBegin = pTemp;
				if (*pBegin == '\n')
				{
					printf("配置项：%s 没有配置Value \n", pKey);
					goto End;
				}
				break;
			}
		}

		//获取Value字符串的终点
		while (1)
		{
			if ((*pTemp == ' '|| *pTemp == '\n'))
			{
				break;
			}
			else
			{
				pTemp++;
			}
		}
		pEnd = pTemp;
		///////////////////////////////

		//赋值
		*pValueLen = pEnd - pBegin;
		memcpy(pValue, pBegin, *pValueLen);	
		break;
	}
End:
	if (fp != NULL)
	{
		fclose(fp);
	}
	return ret;
}

//写入配置项流程
//循环读每一行，检查Key配置是否已经存在，如果存在就修改对应的value值
//如果不存在。在文件末尾添加“key = value”
//难点在于如何修改文件流中的值
int WriteCfgItem(char *pFileName/*in*/, char *pItemName/*in*/, char *pItemValue/*out*/, int *pItemValueLen/*out*/)
{
	int ret = 0, iTag = 0, length = 0;     //iTag用来判断新增还是修改
	FILE *fp = NULL;
	char lineBuf[MaxLine];            //文件的每行数据
	char *pTmp = NULL, *pBegin = NULL, *pEnd = NULL;
	char fileBuf[1024 * 8] = { 0 };   //写入文件不超过8k

	if (pFileName == NULL || pItemName == NULL || pItemValue == NULL)
	{
		ret = -1;
		printf("func TestWriteCfgItem() err \n");
		goto End;
	}

	fp = fopen(pFileName, "r+");   //读写的方式
	if (fp == NULL)
	{
		ret = -2;
		printf(" fopen() err :%d\n", ret);

		fp = fopen(pFileName, "w+t");    //若没有文件，则新建一个文件
		if (fp == NULL)
		{
			ret = -3;
			printf(" fopen() err :%d\n", ret);
			goto End;
		}
	}

	fseek(fp, 0L, SEEK_END);   //文件刚打开，把文件指针从0位置，移动到文件的末尾，为了调用ftell计算长度
	//获取文件的长度
	length = ftell(fp);
	fseek(fp, 0L, SEEK_SET);   //再把指针移回来，返回0位置
	if (length > 1024 * 8)
	{
		ret = 03;
		printf("文件超过1024*8 ,numsupport");
		goto End;
	}
	
	while (!feof(fp))
	{
		memset(lineBuf, 0, sizeof(lineBuf));
		//fgets(lineBuf, MaxLine, fp);
		pTmp = fgets(lineBuf, MaxLine, fp);

		if (pTmp == NULL)   //文件里没东西直接跳出加
		{
			break;
		}

		pTmp = strstr(lineBuf, pItemName);
		if (pTmp == NULL)
		{
			strcat(fileBuf, lineBuf);     //key关键字不在本行，则把本行copy到fileBuf
			continue;
		}
		else if (*(pTmp + strlen(pItemName)) == ' ')
		{
			//若key关键字存在本行，则重写，替换旧的行 再copy到fileBuf
			//还可以自己搜一下如何直接替换文件流的中间内容
			sprintf(lineBuf, "%s = %s\n", pItemName, pItemValue);
			strcat(fileBuf, lineBuf);
	
			//若存在key
			iTag = 1;
		}
		else
		{
			strcat(fileBuf, lineBuf);     //key关键字不在本行，则把本行copy到fileBuf
			continue;
		}
	}

	if (iTag == 0)
	{
		//原来没有key关键，在文件后追加
		fprintf(fp, "%s = %s\n", pItemName, pItemValue);
	}
	else  //关键字key存在，重新创建文件
	{
		if (fp != NULL)
		{
			fclose(fp);
			fp = NULL;
		}
		fp = fopen(pFileName, "w+t");   //重新创建同名文件覆盖源文件
		if (fp == NULL)
		{
			printf("func fopen() err. \n");
			ret = -4;
			goto End;
		}
		//把缓冲文件内容放入到文件中
		fputs(fileBuf, fp);
	}

End:
	if (fp != NULL)
	{
		fclose(fp);
		fp = NULL;
	}
	return ret;
}