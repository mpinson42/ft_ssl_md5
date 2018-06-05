#ifndef MD5_H
# define MD5_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <unistd.h>
#include "libft.h"

typedef struct s_gen
{
	int new_len;

	uint32_t h0;
	uint32_t h1;
	uint32_t h2;
	uint32_t h3;
	uint32_t h4;
	uint32_t h5;
	uint32_t h6;
	uint32_t h7;

	uint32_t a;
	uint32_t b;
	uint32_t c;
	uint32_t d;
	uint32_t e;
	uint32_t f;
	uint32_t g;
	uint32_t h;

	uint32_t *w;

	uint8_t *msg;

	int i;
	uint32_t temp;
	uint32_t bits_len;
	int offset;

	uint32_t f_p;
	uint32_t f_q;
	uint32_t f_r;
	uint32_t f_s;


}				t_gen;

        int md5(uint8_t *init_msg, size_t len, t_gen *g);
        int sha256(uint8_t *init_msg, size_t len, t_gen *g);
        uint32_t revers_uint32(uint32_t n);
        uint64_t revers_uint64(uint64_t n);
#endif