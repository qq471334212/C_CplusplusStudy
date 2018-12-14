#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;

template<typename T>
class Complex
{
	//friend Complex Mysub <T>(Complex &c1, Complex &c2);
	friend ostream& operator<< <T> (ostream &out, Complex &c);
	friend istream& operator>> <T> (istream &in,  Complex &c);

public:
	Complex(T a, T b);
	void printCom();
	//÷ÿ‘ÿ∏¥ ˝+∫≈
	Complex operator+(Complex &c);
	Complex operator-(Complex &c);

private:
	T a;
	T b;
};