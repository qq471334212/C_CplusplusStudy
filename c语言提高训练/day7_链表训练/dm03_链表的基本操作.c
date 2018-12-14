#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//有局限性，不能包含所有要用的结构体
typedef  struct Node
{
	int data;
	struct Node *next;
}SLIST;

//解决方法
//1.定义一个作链表功能的结构体
typedef struct myNode
{
	struct myNode *next;
}myNode;
//2.定义存储业务数据的结构体去包含链表
typedef struct Teacher
{
	char name[64];
	int  age;
	myNode node;      //链表地址与大的结构体地址偏移量为64+4=68
}Teacher;

//3.优化企业链表，让小链表的地址与大的结构体的地址重叠
typedef struct Teacher1
{
	myNode node;
	char name[64];
	int  age;
}Teacher1;

void testMynode()
{
	Teacher t1, t2, t3;
	t1.node.next = &(t2.node);
	t2.node.next = &(t3.node);
	t3.node.next = NULL;
}

//链表api
SLIST * SList_Creat();   //创建链表
int SList_Print(SLIST *pHead);    //遍历打印链表
int SList_NodeInsert(SLIST *pHead, int x, int y);   //在x值之前 插入y值
int SList_NodeDelete(SLIST *pHead, int x);   //删除节点
int SList_Destroy(SLIST *pHead);   //销毁链表

SLIST * SList_Creat()   
{
	//1.不断接受输入，malloc新节点，-1为结束
	//2.新节点入链表
	//3.让新节点变成当前节点，引入三个指针变量pHead，pCurrent，pM
	int data = 0;
	SLIST *pHead, *pCur, *pTmp;

	//创建头节点
	pHead = (SLIST *)malloc(sizeof(SLIST));
	if (pHead == NULL)
	{
		return NULL;
	}
	pHead->data = 0;
	pHead->next = NULL;

	printf("please enter you data: ");
	scanf("%d", &data);

	pCur = pHead;               //当前节点初始化，指向开头

	while (data != -1)
	{
		//创建业务节点
		pTmp = (SLIST *)malloc(sizeof(SLIST));
		if (pTmp == NULL)
		{
			return NULL;
		}
		pTmp->data = data;
		pTmp->next = NULL;     //保证尾节点为null

		pCur->next = pTmp;     //新节点入链表
		pCur = pTmp;           //把当前节点移到下一个节点，链表节点尾部追加

		printf("please enter you next data: ");
		scanf("%d", &data);
	}
	return pHead;              //导出头节点地址
}


int SList_Creat2(SLIST **mypHead)
{
	//1.不断接受输入，malloc新节点，-1为结束
	//2.新节点入链表
	//3.让新节点变成当前节点，引入三个指针变量pHead，pCurrent，pM
	int ret = 0;
	int data = 0;
	SLIST *pHead, *pCur, *pTmp;

	//创建头节点
	pHead = (SLIST *)malloc(sizeof(SLIST));
	if (pHead == NULL)
	{
		ret = -1;
		printf("func SList_Creat2() err: %d", ret);
		goto End;
	}
	pHead->data = 0;
	pHead->next = NULL;

	printf("please enter you data: ");
	scanf("%d", &data);

	pCur = pHead;               //当前节点初始化，指向开头

	while (data != -1)
	{
		//创建业务节点
		pTmp = (SLIST *)malloc(sizeof(SLIST));
		if (pTmp == NULL)
		{
			ret = -2;
			printf("func malloc() err: %d", ret);
			goto End;
		}
		pTmp->data = data;
		pTmp->next = NULL;     //保证尾节点为null

		pCur->next = pTmp;     //新节点入链表
		pCur = pTmp;           //把当前节点移到下一个节点，链表节点尾部追加

		printf("please enter you next data: ");
		scanf("%d", &data);
	}

End:
	if (ret != 0)
	{
		SList_Destroy(pHead);
	}
	else
	{
		*mypHead = pHead;
	}
	return ret;              //导出头节点地址
}

int SList_Print(SLIST *pHead)    
{
	if (pHead == NULL)
	{
		return -1;
	}
	SLIST *pTmp = NULL;
	pTmp = pHead->next;
	printf("\nbegin \n");
	while (pTmp)
	{
		printf("%d\n", pTmp->data);
		pTmp = pTmp->next;
	}
	printf("\nend \n");
	return 0;
}

