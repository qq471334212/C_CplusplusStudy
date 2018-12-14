#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MaxLine 2048

//��ȡ������
//����һ��key���������ļ��а��в����Ƿ����key���ã������ڲ��Ҹ����Ƿ��С�=��
//�����߶����ڣ�����������valueֵ����value��ǰ��ո�������ȥ
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
	while (!feof(fp))    //û�е��ļ�ĩβ��һֱѭ����
	{
		memset(lineBuf, 0, sizeof(lineBuf)); //����ڴ�ռ�
		fgets(lineBuf, MaxLine, fp);
		//printf("lineBuf :%s", lineBuf);  //����Ҫ��'\n'��fegts����ÿһ���Դ����з�

		//pTemp = strchr(lineBuf, '=');   //�����һ��û�еȺţ���˵��û��key��valueֵ��������һ�����������
		//if (pTemp == NULL)
		//{
		//	continue;
		//}
		pTemp = strstr(lineBuf, pKey);
		if (pTemp == NULL)            //�ж���һ����û��Ҫ����Key
		{
			continue;
		}
		else if (*(pTemp + strlen(pKey)) == ' ')        //ȷ��ȡ�������ǹؼ���key��ֵ��������key1��key2��keyMike�ȵ�
		{
			//�����Key
			pTemp = pTemp + strlen(pKey);  //ָ��� "key = value" ==> "= value"
		}
		else
		{
			continue;
		}
		
		//���ж���û�еȺ�
		pTemp = strchr(lineBuf, '=');   //�����һ��û�еȺţ���˵��û��key��valueֵ��������һ�����������
		if (pTemp == NULL)
		{
			continue;
		}
		pTemp = pTemp + 1;           ////ָ��� "= value" ==> " value"
		//printf("pTemp:%s", pTemp);

		/////////////////////////////////////
		//ȥ��ǰ��ո�,��ȡValue�ַ��������
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
					printf("�����%s û������Value \n", pKey);
					goto End;
				}
				break;
			}
		}

		//��ȡValue�ַ������յ�
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

		//��ֵ
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

//д������������
//ѭ����ÿһ�У����Key�����Ƿ��Ѿ����ڣ�������ھ��޸Ķ�Ӧ��valueֵ
//��������ڡ����ļ�ĩβ��ӡ�key = value��
//�ѵ���������޸��ļ����е�ֵ
int WriteCfgItem(char *pFileName/*in*/, char *pItemName/*in*/, char *pItemValue/*out*/, int *pItemValueLen/*out*/)
{
	int ret = 0, iTag = 0, length = 0;     //iTag�����ж����������޸�
	FILE *fp = NULL;
	char lineBuf[MaxLine];            //�ļ���ÿ������
	char *pTmp = NULL, *pBegin = NULL, *pEnd = NULL;
	char fileBuf[1024 * 8] = { 0 };   //д���ļ�������8k

	if (pFileName == NULL || pItemName == NULL || pItemValue == NULL)
	{
		ret = -1;
		printf("func TestWriteCfgItem() err \n");
		goto End;
	}

	fp = fopen(pFileName, "r+");   //��д�ķ�ʽ
	if (fp == NULL)
	{
		ret = -2;
		printf(" fopen() err :%d\n", ret);

		fp = fopen(pFileName, "w+t");    //��û���ļ������½�һ���ļ�
		if (fp == NULL)
		{
			ret = -3;
			printf(" fopen() err :%d\n", ret);
			goto End;
		}
	}

	fseek(fp, 0L, SEEK_END);   //�ļ��մ򿪣����ļ�ָ���0λ�ã��ƶ����ļ���ĩβ��Ϊ�˵���ftell���㳤��
	//��ȡ�ļ��ĳ���
	length = ftell(fp);
	fseek(fp, 0L, SEEK_SET);   //�ٰ�ָ���ƻ���������0λ��
	if (length > 1024 * 8)
	{
		ret = 03;
		printf("�ļ�����1024*8 ,numsupport");
		goto End;
	}
	
	while (!feof(fp))
	{
		memset(lineBuf, 0, sizeof(lineBuf));
		//fgets(lineBuf, MaxLine, fp);
		pTmp = fgets(lineBuf, MaxLine, fp);

		if (pTmp == NULL)   //�ļ���û����ֱ��������
		{
			break;
		}

		pTmp = strstr(lineBuf, pItemName);
		if (pTmp == NULL)
		{
			strcat(fileBuf, lineBuf);     //key�ؼ��ֲ��ڱ��У���ѱ���copy��fileBuf
			continue;
		}
		else if (*(pTmp + strlen(pItemName)) == ' ')
		{
			//��key�ؼ��ִ��ڱ��У�����д���滻�ɵ��� ��copy��fileBuf
			//�������Լ���һ�����ֱ���滻�ļ������м�����
			sprintf(lineBuf, "%s = %s\n", pItemName, pItemValue);
			strcat(fileBuf, lineBuf);
	
			//������key
			iTag = 1;
		}
		else
		{
			strcat(fileBuf, lineBuf);     //key�ؼ��ֲ��ڱ��У���ѱ���copy��fileBuf
			continue;
		}
	}

	if (iTag == 0)
	{
		//ԭ��û��key�ؼ������ļ���׷��
		fprintf(fp, "%s = %s\n", pItemName, pItemValue);
	}
	else  //�ؼ���key���ڣ����´����ļ�
	{
		if (fp != NULL)
		{
			fclose(fp);
			fp = NULL;
		}
		fp = fopen(pFileName, "w+t");   //���´���ͬ���ļ�����Դ�ļ�
		if (fp == NULL)
		{
			printf("func fopen() err. \n");
			ret = -4;
			goto End;
		}
		//�ѻ����ļ����ݷ��뵽�ļ���
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