#pragma once

//配置文件读写集成框架

#ifndef __CFG_OP_H__    //如果没有定义cfg_op.h，则定义一个
#define __CFG_OP_H__

#ifdef __cplusplus     //如果是C++编译器，则按C语言风格执行
extern "C" {

#endif

	//获取配置项
	int GetCfgItem(char *pFileName/*in*/, char *pKey/*in*/, char *pValue/*in*/, int *pValueLen/*in*/);

	//写入配置项
	int WriteCfgItem(char *pFileName/*in*/, char *pItemName/*in*/, char *pItemValue/*out*/, int *pItemValueLen/*out*/);

#ifdef __cplusplus
}
#endif

#endif
