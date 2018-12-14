#pragma once

template <typename T>   //实现泛型编程

class SeqList
{
public:
	SeqList(int capicity);
	~SeqList();

	//获取线性表长度
	int GetLength();

	//线性表容量
	int GetCapicity();

	//指定位置插入节点
	int myInsert(T &t, int pos);

	//获取指定位置节点
	int GetNode(int pos, T &t);           //用引用返回

	//删除置顶位置节点
	int DeleteNode(int pos, T &t);

	int clear();
private:
	int length;
	int capicity;
	T *pArray;      //unsigned int **node;        
				    //结构体套二级指针，指针数组
				    //用二级指针比较好
};

