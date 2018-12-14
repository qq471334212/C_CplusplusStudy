#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


//二叉链表示法
typedef struct BitNode
{
	int data;
	struct BitNode *lchild, *rchild;   //左孩子节点和右孩子节点

}BitNode, *BiTree;

//本质！！！！
//三种遍历的递归访问节点路径都是一样的，只是访问节点的时机不一样，重点！！！！！
//先序遍历
void preOrder(BitNode *root)
{
	if (root == NULL)
	{
		return;
	}
	//遍历根节点
	printf("%d ", root->data);
	//遍历左子树
	preOrder(root->lchild);
	//遍历右子树
	preOrder(root->rchild);
}

//中序遍历
void inOrder(BitNode *root)
{
	if (root == NULL)
	{
		return;
	}
	//遍历左子树
	inOrder(root->lchild);
	//遍历根节点
	printf("%d ", root->data);
	//遍历右子树
	inOrder(root->rchild);
}

//后序遍历
void postOrder(BitNode *root)
{
	if (root == NULL)
	{
		return;
	}
	//遍历左子树
	postOrder(root->lchild);
	//遍历右子树
	postOrder(root->rchild);
	//遍历根节点
	printf("%d ", root->data);
}

int sum;          //全局变量变成参数
void countLeaf(BitNode *T)
{
	if (T)
	{
		if (T->lchild == NULL && T->rchild == NULL)
		{
			sum++;
		}
		if (T->lchild)
		{
			countLeaf(T->lchild);
		}
		if (T->rchild)
		{
			countLeaf(T->rchild);
		}
	}
}

void countLeaf2(BitNode *T,int *sum)
{
	if (T)
	{
		if (T->lchild == NULL && T->rchild == NULL)
		{
			*sum = (*sum) + 1;
		}
		if (T->lchild)
		{
			countLeaf2(T->lchild,sum);
		}
		if (T->rchild)
		{
			countLeaf2(T->rchild,sum);
		}
	}
}

void countLeaf3(BitNode *T, int *sum)
{
	if (T)
	{
		if (T->lchild)
		{
			countLeaf3(T->lchild, sum);
		}
		if (T->lchild == NULL && T->rchild == NULL)   //该判断放在前中后都可以，因为访问路径都是一样的
		{
			*sum = (*sum) + 1;
		}
		if (T->rchild)
		{
			countLeaf3(T->rchild, sum);
		}
	}
}
void main()
{
	BitNode t1, t2, t3, t4, t5;
	memset(&t1, 0, sizeof(BitNode));
	memset(&t2, 0, sizeof(BitNode));
	memset(&t3, 0, sizeof(BitNode));
	memset(&t4, 0, sizeof(BitNode));
	memset(&t5, 0, sizeof(BitNode));   //节点全部初始化，防止某个节点度小于2，造成野指针
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

	sum = 0;
	countLeaf(&t1);
	printf("叶子节点的个数：%d \n", sum);

	{
		int mysum = 0;
		countLeaf2(&t1, &mysum);
		printf("叶子节点的个数：%d \n", mysum);
	}

	{
		int mysum1 = 0;
		countLeaf3(&t1, &mysum1);
		printf("叶子节点的个数：%d ", mysum1);
	}

	////树的遍历
	//printf("先序遍历的结果 ：");
	//preOrder(&t1);
	//printf("\n");

	//printf("中序遍历的结果 ：");
	//inOrder(&t1);
	//printf("\n");

	//printf("后序遍历的结果 ：");
	//postOrder(&t1);
	//printf("\n");


	system("pause");
	return;
}
