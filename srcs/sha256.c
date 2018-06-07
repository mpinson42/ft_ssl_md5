#include "md5.h"

uint32_t rigthrotat(uint32_t x, uint32_t n)
{
	return ((((unsigned int)x >> n)) | (x << (32 - n)));
}

const uint32_t k2[] = {0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5, 0x3956c25b, 0x59f111f1, 0x923f82a4, 0xab1c5ed5,
   0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3, 0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174,
   0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc, 0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da,
   0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7, 0xc6e00bf3, 0xd5a79147, 0x06ca6351, 0x14292967,
   0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13, 0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85,
   0xa2bfe8a1, 0xa81a664b, 0xc24b8b70, 0xc76c51a3, 0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070,
   0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5, 0x391c0cb3, 0x4ed8aa4a, 0x5b9cca4f, 0x682e6ff3,
   0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208, 0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2
};

int ft_prepross_sha256(unsigned char *init_msg, size_t len, t_gen *g)
{
    g->h0 = 0x6a09e667;
    g->h1 = 0xbb67ae85;
    g->h2 = 0x3c6ef372;
    g->h3 = 0xa54ff53a;
    g->h4 = 0x510e527f;
    g->h5 = 0x9b05688c;
    g->h6 = 0x1f83d9ab;
    g->h7 = 0x5be0cd19;
    g->new_len = len + 1;
    while(g->new_len%64!=60)
        g->new_len++;
    if(!(g->msg = malloc(g->new_len * 8 + 64)))
        return (-1);
    g->msg = ft_bzero(g->msg, g->new_len + 64);
    ft_strcpy((char*)g->msg, (const char *)init_msg);
    *(uint32_t*)(g->msg + len) = 0x80;
    g->i = 0;
    while(g->i < g->new_len / 4)
    {
        *(uint32_t*)&g->msg[g->i] = revers_uint32(*(uint32_t*)&g->msg[g->i]);
        g->i+=4;
    }
    *(uint64_t*)(g->msg + g->new_len) = (uint64_t)(8*len);
    g->offset = 0;
    return(0);
}

int sha256(unsigned char *init_msg, size_t len, t_gen *g)
{
	if(ft_prepross_sha256(init_msg, len, g) == -1)
        return (-1);

    while(g->offset<g->new_len) {
    	g->w = (uint32_t *)g->msg + g->offset;
    	g->i = 15;
    	while (++g->i < 64)
    	{
    		g->tmp3   = rigthrotat(g->w[g->i-15], 7) ^ rigthrotat(g->w[g->i-15], 18) ^ (g->w[g->i-15] >> 3);
            g->tmp4   = rigthrotat(g->w[g->i-2], 17) ^ rigthrotat(g->w[g->i-2], 19) ^ (g->w[g->i-2] >> 10);
            g->w[g->i] = g->w[g->i-16] + g->tmp3 + g->w[g->i-7] + g->tmp4;
    	}
    	g->a = g->h0;
	    g->b = g->h1;
	    g->c = g->h2;
	    g->d = g->h3;
	    g->e = g->h4;
	    g->f = g->h5;
	    g->g = g->h6;
	    g->h = g->h7;


	    g->i = -1;
	    while(++g->i < 64)
	    {
	    	g->tmp4 = rigthrotat(g->e, 6) ^ rigthrotat(g->e, 11) ^ rigthrotat(g->e, 25);
            g->ch = (g->e & g->f) ^ ((~g->e) & g->g);
            g->tmp1 = g->h + g->tmp4 + g->ch + k2[g->i] + g->w[g->i];
            g->tmp3 = rigthrotat(g->a, 2) ^ rigthrotat(g->a, 13) ^ rigthrotat(g->a, 22);
            g->maj = (g->a & g->b) ^ (g->a & g->c) ^ (g->b & g->c);
            g->tmp2 = g->tmp3 + g->maj;
            g->h = g->g;
            g->g = g->f;
            g->f = g->e;
            g->e = g->d + g->tmp1;
            g->d = g->c;
            g->c = g->b;
            g->b = g->a;
            g->a = g->tmp1 + g->tmp2;
	    }

	    g->h0 += g->a;
	    g->h1 += g->b;
	    g->h2 += g->c;
	    g->h3 += g->d;
	    g->h4 += g->e;
	    g->h5 += g->f;
	    g->h6 += g->g;
	    g->h7 += g->h;

    	g->offset += 64;
    }

    free(g->msg);
	return(0);
}