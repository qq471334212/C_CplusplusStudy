#pragma once
#include<iostream>
#include"shape.h"
using namespace std;

class cube:public shape
{
public:
	cube() { cout << "�����������޲εĹ��캯��" << endl; }
	cube(int l) { len = l; cout << "�����������вεĹ��캯��" << endl; }
	~cube() { cout << "�������������" << endl; }
	virtual float area(float len);
	virtual float vol(float len);
	void setLen(float l) { len = l; }
private:
	float len;
};