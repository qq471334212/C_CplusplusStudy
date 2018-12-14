#pragma once
#ifndef  _SOCKETCLIENT_H
#define  _SOCKETCLIENT_H

//C风格编译器接口
#ifdef __cplusplus
extern "C" {
#endif

	//定义一套协议
	//加密回调函数协议
	typedef int(*EncData)(unsigned char *in, int inlen, unsigned char *out, int *outlen, void *ref, int reflen);  	
	//解密回调函数协议
	typedef int(*DecData)(unsigned char *in, int inlen, unsigned char *out, int *outlen, void *ref, int reflen);   //ref,reflen是回调函数系数


	//第一套api函数
	//socket客户端环境初始化
	int socketclient_init(void **handle);

	//socket客户端报文发送
	int socketclient_send(void *handle, unsigned char *buf, int bufLen);

	//socket客户端加密报文发送
	int socketclient_EncAndSend(void *handle, unsigned char *buf, int bufLen, EncData encDataCallback, void *Ref, int RefLen);

	//socket客户端报文接受
	int socketclient_recv(void *handle, unsigned char *buf, int *bufLen);


	//socket客户端环境释放
	int socketclient_destroy(void *handle);

	//第二套api函数
	//socket客户端环境初始化
	int socketclient_init2(void **handle);

	//socket客户端报文发送
	int socketclient_send2(void *handle, unsigned char *buf, int bufLen);

	//socket客户端报文接受
	int socketclient_recv2(void *handle, unsigned char **buf, int *bufLen);
	int socketclient_recv2Free(unsigned char **buf);
	//socket客户端环境释放
	int socketclient_destroy2(void **handle);

	//技术点分析
	//1级指针
	//2级指针
	//封装，void **handle句柄的概念


	//实现了把上层应用加密入口地址 塞入到动态库里面
	int socketclientSetEncFunc(void *handle, EncData encDataFunc, void *enc_ref, int enc_refLen);

#ifdef __cplusplus
}
#endif

#endif