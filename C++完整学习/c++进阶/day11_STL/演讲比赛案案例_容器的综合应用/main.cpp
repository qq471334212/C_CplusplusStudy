#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include"iterator"  //�������ͷ�ļ�
#include<string>
#include<vector>
#include<list>
#include<map>
#include<set>
#include<deque>
#include<algorithm>
#include<functional>
#include<numeric>
using namespace std;

class Speaker
{
public:
	string m_name;

	int m_score[3];   //�ܹ����ֵ÷�

	
};
//����ѡ��
int GetSpeaker(map<int, Speaker> &mapSpeaker, vector<int> &v)
{
	string str = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	random_shuffle(str.begin(), str.end());
	for (int i = 0; i < 24; i++)
	{
		Speaker tmp;
		tmp.m_name = "ѡ��";
		tmp.m_name = tmp.m_name + str[i];
		mapSpeaker.insert(pair<int, Speaker>(100 + i, tmp));   //��š��Ͳ���ѡ�ֲ���
	}

	for (int i = 0; i < 24; i++)
	{
		v.push_back(100 + i);           //�Ѳ���ѡ�ֱ�ż��뵽����������
	}

	return 0;
}
//��ǩ
int speech_contest_draw(vector<int> &v)
{
	random_shuffle(v.begin(), v.end());
	return 0;
}
//����ҵ����
//��������
int speech_contest(int index, vector<int> &v1, map<int, Speaker> &mapSpeaker, vector<int> &v2)
{
	//С������÷� ��¼���� ���ǰ�����Լ� ������
	multimap<int, int, greater<int>> multimapGroup;  //С��ɼ�
	int tempCount = 1;
	//��������ѡ�ֱ�ǩ
	for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
	{
		//���
		{
			deque<int> d1;
			for (int i = 0; i < 10; i++)
			{
				int score = 50 + rand() % 50;
				d1.push_back(score);
			}
			sort(d1.begin(), d1.end());
			d1.pop_back();    //ȥ����߷�
			d1.pop_front();   //ȥ����ͷ�
			//��ƽ����
			int scoreSum = accumulate(d1.begin(), d1.end(), 0);
			int scoreAvg = scoreSum / d1.size();
			mapSpeaker[*it].m_score[index] = scoreAvg;      //�ѵ�index�ֵĵ÷ַ����Ӧ��ǩѡ�ֵĵ÷���
			multimapGroup.insert(pair<int, int>(scoreAvg, *it));
		}

		//�������
		if(tempCount%6==0)
		{
			cout << "��" << tempCount / 6 << "С������ɼ�" << endl;
			for (multimap<int, int, greater<int>>::iterator mit = multimapGroup.begin(); mit != multimapGroup.end(); mit++)
			{
				//��� ���� �÷�
				cout << mit->second << " " << mapSpeaker[mit->second].m_name << " " << mit->first << endl;
			}
			cout << endl;
			//ǰ��������
			while (multimapGroup.size() > 3)
			{
				multimap<int, int, greater<int>>::iterator mit1 = multimapGroup.begin();
				v2.push_back(mit1->second);   //��ǰ�����ŵ�  v2��������������
				multimapGroup.erase(mit1);    //ɾ��ǰ������ʣ�º�����
			}
			multimapGroup.clear();            //������С��ɼ�������һС��ʹ��
		}
		tempCount++;
	}
	return 0;
}
//�鿴�������
int speech_contest_print(int index, vector<int> &v, map<int, Speaker> &mapSpeaker)
{
	if (index != 2)
	{
		cout << "��" << index + 1 << "�ֽ�������" << endl;
		//��� ���� �÷�
		for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
		{
			cout << "������ţ�" << *it << "\t" << "ѡ��������" << mapSpeaker[*it].m_name << "\t" << "ѡ�ֵ÷֣�" << mapSpeaker[*it].m_score[index] << endl;
		}
	}
	else
	{
		cout << "����������" << endl;
		//��� ���� �÷�
		for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
		{
			cout << "������ţ�" << *it << "\t" << "ѡ��������" << mapSpeaker[*it].m_name << "\t" << "ѡ�ֵ÷֣�" << mapSpeaker[*it].m_score[index] << endl;
		}
	}
	return 0;
}
int main()
{
	//���������
	map<int, Speaker> mapSpeaker;  //����ѡ��
	vector<int>       v1;     //��һ�� �ݽ����� ����
	vector<int>       v2;     //�ڶ��� �ݽ����� ����
	vector<int>		  v3;     //���� �ݽ����� ����
	vector<int>		  v4;     //�� �ݽ����� ����

	//����ѡ�� �õ���һ��ѡ�ֲ�������
	GetSpeaker(mapSpeaker, v1);

	//��һ��ѡ�ֳ�ǩ  ѡ�ֱ���  �鿴�������
	cout << "\n\n\n�������ʼ��һ�ֱ���" << endl;
	cin.get();
	speech_contest_draw(v1);
	speech_contest(0,v1,mapSpeaker,v2);     //�ڼ��ֱ���������ѡ������v1��ѡ��mapSpeaker����һ������v2
	speech_contest_print(0, v2, mapSpeaker);
	//�ڶ���ѡ�ֳ�ǩ  ѡ�ֱ���  �鿴�������
	cout << "\n\n\n�������ʼ�ڶ��ֱ���" << endl;
	cin.get();
	speech_contest_draw(v2);
	speech_contest(1, v2, mapSpeaker, v3);    
	speech_contest_print(1, v3, mapSpeaker);
	//����ѡ�ֳ�ǩ  ѡ�ֱ���  �鿴�������
	cout << "\n\n\n�������ʼ����" << endl;
	cin.get();
	speech_contest_draw(v3);
	speech_contest(2, v3, mapSpeaker, v4);     
	speech_contest_print(2, v4, mapSpeaker);

	system("pause");
	return 0;
}