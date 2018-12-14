#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"socketClient.h"
#include"itcastLog.h"
#include"memwatch.h"

//����ĳ��̼��ܺ���
//���� void *ref, int reflen�����ǽṹ����׵�ַ�ͳ��ȴ�������Ȼ���ڼ��ܺ��������
int myEncData(unsigned char *in, int inlen, unsigned char *out, int *outlen, void *ref, int reflen)
{
	memcpy(out, "1111111111111111111", 10);
	*outlen = 10;
	return 0;
}

//��һ��api����
int main()
{
	int ret = 0;
	void *handle = NULL;
	unsigned char buf[128] = { 0 };
	int bufLen = 3;
	strcpy(buf, "safdafasfaf");

	unsigned char outBuf[128] = { 0 };
	int outBufLen = 0;
	//socket�ͻ��˻�����ʼ��
	ret = socketclient_init(&handle);
	if (ret != 0)
	{
		ret = -1;
		printf("func socketclient_init() err:%d ", ret);
		return ret;
	}

	//����2.���ü��ܺ�����ڵ�ַ
	socketclientSetEncFunc(handle, myEncData, NULL, 0);
	if (ret != 0)
	{
		ret = -5;
		printf("func socketclientSetEncFunc() err:%d ", ret);
		return ret;
	}

	//socket�ͻ��˱��ķ���
	ret = socketclient_send(handle, buf, bufLen);
	if (ret != 0)
	{
		ret = -2;
		printf("func socketclient_send() err:%d ", ret);
		return ret;
	}

	////����һ.socket�ͻ��˼��ܱ��ķ���,���ܺ���ָ������������
	//ret = socketclient_EncAndSend(handle, buf, bufLen, myEncData, NULL, 0);
	//if (ret != 0)
	//{
	//	ret = -2;
	//	printf("func socketclient_send2() err:%d ", ret);
	//	return ret;
	//}

	//socket�ͻ��˱��Ľ���
	ret = socketclient_recv(handle, outBuf, &outBufLen);
	if (ret != 0)
	{
		ret = -3;
		printf("func socketclient_recv() err:%d ", ret);
		return ret;
	}

	//socket�ͻ��˻����ͷ�
	ret = socketclient_destroy(handle);
	if (ret != 0)
	{
		ret = -4;
		printf("func socketclient_destroy() err:%d ", ret);
		return ret;
	}

	system("pause");
	return ret;
}

//�ڶ���api����
int main02()
{
	int ret = 0;
	void *handle = NULL;
	unsigned char buf[128] = { 0 };
	int bufLen = 3;
	/*unsigned char outBuf[128] = { 0 };       //�����߷����ڴ棬��˽���ʱ��buf�������ó���ָ��
	int outBufLen = 0;*/
	char *pOut = NULL;
	int pOutLen = 0;

	strcpy(buf, "safdafasfaf");

	
	//socket�ͻ��˻�����ʼ��
	ret = socketclient_init2(&handle);
	if (ret != 0)
	{
		ret = -1;
		printf("func socketclient_init2() err:%d ", ret);
		return ret;
	}

	//socket�ͻ��˱��ķ���
	ret = socketclient_send2(handle, buf, bufLen);
	if (ret != 0)
	{
		ret = -2;
		printf("func socketclient_send2() err:%d ", ret);
		return ret;
	}


	//socket�ͻ��˱��Ľ���
	ret = socketclient_recv2(handle, &pOut, &pOutLen);

	if (ret != 0)
	{
		ret = -3;
		printf("func socketclient_recv2() err:%d ", ret);
		return ret;
	}
	ret = socketclient_recv2Free(&pOut);   //����Ұָ�롣��pOut��ָ�ڴ��ͷŲ��������ΪNULL
	if (ret != 0)
	{
		ret = -4;
		printf("func socketclient_recv2Free() err:%d ", ret);
		return ret;
	}

	//socket�ͻ��˻����ͷ�
	ret = socketclient_destroy2(&handle);
	if (ret != 0)
	{
		ret = -5;
		printf("func socketclient_destroy2() err:%d ", ret);
		return ret;
	}
	system("pause");
	return ret;
}

//void ITCAST_LOG(const char *File, int line, int level, int status, const char *fmt, ...);
//int main03()
//{
//	ITCAST_LOG(__FILE__, __LINE__, LogLevel[1],0,"111111");
//
//	system("pause");
//	return 0;
//}

//int getMem(char **myp)
//{
//	char *p = NULL;
//	p = (char *)malloc(56 * sizeof(char));
//	strcpy(p, "asdadas");
//	*myp = p;
//	return 0;
//}
//void main()
//{
//	mwInit();                  //�������ڴ�й©
//	char *myp = NULL;
//	getMem(&myp);
//	//printf("%s\n", *myp);
//
//
//	mwTerm();
//	//CHECK();
//	system("pause");
//	return;
//
//}