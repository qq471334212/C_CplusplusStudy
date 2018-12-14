#pragma once
#include<iostream>
#include"shape.h"
using namespace std;

class ball :public shape
{
public:
	ball() { cout << "调用球类无参的构造函数" << endl; }
	ball(int r) { radius = r; cout << "调用球类有参的构造函数" << endl; }
	~ball() { cout << "球体对象被析构" << endl; }
	virtual float area(float r);
	virtual float vol(float r);
	void setRadius(float r) { radius = r; }
private:
	float radius;
};
