#define _CRT_SECURE_NO_WARNINGS     //解决strcpy对unsigned char*的转换问题
#include<iostream>
#include<string>
#include"CSocketProtocol.h"
#include"CSckFactoryImp1.h"
#include"CSckFactoryImp2.h"

#include"CEncryptProtocol.h"
#include"HwEncDec.h"
using namespace std;

//面向抽象类编程 建立框架 这个是借口层
//接受/发送报文函数
int SckSendAndRev(CSocketProtocol *sp, unsigned char *in, int inlen, unsigned char *out, int *outlen)
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

//发送加解密
int SckSendAndRev_EncDec(CSocketProtocol *sp, CEncryptProtocol *ed, unsigned char *in, int inlen, unsigned char *out, int *outlen)
{
	int ret = 0;
	unsigned char data[4096];
	int datalen = 0;
	ret = sp->cltSocketInit();            //发生多态
	if (ret != 0)
	{
		goto End;
	}

	ret = ed->EncData(in, inlen, data, &datalen);  //发送数据前先进行加密
	if (ret != 0)
	{
		goto End;
	}

	ret = sp->cltSocketSend(data, datalen);  //发生多态
	if (ret != 0)
	{
		goto End;
	}


	ret = sp->cltSocketRev(data, &datalen); //发生多态  

	if (ret != 0)
	{
		goto End;
	}
	//接收到的数据需要解密
	ret = ed->DecData(data, datalen, out, outlen);
	if (ret != 0)
	{
		goto End;
	}
End:
	ret = sp->cltSocketDestory();        //发生多态
	return 0;
}
int main2()
{
	int ret = 0;
	unsigned char in[4096];
	int inlen;
	unsigned char out[4096];
	int outlen = 0;

	strcpy((char *)in, "aaddddddaaaaaaaaaaaaa");
	inlen = 9;
	CSocketProtocol *sp = NULL;

	CEncryptProtocol *ed = NULL;
	ed = new HwEncDec;
	//sp = new CSckFactoryImp1;               //此处发生多态
	sp = new CSckFactoryImp2;
	ret = SckSendAndRev_EncDec(sp, ed, in, inlen, out, &outlen);

	if (ret != 0)
	{
		printf("fun:SckSendAndRev() err:%d \n", ret);
		return ret;
	}

	delete sp;         //想通过父类指针释放所有子类对象资源，则该父类的析构函数要声明了虚函数


	system("pause");
	return ret;
}