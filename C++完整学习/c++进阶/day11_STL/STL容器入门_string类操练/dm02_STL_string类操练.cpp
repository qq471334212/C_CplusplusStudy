#define _CRT_SECURE_NO_WARNINGS
#define D_SCL_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include"algorithm"
using namespace std;

//string4�ֳ�ʼ����ʽ
void stringInit()
{
	string s1 = "aaaaaaa";
	string s2("bbbb");
	
	string s3 = s2;        //�������캯��
	string s4(10, 'a');

	cout << s1 << endl;
	cout << s2 << endl;
	cout << s3 << endl;
	cout << s4 << endl;
}

//������ʽ
void stringBianli()
{
	string s1 = "abcdefgh";
	for (size_t i = 0; i < s1.length(); i++)
	{
		cout << s1[i] << " ";
	}
	cout << endl;

	//2.������
	for (string::iterator it = s1.begin(); it < s1.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	//at(),Խ����׳��쳣,��[]�±��������ֱ���жϳ���
	try {
		for (size_t i = 0; i < s1.length() + 3; i++)
		{
			cout << s1.at(i) << " ";
		}
	}
	catch (out_of_range)
	{
		cout << "�����쳣" << endl;
	}
}

//�ַ�ָ���string��ת��
void stringChar()
{
	string s1 = "aaabbbcccddd";
	printf("s1:%s\n", s1.c_str());    //c_str��stringת��char * C���Ը�ʽ


	//����
	char buf1[128] = {0};
	s1.copy(buf1, 6, 3);             //s1��3��λ�ÿ�ʼ����6���ַ���buf1��������C����ַ���
	cout << "buf1 :" << buf1 << endl;
}

//�ַ�������
void stringCat()
{
	string s1 = "aaa";
	string s2("bbb");

	s1 = s1 + s2;
	cout << "s1 : " << s1 << endl;

	string s3 = "333";
	string s4 = "444";
	s3.append(s4);
	cout << "s3 : " << s3 << endl;
}

//�ַ����Ĳ��Һ��滻
void stingFindAndReplace()
{
	int cnt = 0;
	string s1 = "wbm hello wbm 111 wbm 222 wbm 333";
	//���ҵ�һ�γ���wbm�������±�
	//�ַ����±�Ҳ�Ǵ�0��ʼ��
	size_t index = s1.find("wbm", 0);
	cout << "index: " << index << endl;

	//ͳ��wbm���ֵĴ���
	//while (index != string::npos)    //npos��ʾ-1������λ��
	while(index<(s1.length()-3))
	{
		cout << "�ҵ�wbm���±�index: " << index << endl;
		cnt++;
		index = s1.find("wbm", index + 1);
	}
	cout << "wbm���ִ���Ϊ��" << cnt << endl;

	//�滻�ַ�
    index = s1.find("wbm", 0);
	while (index<(s1.length() - 3))
	{
		s1.replace(index, 3, "WBM");
		index = s1.find("wbm", index + 1);
	}
	cout << s1 << endl;
}

//ɾ���Ͳ���
void stringDelAndInsert()
{
	string s1 = "hello1,hello2,hello3";
	string::iterator it = find(s1.begin(), s1.end(), 'l');
	if (it != s1.end())
	{
		s1.erase(it);
	}

	cout << "ɾ��l֮��Ľ���� " << s1 <<endl;
	s1.erase(s1.begin(), s1.end());
	cout << "ɾ��ȫ���Ľ���� " << s1 << "  " << "s1�ĳ��ȣ�  " << s1.length() << endl;

	//ͷ��
	string s2 = "BBB";
	s2.insert(0, "AAA");
	cout << "s2ͷ����������� " << s2 << endl;
	s2.insert(s2.length(), "AAA");
	cout << "s2β����������� " << s2 << endl;
}

//string����㷨
void stringAlgorithm()
{
	string s1 = "shdalk";
	//1.��������ڵ�ַ 2.�������� 3.Ԥ����ĺ�������
	transform(s1.begin(), s1.end(), s1.begin(), toupper);
	cout << s1 << endl;

	string s2 = "SLAHDLKASHD";
	//1.��������ڵ�ַ 2.�������� 3.Ԥ����ĺ�������
	transform(s2.begin(), s2.end(), s2.begin(), tolower);
	cout << s2 << endl;
}


int main()
{
	//stringInit();
	//stringBianli();
	//stringChar();
	//stringCat();
	//stingFindAndReplace();
	//stringDelAndInsert();
	stringAlgorithm();
	system("pause");
	return 0;
}