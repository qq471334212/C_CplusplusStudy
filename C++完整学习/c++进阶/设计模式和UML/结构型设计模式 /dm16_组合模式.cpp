#include<iostream>
#include<string>
#include<list>
using namespace std;

//案例：目录结构
//定义目录抽象接口
class IFile
{
public:
	virtual void display() = 0;
	virtual int add(IFile *ifile) = 0;
	virtual int remove(IFile *ifile) = 0;
	virtual list<IFile *>* getChild() = 0;
};

//文件
class File :public IFile
{
public:
	File(string name)
	{
		m_name = name;
	}

	virtual void display()
	{
		cout << m_name << endl;
	}
	virtual int add(IFile *ifile)
	{
		return -1;
	}
	virtual int remove(IFile *ifile)
	{
		return -1;
	}
	virtual list<IFile *>* getChild()
	{
		return NULL;
	}
private:
	string m_name;
};
//目录
class Dir :public IFile
{
public:
	Dir(string name)
	{
		m_name = name;
		m_list = new list<IFile *>;
		m_list->clear();
	}

	virtual void display()
	{
		cout << m_name << endl;
	}
	virtual int add(IFile *ifile)
	{
		m_list->push_back(ifile);
		return 0;
	}
	virtual int remove(IFile *ifile)
	{
		m_list->remove(ifile);
		return 0;
	}
	virtual list<IFile *>* getChild()
	{
		return m_list;
	}
private:
	string m_name;
	list<IFile *>* m_list;
};
//递归地显示树
//1.显示根节点目录的名字
//2.若根节点有子孩子 --》
      //1.若是文字直接显示名字；
      //2.若是目录，递归地调用该函数，showTree(子目录)
void showTree(IFile *root,int level)    //level表示目录等级缩进
{
	list<IFile *> *mylist = NULL;
	int i = 0;
	for (i = 0; i < level; i++)
	{
		printf("\t");
	}

	if (root == NULL)
	{
		return;
	}
	root->display();   //先显示根节点

	mylist = root->getChild();   //获取孩子节点
	if (mylist != NULL)          //说明是个目录
	{
		//显示目录下的文件
		for (list<IFile *>::iterator it = mylist->begin(); it != mylist->end(); it++)
		{
			if ((*it)->getChild() == NULL)
			{
				for (i = 0; i <= level; i++)
				{
					printf("\t");
				}
				//如果目录下是文件直接显示
				(*it)->display();
			}
			else
			{
				//如果目录下还有一个目录，则递归调用showTree()函数
				showTree(*it, level + 1);
			}
		}
	}
}

//目录结构
//root C
//C: dir1 , aaa.txt
//C: dir1(dir2 , bbb.txt), aaa.txt

void main161()
{
	Dir *root = NULL;                //根目录
	Dir *dir1 = NULL;
	Dir *dir2 = NULL;
	root = new Dir("C");       
	//root->display();
	dir1 = new Dir("dir1");

	File *aaafile = new File("aaa.txt");
	//添加文件下的孩子
	root->add(dir1);
	root->add(aaafile);

	list<IFile *> *mylist = root->getChild();  //获取根目录root节点下的 孩子集合
	//遍历文件
	for (list<IFile *>::iterator it = mylist->begin(); it != mylist->end(); it++)
	{
		(*it)->display();
	}

	//在孩子节点下再添加节点
	dir2 = new Dir("dir2");
	File *bbbfile = new File("bbb.txt");
	dir1->add(dir2);
	dir1->add(bbbfile);

	cout << "通过showTree()的方式 显示 root节点下的 所有子结点" << endl;
	showTree(root,0);

	delete root;
	delete dir1;
	delete aaafile;
	delete dir2;
	delete bbbfile;
}

int main16()
{
	main161();
	system("pause");
	return 0;
}