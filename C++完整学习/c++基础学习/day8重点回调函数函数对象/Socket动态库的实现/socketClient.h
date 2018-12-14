#pragma once
#ifndef  _SOCKETCLIENT_H
#define  _SOCKETCLIENT_H

//C���������ӿ�
#ifdef __cplusplus
extern "C" {
#endif

	//����һ��Э��
	//���ܻص�����Э��
	typedef int(*EncData)(unsigned char *in, int inlen, unsigned char *out, int *outlen, void *ref, int reflen);  	
	//���ܻص�����Э��
	typedef int(*DecData)(unsigned char *in, int inlen, unsigned char *out, int *outlen, void *ref, int reflen);   //ref,reflen�ǻص�����ϵ��


	//��һ��api����
	//socket�ͻ��˻�����ʼ��
	int socketclient_init(void **handle);

	//socket�ͻ��˱��ķ���
	int socketclient_send(void *handle, unsigned char *buf, int bufLen);

	//socket�ͻ��˼��ܱ��ķ���
	int socketclient_EncAndSend(void *handle, unsigned char *buf, int bufLen, EncData encDataCallback, void *Ref, int RefLen);

	//socket�ͻ��˱��Ľ���
	int socketclient_recv(void *handle, unsigned char *buf, int *bufLen);


	//socket�ͻ��˻����ͷ�
	int socketclient_destroy(void *handle);

	//�ڶ���api����
	//socket�ͻ��˻�����ʼ��
	int socketclient_init2(void **handle);

	//socket�ͻ��˱��ķ���
	int socketclient_send2(void *handle, unsigned char *buf, int bufLen);

	//socket�ͻ��˱��Ľ���
	int socketclient_recv2(void *handle, unsigned char **buf, int *bufLen);
	int socketclient_recv2Free(unsigned char **buf);
	//socket�ͻ��˻����ͷ�
	int socketclient_destroy2(void **handle);

	//���������
	//1��ָ��
	//2��ָ��
	//��װ��void **handle����ĸ���


	//ʵ���˰��ϲ�Ӧ�ü�����ڵ�ַ ���뵽��̬������
	int socketclientSetEncFunc(void *handle, EncData encDataFunc, void *enc_ref, int enc_refLen);

#ifdef __cplusplus
}
#endif

#endif