#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include"dm04_myComplex.cpp"
using namespace std;


int main()
{
	Complex<int>  c1(1, 2);
	Complex<int>  c2(3, 4);
	Complex<int>  c3 = c1 + c2;
	//{
	//	Complex<int> c4 = c1 - c2;
	//	cout << c4;
	//}

	{
		Complex<int> c5(5,6);
		cin >> c5;
		cout << c5;
	}
	//不要滥用友元函数
	/*{
		Complex<int> c5 = Mysub<int>(c1, c2);
		cout << c5;
	}*/
	cout << c3;
	system("pause");
	return 0;
}