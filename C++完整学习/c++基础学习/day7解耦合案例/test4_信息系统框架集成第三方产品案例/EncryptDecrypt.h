#ifndef _ENCRYPTDECRYPT_H
#define _ENCRYPTDECRYPT_H

#ifdef __cplusplus
extern "C" {
#endif


	int DesEnc(unsigned char *plain, int plainlen, unsigned char *cryptdata, int *cryptlen);

	int DesDec(unsigned char *cryptdata, int cryptlen, unsigned char *plain, int *plainlen);

#ifdef __cplusplus
}
#endif


#endif
