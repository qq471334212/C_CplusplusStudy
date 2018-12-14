#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//底层结构体，动态库内部的数据类型
typedef struct _SCK_HANDLE
{
	char            version[64];
	char            ip[128];
	int             port;
	unsigned char   *p;
	int             plen;
}SCK_HANDLE;
//数据类型的封装


//第一套api函数
//socket客户端环境初始化
__declspec(dllexport)        //导出动态的，让调用程序可以使用
int socketclient_init(void **handle/*out*/)
{
	int ret = 0;
	//printf("func socketclient_init() begin \n");
	SCK_HANDLE *hdl = NULL;
	hdl = (SCK_HANDLE*)malloc(sizeof(SCK_HANDLE));    //在内部动态申请内存，在外部释放
	if (hdl == NULL)
	{
		ret = -1;
		printf("func socketclient_init() err: %d\n", ret);
	}
	memset(hdl, 0, sizeof(SCK_HANDLE));       //初始化把指针所指向的内存空间置0
	strcpy(hdl->ip, "196.128.6.254");
	hdl->port = 8081;
	*handle = hdl;
	return ret;
}

//socket客户端报文发送
__declspec(dllexport)        //导出动态的，让调用程序可以使用
int socketclient_send(void *handle, unsigned char *buf, int bufLen)
{
	int ret = 0;
	//printf("func socketclient_init() begin \n");
	SCK_HANDLE *hdl = NULL;
	if (handle == NULL || buf == NULL)
	{
		ret = -1;
		printf("func socketclient_send() err: %d\n (handle = NULL || buf == NULL)", ret);
		return ret;
	}

	hdl = (SCK_HANDLE *)handle;             //将传进来的数据缓存到动态库封装的数据类型中
	hdl->p = (unsigned char *)malloc(bufLen * sizeof(unsigned char));
	if (hdl->p == NULL)
	{
		ret = -2;
		printf("func socketclient_send() err: %d\n (unsigned char *)malloc(bufLen * sizeof(unsigned char))", ret);
		return ret;
	}
	//拷贝内容和长度，内存打包技术
	memcpy(hdl->p, buf, bufLen);       
	hdl->plen = bufLen;
	return ret;
}

//socket客户端报文接受
__declspec(dllexport)        //导出动态的，让调用程序可以使用
int socketclient_recv(void *handle, unsigned char *buf, int *bufLen)
{
	int ret = 0;
	//printf("func socketclient_init() begin \n");
	SCK_HANDLE *hdl = NULL;
	if (handle == NULL || buf == NULL || bufLen == NULL)
	{
		ret = -1;
		printf("func socketclient_recv() err: %d\n (handle = NULL || buf == NULL || bufLen == NULL)", ret);
		return ret;
	}
	hdl = (SCK_HANDLE *)handle;             //将传进来的数据缓存到动态库封装的数据类型中
	//内存打包技术，复制长度和内容
	memcpy(buf, hdl->p, hdl->plen);
	*bufLen = hdl->plen;

	return ret;
}

//socket客户端环境释放
__declspec(dllexport)        //导出动态的，让调用程序可以使用
int socketclient_destroy(void *handle)
{
	int ret = 0;
	//printf("func socketclient_init() begin \n");
	SCK_HANDLE *hdl = NULL;

	if (handle == NULL)
	{
		ret = -1;
		printf("func socketclient_destroy() err: %d (handle == NULL)\n", ret);
	}

	hdl = (SCK_HANDLE *)handle;
	if (hdl->p)
	{
		free(hdl->p);
	}
	free(hdl);
	return 0;
}



//第二套api函数
//socket客户端环境初始化
__declspec(dllexport)
int socketclient_init2(void **handle)
{
	return socketclient_init(handle);
}

//socket客户端报文发送
__declspec(dllexport)
int socketclient_send2(void *handle, unsigned char *buf, int bufLen)       //使用者在外部分配内存
{
	return socketclient_send(handle,buf,bufLen);
}

//socket客户端报文接受
__declspec(dllexport) 
int socketclient_recv2(void *handle, unsigned char **buf, int *bufLen)       //动态库分配内存并释放
{
	int        ret = 0;
	//printf("func socketclient_init() begin \n");
	SCK_HANDLE *hdl = NULL;
	unsigned char  *tmp = NULL;
	if (handle == NULL || buf == NULL || bufLen == NULL)
	{
		ret = -1;
		printf("func socketclient_recv() err: %d\n (handle = NULL || buf == NULL || bufLen == NULL)", ret);
		return ret;
	}
	hdl = (SCK_HANDLE *)handle;             //将传进来的数据缓存到动态库封装的数据类型中
											//内存打包技术，复制长度和内容

	tmp = (unsigned char*)malloc(hdl->plen * sizeof(unsigned char));
	if (tmp == NULL)
	{
		ret = -1;
		printf("func socketclient_recv() err: %d\n (tmp == NULL)", ret);
		return ret;
	}
	memcpy(tmp, hdl->p, hdl->plen);
	*bufLen = hdl->plen;    //间接赋值
	*buf = tmp;

	return ret;
}

__declspec(dllexport)
int socketclient_recv2Free(unsigned char **buf)
{
	if (buf == NULL)
	{
		return -1;
	}
	if (*buf != NULL)
	{
		free(*buf);
	}
	*buf = NULL;       //*实参的地址，去间接修改实参的值，重新初始化
	return 0;
}

//socket客户端环境释放
__declspec(dllexport)
int socketclient_destroy2(void **handle)
{
	SCK_HANDLE *tmp = NULL;
	if (handle == NULL)
	{
		return -1;
	}
	tmp = *handle;
	if (tmp != NULL)
	{
		if (tmp->p)
		{
			free(tmp->p);
		}
		free(tmp);
	}
	*handle = NULL;
	return 0;
}