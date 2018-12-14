#pragma once
#include<iostream>
using namespace std;

//加密接口类
class CEncryptProtocol
{
public:
	CEncryptProtocol() {}

	virtual ~CEncryptProtocol() {}
	//加密
	virtual int EncData(unsigned char *plain, int plainlen, unsigned char *cryptdata, int *cryptlen) = 0;            //明文plain,明文长度plainlen，密文cryptdata,密文长度cryptlen

																													 //解密
	virtual int DecData(unsigned char *cryptdata, int cryptlen, unsigned char *plain, int *plainlen) = 0;
};
