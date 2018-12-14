#include<iostream>
#include<string>
#include<list>
using namespace std;

//������Ŀ¼�ṹ
//����Ŀ¼����ӿ�
class IFile
{
public:
	virtual void display() = 0;
	virtual int add(IFile *ifile) = 0;
	virtual int remove(IFile *ifile) = 0;
	virtual list<IFile *>* getChild() = 0;
};

//�ļ�
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
//Ŀ¼
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
//�ݹ����ʾ��
//1.��ʾ���ڵ�Ŀ¼������
//2.�����ڵ����Ӻ��� --��
      //1.��������ֱ����ʾ���֣�
      //2.����Ŀ¼���ݹ�ص��øú�����showTree(��Ŀ¼)
void showTree(IFile *root,int level)    //level��ʾĿ¼�ȼ�����
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
	root->display();   //����ʾ���ڵ�

	mylist = root->getChild();   //��ȡ���ӽڵ�
	if (mylist != NULL)          //˵���Ǹ�Ŀ¼
	{
		//��ʾĿ¼�µ��ļ�
		for (list<IFile *>::iterator it = mylist->begin(); it != mylist->end(); it++)
		{
			if ((*it)->getChild() == NULL)
			{
				for (i = 0; i <= level; i++)
				{
					printf("\t");
				}
				//���Ŀ¼�����ļ�ֱ����ʾ
				(*it)->display();
			}
			else
			{
				//���Ŀ¼�»���һ��Ŀ¼����ݹ����showTree()����
				showTree(*it, level + 1);
			}
		}
	}
}

//Ŀ¼�ṹ
//root C
//C: dir1 , aaa.txt
//C: dir1(dir2 , bbb.txt), aaa.txt

void main161()
{
	Dir *root = NULL;                //��Ŀ¼
	Dir *dir1 = NULL;
	Dir *dir2 = NULL;
	root = new Dir("C");       
	//root->display();
	dir1 = new Dir("dir1");

	File *aaafile = new File("aaa.txt");
	//����ļ��µĺ���
	root->add(dir1);
	root->add(aaafile);

	list<IFile *> *mylist = root->getChild();  //��ȡ��Ŀ¼root�ڵ��µ� ���Ӽ���
	//�����ļ�
	for (list<IFile *>::iterator it = mylist->begin(); it != mylist->end(); it++)
	{
		(*it)->display();
	}

	//�ں��ӽڵ�������ӽڵ�
	dir2 = new Dir("dir2");
	File *bbbfile = new File("bbb.txt");
	dir1->add(dir2);
	dir1->add(bbbfile);

	cout << "ͨ��showTree()�ķ�ʽ ��ʾ root�ڵ��µ� �����ӽ��" << endl;
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