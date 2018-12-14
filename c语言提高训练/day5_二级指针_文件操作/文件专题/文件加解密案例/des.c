#include "des.h"


int DesEnc(unsigned char *plain, int plainlen, unsigned char *cryptdata, int *cryptlen)
{
	for (int i = 0; i < plainlen; i++)
	{
		*(cryptdata + i) = *(plain + i) + 1;
	}
	*cryptlen = plainlen;
	return 0;
}

int DesDec(unsigned char *cryptdata, int cryptlen, unsigned char *plain, int *plainlen)
{
	for (int i = 0; i < cryptlen; i++)
	{
		*(plain + i) = *(cryptdata + i) - 1;
	}
	*plainlen = cryptlen;
	return 0;
}