#pragma once

//�����ļ���д���ɿ��

#ifndef __CFG_OP_H__    //���û�ж���cfg_op.h������һ��
#define __CFG_OP_H__

#ifdef __cplusplus     //�����C++����������C���Է��ִ��
extern "C" {

#endif

	//��ȡ������
	int GetCfgItem(char *pFileName/*in*/, char *pKey/*in*/, char *pValue/*in*/, int *pValueLen/*in*/);

	//д��������
	int WriteCfgItem(char *pFileName/*in*/, char *pItemName/*in*/, char *pItemValue/*out*/, int *pItemValueLen/*out*/);

#ifdef __cplusplus
}
#endif

#endif
