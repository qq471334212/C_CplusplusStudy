#pragma once
//在插入元素时，在摸板类中应该每一个T保存下来
//摸板类中应该能分配节点 缓存节点 ==》 思想很重

//怎么样缓存 ===》 linklist 做链表

template <typename T>   //实现泛型编程
struct Node
{
	T t;
	Node<T> *next;
	//Node<T> *pre;    //开发双向链表

};

template <typename T>   //实现泛型编程

class LinkList
{
public:
	LinkList();
	~LinkList();

	//清除链式表数据
	int clear();

	//获取链式表长度
	int getlen();

	//指定位置插入节点
	int Insert(T &t, int pos);

	//获取指定位置节点
	int Get(int pos, T &t);

	//删除置顶位置节点
	int Del(int pos, T &t);
private:
	Node<T> *head;    //链表的头节点
	int len;
};

