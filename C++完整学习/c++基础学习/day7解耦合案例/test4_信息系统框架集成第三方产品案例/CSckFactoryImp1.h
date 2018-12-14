#pragma once
#include<iostream>
#include"CSocketProtocol.h"
using namespace std;

//创建厂商1
class CSckFactoryImp1:public CSocketProtocol
{
public:
	//客户端初始化
	virtual int cltSocketInit( /*out*/);

	//客户端发报文
	virtual int cltSocketSend(unsigned char *buf/*in*/, int buflen/*in*/);

	//客户端收报文
	virtual int cltSocketRev(unsigned char *buf/*in*/, int *buflen/*out*/);

	//客户端释放资源
	virtual int cltSocketDestory(/*in*/);

private:
	unsigned char *p;
	int len;
};
