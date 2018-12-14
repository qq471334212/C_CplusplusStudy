#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//��������ʾ��,�õıȽ��٣��˽�ͺ�
typedef struct TriNode
{
	int data;
	struct TriNode *lchild, *rchild;   //���ӽڵ���Һ��ӽڵ�
	struct TriNode *parent;

}TriNode, *TriTree;

//��������ʾ��
typedef struct BitNode
{
	int data;
	struct BitNode *lchild, *rchild;   //���ӽڵ���Һ��ӽڵ�

}BitNode,*BiTree;

//˫�������ʾ��
#define MAX_TREE_SIZE 100
typedef struct BPTNode
{
	int data;
	int parentPosition;      //ָ��˫�׵�ָ��  �����±�
	char LRTag;              //���Һ��ӱ�־��
}BPTNode;

typedef struct BPTree
{
	BPTNode nodes[100];   //�ڵ��Ƿ�ɢ�ģ������Ҫ�ѽڵ�洢��������
	int num_node;         //�ڵ���Ŀ
	int root;             //���ڵ��λ��   //ע�����洢���Ǹ��׽ڵ��������е��±�
}BPTree;
void main1()
{
	BitNode t1, t2, t3, t4, t5;
	t1.data = 1;
	t2.data = 2;
	t3.data = 3;
	t4.data = 4;
	t5.data = 5;
	
	//���佨����ϵ
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

	//���佨����ϵ
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
	//���ڵ㣬�����Լ���
	tree.nodes[0].parentPosition = 10000;
	tree.nodes[1].parentPosition = 0;
	tree.nodes[1].data = 'B';
	tree.nodes[1].LRTag = 1;      //���Һ��ӱ�־

	tree.nodes[1].parentPosition = 0;
	tree.nodes[1].data = 'C';
	tree.nodes[1].LRTag = 2;      //���Һ��ӱ�־

	system("pause");
	return;
}
