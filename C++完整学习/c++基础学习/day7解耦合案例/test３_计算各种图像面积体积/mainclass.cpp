#include<iostream>
#include"shape.h"
#include"ball.h"
#include"cube.h"
using namespace std;

void display(shape *s,float r)
{
	cout << s->area(r) << "  " << s->vol(r) << endl;
}

int main()
{
	shape * myShape = NULL;

	myShape = new ball;

	cout << "球形的面积和体积为：" <<endl;
	display(myShape, 5);
	delete myShape;

	cout << endl;
	myShape = new cube;

	cout << "正方体的面积和体积为：" << endl;
	display(myShape, 5);

	delete myShape;
	system("pause");
	return 0;
}