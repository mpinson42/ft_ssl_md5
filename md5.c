#include "md5.h"
 
   const uint32_t r[] = {7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22,
                    5,  9, 14, 20, 5,  9, 14, 20, 5,  9, 14, 20, 5,  9, 14, 20,
                    4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23,
                    6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21};

    const uint32_t k[] = {
        0xd76aa478, 0xe8c7b756, 0x242070db, 0xc1bdceee,
        0xf57c0faf, 0x4787c62a, 0xa8304613, 0xfd469501,
        0x698098d8, 0x8b44f7af, 0xffff5bb1, 0x895cd7be,
        0x6b901122, 0xfd987193, 0xa679438e, 0x49b40821,
        0xf61e2562, 0xc040b340, 0x265e5a51, 0xe9b6c7aa,
        0xd62f105d, 0x02441453, 0xd8a1e681, 0xe7d3fbc8,
        0x21e1cde6, 0xc33707d6, 0xf4d50d87, 0x455a14ed,
        0xa9e3e905, 0xfcefa3f8, 0x676f02d9, 0x8d2a4c8a,
        0xfffa3942, 0x8771f681, 0x6d9d6122, 0xfde5380c,
        0xa4beea44, 0x4bdecfa9, 0xf6bb4b60, 0xbebfbc70,
        0x289b7ec6, 0xeaa127fa, 0xd4ef3085, 0x04881d05,
        0xd9d4d039, 0xe6db99e5, 0x1fa27cf8, 0xc4ac5665,
        0xf4292244, 0x432aff97, 0xab9423a7, 0xfc93a039,
        0x655b59c3, 0x8f0ccc92, 0xffeff47d, 0x85845dd1,
        0x6fa87e4f, 0xfe2ce6e0, 0xa3014314, 0x4e0811a1,
        0xf7537e82, 0xbd3af235, 0x2ad7d2bb, 0xeb86d391};

uint32_t leftrotate(uint32_t x, uint32_t c)
{
    return ((((x) << (c)) | ((x) >> (32 - (c)))));
}


int md5(uint8_t *init_msg, size_t len, t_gen *g) {
    g->h0 = 0x67452301;
    g->h1 = 0xefcdab89;
    g->h2 = 0x98badcfe;
    g->h3 = 0x10325476;
    g->new_len = len + 1;
  
    while(g->new_len%64!=56)
    	g->new_len++;
    if(!(g->msg = malloc(g->new_len + 64)))
    	return (-1);
    g->msg = ft_memset(g->msg, 0,g->new_len + 64);
    ft_memcpy(g->msg, init_msg, len);
    g->msg[len] = 0x80;
    g->bits_len = 8*len;
    ft_memcpy(g->msg + g->new_len, &g->bits_len, 4);
    g->offset = 0;
    while(g->offset<g->new_len) {
        g->w = (uint32_t *) (g->msg + g->offset);
        g->a = g->h0;
        g->b = g->h1;
        g->c = g->h2;
        g->d = g->h3;
        g->i = 0;
        while(g->i<64) { 
 
             if (g->i < 16) {
                g->f = (g->b & g->c) | ((~g->b) & g->d);
                g->g = g->i;
            } else if (g->i < 32) {
                g->f = (g->d & g->b) | ((~g->d) & g->c);
                g->g = (5*g->i + 1) % 16;
            } else if (g->i < 48) {
                g->f = g->b ^ g->c ^ g->d;
                g->g = (3*g->i + 5) % 16;          
            } else {
                g->f = g->c ^ (g->b | (~g->d));
                g->g = (7*g->i) % 16;
            }
            g->temp = g->d;
            g->d = g->c;
            g->c = g->b;
            g->b = g->b + leftrotate((g->a + g->f + k[g->i] + g->w[g->g]), r[g->i]);
            g->a = g->temp;
            g->i++;
        }
 
        g->h0 += g->a;
        g->h1 += g->b;
        g->h2 += g->c;
        g->h3 += g->d;
 		g->offset += 64;
    }
    free(g->msg);
    return (0);
}