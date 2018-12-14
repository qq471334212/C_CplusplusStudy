#include<iostream>
#include<list>                 //链表容器头文件名字
#include<algorithm>
using namespace std;

struct Node
{
	int a;
	char c;

	Node(int d, char e)        //结构体构造函数
	{
		a = d;
		c = e;
	}

	bool operator==(const Node &f)   //const很重要，没有的话会报错
	{
		if (f.a == this->a&&f.c == this->c)
		{
			return true;
		}
		return false;
	}

	bool operator<(const Node &f)   //const很重要，没有的话会报错
	{
		if (f.a > this->a)   //从小到大排序
		{
			return true;
		}
		return false;
	}
};

void fun(Node &d)
{
	cout << d.a << "  " << d.c << endl;   //(int)d.c 将字符强制转换为整形
}
//void listDefine()
//{
//	list<Node> lt;
//	list<Node> lt1(5);
//	Node no(12, 'a');
//	list<Node> lt2(6,no);
//
//	list<Node> lt3(lt2.begin(), lt2.end());
//	
//	list<Node>::iterator ite = lt2.begin();
//	ite++;
//	//ite + 2; //错误，跟数组不一样是不连续的空间
//
//	for_each(lt3.begin(), lt3.end(), fun);
//}

//void listSize()
//{
//	
//	//Node no(12, 'a');
//	list<Node> lt3(6, Node(12,'a'));
//
//	lt3.resize(4);
//	cout << lt3.empty() << endl;
//	cout << lt3.size() << endl;
//	for_each(lt3.begin(), lt3.end(), fun);
//}
void listPrintAdd()
{
	Node no(12, 'a');
	list<Node> ls(6, no);

	///*for (list<Node>::iterator ite = ls.begin(); ite != ls.end(); ite++)
	//{
	//	cout << ite->a << " " << ite->c << endl;
	//}*/

	//cout << ls.back().a << endl;
	//cout << ls.front().c << endl;

	list<Node> lt;
	//Node no = { 12,'a' };

	
	lt.push_front(Node(12, 'a'));
	lt.push_back(Node(13, 'a'));
	lt.push_front(Node(14, 'a'));

	list<Node>::iterator ite = lt.begin();
	list<Node>::iterator ite1 = ls.begin();
	ite++;

	//lt.insert(ite, Node(15, 'a'));
	//lt.insert(ite, 3, Node(15, 'd'));
	lt.insert(ite,ite1,ls.end());
	for_each(lt.begin(), lt.end(), fun);
}

void listDelete()
{

	list<Node> lt;

	

	lt.push_front(Node(12, 'a'));
	lt.push_front(Node(13, 'b'));
	lt.push_front(Node(14, 'c'));
	lt.push_front(Node(14, 'c'));
	lt.push_front(Node(15, 'd'));
	lt.push_front(Node(16, 'e'));

	//lt.pop_back();    //尾删除
	//lt.pop_front();   //头删除

	list<Node> lt1;
	lt1 = lt;
	lt1.push_front(Node(17, 'f'));
	list<Node>::iterator ite1 = lt1.begin();
	ite1++;
	ite1++;

	//lt.erase(ite);
	//lt.erase(--lt.end());   //最后一个
	//lt.erase(ite, --lt.end()); //最后一个是不删除的
	//lt.clear();
	//lt.remove(Node(14, 'c'));        //要判断两个结构体是否相等
	lt.unique();           //删除相连在一起的重复元素

	//lt.assign(3,Node(2,'c'));
	//lt.assign(ite1,(lt1.begin(),lt1.end()));
	lt.assign(ite1, lt1.end());
	for_each(lt.begin(), lt.end(), fun);
}

void listDo()
{
	list<Node> lt;

	lt.push_front(Node(12, 'a'));
	lt.push_front(Node(15, 'd'));
	lt.push_front(Node(16, 'e'));
	lt.push_front(Node(13, 'b'));
	lt.push_front(Node(14, 'c'));

	list<Node>::iterator ite = find(lt.begin(), lt.end(), Node(12, 'f'));   //返回节点的迭代器
	cout << ite->a << endl;
	
	/*lt.sort();
	for_each(lt.begin(), lt.end(), fun);*/

	/*cout << endl;

	list<Node> ls;
	ls.push_front(Node(17, 'e'));
	ls.push_front(Node(13, 'c'));
	ls.push_front(Node(10, 'd'));

	ls.merge(lt);

	for_each(ls.begin(), ls.end(), fun);*/

	//list<Node> ls1;
	
	//ls1.push_back(Node(123, 'a'));

	//ls1.swap(lt);
	
	//for_each(lt.begin(), lt.end(), fun);

	//lt.reverse();
	//lt.sort();                //重载运算符

	//for_each(lt.begin(), lt.end(), fun);
}

int main1()
{
	//listSize();
	//listDefine();
	//listPrintAdd();
	//listDelete();
	listDo();

	system("pause");
	return 0;
}