//单向链表插入时注意当前节点的位置保存在前驱节点的位置中
//因此插入应该先连后面，再连前面，否则前面的next中保存的节点位置被新节点占据
int SList_NodeInsert(SLIST *pHead, int x, int y)   
{
	int iTag = 0;
	SLIST *pCur = NULL, *pTmp = NULL, *pPre = NULL;
	if (pHead == NULL)
	{
		return -1;
	}

	//创建业务节点
	pTmp = (SLIST *)malloc(sizeof(SLIST));
	if (pTmp == NULL)
	{
		return -2;
	}
	pTmp->next = NULL;
	pTmp->data = y;

	pPre = pHead;               //当前节点初始化，指向开头
	pCur = pHead->next;
	while (pCur)
	{
		if (pCur->data == x)
		{	
			iTag = 1;
			break;
		}
	
		pPre = pCur;
		pCur = pCur->next;
	
	}
	//新节点链接前后节点
	pTmp->next = pPre->next;          //没有找到要插入的位置的话pCur为NULL，也符合要求
	pPre->next = pTmp;
	if (iTag == 1)
	{
		printf("\n成功插入节点！！\n");
	
	}
	else
	{
		printf("\n没有找到要插入的节点！！\n");
	}
	return 0;
}

int SList_NodeDelete(SLIST *pHead, int x)
{
	int iTag = 0;
	SLIST *pCur = NULL, *pPre = NULL;
	if (pHead == NULL)
	{
		return -1;
	}

	pPre = pHead;               //当前节点初始化，指向开头
	pCur = pHead->next;
	while (pCur)
	{
		if (pCur->data == x)
		{
			iTag = 1; 		
			break;
		}

		pPre = pCur;
		pCur = pCur->next;
	}
	

	if (iTag == 1)
	{
		//删除操作
		pPre->next = pCur->next;
		if (pCur != NULL)
		{
			free(pCur);
		}
		printf("\n成功删除节点！！\n");

	}
	else
	{
		printf("\n没有找到要删除的节点！！\n");
	}
	return 0;
}

//依次删除节点，但是删之前要缓存一个，不然删除了前一个节点后，找不到下一个要删除的节点的位置了
int SList_Destroy(SLIST *pHead)
{
	SLIST *pTmp = NULL;
	if (pHead == NULL)
	{
		return -1;
	}
    
	while (pHead)
	{ 
		pTmp = pHead->next;    //删除一个节点之前，先缓存此节点存储的下一个节点的地址
		free(pHead);           //删除此节点
		pHead = pTmp;          //下一个节点的位置变为头指针
	}

	return 0;
}
//逆置也是一个个节点进行操作的
//把头节点指向末尾，然后反向向前
//逆置过程中也要缓存下一个节点的next地址
int SList_Reverse(SLIST *pHead)
{
	if (pHead == NULL || pHead->next == NULL || pHead->next->next == NULL)
	{
		return 0;
	}

	SLIST *p = NULL;  //前驱指针
	SLIST *q = NULL;  //当前指针
	SLIST *t = NULL;  //缓存的一个节点

	//初始化
	/*p = pHead;
	q = pHead->next;*/
	p = pHead->next;
	q = pHead->next->next;

	//一个节点一个节点逆置  ,交换链表的方向来操作
	while (q)
	{
		t = q->next;   //缓存后面的链表
		q->next = p;   //逆置
		p = q;         //后移
		q = t;
	}

	//头节点变尾部节点 后置NULL
	
	pHead->next->next = NULL;
	pHead->next = p;

	

	return 0;
}
void main()
{
	int ret = 0;
	SLIST *list = NULL;
	
	//list = SList_Creat();
	ret = SList_Creat2(&list);
	if (ret != 0)
	{
		printf("func SList_Creat2() err : %d", ret);
	}


	ret = SList_Print(list);
	if (ret != 0)
	{
		printf("func SList_Print() err : %d", ret);
	}

	ret = SList_NodeInsert(list, 20, 19);
	if (ret != 0)
	{
		printf("func SList_NodeInsert() err : %d", ret);
	}

	ret = SList_Print(list);

	ret = SList_NodeDelete(list, 19);
	if (ret != 0)
	{
		printf("func SList_NodeDelete() err : %d", ret);
	}

	ret = SList_Print(list);

	ret = SList_Reverse(list);
	if (ret != 0)
	{
		printf("func SList_Reverse() err : %d", ret);
	}

	ret = SList_Print(list);

	ret = SList_Destroy(list);
	if (ret != 0)
	{
		printf("func SList_Destroy() err : %d", ret);
	}
	system("pause");
	return;
}