#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"des.h"

//定义接口，文件传送
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
	fp2 = fopen(pFile2, "wb");   //wb不存在会新建
	if (fp2 == NULL)
	{
		ret = -2;
		goto End;
	}

	while (!feof(fp1))
	{
		plainLen = fread(plain, 1, 4096, fp1);     	//!!!!!!!!!!!!!!!!!!
		                                            //fread(plain, 1, 4096, fp1)这样使用。
		                                            //返回值才是在文件fp1中读了几个字节

		//plianLen = fread(plain, 4096, 1, fp1);      //fread(plain, 4096, 1, fp1);
		                                            //返回值为，返回1表示读取了4096字节
		                                            //返回0表示读取数量小于4096字节
	
		if (feof(fp1))     //判断，如果读完数据文件结束，则跳出循环
		{
			break;
		}
		//加密等于4K的数据
		ret = DesEnc(plain, plainLen, cryptbuf, &cryptLen);
		if (ret != 0)
		{
			ret = -3;
			printf("func DesEnc() err : %d", ret);
			return ret;
		}

		//大文件继续读，每次搬运4K大小
		cryptLen2 = fwrite(cryptbuf, 1, cryptLen, fp2);   //根据返回值判断是否全部写入fp2
		if (cryptLen2 != cryptLen)
		{
			ret = -4;
			printf("写密文失败，fp2内存不够，请检查是否磁盘已满！\n");
			goto End;
		}
	}
	//加密小于4K的数据，不满4K的时候，在实际工程中会调用DesEnc_raw函数（padding）
	ret = DesEnc(plain, plainLen, cryptbuf, &cryptLen);
	if (ret != 0)
	{
		ret = -3;
		printf("func DesEnc() err : %d", ret);
		return ret;
	}

	cryptLen2 = fwrite(cryptbuf, 1, cryptLen, fp2);   //根据返回值判断是否全部写入fp2
	if (cryptLen2 != cryptLen)
	{
		ret = -4;
		printf("写密文失败，fp2内存不够，请检查是否磁盘已满！\n");
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
	fp2 = fopen(pFile2, "wb");   //wb不存在会新建
	if (fp2 == NULL)
	{
		ret = -2;
		goto End;
	}

	while (!feof(fp1))
	{
		cryptLen = fread(cryptbuf, 1, 4096, fp1);     	//!!!!!!!!!!!!!!!!!!
													//fread(plain, 1, 4096, fp1)这样使用。
													//返回值才是在文件fp1中读了几个字节

													//plianLen = fread(plain, 4096, 1, fp1);      //fread(plain, 4096, 1, fp1);
													//返回值为，返回1表示读取了4096字节
													//返回0表示读取数量小于4096字节

		if (feof(fp1))     //判断，如果读完数据文件结束，则跳出循环
		{
			break;
		}
		//加密等于4K的数据
		ret = DesDec(cryptbuf, cryptLen, plain, &plainLen);
		if (ret != 0)
		{
			ret = -3;
			printf("func DesDec() err : %d", ret);
			return ret;
		}

		//大文件继续读，每次搬运4K大小
		plainLen2 = fwrite(plain, 1, plainLen, fp2);   //根据返回值判断是否全部写入fp2
		if (plainLen2 != plainLen)
		{
			ret = -4;
			printf("写解密文失败，fp2内存不够，请检查是否磁盘已满！\n");
			goto End;
		}
	}
	//加密小于4K的数据，不满4K的时候，在实际工程中会调用DesEnc_raw函数（padding）
	ret = DesDec(cryptbuf, cryptLen, plain, &plainLen);
	if (ret != 0)
	{
		ret = -3;
		printf("func DesDec() err : %d", ret);
		return ret;
	}

	plainLen2 = fwrite(plain, 1, plainLen, fp2);   //根据返回值判断是否全部写入fp2
	if (plainLen2 != plainLen)
	{
		ret = -4;
		printf("写解密文失败，fp2内存不够，请检查是否磁盘已满！\n");
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