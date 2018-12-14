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

	//1.��ʼ��
	p = buf1;
	pTmp = buf1;

	//��һ��ɨ������ַ�count
	do
	{
		//2.��������������λ�ã�p�����γɲ�ֵ����ȡ�ַ���
		p = strchr(p, c); //����'c'�ַ���λ�ò����ظ�ָ��p
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
	//������ַ�����Ҫ�ڵĴ��������ݶ����з����ڴ�
	myp = (char **)malloc(sizeof(char *) * tmpCount);
	if (myp == NULL)
	{
		return NULL;
	}

	//1.��ʼ��
	p = buf1;
	pTmp = buf1;

	tmpCount = 0;
	do
	{
		//2.��������������λ�ã�p�����γɲ�ֵ����ȡ�ַ���
		p = strchr(p, c); //����'c'�ַ���λ�ò����ظ�ָ��p
		if (p != NULL)
		{
			if (p - pTmp > 0)
			{
				//��ȷ����ÿ���ڴ�
				d = p - pTmp + 1;    //�ַ���ĩβ���и�'\0'��Ҫ��©
				myp[tmpCount] = (char *)malloc(d * sizeof(char));
				if (myp[tmpCount] == NULL)
				{
					return NULL;
				}
				strncpy(myp[tmpCount], pTmp, p - pTmp);   //�������			
				myp[tmpCount][d - 1] = '\0';           //�ѵ�һ�����ݱ��C����ַ���
				tmpCount++;
				//3.������p��pTmp�ﵽ��һ�μ���������
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

//����ָ��������ֵ
int spitString4(const char *buf1, char c, char ***myp3, int *count)
{
	char **myp = NULL;
	char *p = NULL, *pTmp = NULL;
	int tmpCount = 0;
	int d;
	int ret = 0;
	int i = 0;
	//1.��ʼ��
	p = buf1;
	pTmp = buf1;

	//��һ��ɨ������ַ�count
	do
	{
		//2.��������������λ�ã�p�����γɲ�ֵ����ȡ�ַ���
		p = strchr(p, c); //����'c'�ַ���λ�ò����ظ�ָ��p
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
	//������ַ�����Ҫ�ڵĴ��������ݶ����з����ڴ�
	myp = (char **)malloc(sizeof(char *) * tmpCount);
	if (myp == NULL)
	{
		ret = -1;
		goto End;
		printf("func spitString4() err:%d sizeof(char *) * tmpCount ", ret);
		//return -1;
	}
	memset(myp, 0, sizeof(char *) * tmpCount);

	//1.��ʼ��
	p = buf1;
	pTmp = buf1;

	tmpCount = 0;
	do
	{
		//2.��������������λ�ã�p�����γɲ�ֵ����ȡ�ַ���
		p = strchr(p, c); //����'c'�ַ���λ�ò����ظ�ָ��p
		if (p != NULL)
		{
			if (p - pTmp > 0)
			{
				//��ȷ����ÿ���ڴ�
				d = p - pTmp + 1;    //�ַ���ĩβ���и�'\0'��Ҫ��©
				myp[tmpCount] = (char *)malloc(d * sizeof(char));
				if (myp[tmpCount] == NULL)
				{
					ret = -2;
					goto End;
					printf("func spitString4() err:%d sizeof(char ) * d ", ret);
					//return -2;
				}
				strncpy(myp[tmpCount], pTmp, p - pTmp);   //�������			
				myp[tmpCount][d - 1] = '\0';           //�ѵ�һ�����ݱ��C����ַ���
				tmpCount++;
				//3.������p��pTmp�ﵽ��һ�μ���������
				pTmp = p = p + 1;

			}
		}
		else
		{
			break;
		}
	} while (*p != '\0');

End:          //��ͬ��ĳ��ڴ����ѷ���ʧ�ܵĿռ䶼�ͷŵ�
	if (ret != 0)
	{
		//���Ե���д��һ���ͷſռ�ĺ���
		if (myp == NULL)
		{
			return;
		}
		for (i = 0; i < tmpCount; i++)
		{
			if (myp[i] != NULL)             //�����άʱʧ�ܣ���֮ǰ�Ѿ������ڴ��ά�ռ���ͷŵ�
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
		*myp3 = myp;     //����ռ�ɹ�
	}



	return ret;
}

//�༶ָ�����Ұָ��
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