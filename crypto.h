#include <openssl/evp.h>

static void checksum_art(FILE * fp, const EVP_MD * type)
{
	int i, bytes;
	
	EVP_MD_CTX *ctx;
	ctx = EVP_MD_CTX_new();
	
	EVP_DigestInit_ex(ctx, type, NULL);
	
	unsigned char buf[1028], data[128], frt[128];
	
	while ((bytes = fread (buf, 1, 1028, fp)) != 0)
	{
		EVP_DigestUpdate(ctx, buf, bytes);
	}
	
	unsigned int s;
	
	EVP_DigestFinal(ctx, frt, &s);
	EVP_MD_CTX_free(ctx);
	
	EVP_MD_CTX *ctx2;
	ctx2 = EVP_MD_CTX_new();
	
	EVP_DigestInit_ex(ctx2, type, NULL);
	EVP_DigestUpdate(ctx2, frt, 64);
	EVP_DigestFinal(ctx2, data, &s);
	EVP_MD_CTX_free(ctx2);
	strcat((char *)data, (char *)frt);
	
	max_height = (s * 2) / 8;
	
	i = 0;
	for(i = 0; i < s * 2; i++)
	{
		sprintf(&ascii_art[i / 8][i % 8 * 2],"%02x", data[i]);
		int len = strlen(ascii_art[i / 8]);
		if (len > max_width)
		{
			max_width = len;
		}
	}
	
	rewind(fp);
}
