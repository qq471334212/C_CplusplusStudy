#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<map>
#include<functional>
using namespace std;

//mapԪ�ص����/����/ɾ���Ȼ�������
void mapInit()
{
	map<int, string> map1;

	//���뷽��1
	map1.insert(pair<int, string>(1, "teacher1"));
	map1.insert(pair<int, string>(2, "teacher2"));

	//���뷽��2
	map1.insert(make_pair(3, "teacher3"));

	//���뷽��3
	map1.insert(map<int, string>::value_type(4, "teacher4"));

	//���뷽��4
	map1[5] = "teacher5";          //��������

	//map����
	for (map<int, string>::iterator it = map1.begin(); it != map1.end(); it++)
	{
		cout << it->first << " " << it->second << endl;
	}

	while (!map1.empty())
	{
		map<int, string>::iterator it = map1.begin();
		cout << it->first << " " << it->second << endl;
		map1.erase(it);         //eraseɾ����λ�õ��������Զ�+1
	}
}

//��������ַ���
//ǰ���ַ��ص���pair<T1,T2>����
//�����ֲ��룬��key�Ѿ����ڣ����Ԫ�ؽ����޸�
void mapTest()
{
	map<int, string> map1;

	//���뷽��1
	pair<map<int, string>::iterator, bool> mypair1 = map1.insert(pair<int, string>(1, "teacher1"));
	map1.insert(pair<int, string>(2, "teacher2"));

	//���뷽��2
	pair<map<int, string>::iterator, bool> mypair3 = map1.insert(make_pair(3, "teacher3"));

	//���뷽��3
	pair<map<int, string>::iterator, bool> mypair4 = map1.insert(map<int, string>::value_type(4, "teacher4"));
	if (mypair4.second == true)
	{
		cout << mypair4.first->first << "  " << mypair4.first->second << endl;
	}
	else
	{
		cout << "key4����ʧ��" << endl;
	}
	pair<map<int, string>::iterator, bool> mypair5 = map1.insert(map<int, string>::value_type(4, "teacher4"));
	if (mypair5.second == true)
	{
		cout << mypair5.first->first << "  " << mypair5.first->second << endl;
	}
	else
	{
		cout << "key4����ʧ��" << endl;
	}

	//���뷽��4
	map1[5] = "teacher51";          //��������
	map1[5] = "teacher52";          //��keyΪ5�Ľ���ֵ�޸�
	map1[6] = "teacher6";

								   //map����
	for (map<int, string>::iterator it = map1.begin(); it != map1.end(); it++)
	{
		cout << it->first << " " << it->second << endl;
	}

	//����
	map<int, string>::iterator it2 = map1.find(100);
	if (it2 == map1.end())
	{
		cout << "����ʧ��" << endl;
	}
	else
	{
		cout << it2->first << " " << it2->second << endl;
	}

	//equal_range
	//�����������������γ�pair
	//��һ����������>=5��λ��
	//�ڶ����������� =5��λ��
	pair<map<int, string>::iterator, map<int, string>::iterator> mypair = map1.equal_range(5); 
	
	if (mypair.first == map1.end())
	{
		cout << "��һ��������>=5 ��λ�ò�����" << endl;
	}
	else
	{
		cout << mypair.first->first << " " << mypair.first->second << endl;
	}

	if (mypair.second == map1.end())
	{
		cout << "�ڶ���������>5 ��λ�ò�����" << endl;
	}
	else
	{
		cout << mypair.second->first << " " << mypair.second->second << endl;
	}
}



int main81()
{
	//mapInit();
	mapTest();
	system("pause");
	return 0;
}