#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"socketClient.h"
#include"itcastLog.h"
#include"memwatch.h"

//假设的厂商加密函数
//参数 void *ref, int reflen可以是结构体的首地址和长度传进来，然后在加密函数里调用
int myEncData(unsigned char *in, int inlen, unsigned char *out, int *outlen, void *ref, int reflen)
{
	memcpy(out, "1111111111111111111", 10);
	*outlen = 10;
	return 0;
}

//第一套api调用
int main()
{
	int ret = 0;
	void *handle = NULL;
	unsigned char buf[128] = { 0 };
	int bufLen = 3;
	strcpy(buf, "safdafasfaf");

	unsigned char outBuf[128] = { 0 };
	int outBufLen = 0;
	//socket客户端环境初始化
	ret = socketclient_init(&handle);
	if (ret != 0)
	{
		ret = -1;
		printf("func socketclient_init() err:%d ", ret);
		return ret;
	}

	//方法2.设置加密函数入口地址
	socketclientSetEncFunc(handle, myEncData, NULL, 0);
	if (ret != 0)
	{
		ret = -5;
		printf("func socketclientSetEncFunc() err:%d ", ret);
		return ret;
	}

	//socket客户端报文发送
	ret = socketclient_send(handle, buf, bufLen);
	if (ret != 0)
	{
		ret = -2;
		printf("func socketclient_send() err:%d ", ret);
		return ret;
	}

	////方法一.socket客户端加密报文发送,加密函数指针做函数参数
	//ret = socketclient_EncAndSend(handle, buf, bufLen, myEncData, NULL, 0);
	//if (ret != 0)
	//{
	//	ret = -2;
	//	printf("func socketclient_send2() err:%d ", ret);
	//	return ret;
	//}

	//socket客户端报文接受
	ret = socketclient_recv(handle, outBuf, &outBufLen);
	if (ret != 0)
	{
		ret = -3;
		printf("func socketclient_recv() err:%d ", ret);
		return ret;
	}

	//socket客户端环境释放
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

//第二套api调用
int main02()
{
	int ret = 0;
	void *handle = NULL;
	unsigned char buf[128] = { 0 };
	int bufLen = 3;
	/*unsigned char outBuf[128] = { 0 };       //调用者分配内存，因此接收时的buf不能再用常量指针
	int outBufLen = 0;*/
	char *pOut = NULL;
	int pOutLen = 0;

	strcpy(buf, "safdafasfaf");

	
	//socket客户端环境初始化
	ret = socketclient_init2(&handle);
	if (ret != 0)
	{
		ret = -1;
		printf("func socketclient_init2() err:%d ", ret);
		return ret;
	}

	//socket客户端报文发送
	ret = socketclient_send2(handle, buf, bufLen);
	if (ret != 0)
	{
		ret = -2;
		printf("func socketclient_send2() err:%d ", ret);
		return ret;
	}


	//socket客户端报文接受
	ret = socketclient_recv2(handle, &pOut, &pOutLen);

	if (ret != 0)
	{
		ret = -3;
		printf("func socketclient_recv2() err:%d ", ret);
		return ret;
	}
	ret = socketclient_recv2Free(&pOut);   //避免野指针。把pOut所指内存释放并把其变量为NULL
	if (ret != 0)
	{
		ret = -4;
		printf("func socketclient_recv2Free() err:%d ", ret);
		return ret;
	}

	//socket客户端环境释放
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
//	mwInit();                  //检查代码内存泄漏
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