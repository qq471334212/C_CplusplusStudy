#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include"iterator"  //输出流的头文件
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

	int m_score[3];   //总共三轮得分

	
};
//产生选手
int GetSpeaker(map<int, Speaker> &mapSpeaker, vector<int> &v)
{
	string str = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	random_shuffle(str.begin(), str.end());
	for (int i = 0; i < 24; i++)
	{
		Speaker tmp;
		tmp.m_name = "选手";
		tmp.m_name = tmp.m_name + str[i];
		mapSpeaker.insert(pair<int, Speaker>(100 + i, tmp));   //编号。和参赛选手插入
	}

	for (int i = 0; i < 24; i++)
	{
		v.push_back(100 + i);           //把参赛选手编号加入到参赛名单中
	}

	return 0;
}
//抽签
int speech_contest_draw(vector<int> &v)
{
	random_shuffle(v.begin(), v.end());
	return 0;
}
//核心业务函数
//比赛函数
int speech_contest(int index, vector<int> &v1, map<int, Speaker> &mapSpeaker, vector<int> &v2)
{
	//小组比赛得分 纪录下来 求出前三名以及 后三名
	multimap<int, int, greater<int>> multimapGroup;  //小组成绩
	int tempCount = 1;
	//遍历参赛选手标签
	for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
	{
		//打分
		{
			deque<int> d1;
			for (int i = 0; i < 10; i++)
			{
				int score = 50 + rand() % 50;
				d1.push_back(score);
			}
			sort(d1.begin(), d1.end());
			d1.pop_back();    //去除最高分
			d1.pop_front();   //去除最低分
			//求平均分
			int scoreSum = accumulate(d1.begin(), d1.end(), 0);
			int scoreAvg = scoreSum / d1.size();
			mapSpeaker[*it].m_score[index] = scoreAvg;      //把第index轮的得分放入对应标签选手的得分中
			multimapGroup.insert(pair<int, int>(scoreAvg, *it));
		}

		//处理分组
		if(tempCount%6==0)
		{
			cout << "第" << tempCount / 6 << "小组比赛成绩" << endl;
			for (multimap<int, int, greater<int>>::iterator mit = multimapGroup.begin(); mit != multimapGroup.end(); mit++)
			{
				//编号 姓名 得分
				cout << mit->second << " " << mapSpeaker[mit->second].m_name << " " << mit->first << endl;
			}
			cout << endl;
			//前三名晋级
			while (multimapGroup.size() > 3)
			{
				multimap<int, int, greater<int>>::iterator mit1 = multimapGroup.begin();
				v2.push_back(mit1->second);   //将前三名放到  v2容器晋级名单中
				multimapGroup.erase(mit1);    //删除前三名，剩下后三名
			}
			multimapGroup.clear();            //析构本小组成绩，供下一小组使用
		}
		tempCount++;
	}
	return 0;
}
//查看比赛结果
int speech_contest_print(int index, vector<int> &v, map<int, Speaker> &mapSpeaker)
{
	if (index != 2)
	{
		cout << "第" << index + 1 << "轮晋级名单" << endl;
		//编号 姓名 得分
		for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
		{
			cout << "参赛编号：" << *it << "\t" << "选手姓名：" << mapSpeaker[*it].m_name << "\t" << "选手得分：" << mapSpeaker[*it].m_score[index] << endl;
		}
	}
	else
	{
		cout << "决赛获奖名单" << endl;
		//编号 姓名 得分
		for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
		{
			cout << "参赛编号：" << *it << "\t" << "选手姓名：" << mapSpeaker[*it].m_name << "\t" << "选手得分：" << mapSpeaker[*it].m_score[index] << endl;
		}
	}
	return 0;
}
int main()
{
	//容器的设计
	map<int, Speaker> mapSpeaker;  //参赛选手
	vector<int>       v1;     //第一轮 演讲比赛 名单
	vector<int>       v2;     //第二轮 演讲比赛 名单
	vector<int>		  v3;     //决赛 演讲比赛 名单
	vector<int>		  v4;     //获奖 演讲比赛 名单

	//产生选手 得到第一轮选手参赛名单
	GetSpeaker(mapSpeaker, v1);

	//第一轮选手抽签  选手比赛  查看比赛结果
	cout << "\n\n\n任意键开始第一轮比赛" << endl;
	cin.get();
	speech_contest_draw(v1);
	speech_contest(0,v1,mapSpeaker,v2);     //第几轮比赛，参赛选手名单v1，选手mapSpeaker，下一轮名单v2
	speech_contest_print(0, v2, mapSpeaker);
	//第二轮选手抽签  选手比赛  查看比赛结果
	cout << "\n\n\n任意键开始第二轮比赛" << endl;
	cin.get();
	speech_contest_draw(v2);
	speech_contest(1, v2, mapSpeaker, v3);    
	speech_contest_print(1, v3, mapSpeaker);
	//决赛选手抽签  选手比赛  查看比赛结果
	cout << "\n\n\n任意键开始决赛" << endl;
	cin.get();
	speech_contest_draw(v3);
	speech_contest(2, v3, mapSpeaker, v4);     
	speech_contest_print(2, v4, mapSpeaker);

	system("pause");
	return 0;
}