#pragma once
#include<iostream>
using namespace std;

//���ܽӿ���
class CEncryptProtocol
{
public:
	CEncryptProtocol() {}

	virtual ~CEncryptProtocol() {}
	//����
	virtual int EncData(unsigned char *plain, int plainlen, unsigned char *cryptdata, int *cryptlen) = 0;            //����plain,���ĳ���plainlen������cryptdata,���ĳ���cryptlen

																													 //����
	virtual int DecData(unsigned char *cryptdata, int cryptlen, unsigned char *plain, int *plainlen) = 0;
};
