#ifndef _ENCRYPTDECRYPT_H           //���û�����ͷ�ļ�
#define _ENCRYPTDECRYPT_H           //����һ��

#ifdef __cplusplus
extern "C" {
#endif


	int DesEnc(unsigned char *plain, int plainlen, unsigned char *cryptdata, int *cryptlen);

	int DesDec(unsigned char *cryptdata, int cryptlen, unsigned char *plain, int *plainlen);

#ifdef __cplusplus
}
#endif

#endif
