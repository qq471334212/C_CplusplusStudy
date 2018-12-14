#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;

//函数模板的本质:  类型参数化

//对字符数组 int数组进行排序
template <typename T>
int mySort(T array[], int size)
{
	int i = 0;
	int j = 0;
	T t = 0;
	if (array == NULL)
	{
		return -1;
	}
	//选择法排序
	for (i = 0; i < size; i++)
	{
		for (j = i + 1; j < size; j++)
		{
			if (array[i] > array[j])
			{
				t = array[i];
				array[i] = array[j];
				array[j] = t;
			}
		}
	}
	return 0;
}
template <typename T>
int myPrint(T array[], int size)
{
	int i = 0;
	for (i = 0; i < size; i++)
	{
		cout << array[i] << " ";
	}
	cout << endl;
	return 0;
}

int main03()
{
	{
		int ret = 0;
		int myArray[] = { 11,22,44,5,33,87,30 };
		int len;
		len = sizeof(myArray) / sizeof(*myArray);
		//ret = mySort(myArray, len);
		ret = mySort<int>(myArray, len);
		if (ret != 0)
		{
			cout << "func mySort() err: " << ret << endl;
		}
		cout << "排序之后: ";
		//myPrint(myArray, len);
		myPrint<int>(myArray, len);
	}
	cout << endl;
	{
		int ret = 0;
		char buf[] = "amsbdachahsd";
		int len;
		len = strlen(buf);
		//ret = mySort(myArray, len);
		ret = mySort<char>(buf, len);
		if (ret != 0)
		{
			cout << "func mySort() err: " << ret << endl;
		}
		cout << "排序之后: ";
		//myPrint(myArray, len);
		myPrint<char>(buf, len);
	
	}
	system("pause");
	return 0;
}