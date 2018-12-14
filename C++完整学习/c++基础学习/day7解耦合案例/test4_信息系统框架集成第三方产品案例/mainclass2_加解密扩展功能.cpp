#define _CRT_SECURE_NO_WARNINGS     //���strcpy��unsigned char*��ת������
#include<iostream>
#include<string>
#include"CSocketProtocol.h"
#include"CSckFactoryImp1.h"
#include"CSckFactoryImp2.h"

#include"CEncryptProtocol.h"
#include"HwEncDec.h"
using namespace std;

//����������� ������� ����ǽ�ڲ�
//����/���ͱ��ĺ���
int SckSendAndRev(CSocketProtocol *sp, unsigned char *in, int inlen, unsigned char *out, int *outlen)
{
	int ret = 0;
	ret = sp->cltSocketInit();            //������̬
	if (ret != 0)
	{
		goto End;
	}

	ret = sp->cltSocketSend(in, inlen);  //������̬
	if (ret != 0)
	{
		goto End;
	}

	ret = sp->cltSocketRev(out, outlen); //������̬
	if (ret != 0)
	{
		goto End;
	}
End:
	ret = sp->cltSocketDestory();        //������̬
	return 0;
}

//���ͼӽ���
int SckSendAndRev_EncDec(CSocketProtocol *sp, CEncryptProtocol *ed, unsigned char *in, int inlen, unsigned char *out, int *outlen)
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
	//sp = new CSckFactoryImp1;               //�˴�������̬
	sp = new CSckFactoryImp2;
	ret = SckSendAndRev_EncDec(sp, ed, in, inlen, out, &outlen);

	if (ret != 0)
	{
		printf("fun:SckSendAndRev() err:%d \n", ret);
		return ret;
	}

	delete sp;         //��ͨ������ָ���ͷ��������������Դ����ø������������Ҫ�������麯��


	system("pause");
	return ret;
}