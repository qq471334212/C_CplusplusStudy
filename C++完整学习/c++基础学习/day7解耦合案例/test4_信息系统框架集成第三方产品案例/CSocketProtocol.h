#pragma once    //��ֻ������һ�Σ��궨�壬��Ҫ��������
#include<iostream>
using namespace std;

//�������ӿ���
class CSocketProtocol
{
public:
	CSocketProtocol()
	{
	
	}
	//�ͻ��˳�ʼ������ȡhandles����,handles��ʾΪ�������C������Ҫʹ�ã�C++�в���Ҫ
	//int cltSocketInit(void **handles /*out*/) = 0;
	virtual int cltSocketInit( /*out*/) = 0;

	//�ͻ��˷�����
	virtual int cltSocketSend (unsigned char *buf/*in*/, int buflen/*in*/) = 0;

	//�ͻ����ձ���
	virtual int cltSocketRev(unsigned char *buf/*in*/, int *buflen/*out*/) = 0;

	//�ͻ����ͷ���Դ
	virtual int cltSocketDestory(/*in*/) = 0;

	virtual ~CSocketProtocol() {}
}; 
