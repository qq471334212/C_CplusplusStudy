#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//�ײ�ṹ�壬��̬���ڲ�����������
typedef struct _SCK_HANDLE
{
	char            version[64];
	char            ip[128];
	int             port;
	unsigned char   *p;
	int             plen;
}SCK_HANDLE;
//�������͵ķ�װ


//��һ��api����
//socket�ͻ��˻�����ʼ��
__declspec(dllexport)        //������̬�ģ��õ��ó������ʹ��
int socketclient_init(void **handle/*out*/)
{
	int ret = 0;
	//printf("func socketclient_init() begin \n");
	SCK_HANDLE *hdl = NULL;
	hdl = (SCK_HANDLE*)malloc(sizeof(SCK_HANDLE));    //���ڲ���̬�����ڴ棬���ⲿ�ͷ�
	if (hdl == NULL)
	{
		ret = -1;
		printf("func socketclient_init() err: %d\n", ret);
	}
	memset(hdl, 0, sizeof(SCK_HANDLE));       //��ʼ����ָ����ָ����ڴ�ռ���0
	strcpy(hdl->ip, "196.128.6.254");
	hdl->port = 8081;
	*handle = hdl;
	return ret;
}

//socket�ͻ��˱��ķ���
__declspec(dllexport)        //������̬�ģ��õ��ó������ʹ��
int socketclient_send(void *handle, unsigned char *buf, int bufLen)
{
	int ret = 0;
	//printf("func socketclient_init() begin \n");
	SCK_HANDLE *hdl = NULL;
	if (handle == NULL || buf == NULL)
	{
		ret = -1;
		printf("func socketclient_send() err: %d\n (handle = NULL || buf == NULL)", ret);
		return ret;
	}

	hdl = (SCK_HANDLE *)handle;             //�������������ݻ��浽��̬���װ������������
	hdl->p = (unsigned char *)malloc(bufLen * sizeof(unsigned char));
	if (hdl->p == NULL)
	{
		ret = -2;
		printf("func socketclient_send() err: %d\n (unsigned char *)malloc(bufLen * sizeof(unsigned char))", ret);
		return ret;
	}
	//�������ݺͳ��ȣ��ڴ�������
	memcpy(hdl->p, buf, bufLen);       
	hdl->plen = bufLen;
	return ret;
}

//socket�ͻ��˱��Ľ���
__declspec(dllexport)        //������̬�ģ��õ��ó������ʹ��
int socketclient_recv(void *handle, unsigned char *buf, int *bufLen)
{
	int ret = 0;
	//printf("func socketclient_init() begin \n");
	SCK_HANDLE *hdl = NULL;
	if (handle == NULL || buf == NULL || bufLen == NULL)
	{
		ret = -1;
		printf("func socketclient_recv() err: %d\n (handle = NULL || buf == NULL || bufLen == NULL)", ret);
		return ret;
	}
	hdl = (SCK_HANDLE *)handle;             //�������������ݻ��浽��̬���װ������������
	//�ڴ������������Ƴ��Ⱥ�����
	memcpy(buf, hdl->p, hdl->plen);
	*bufLen = hdl->plen;

	return ret;
}

//socket�ͻ��˻����ͷ�
__declspec(dllexport)        //������̬�ģ��õ��ó������ʹ��
int socketclient_destroy(void *handle)
{
	int ret = 0;
	//printf("func socketclient_init() begin \n");
	SCK_HANDLE *hdl = NULL;

	if (handle == NULL)
	{
		ret = -1;
		printf("func socketclient_destroy() err: %d (handle == NULL)\n", ret);
	}

	hdl = (SCK_HANDLE *)handle;
	if (hdl->p)
	{
		free(hdl->p);
	}
	free(hdl);
	return 0;
}



//�ڶ���api����
//socket�ͻ��˻�����ʼ��
__declspec(dllexport)
int socketclient_init2(void **handle)
{
	return socketclient_init(handle);
}

//socket�ͻ��˱��ķ���
__declspec(dllexport)
int socketclient_send2(void *handle, unsigned char *buf, int bufLen)       //ʹ�������ⲿ�����ڴ�
{
	return socketclient_send(handle,buf,bufLen);
}

//socket�ͻ��˱��Ľ���
__declspec(dllexport) 
int socketclient_recv2(void *handle, unsigned char **buf, int *bufLen)       //��̬������ڴ沢�ͷ�
{
	int        ret = 0;
	//printf("func socketclient_init() begin \n");
	SCK_HANDLE *hdl = NULL;
	unsigned char  *tmp = NULL;
	if (handle == NULL || buf == NULL || bufLen == NULL)
	{
		ret = -1;
		printf("func socketclient_recv() err: %d\n (handle = NULL || buf == NULL || bufLen == NULL)", ret);
		return ret;
	}
	hdl = (SCK_HANDLE *)handle;             //�������������ݻ��浽��̬���װ������������
											//�ڴ������������Ƴ��Ⱥ�����

	tmp = (unsigned char*)malloc(hdl->plen * sizeof(unsigned char));
	if (tmp == NULL)
	{
		ret = -1;
		printf("func socketclient_recv() err: %d\n (tmp == NULL)", ret);
		return ret;
	}
	memcpy(tmp, hdl->p, hdl->plen);
	*bufLen = hdl->plen;    //��Ӹ�ֵ
	*buf = tmp;

	return ret;
}

__declspec(dllexport)
int socketclient_recv2Free(unsigned char **buf)
{
	if (buf == NULL)
	{
		return -1;
	}
	if (*buf != NULL)
	{
		free(*buf);
	}
	*buf = NULL;       //*ʵ�εĵ�ַ��ȥ����޸�ʵ�ε�ֵ�����³�ʼ��
	return 0;
}

//socket�ͻ��˻����ͷ�
__declspec(dllexport)
int socketclient_destroy2(void **handle)
{
	SCK_HANDLE *tmp = NULL;
	if (handle == NULL)
	{
		return -1;
	}
	tmp = *handle;
	if (tmp != NULL)
	{
		if (tmp->p)
		{
			free(tmp->p);
		}
		free(tmp);
	}
	*handle = NULL;
	return 0;
}