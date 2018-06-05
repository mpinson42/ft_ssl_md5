/*
	-q mode silancieu : enleve les annonce tout sauf les clef et le -p
	-p affiche l entre stendar en debut de printing
	-r affiche la clef avent le nom du fichier
*/

#include "md5.h"
char *add0(char *str)
{
	int i = ft_strlen(str);

	while(i < 8)
	{
		ft_putchar('0');
		i++;
	}
	return(str);
}


uint32_t revers_uint32(uint32_t n)
{

	return ((n >> 24) | ((n & 0xff0000) >> 8) | ((n & 0xff00) << 8) | (n << 24));
}

uint64_t revers_uint64(uint64_t n)
{
	return ((n & 0xff00000000000000) >> 56 \
			| (n & 0x00ff000000000000) >> 40 \
			| (n & 0x0000ff0000000000) >> 24 \
			| (n & 0x000000ff00000000) >> 8 \
			| (n & 0x00000000ff000000) << 8 \
			| (n & 0x0000000000ff0000) << 24 \
			| (n & 0x000000000000ff00) << 40 \
			| (n & 0x00000000000000ff) << 56);
}
 
int main(int argc, char **argv) { 
 	t_gen g;

    if (argc < 3) {
        ft_putstr("usage: ft_ssl command [command opts] [command args]\n");
        return 1;
    }

    if(ft_strcmp(argv[1], "md5") == 0)
    {
	    char *msg = argv[2];
	    g.i = 2;
	    while(g.i < argc)
	    {
	    	if(ft_strcmp("-p", argv[g.i]) == 0)
	    		g.f_p = 1;
	    	else if(ft_strcmp("-q", argv[g.i]) == 0)
	    		g.f_q = 1;
	    	else if(ft_strcmp("-r", argv[g.i]) == 0)
	    		g.f_r = 1;
	    	else if(ft_strcmp("-s", argv[g.i]) == 0)
	    		g.f_s = 1;
	    	else
	    		break;

	    	g.i++;
	    }

	    size_t len = ft_strlen(msg);
	    if(md5((uint8_t *)msg, len, &g) == -1)
	    	return(-1);
	    ft_putstr(add0(ft_itoa_base(revers_uint32(g.h0), 16)));
	    ft_putstr(add0(ft_itoa_base(revers_uint32(g.h1), 16)));
	    ft_putstr(add0(ft_itoa_base(revers_uint32(g.h2), 16)));
	    ft_putstr(add0(ft_itoa_base(revers_uint32(g.h3), 16)));
	}
	else if (ft_strcmp(argv[1], "sha256") == 0)
	{
		char *msg = argv[2];
	    size_t len = ft_strlen(msg);
	    if(sha256((uint8_t *)msg, len, &g) == -1)
	    	return(-1);
	    uint32_t digest[8] = { g.h0, g.h1, g.h2, g.h3, g.h4, g.h5, g.h6, g.h7 };



    	printf("\n\nDigest: %x%x%x%x%x%x%x%x\n", digest[0], digest[1], digest[2], digest[3], digest[4], digest[5], digest[6], digest[7]);
	    exit(0);
	    ft_putstr(add0(ft_itoa_base(revers_uint32(g.h0), 16)));
	    ft_putstr(add0(ft_itoa_base(revers_uint32(g.h1), 16)));
	    ft_putstr(add0(ft_itoa_base(revers_uint32(g.h2), 16)));
	    ft_putstr(add0(ft_itoa_base(revers_uint32(g.h3), 16)));
	    ft_putstr(add0(ft_itoa_base(revers_uint32(g.h4), 16)));
	    ft_putstr(add0(ft_itoa_base(revers_uint32(g.h5), 16)));
	    ft_putstr(add0(ft_itoa_base(revers_uint32(g.h6), 16)));
	    ft_putstr(add0(ft_itoa_base(revers_uint32(g.h7), 16)));
	}
	else
	{
		ft_putstr("ft_sll: Error: '");
		ft_putstr(argv[1]);
		ft_putstr("' is an invalid command.\n\nStandard commands:\n\nMessage Digest commands:\nmd5\nsha256\n\nCipher commands:");

	}
    
 
    return 0;
}
