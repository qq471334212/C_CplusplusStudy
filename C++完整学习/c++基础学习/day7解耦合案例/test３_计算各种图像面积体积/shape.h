#pragma once
#include<iostream>
using namespace std;

class shape
{
public:
	shape() {}
	virtual ~shape() {}
	virtual float area(float len) = 0;
	virtual float vol(float len) = 0;
};