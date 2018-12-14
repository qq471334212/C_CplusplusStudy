#define _CRT_SECURE_NO_WARNINGS     //解决strcpy对unsigned char*的转换问题
#include<iostream>
#include<string>
#include"CSocketProtocol.h"
#include"CSckFactoryImp1.h"
#include"CSckFactoryImp2.h"

using namespace std;

//面向抽象类编程 建立框架
//接受/发送报文函数
int SckSendAndRev01(CSocketProtocol *sp, unsigned char *in, int inlen, unsigned char *out, int *outlen)
{
	int ret = 0;
	ret = sp->cltSocketInit();            //发生多态
	if (ret != 0)
	{
		goto End;
	}

	ret = sp->cltSocketSend(in, inlen);  //发生多态
	if (ret != 0)
	{
		goto End;
	}

	ret = sp->cltSocketRev(out, outlen); //发生多态
	if (ret != 0)
	{
		goto End;
	}
End:
	ret = sp->cltSocketDestory();        //发生多态
	return 0;
}

int main01()
{
	int ret = 0;
	unsigned char in[4096];
	int inlen;
	unsigned char out[4096];
	int outlen = 0;

	strcpy((char *)in, "aaddddddaaaaaaa");
	inlen =16;
	CSocketProtocol *sp = NULL;
	//sp = new CSckFactoryImp1;               //此处发生多态
	sp = new CSckFactoryImp2;
	ret = SckSendAndRev01(sp, in, inlen, out, &outlen);

	if (ret != 0)
	{
		printf("fun:SckSendAndRev() err:%d \n", ret);
		return ret;
	}

	delete sp;         //想通过父类指针释放所有子类对象资源，则该父类的析构函数要声明了虚函数


	system("pause");
	return ret;
}