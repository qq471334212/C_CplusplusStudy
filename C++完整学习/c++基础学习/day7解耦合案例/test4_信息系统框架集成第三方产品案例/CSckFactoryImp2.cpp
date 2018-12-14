#include<iostream>
#include"CSckFactoryImp2.h"
using namespace std;

//客户端初始化
int CSckFactoryImp2::cltSocketInit( /*out*/)
{
	p = NULL;
	len = 0;
	return 0;
}

//客户端发报文
int CSckFactoryImp2::cltSocketSend(unsigned char *buf/*in*/, int buflen/*in*/)
{
	p = (unsigned char *)malloc(sizeof(unsigned char) * buflen);   //给内存分配空间
	if (p == NULL)
	{
		return -1;
	}
	memcpy(p, buf, buflen);   //对厂商属性赋值
	len = buflen;
	return 0;
}
//客户端收报文
int CSckFactoryImp2::cltSocketRev(unsigned char *buf/*in*/, int *buflen/*out*/)
{
	if (buf == NULL || buflen == NULL)
	{
		return -1;
	}
	*buflen = this->len;
	memcpy(buf, this->p, this->len);
	return 0;
}
//客户端释放资源
int CSckFactoryImp2::cltSocketDestory(/*in*/)
{
	if (p != NULL)
	{
		free(p);
		p = NULL;
		len = 0;
	}
	return 0;
}