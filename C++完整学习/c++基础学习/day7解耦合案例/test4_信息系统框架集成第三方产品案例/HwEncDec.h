#pragma once
#include<iostream>
#include"CEncryptProtocol.h"
using namespace std;

//���ܽӿ���
class HwEncDec:public CEncryptProtocol
{
public:
	HwEncDec() {}

	~HwEncDec() {}
	//����
	virtual int EncData(unsigned char *plain, int plainlen, unsigned char *cryptdata, int *cryptlen);            //����plain,���ĳ���plainlen������cryptdata,���ĳ���cryptlen
																													 //����
	virtual int DecData(unsigned char *cryptdata, int cryptlen, unsigned char *plain, int *plainlen);
	
}; 
