#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//三叉链表示法,用的比较少，了解就好
typedef struct TriNode
{
	int data;
	struct TriNode *lchild, *rchild;   //左孩子节点和右孩子节点
	struct TriNode *parent;

}TriNode, *TriTree;

//二叉链表示法
typedef struct BitNode
{
	int data;
	struct BitNode *lchild, *rchild;   //左孩子节点和右孩子节点

}BitNode,*BiTree;

//双亲链表表示法
#define MAX_TREE_SIZE 100
typedef struct BPTNode
{
	int data;
	int parentPosition;      //指向双亲的指针  数组下标
	char LRTag;              //左右孩子标志域
}BPTNode;

typedef struct BPTree
{
	BPTNode nodes[100];   //节点是分散的，因此需要把节点存储在数组中
	int num_node;         //节点数目
	int root;             //根节点的位置   //注意此域存储的是父亲节点在数组中的下标
}BPTree;
void main1()
{
	BitNode t1, t2, t3, t4, t5;
	t1.data = 1;
	t2.data = 2;
	t3.data = 3;
	t4.data = 4;
	t5.data = 5;
	
	//结点间建立关系
	t1.lchild = &t2;
	t1.rchild = &t3;
	t2.lchild = &t4;
	t3.lchild = &t5;

	
	system("pause");
	return;
}

void main2()
{
	BitNode *p1, *p2, *p3, *p4, *p5;
	p1 = (BitNode *)malloc(sizeof(BitNode));
	p2 = (BitNode *)malloc(sizeof(BitNode));
	p3 = (BitNode *)malloc(sizeof(BitNode));
	p4 = (BitNode *)malloc(sizeof(BitNode));
	p5 = (BitNode *)malloc(sizeof(BitNode));

	p1->data = 1;
	p2->data = 2;
	p3->data = 3;
	p4->data = 4;
	p5->data = 5;

	//结点间建立关系
	p1->lchild = &p2;
	p1->rchild = &p3;
	p2->lchild = &p4;
	p3->lchild = &p5;

	system("pause");
	return;
}

void main3()
{
	BPTree tree;
	//根节点，可以自己定
	tree.nodes[0].parentPosition = 10000;
	tree.nodes[1].parentPosition = 0;
	tree.nodes[1].data = 'B';
	tree.nodes[1].LRTag = 1;      //左右孩子标志

	tree.nodes[1].parentPosition = 0;
	tree.nodes[1].data = 'C';
	tree.nodes[1].LRTag = 2;      //左右孩子标志

	system("pause");
	return;
}
