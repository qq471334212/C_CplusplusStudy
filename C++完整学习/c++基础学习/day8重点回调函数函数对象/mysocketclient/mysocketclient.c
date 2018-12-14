#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define API __declspec(dllexport) 

//定义一套协议
//加密回调函数协议
typedef int(*EncData)(unsigned char *in, int inlen, unsigned char *out, int *outlen, void *ref, int reflen);   //ref是回调函数
//解密回调函数协议																									 
typedef int(*DecData)(unsigned char *in, int inlen, unsigned char *out, int *outlen, void *ref, int reflen);   //ref是回调函数

//底层结构体，动态库内部的数据类型
typedef struct _SCK_HANDLE
{
	char            version[64];
	char            ip[128];
	int             port;
	unsigned char   *p;
	int             plen;

	//加密函数入口地址
	EncData        encDataFunc;
	void		   *enc_ref;
	int            enc_refLen;

	//解密函数入口地址
	DecData        decDataFunc;
	void		   *dec_ref;
	int            dec_refLen;
}SCK_HANDLE;
//数据类型的封装




//第一套api函数
//socket客户端环境初始化
//__declspec(dllexport)       //导出动态的，让调用程序可以使用
int API socketclient_init(void **handle/*out*/)
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
//__declspec(dllexport)        //导出动态的，让调用程序可以使用
//int API socketclient_send(void *handle, unsigned char *buf, int bufLen)
//{
//	int ret = 0;
//	//printf("func socketclient_init() begin \n");
//	SCK_HANDLE *hdl = NULL;
//	if (handle == NULL || buf == NULL)
//	{
//		ret = -1;
//		printf("func socketclient_send() err: %d\n (handle = NULL || buf == NULL)", ret);
//		return ret;
//	}
//
//	hdl = (SCK_HANDLE *)handle;             //将传进来的数据缓存到动态库封装的数据类型中
//	hdl->p = (unsigned char *)malloc(bufLen * sizeof(unsigned char));
//	if (hdl->p == NULL)
//	{
//		ret = -2;
//		printf("func socketclient_send() err: %d\n (unsigned char *)malloc(bufLen * sizeof(unsigned char))", ret);
//		return ret;
//	}
//	//拷贝内容和长度，内存打包技术
//	memcpy(hdl->p, buf, bufLen);       
//	hdl->plen = bufLen;
//	return ret;
//}

int API socketclient_send(void *handle, unsigned char *buf, int bufLen)
{
	int      ret = 0;
	unsigned char bufdata[4096] = { 0 };
	int      bufdatalen = 4096;
	//printf("func socketclient_init() begin \n");
	SCK_HANDLE *hdl = NULL;
	if (handle == NULL || buf == NULL)
	{
		ret = -1;
		printf("func socketclient_send() err: %d\n (handle = NULL || buf == NULL)", ret);
		return ret;
	}

	hdl = (SCK_HANDLE *)handle;             //将传进来的数据缓存到动态库封装的数据类型中

	//数据加密
	if (hdl->encDataFunc != NULL)
	{
		//如果需要加密
		ret = hdl->encDataFunc(buf, bufLen, bufdata, &bufdatalen, hdl->enc_ref, hdl->enc_refLen);
		if (ret != 0)
		{
			printf("func encDataFunc() err :%d", ret);
			return ret;
		}
		hdl->p = (unsigned char *)malloc(bufdatalen * sizeof(unsigned char));
		if (hdl->p == NULL)
		{
			ret = -2;
			printf("func socketclient_send() err: %d\n (unsigned char *)malloc(bufLen * sizeof(unsigned char))", ret);
			return ret;
		}
		//拷贝内容和长度，内存打包技术
		memcpy(hdl->p, bufdata, bufdatalen);
		hdl->plen = bufdatalen;
	}
	else
	{
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
	}

	return ret;
}

//调用回调函数，加密并发送
int API socketclient_EncAndSend(void *handle, unsigned char *buf, int bufLen, EncData encDataCallback, void *Ref, int RefLen)
{
	int            ret = 0;
	unsigned char  bufdata[4096];
	int            bufdatalen = 4096;
	//printf("func socketclient_init() begin \n");
	SCK_HANDLE *hdl = NULL;
	if (handle == NULL || buf == NULL)
	{
		ret = -1;
		printf("func socketclient_send() err: %d\n (handle = NULL || buf == NULL)", ret);
		return ret;
	}

	//先加密
	if (encDataCallback != NULL)
	{
		//回调函数调用
		ret = encDataCallback(buf, bufLen, bufdata, &bufdatalen, Ref, RefLen);   
		if (ret != 0)
		{
			ret = -2;
			printf("func encDataCallback() err: %d\n", ret);
			return ret;
		}
	}

	hdl = (SCK_HANDLE *)handle;             //将传进来的数据缓存到动态库封装的数据类型中
	hdl->p = (unsigned char *)malloc(bufdatalen * sizeof(unsigned char));
	if (hdl->p == NULL)
	{
		ret = -3;
		printf("func socketclient_send() err: %d\n (unsigned char *)malloc(bufLen * sizeof(unsigned char))", ret);
		return ret;
	}
	//拷贝内容和长度，内存打包技术
	memcpy(hdl->p, bufdata, bufdatalen);
	hdl->plen = bufdatalen;
	return ret;
}



//socket客户端报文接受
//__declspec(dllexport)        //导出动态的，让调用程序可以使用
int API socketclient_recv(void *handle, unsigned char *buf, int *bufLen)
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
//__declspec(dllexport)        //导出动态的，让调用程序可以使用
int API socketclient_destroy(void *handle)
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
//__declspec(dllexport)
int API socketclient_init2(void **handle)
{
	return socketclient_init(handle);
}

//socket客户端报文发送
//__declspec(dllexport)
int API socketclient_send2(void *handle, unsigned char *buf, int bufLen)       //使用者在外部分配内存
{
	return socketclient_send(handle,buf,bufLen);
}

//socket客户端报文接受
//__declspec(dllexport) 
int API socketclient_recv2(void *handle, unsigned char **buf, int *bufLen)       //动态库分配内存并释放
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

//__declspec(dllexport)
int API socketclient_recv2Free(unsigned char **buf)
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
//__declspec(dllexport)
int API socketclient_destroy2(void **handle)
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

int API socketclientSetEncFunc(void *handle, EncData encDataFunc, void *enc_ref, int enc_refLen)
{
	int ret = 0;
	SCK_HANDLE *sh = NULL;
	if (handle == NULL /*|| encDataFunc == NULL*/)
	{
		ret = -1;
		return ret;
	}
	//把加密函数的入口地址以及参数缓存进来
	sh = (SCK_HANDLE*)handle;
	sh->encDataFunc = encDataFunc;
	if (enc_refLen > 0)
	{
		sh->enc_refLen = enc_refLen;
		sh->enc_ref = malloc(enc_refLen);    //分配空间
		memcpy(sh->enc_ref, enc_ref, enc_refLen);
	}

	return ret;
}