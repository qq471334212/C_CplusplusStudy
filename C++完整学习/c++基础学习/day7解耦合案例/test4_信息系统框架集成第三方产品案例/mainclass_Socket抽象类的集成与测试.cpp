#define _CRT_SECURE_NO_WARNINGS     //���strcpy��unsigned char*��ת������
#include<iostream>
#include<string>
#include"CSocketProtocol.h"
#include"CSckFactoryImp1.h"
#include"CSckFactoryImp2.h"

using namespace std;

//����������� �������
//����/���ͱ��ĺ���
int SckSendAndRev01(CSocketProtocol *sp, unsigned char *in, int inlen, unsigned char *out, int *outlen)
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
	//sp = new CSckFactoryImp1;               //�˴�������̬
	sp = new CSckFactoryImp2;
	ret = SckSendAndRev01(sp, in, inlen, out, &outlen);

	if (ret != 0)
	{
		printf("fun:SckSendAndRev() err:%d \n", ret);
		return ret;
	}

	delete sp;         //��ͨ������ָ���ͷ��������������Դ����ø������������Ҫ�������麯��


	system("pause");
	return ret;
}