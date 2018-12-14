#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;

//传统出错处理机制
int my_strcpy(char *to, char *from)
{
	if (from == NULL)
	{
		return 1;
	}
	if (to == NULL)
	{
		return 2;
	}
	if (*from == 'a')
	{
		return 3;
	}
	while (*from != '\0')
	{
		*to = *from;
		to++;
		from++;
	}
	*to = '\0';
	return 0;
}

//throw int类型异常
void my_strcpy1(char *to, char *from)
{
	if (from == NULL)
	{
		throw 1;
	}
	if (to == NULL)
	{
		throw 2;
	}
	if (*from == 'a')
	{
		throw 3;
	}
	while (*from != '\0')
	{
		*to = *from;
		to++;
		from++;
	}
	*to = '\0';
}

//throw char*类型异常
void my_strcpy2(char *to, char *from)
{
	if (from == NULL)
	{
		throw "func my_strcpy() err: 源buf出错\n";
	}
	if (to == NULL)
	{
		throw "func my_strcpy() err: 目的buf出错\n";
	}
	if (*from == 'a')
	{
		throw "func my_strcpy() err: 拷贝过程出错\n";
	}
	while (*from != '\0')
	{
		*to = *from;
		to++;
		from++;
	}
	*to = '\0';
}

class BadSrcType
{
public:
	BadSrcType() { cout << "BadSrcType构造函数！" << endl; }
	BadSrcType(const BadSrcType & bst) { cout << "BadSrcType拷贝构造函数！" << endl; }
	~BadSrcType() { cout << "BadSrcType析构函数！" << endl; }
};

class BadDecType
{
public:
	BadDecType() { cout << "BadDecType构造函数！" << endl; }
	BadDecType(const BadDecType & bdt) { cout << "BadDecType拷贝构造函数！" << endl; }
	~BadDecType() { cout << "BadDecType析构函数！" << endl; }
};

class BadProType
{
public:
	BadProType() { cout << "BadProType构造函数！" << endl; }
	BadProType(const BadProType & bpt) { cout << "BadProType拷贝构造函数！" << endl; }
	~BadProType() { cout << "BadProType析构函数！" << endl; }
};

//对象类型异常
void my_strcpy3(char *to, char *from)
{
	if (from == NULL)
	{
		throw BadSrcType();    //会不会分配匿名对象呢？
	}
	if (to == NULL)
	{
		throw BadDecType();
	}
	if (*from == 'a')
	{
		cout << "开始BadProType类型异常....." << endl;
		throw BadProType();
	}

	if (*from == 'b')
	{
		throw &(BadProType());   //抛出地址，让指针类型被捕获
	}

	if (*from == 'c')
	{
		throw new BadProType;   //抛出地址，让指针类型被捕获，并且这样不会造成野指针，程序安全
	}


	while (*from != '\0')
	{
		*to = *from;
		to++;
		from++;
	}
	*to = '\0';
}

int main13()
{
	int ret = 0;
	char buf1[] = "bsadsad";
	char buf2[1024] = { 0 };
	//char *buf2 = NULL;
	/*
	ret = my_strcpy(buf2, buf1);
	if (ret != 0)      //传统C语言错误处理
	{
		switch (ret)
		{
		case 1:
			cout << "func my_strcpy() err: 源buf出错" << endl;
			break;
		case 2:
			cout << "func my_strcpy() err: 目的buf出错" << endl;
			break;
		case 3:
			cout << "func my_strcpy() err: 拷贝过程出错" << endl;
			break;
		default:
			cout << "func my_strcpy() err: 未知错误" << endl;
			break;
		}
	}
	*/


	//C++捕获int类型变量
	//{
	//	try {
	//		//my_strcpy1(buf2, buf1);
	//		my_strcpy2(buf2, buf1);
	//	}
	//	catch (int e)     //变量e可以写，也可以不屑 //捕获int 类型
	//	{
	//		cout << e <<"int 类型异常" << endl;
	//	}
	//	catch (const char *c)     //捕获char *类型  //这个指针的内存分配是在抛出的时候分配的
	//	{
	//		cout << c << "const char* 类型异常" << endl;
	//	}
	//	catch (...)
	//	{
	//		cout << "未知 类型异常" << endl;
	//	}
	//}


	//捕获类对象异常
	{
		try {
			my_strcpy3(buf2, buf1);
		}
		catch (int e)     //变量e可以写，也可以不屑 //捕获int 类型
		{
			cout << e << "int 类型异常" << endl;
		}
		catch (const char *c)     //捕获char *类型  //这个指针的内存分配是在抛出的时候分配的
		{
			cout << c << "const char* 类型异常" << endl;
		}
		catch (BadSrcType e)      //抛出时，是把匿名对象拷贝给e，还是e就是匿名对象
		{                         //经过测试，是把匿名对象拷贝给e，调用了拷贝构造函数
			cout << "func my_strcpy() err: 源buf出错 BadSrcType类型异常" << endl;
		}
		catch (BadDecType e)     
		{
			cout << "func my_strcpy() err: 目的buf出错 BadDecType类型异常" << endl;
		}
		/*
		catch (BadProType e)     结论1：接受异常时使用一个异常变量。则进行拷贝构造过程
		{
			cout << "func my_strcpy() err: 拷贝过程出错 BadProType类型异常" << endl;
		}
		*/

		//用引用捕捉是最好的
		//结论2：使用引用的话，会使用抛出时的匿名对象
		catch (BadProType &e)
		{
			cout << "func my_strcpy() err: 拷贝过程出错 BadProType类型异常" << endl;
		}

		//结论3：指针可以和引用元素一起捕捉，但是对象元素和引用不可以写一起
		catch (BadProType *e)    //捕获是严格按照类型来匹配的，抛出的是元素，所以指针类型接收不到，要向捕获到，则抛出也要是指针类型
			                     //在上面已经被析构了，形成野指针。不稳定，因此要动态控制生命周期
		{
			cout << "func my_strcpy() err: 拷贝过程出错 BadProType类型异常，捕获指针类型" << endl;
			delete e;
		}
		catch (...)
		{
			cout << "未知 类型异常" << endl;
		}
	}

	system("pause");
	return 0;
}