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

	cout << "���ε���������Ϊ��" <<endl;
	display(myShape, 5);
	delete myShape;

	cout << endl;
	myShape = new cube;

	cout << "���������������Ϊ��" << endl;
	display(myShape, 5);

	delete myShape;
	system("pause");
	return 0;
}