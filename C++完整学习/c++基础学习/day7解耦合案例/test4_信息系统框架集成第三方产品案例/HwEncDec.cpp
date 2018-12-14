#include<iostream>
#include"HwEncDec.h"
#include"EncryptDecrypt.h"
using namespace std;



int HwEncDec::EncData(unsigned char *plain, int plainlen, unsigned char *cryptdata, int *cryptlen)           //明文plain,明文长度plainlen，密文cryptdata,密文长度cryptlen
{
	int ret = 0;
	//用户调用加密
	ret = DesEnc(plain, plainlen,cryptdata,cryptlen);
	if (ret != 0)
	{
		printf("fun DesEnc() err:%d \n", ret);
		return ret;
	}
	return ret;
}
int HwEncDec::DecData(unsigned char *cryptdata, int cryptlen, unsigned char *plain, int *plainlen)          //解密
{
	int ret = 0;
	//用户调用解密
	ret = DesDec(cryptdata, cryptlen, plain, plainlen);
	if (ret != 0)
	{
		printf("fun DesDec() err:%d \n", ret);
		return ret;
	}
	return ret;
}