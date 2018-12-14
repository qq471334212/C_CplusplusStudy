#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"cfg_op.h"

#define CFGNAME "E:/testCfg.ini"   //宏定义测试配置文件
void showMenu()
{
	printf("==========================\n");
	printf("(1)测试写配置文件\n");
	printf("(2)测试读配置文件\n");
	printf("其他任意键退出\n");
	printf("==========================\n");
}
//测试项

	//测试读配置项
	int TestGetCfgItem()
	{
		int  ret = 0;
		char name[1024] = { 0 };
		char value[1024] = { 0 };
		int  valueLen = 0;

		printf("\n请输入Key: ");
		scanf("%s", name);


		ret = GetCfgItem(CFGNAME/*in*/, name/*in*/, value/*out*/, &valueLen/*out*/);
		if (ret != 0)
		{
			printf("func GetCfgItem() err : %d\n", ret);
			return ret;
		}
		printf("\n你读出的是Value =  %s \n",value);
		return ret;
	}

	//测试写入配置项
	int TestWriteCfgItem()
	{
		int ret = 0;
		char name[1024] = { 0 };
		char value[1024] = { 0 };

		printf("\n请输入Key: ");
		scanf("%s", name);

		printf("\n请输入Value: ");
		scanf("%s", value);

		ret = WriteCfgItem(CFGNAME/*in*/, name/*in*/, value/*out*/, strlen(value)/*out*/);
		if (ret != 0)
		{
			printf("func WriteCfgItem() err : %d\n", ret);
			return ret;
		}
		printf("\n你写入的是 Key %s = Value %s \n", name, value);
		return ret;
	}

void main()
{
	int choice;

	for (;;)
	{
		//显示一个菜单
		showMenu();
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:   //写配置项
			TestWriteCfgItem();
			break;
		case 2:   //读配置项
			TestGetCfgItem();
			break;
		case 0:   //退出
			exit(0);
			break;
		default:
			exit(0);
			break;
		}
	}
	system("pause");
	return;
}