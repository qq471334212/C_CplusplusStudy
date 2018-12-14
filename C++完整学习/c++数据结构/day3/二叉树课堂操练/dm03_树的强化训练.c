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


void countLeaf2(BitNode *T, int *sum)
{
	if (T)
	{
		if (T->lchild == NULL && T->rchild == NULL)
		{
			*sum = (*sum) + 1;
		}
		if (T->lchild)
		{
			countLeaf2(T->lchild, sum);
		}
		if (T->rchild)
		{
			countLeaf2(T->rchild, sum);
		}
	}
}

int Depth(BitNode *T)
{
	int depthValue = 0;
	int depthLeft = 0;
	int depthRight = 0;
	if (T == NULL)
	{
		return depthValue;
	}
	
	depthLeft = Depth(T->lchild);   //求左子树的高度

	depthRight = Depth(T->rchild);  //求右子树的高度

	depthValue = 1 + ((depthLeft > depthRight) ? depthLeft : depthRight);
	return depthValue;
}
BitNode *copyTree(BitNode *T)
{
	BitNode *newNode = NULL;
	BitNode *newLp = NULL;
	BitNode *newRp = NULL;

	if (T == NULL)
	{
		return NULL;
	}

	if (T->lchild != NULL)
	{
		newLp = copyTree(T->lchild);    //copy左子树
	}
	else
	{
		newLp = NULL;
	}

	if (T->rchild != NULL)
	{
		newRp = copyTree(T->rchild);    //copy左子树
	}
	else
	{
		newRp = NULL;
	}

	//创建内存空间
	newNode = (BitNode *)malloc(sizeof(BitNode));
	if (newNode == NULL)
	{
		return NULL;
	}
	newNode->lchild = newLp;
	newNode->rchild = newRp;
	//赋值数据
	newNode->data = T->data;
	return newNode;
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

	{
		int mysum = 0;
		countLeaf2(&t1, &mysum);
		printf("叶子节点的个数：%d \n", mysum);
	}

	printf("树的高度为：%d\n",Depth(&t1));

	//树的中序遍历
	printf("inOrder old:");
	inOrder(&t1);
	printf("\n");

	{
		//拷贝树
		BitNode *root = copyTree(&t1);
		printf("inOrder new:");
		inOrder(root);
	}

	system("pause");
	return;
}
