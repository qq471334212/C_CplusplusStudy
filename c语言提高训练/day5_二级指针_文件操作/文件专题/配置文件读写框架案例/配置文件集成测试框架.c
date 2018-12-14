#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"cfg_op.h"

#define CFGNAME "E:/testCfg.ini"   //�궨����������ļ�
void showMenu()
{
	printf("==========================\n");
	printf("(1)����д�����ļ�\n");
	printf("(2)���Զ������ļ�\n");
	printf("����������˳�\n");
	printf("==========================\n");
}
//������

	//���Զ�������
	int TestGetCfgItem()
	{
		int  ret = 0;
		char name[1024] = { 0 };
		char value[1024] = { 0 };
		int  valueLen = 0;

		printf("\n������Key: ");
		scanf("%s", name);


		ret = GetCfgItem(CFGNAME/*in*/, name/*in*/, value/*out*/, &valueLen/*out*/);
		if (ret != 0)
		{
			printf("func GetCfgItem() err : %d\n", ret);
			return ret;
		}
		printf("\n���������Value =  %s \n",value);
		return ret;
	}

	//����д��������
	int TestWriteCfgItem()
	{
		int ret = 0;
		char name[1024] = { 0 };
		char value[1024] = { 0 };

		printf("\n������Key: ");
		scanf("%s", name);

		printf("\n������Value: ");
		scanf("%s", value);

		ret = WriteCfgItem(CFGNAME/*in*/, name/*in*/, value/*out*/, strlen(value)/*out*/);
		if (ret != 0)
		{
			printf("func WriteCfgItem() err : %d\n", ret);
			return ret;
		}
		printf("\n��д����� Key %s = Value %s \n", name, value);
		return ret;
	}

void main()
{
	int choice;

	for (;;)
	{
		//��ʾһ���˵�
		showMenu();
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:   //д������
			TestWriteCfgItem();
			break;
		case 2:   //��������
			TestGetCfgItem();
			break;
		case 0:   //�˳�
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