    //��������������У��ӿ�Ҫ�����ģ��Ҫ����





	//1.���������
	//2.���������ܵ����������
	//3.ʵ�ִ���

	//д�ļ��������ж����key�Ѿ����ڵĻ��������޸Ĺ���
	int WriteCfgItem(const char *filename/*in*/, const char *key/*in*/, const char *value/*in*/);  //����ķ�װ�ӿ�

	////�޸������ļ�,��д�Ĺ�����һ���ģ�������һ��ǰ���ǵ�����֪����key�Ѿ������ˣ���д�Ľӿ�Ӧ�÷���һ��
	//int ModifyCfgItem(const char *filename/*in*/, const char *key/*in*/, const char *value/*in*/);

	//�������ļ�
	int GetCfgItem(const char *filename/*in*/, const char *key/*in*/, char *value/*in*/);

	int GetCfgItem2(const char *filename/*in*/, const char *key/*in*/, char **value/*out*/);   //��һ��ָ���ַ˦����