#define _CRT_SECURE_NO_WARNINGS     //���strcpy��unsigned char*��ת������
#include<iostream>
#include<string>
#include"CSocketProtocol.h"
#include"CSckFactoryImp1.h"
#include"CSckFactoryImp2.h"

#include"CEncryptProtocol.h"
#include"HwEncDec.h"
using namespace std;

//�������ڶ�̳��е�Ӧ��
/*
class MainOp :public CSocketProtocol, public CEncryptProtocol
{
public:

};
*/

//c++�������ӿ��ࡣC��������ʹ�ýӿں�����ʵ��
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
	//��һ���ӿڣ�ע��
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
		ret = sp->cltSocketInit();            //������̬
		if (ret != 0)
		{
			goto End;
		}

		ret = ed->EncData(in, inlen, data, &datalen);  //��������ǰ�Ƚ��м���
		if (ret != 0)
		{
			goto End;
		}

		ret = sp->cltSocketSend(data, datalen);  //������̬
		if (ret != 0)
		{
			goto End;
		}


		ret = sp->cltSocketRev(data, &datalen); //������̬  

		if (ret != 0)
		{
			goto End;
		}
		//���յ���������Ҫ����
		ret = ed->DecData(data, datalen, out, outlen);
		if (ret != 0)
		{
			goto End;
		}
	End:
		ret = sp->cltSocketDestory();        //������̬
		return 0;
	}
     
	//֧�ֺ�������,ʹ�ó�Ա���ԣ�*sp��*ed
	int SckSendAndRev_EncDec3(unsigned char *in, int inlen, unsigned char *out, int *outlen)
	{
		int ret = 0;
		unsigned char data[4096];
		int datalen = 0;
		ret = this->sp->cltSocketInit();            //ʹ�����Ա
		if (ret != 0)
		{
			goto End;
		}
		printf("�ͻ���������ǰ��%s \n", in);
		ret = this->ed->EncData(in, inlen, data, &datalen);  //��������ǰ�Ƚ��м���
		if (ret != 0)
		{
			goto End;
		}

		ret = this->sp->cltSocketSend(data, datalen);  //������̬
		if (ret != 0)
		{
			goto End;
		}


		ret = this->sp->cltSocketRev(data, &datalen); //������̬  

		if (ret != 0)
		{
			goto End;
		}
		//���յ���������Ҫ����
		ret = this->ed->DecData(data, datalen, out, outlen);
		if (ret != 0)
		{
			goto End;
		}
		printf("�ͻ����������%s", out);
	End:
		ret = this->sp->cltSocketDestory();        
		return 0;
	}

private:
	CSocketProtocol  *sp;            //���Ա���ԣ���һ��Socket���Ժ�һ�����ܽ��ܵ�Socket����
	CEncryptProtocol *ed;
};

//����������� ������� ����ǽ�ڲ�
//���ͼӽ���
//int SckSendAndRev_EncDec3(CSocketProtocol *sp, CEncryptProtocol *ed, unsigned char *in, int inlen, unsigned char *out, int *outlen)
//{
//	int ret = 0;
//	unsigned char data[4096];
//	int datalen = 0;
//	ret = sp->cltSocketInit();            //������̬
//	if (ret != 0)
//	{
//		goto End;
//	}
//
//	ret = ed->EncData(in, inlen, data, &datalen);  //��������ǰ�Ƚ��м���
//	if (ret != 0)
//	{
//		goto End;
//	}
//
//	ret = sp->cltSocketSend(data, datalen);  //������̬
//	if (ret != 0)
//	{
//		goto End;
//	}
//
//
//	ret = sp->cltSocketRev(data, &datalen); //������̬  
//
//	if (ret != 0)
//	{
//		goto End;
//	}
//	//���յ���������Ҫ����
//	ret = ed->DecData(data, datalen, out, outlen);
//	if (ret != 0)
//	{
//		goto End;
//	}
//End:
//	ret = sp->cltSocketDestory();        //������̬
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
	//sp = new CSckFactoryImp1;               //�˴�������̬
	sp = new CSckFactoryImp2;

	myMainOp->setEd(ed);           //�����������̣����ܳ��̺�socket����
	myMainOp->setSp(sp);

	ret = myMainOp->SckSendAndRev_EncDec3(in, inlen, out, &outlen);
	if (ret != 0)
	{
		printf("myMainOp SckSendAndRev_EncDec3() err: %d\n", ret);
	}

	delete ed;
	delete sp;         //��ͨ������ָ���ͷ��������������Դ����ø������������Ҫ�������麯��
	delete myMainOp;

	system("pause");
	return ret;
}