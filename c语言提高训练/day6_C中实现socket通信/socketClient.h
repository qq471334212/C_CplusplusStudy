#pragma once
#ifndef  _SOCKETCLIENT_H
#define  _SOCKETCLIENT_H

//C���������ӿ�
#ifdef __cplusplus
extern "C" {
#endif

	//��һ��api����
	//socket�ͻ��˻�����ʼ��
	int socketclient_init(void **handle);

	//socket�ͻ��˱��ķ���
	int socketclient_send(void *handle, unsigned char *buf, int bufLen);

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

#ifdef __cplusplus
}
#endif

#endif