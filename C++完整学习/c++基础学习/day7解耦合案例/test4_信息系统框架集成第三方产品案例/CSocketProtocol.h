#pragma once    //类只被包含一次，宏定义，重要！！！！
#include<iostream>
using namespace std;

//定义抽象接口类
class CSocketProtocol
{
public:
	CSocketProtocol()
	{
	
	}
	//客户端初始化，获取handles上下,handles表示为句柄，在C语言中要使用，C++中不需要
	//int cltSocketInit(void **handles /*out*/) = 0;
	virtual int cltSocketInit( /*out*/) = 0;

	//客户端发报文
	virtual int cltSocketSend (unsigned char *buf/*in*/, int buflen/*in*/) = 0;

	//客户端收报文
	virtual int cltSocketRev(unsigned char *buf/*in*/, int *buflen/*out*/) = 0;

	//客户端释放资源
	virtual int cltSocketDestory(/*in*/) = 0;

	virtual ~CSocketProtocol() {}
}; 
