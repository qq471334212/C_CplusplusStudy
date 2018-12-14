    //在软件开发过程中，接口要求紧，模块要求松





	//1.分清楚功能
	//2.分析出功能的输入与输出
	//3.实现代码

	//写文件，并且判断如果key已经存在的话，则是修改功能
	int WriteCfgItem(const char *filename/*in*/, const char *key/*in*/, const char *value/*in*/);  //合理的封装接口

	////修改配置文件,跟写的功能是一样的，但是有一个前提是调用者知道键key已经存在了，跟写的接口应该放在一起
	//int ModifyCfgItem(const char *filename/*in*/, const char *key/*in*/, const char *value/*in*/);

	//读配置文件
	int GetCfgItem(const char *filename/*in*/, const char *key/*in*/, char *value/*in*/);

	int GetCfgItem2(const char *filename/*in*/, const char *key/*in*/, char **value/*out*/);   //将一级指针地址甩出来