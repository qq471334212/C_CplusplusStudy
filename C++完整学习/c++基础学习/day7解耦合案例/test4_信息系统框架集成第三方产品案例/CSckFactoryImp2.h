#pragma once
#include<iostream>
#include"CSocketProtocol.h"
using namespace std;

//��������1
class CSckFactoryImp2 :public CSocketProtocol
{
public:
	//�ͻ��˳�ʼ��
	virtual int cltSocketInit( /*out*/);

	//�ͻ��˷�����
	virtual int cltSocketSend(unsigned char *buf/*in*/, int buflen/*in*/);

	//�ͻ����ձ���
	virtual int cltSocketRev(unsigned char *buf/*in*/, int *buflen/*out*/);

	//�ͻ����ͷ���Դ
	virtual int cltSocketDestory(/*in*/);

private:
	unsigned char *p;
	int len;
};
