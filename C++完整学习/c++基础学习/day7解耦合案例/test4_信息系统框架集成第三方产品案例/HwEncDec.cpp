#include<iostream>
#include"HwEncDec.h"
#include"EncryptDecrypt.h"
using namespace std;



int HwEncDec::EncData(unsigned char *plain, int plainlen, unsigned char *cryptdata, int *cryptlen)           //����plain,���ĳ���plainlen������cryptdata,���ĳ���cryptlen
{
	int ret = 0;
	//�û����ü���
	ret = DesEnc(plain, plainlen,cryptdata,cryptlen);
	if (ret != 0)
	{
		printf("fun DesEnc() err:%d \n", ret);
		return ret;
	}
	return ret;
}
int HwEncDec::DecData(unsigned char *cryptdata, int cryptlen, unsigned char *plain, int *plainlen)          //����
{
	int ret = 0;
	//�û����ý���
	ret = DesDec(cryptdata, cryptlen, plain, plainlen);
	if (ret != 0)
	{
		printf("fun DesDec() err:%d \n", ret);
		return ret;
	}
	return ret;
}