#ifndef _ENCRYPTDECRYPT_H           //如果没有这个头文件
#define _ENCRYPTDECRYPT_H           //则定义一个

#ifdef __cplusplus
extern "C" {
#endif


	int DesEnc(unsigned char *plain, int plainlen, unsigned char *cryptdata, int *cryptlen);

	int DesDec(unsigned char *cryptdata, int cryptlen, unsigned char *plain, int *plainlen);

#ifdef __cplusplus
}
#endif

#endif
