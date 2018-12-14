#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define API __declspec(dllexport) 

//����һ��Э��
//���ܻص�����Э��
typedef int(*EncData)(unsigned char *in, int inlen, unsigned char *out, int *outlen, void *ref, int reflen);   //ref�ǻص�����
//���ܻص�����Э��																									 
typedef int(*DecData)(unsigned char *in, int inlen, unsigned char *out, int *outlen, void *ref, int reflen);   //ref�ǻص�����

//�ײ�ṹ�壬��̬���ڲ�����������
typedef struct _SCK_HANDLE
{
	char            version[64];
	char            ip[128];
	int             port;
	unsigned char   *p;
	int             plen;

	//���ܺ�����ڵ�ַ
	EncData        encDataFunc;
	void		   *enc_ref;
	int            enc_refLen;

	//���ܺ�����ڵ�ַ
	DecData        decDataFunc;
	void		   *dec_ref;
	int            dec_refLen;
}SCK_HANDLE;
//�������͵ķ�װ




//��һ��api����
//socket�ͻ��˻�����ʼ��
//__declspec(dllexport)       //������̬�ģ��õ��ó������ʹ��
int API socketclient_init(void **handle/*out*/)
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
//__declspec(dllexport)        //������̬�ģ��õ��ó������ʹ��
//int API socketclient_send(void *handle, unsigned char *buf, int bufLen)
//{
//	int ret = 0;
//	//printf("func socketclient_init() begin \n");
//	SCK_HANDLE *hdl = NULL;
//	if (handle == NULL || buf == NULL)
//	{
//		ret = -1;
//		printf("func socketclient_send() err: %d\n (handle = NULL || buf == NULL)", ret);
//		return ret;
//	}
//
//	hdl = (SCK_HANDLE *)handle;             //�������������ݻ��浽��̬���װ������������
//	hdl->p = (unsigned char *)malloc(bufLen * sizeof(unsigned char));
//	if (hdl->p == NULL)
//	{
//		ret = -2;
//		printf("func socketclient_send() err: %d\n (unsigned char *)malloc(bufLen * sizeof(unsigned char))", ret);
//		return ret;
//	}
//	//�������ݺͳ��ȣ��ڴ�������
//	memcpy(hdl->p, buf, bufLen);       
//	hdl->plen = bufLen;
//	return ret;
//}

int API socketclient_send(void *handle, unsigned char *buf, int bufLen)
{
	int      ret = 0;
	unsigned char bufdata[4096] = { 0 };
	int      bufdatalen = 4096;
	//printf("func socketclient_init() begin \n");
	SCK_HANDLE *hdl = NULL;
	if (handle == NULL || buf == NULL)
	{
		ret = -1;
		printf("func socketclient_send() err: %d\n (handle = NULL || buf == NULL)", ret);
		return ret;
	}

	hdl = (SCK_HANDLE *)handle;             //�������������ݻ��浽��̬���װ������������

	//���ݼ���
	if (hdl->encDataFunc != NULL)
	{
		//�����Ҫ����
		ret = hdl->encDataFunc(buf, bufLen, bufdata, &bufdatalen, hdl->enc_ref, hdl->enc_refLen);
		if (ret != 0)
		{
			printf("func encDataFunc() err :%d", ret);
			return ret;
		}
		hdl->p = (unsigned char *)malloc(bufdatalen * sizeof(unsigned char));
		if (hdl->p == NULL)
		{
			ret = -2;
			printf("func socketclient_send() err: %d\n (unsigned char *)malloc(bufLen * sizeof(unsigned char))", ret);
			return ret;
		}
		//�������ݺͳ��ȣ��ڴ�������
		memcpy(hdl->p, bufdata, bufdatalen);
		hdl->plen = bufdatalen;
	}
	else
	{
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
	}

	return ret;
}

//���ûص����������ܲ�����
int API socketclient_EncAndSend(void *handle, unsigned char *buf, int bufLen, EncData encDataCallback, void *Ref, int RefLen)
{
	int            ret = 0;
	unsigned char  bufdata[4096];
	int            bufdatalen = 4096;
	//printf("func socketclient_init() begin \n");
	SCK_HANDLE *hdl = NULL;
	if (handle == NULL || buf == NULL)
	{
		ret = -1;
		printf("func socketclient_send() err: %d\n (handle = NULL || buf == NULL)", ret);
		return ret;
	}

	//�ȼ���
	if (encDataCallback != NULL)
	{
		//�ص���������
		ret = encDataCallback(buf, bufLen, bufdata, &bufdatalen, Ref, RefLen);   
		if (ret != 0)
		{
			ret = -2;
			printf("func encDataCallback() err: %d\n", ret);
			return ret;
		}
	}

	hdl = (SCK_HANDLE *)handle;             //�������������ݻ��浽��̬���װ������������
	hdl->p = (unsigned char *)malloc(bufdatalen * sizeof(unsigned char));
	if (hdl->p == NULL)
	{
		ret = -3;
		printf("func socketclient_send() err: %d\n (unsigned char *)malloc(bufLen * sizeof(unsigned char))", ret);
		return ret;
	}
	//�������ݺͳ��ȣ��ڴ�������
	memcpy(hdl->p, bufdata, bufdatalen);
	hdl->plen = bufdatalen;
	return ret;
}



//socket�ͻ��˱��Ľ���
//__declspec(dllexport)        //������̬�ģ��õ��ó������ʹ��
int API socketclient_recv(void *handle, unsigned char *buf, int *bufLen)
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
//__declspec(dllexport)        //������̬�ģ��õ��ó������ʹ��
int API socketclient_destroy(void *handle)
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
//__declspec(dllexport)
int API socketclient_init2(void **handle)
{
	return socketclient_init(handle);
}

//socket�ͻ��˱��ķ���
//__declspec(dllexport)
int API socketclient_send2(void *handle, unsigned char *buf, int bufLen)       //ʹ�������ⲿ�����ڴ�
{
	return socketclient_send(handle,buf,bufLen);
}

//socket�ͻ��˱��Ľ���
//__declspec(dllexport) 
int API socketclient_recv2(void *handle, unsigned char **buf, int *bufLen)       //��̬������ڴ沢�ͷ�
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

//__declspec(dllexport)
int API socketclient_recv2Free(unsigned char **buf)
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
//__declspec(dllexport)
int API socketclient_destroy2(void **handle)
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

int API socketclientSetEncFunc(void *handle, EncData encDataFunc, void *enc_ref, int enc_refLen)
{
	int ret = 0;
	SCK_HANDLE *sh = NULL;
	if (handle == NULL /*|| encDataFunc == NULL*/)
	{
		ret = -1;
		return ret;
	}
	//�Ѽ��ܺ�������ڵ�ַ�Լ������������
	sh = (SCK_HANDLE*)handle;
	sh->encDataFunc = encDataFunc;
	if (enc_refLen > 0)
	{
		sh->enc_refLen = enc_refLen;
		sh->enc_ref = malloc(enc_refLen);    //����ռ�
		memcpy(sh->enc_ref, enc_ref, enc_refLen);
	}

	return ret;
}