#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"des.h"

//����ӿڣ��ļ�����
int FileSymEnc(const char *pFile1/*in*/, const char *pFile2/*out*/)
{
	int ret = 0;
	unsigned char plain[4096] = { 0 };
	int plainLen;
	int plainLen2 ;

	unsigned char cryptbuf[4096] = { 0 };
	int cryptLen = 0;
	int cryptLen2 = 0;
	FILE *fp1 = NULL, *fp2 = NULL;
	fp1 = fopen(pFile1, "rb");
	if (fp1 == NULL)
	{
		ret = -1;
		goto End;
	}
	fp2 = fopen(pFile2, "wb");   //wb�����ڻ��½�
	if (fp2 == NULL)
	{
		ret = -2;
		goto End;
	}

	while (!feof(fp1))
	{
		plainLen = fread(plain, 1, 4096, fp1);     	//!!!!!!!!!!!!!!!!!!
		                                            //fread(plain, 1, 4096, fp1)����ʹ�á�
		                                            //����ֵ�������ļ�fp1�ж��˼����ֽ�

		//plianLen = fread(plain, 4096, 1, fp1);      //fread(plain, 4096, 1, fp1);
		                                            //����ֵΪ������1��ʾ��ȡ��4096�ֽ�
		                                            //����0��ʾ��ȡ����С��4096�ֽ�
	
		if (feof(fp1))     //�жϣ�������������ļ�������������ѭ��
		{
			break;
		}
		//���ܵ���4K������
		ret = DesEnc(plain, plainLen, cryptbuf, &cryptLen);
		if (ret != 0)
		{
			ret = -3;
			printf("func DesEnc() err : %d", ret);
			return ret;
		}

		//���ļ���������ÿ�ΰ���4K��С
		cryptLen2 = fwrite(cryptbuf, 1, cryptLen, fp2);   //���ݷ���ֵ�ж��Ƿ�ȫ��д��fp2
		if (cryptLen2 != cryptLen)
		{
			ret = -4;
			printf("д����ʧ�ܣ�fp2�ڴ治���������Ƿ����������\n");
			goto End;
		}
	}
	//����С��4K�����ݣ�����4K��ʱ����ʵ�ʹ����л����DesEnc_raw������padding��
	ret = DesEnc(plain, plainLen, cryptbuf, &cryptLen);
	if (ret != 0)
	{
		ret = -3;
		printf("func DesEnc() err : %d", ret);
		return ret;
	}

	cryptLen2 = fwrite(cryptbuf, 1, cryptLen, fp2);   //���ݷ���ֵ�ж��Ƿ�ȫ��д��fp2
	if (cryptLen2 != cryptLen)
	{
		ret = -4;
		printf("д����ʧ�ܣ�fp2�ڴ治���������Ƿ����������\n");
		goto End;
	}

End:
	if (fp1 != NULL)
	{
		fclose(fp1);
	}
	if (fp2 != NULL)
	{
		fclose(fp2);
	}
	return ret;
}


void main_enc ()
{
	int ret = 0;
	const char *file1 = "E:/22.txt";
	const char *file2 = "E:/22enc.txt";

	ret = FileSymEnc(file1, file2);
	if (ret != 0)
	{
		printf("func FileSymEnc() err\n");
	}

	return;
}

int FileSymEnc(const char *pFile1/*in*/, const char *pFile2/*out*/)
{
	int ret = 0;
	unsigned char plain[4096] = { 0 };
	int plainLen = 0;
	int plainLen2 = 0;

	unsigned char cryptbuf[4096] = { 0 };
	int cryptLen = 0;
	int cryptLen2 = 0;
	FILE *fp1 = NULL, *fp2 = NULL;
	fp1 = fopen(pFile1, "rb");
	if (fp1 == NULL)
	{
		ret = -1;
		goto End;
	}
	fp2 = fopen(pFile2, "wb");   //wb�����ڻ��½�
	if (fp2 == NULL)
	{
		ret = -2;
		goto End;
	}

	while (!feof(fp1))
	{
		cryptLen = fread(cryptbuf, 1, 4096, fp1);     	//!!!!!!!!!!!!!!!!!!
													//fread(plain, 1, 4096, fp1)����ʹ�á�
													//����ֵ�������ļ�fp1�ж��˼����ֽ�

													//plianLen = fread(plain, 4096, 1, fp1);      //fread(plain, 4096, 1, fp1);
													//����ֵΪ������1��ʾ��ȡ��4096�ֽ�
													//����0��ʾ��ȡ����С��4096�ֽ�

		if (feof(fp1))     //�жϣ�������������ļ�������������ѭ��
		{
			break;
		}
		//���ܵ���4K������
		ret = DesDec(cryptbuf, cryptLen, plain, &plainLen);
		if (ret != 0)
		{
			ret = -3;
			printf("func DesDec() err : %d", ret);
			return ret;
		}

		//���ļ���������ÿ�ΰ���4K��С
		plainLen2 = fwrite(plain, 1, plainLen, fp2);   //���ݷ���ֵ�ж��Ƿ�ȫ��д��fp2
		if (plainLen2 != plainLen)
		{
			ret = -4;
			printf("д������ʧ�ܣ�fp2�ڴ治���������Ƿ����������\n");
			goto End;
		}
	}
	//����С��4K�����ݣ�����4K��ʱ����ʵ�ʹ����л����DesEnc_raw������padding��
	ret = DesDec(cryptbuf, cryptLen, plain, &plainLen);
	if (ret != 0)
	{
		ret = -3;
		printf("func DesDec() err : %d", ret);
		return ret;
	}

	plainLen2 = fwrite(plain, 1, plainLen, fp2);   //���ݷ���ֵ�ж��Ƿ�ȫ��д��fp2
	if (plainLen2 != plainLen)
	{
		ret = -4;
		printf("д������ʧ�ܣ�fp2�ڴ治���������Ƿ����������\n");
		goto End;
	}

End:
	if (fp1 != NULL)
	{
		fclose(fp1);
	}
	if (fp2 != NULL)
	{
		fclose(fp2);
	}
	return ret;
}

void main_enc()
{
	int ret = 0;
	const char *file1 = "E:/22enc.txt";
	const char *file2 = "E:/22dec.txt";

	ret = FileSymDec(file1, file2);
	if (ret != 0)
	{
		printf("func FileSymEnc() err\n");
	}

	return;
}

void main()
{
	//main_enc();
	main_dec();
	system("pause");
	return;
}