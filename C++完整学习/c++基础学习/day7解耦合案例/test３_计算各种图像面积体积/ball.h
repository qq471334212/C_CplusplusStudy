#pragma once
#include<iostream>
#include"shape.h"
using namespace std;

class ball :public shape
{
public:
	ball() { cout << "���������޲εĹ��캯��" << endl; }
	ball(int r) { radius = r; cout << "���������вεĹ��캯��" << endl; }
	~ball() { cout << "�����������" << endl; }
	virtual float area(float r);
	virtual float vol(float r);
	void setRadius(float r) { radius = r; }
private:
	float radius;
};
