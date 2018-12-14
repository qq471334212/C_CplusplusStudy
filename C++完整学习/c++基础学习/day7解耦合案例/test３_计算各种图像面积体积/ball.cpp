#include<iostream>
#include"ball.h"
using namespace std;

float ball::area(float r)
{
	return 4 * 3.14 * r * r;
}
float ball::vol(float r)
{
	return 4 * 3.14 * r * r * r / 3;
}