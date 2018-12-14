#define _CRT_SECURE_NO_WARNINGS     //解决strcpy对unsigned char*的转换问题
#include<iostream>
#include<string>
#include"CSocketProtocol.h"
#include"CSckFactoryImp1.h"
#include"CSckFactoryImp2.h"

#include"CEncryptProtocol.h"
#include"HwEncDec.h"
using namespace std;

//抽象类在多继承中的应用
/*
class MainOp :public CSocketProtocol, public CEncryptProtocol
{
public:

};
*/

//c++用类做接口类。C语言则是使用接口函数来实现
class MainOp
{
public:
	MainOp()
	{
		this->ed = NULL;
		this->sp = NULL;
	}
	MainOp(CSocketProtocol *sp, CEncryptProtocol *ed)
	{
		this->ed = ed;
		this->sp = sp;
	}
	//留一个接口，注入
	void setSp(CSocketProtocol *sp)
	{
		this->sp = sp;
	}
	void setEd(CEncryptProtocol *ed)
	{
		this->ed = ed;
	}

public:
	int SckSendAndRev_EncDec3(CSocketProtocol *sp, CEncryptProtocol *ed, unsigned char *in, int inlen, unsigned char *out, int *outlen)
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
     
	//支持函数重载,使用成员属性，*sp，*ed
	int SckSendAndRev_EncDec3(unsigned char *in, int inlen, unsigned char *out, int *outlen)
	{
		int ret = 0;
		unsigned char data[4096];
		int datalen = 0;
		ret = this->sp->cltSocketInit();            //使用类成员
		if (ret != 0)
		{
			goto End;
		}
		printf("客户加密输入前：%s \n", in);
		ret = this->ed->EncData(in, inlen, data, &datalen);  //发送数据前先进行加密
		if (ret != 0)
		{
			goto End;
		}

		ret = this->sp->cltSocketSend(data, datalen);  //发生多态
		if (ret != 0)
		{
			goto End;
		}


		ret = this->sp->cltSocketRev(data, &datalen); //发生多态  

		if (ret != 0)
		{
			goto End;
		}
		//接收到的数据需要解密
		ret = this->ed->DecData(data, datalen, out, outlen);
		if (ret != 0)
		{
			goto End;
		}
		printf("客户解密输出后：%s", out);
	End:
		ret = this->sp->cltSocketDestory();        
		return 0;
	}

private:
	CSocketProtocol  *sp;            //类成员属性，有一个Socket属性和一个加密解密的Socket属性
	CEncryptProtocol *ed;
};

//面向抽象类编程 建立框架 这个是借口层
//发送加解密
//int SckSendAndRev_EncDec3(CSocketProtocol *sp, CEncryptProtocol *ed, unsigned char *in, int inlen, unsigned char *out, int *outlen)
//{
//	int ret = 0;
//	unsigned char data[4096];
//	int datalen = 0;
//	ret = sp->cltSocketInit();            //发生多态
//	if (ret != 0)
//	{
//		goto End;
//	}
//
//	ret = ed->EncData(in, inlen, data, &datalen);  //发送数据前先进行加密
//	if (ret != 0)
//	{
//		goto End;
//	}
//
//	ret = sp->cltSocketSend(data, datalen);  //发生多态
//	if (ret != 0)
//	{
//		goto End;
//	}
//
//
//	ret = sp->cltSocketRev(data, &datalen); //发生多态  
//
//	if (ret != 0)
//	{
//		goto End;
//	}
//	//接收到的数据需要解密
//	ret = ed->DecData(data, datalen, out, outlen);
//	if (ret != 0)
//	{
//		goto End;
//	}
//End:
//	ret = sp->cltSocketDestory();        //发生多态
//	return 0;
//}
int main()
{
	int ret = 0;
	unsigned char in[4096];
	int inlen;
	unsigned char out[4096];
	int outlen = 0;

	strcpy((char *)in, "aaddddddaaaaaaa");
	inlen = 16;

	MainOp *myMainOp = new MainOp;
	CSocketProtocol *sp = NULL;
	CEncryptProtocol *ed = NULL;
	ed = new HwEncDec;
	//sp = new CSckFactoryImp1;               //此处发生多态
	sp = new CSckFactoryImp2;

	myMainOp->setEd(ed);           //设置两个厂商，加密厂商和socket厂商
	myMainOp->setSp(sp);

	ret = myMainOp->SckSendAndRev_EncDec3(in, inlen, out, &outlen);
	if (ret != 0)
	{
		printf("myMainOp SckSendAndRev_EncDec3() err: %d\n", ret);
	}

	delete ed;
	delete sp;         //想通过父类指针释放所有子类对象资源，则该父类的析构函数要声明了虚函数
	delete myMainOp;

	system("pause");
	return ret;
}