#include<iostream>
#include<string>
#include<vector>    //vector向量容器头文件
#include<functional>
#include<algorithm>
using namespace std;

//vector成员函数一般都使用迭代器，不适用[]下标运算符
void STLDefine()
{
	struct STU
	{
		int age;
	};
	vector<int> vet;
}

void STLConstructer()
{
	vector<int> vet;
	//cout << vet << endl;       //无法输出
	vector<int> vet1(5);
	vector<int> vet2(5, 34);
	vector<int> vet3(vet2);
	vector<int>::iterator ite = vet2.begin();  //是有参数列表的，利用迭代器初始化。
	vector<int>::iterator ite1 = vet2.end();
	vector<int> vet4(ite, ite1);
	for (int i = 0; i < 5; i++)
	{
		cout << vet4[i] << endl;
	}
}

void STLcapacity()
{
	vector<int> vet;
	//cout << vet.capacity() << endl;

	cout << vet.empty() << endl;

	vector<int> vet1(5,12);    //初始容量有自己设定
	cout << vet1.empty() << endl;

	//cout << vet1.capacity() << endl;   //容量5
	//vet1.push_back(1);       //增加一个元素
	//cout << vet1.capacity() << endl;   //容量7
	//vet1.push_back(1);       //增加一个元素 //容量7
	//cout << vet1.capacity() << endl;
	//vet1.push_back(1);       //增加一个元素

	//vet1.reserve(10);
	//cout << vet1.size() << endl;
	//
	//vet1.resize(11);
	//cout << vet1.size() << endl;
	//cout << vet1.capacity() << endl;   //容量变为10
}
void fun(int i)
{
	cout << i << endl;
}

void STLADD()
{
	vector<int> vet;
	vector<int> vet1(5,1);
	/*for (int i = 0; i < 10; i++)
	{
		vet.push_back(i);
	}*/
	//cout << (vet > vet1) << endl;

	//vet.insert(vet.begin() + 2, 12);
	//vet.insert(vet.begin() + 2,5 ,12);
	//vet.insert(vet.begin(),vet1.begin(), vet1.begin()+3);  //插入vet1的前三个
	
	vet.push_back(2);
	vet.push_back(1);
	vet.push_back(4);
	vet.push_back(5);
	vet.push_back(3);

	//sort(vet.begin() + 2, vet.end());
	sort(vet.begin() + 2, vet.end(),greater<int>());

	/*vet.pop_back();
	vet.erase(vet.begin() + 3);
	vet.erase(vet.begin() + 3, vet.begin()+6);

	vet.swap(vet1);*/
	for_each(vet.begin(), vet.end(), fun);	

}

void STLDO()
{
	vector<int> vet;
	for (int i = 0; i < 10; i++)
	{
		vet.push_back(i);
	}

	vector<int>::iterator ite = vet.begin();

	for (ite; ite != vet.end(); ite++)
	{
		//cout << vet[i] << endl;
		cout << *ite << endl;
	}

	for_each(vet.begin(), vet.end(),fun);

	//for (int i = 0; i < 10; i++)
	//{
	//	//cout << vet[i] << endl;
	//	cout << vet.at(i) << endl;
	//}

	//cout << vet.back();
}


int main()
{
	//STLDefine();
	//STLConstructer();
	//STLcapacity();
	//STLDO();
	STLADD();


	system("pause");
	return 0;
}