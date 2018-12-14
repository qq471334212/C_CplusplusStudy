#pragma once
#include<iostream>
#include"shape.h"
using namespace std;

class cube:public shape
{
public:
	cube() { cout << "调用正方体无参的构造函数" << endl; }
	cube(int l) { len = l; cout << "调用正方体有参的构造函数" << endl; }
	~cube() { cout << "正方体对象被析构" << endl; }
	virtual float area(float len);
	virtual float vol(float len);
	void setLen(float l) { len = l; }
private:
	float len;
};