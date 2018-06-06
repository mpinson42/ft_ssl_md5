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

void fake_gnl(char **ptr)
{
	char c[2];
	int verif;
	char *str;

	verif = 42;
	c[1] = 0;
	str = ft_strdup("");
	while(verif > 0)
	{
		verif = read(0,c,1);
		if(c[0] == 10)
			verif = 0;
		if(verif == 0)
		{
			break;
		}
		str = ft_strjoin(str,c);
	}
	ptr[0] = str;

}

void fake_gnl_all(char **ptr, int fd)
{
	char c[2];
	int verif;
	char *str;

	c[1] = 0;
	verif = 42;
	str = ft_strdup("");
	while(verif > 0)
	{
		verif = read(fd,c,1);
		if(verif == 0)
		{
			break;
		}
		str = ft_strjoin(str,c);
	}
	ptr[0] = str;

}
 
void go_md5(char *std, t_gen *g)
{
	size_t len = ft_strlen(std);
	    if(md5((uint8_t *)std, len, g) == -1)
	    	return;
	    uint8_t *p;
 
    // display result
 
	   ft_putstr(add0(ft_itoa_base(revers_uint32(g->h0), 16)));
	    ft_putstr(add0(ft_itoa_base(revers_uint32(g->h1), 16)));
	    ft_putstr(add0(ft_itoa_base(revers_uint32(g->h2), 16)));
	    ft_putstr(add0(ft_itoa_base(revers_uint32(g->h3), 16)));
}

void go_sha256(char *std, t_gen *g)
{
	size_t len = ft_strlen(std);
	    if(sha256((uint8_t *)std, len, g) == -1)
	    	return;
	    uint8_t *p;
/*	 char *save;
	 save = unsigned_itoa_base(g->h0,16);
	 ft_putstr(save);
	 free(save);
	 save = unsigned_itoa_base(g->h0,16);
	 ft_putstr(save);
	 free(save);
	 save = unsigned_itoa_base(g->h0,16);
	 ft_putstr(save);
	 free(save);
	 save = unsigned_itoa_base(g->h0,16);
	 ft_putstr(save);
	 free(save);
	 save = unsigned_itoa_base(g->h0,16);
	 ft_putstr(save);
	 free(save);
	 save = unsigned_itoa_base(g->h0,16);
	 ft_putstr(save);
	 free(save);
	 save = unsigned_itoa_base(g->h0,16);
	 ft_putstr(save);
	 free(save);

	 ft_putstr("\n");*/

	    uint32_t digest[8] = { g->h0, g->h1, g->h2, g->h3, g->h4, g->h5, g->h6, g->h7 };
//	 printf("%s\n",ft_itoa_base(digest[1],16));
    	printf("%x%x%x%x%x%x%x%x", digest[0], digest[1], digest[2], digest[3], digest[4], digest[5], digest[6], digest[7]);

}


int main(int argc, char **argv) { 
 	t_gen g;
 	char *red;

    if (argc < 1) {
        ft_putstr("usage: ft_ssl command [command opts] [command args]\n");
        return 1;
    }

    if(argc == 1)
    {
    	int confirm = 0;
    	while(confirm == 0)
    	{
    		write(1,"ft_ssl> ",8);
    		fake_gnl(&red);

    		if(ft_strcmp(red, "md5") == 0)
    			confirm = 1;
    		else if(ft_strcmp(red, "sha256") == 0)
    			confirm = 2;
    		else if(ft_strcmp(red, "quit") == 0)
    			return(0);
    		else
    		{
    			ft_putstr("ft_sll: Error: '");
				ft_putstr(red);
				ft_putstr("' is an invalid command.\n\nStandard commands:\n\nMessage Digest commands:\nmd5\nsha256\n\nCipher commands:\n");
    		}
    	}
    	fake_gnl_all(&red, 0);
    	if(confirm == 1)
    	{
    		go_md5(red, &g);
	    }
	    else if(confirm == 2)
	    {
	    	go_sha256(red, &g);
	    }
    }


   
    if(ft_strcmp(argv[1], "md5") == 0 || ft_strcmp(argv[1], "sha256") == 0)
    {
	    char *msg = argv[2];
	    g.i = 2;
	    g.f_p = 0;
	    g.f_q = 0;
	    g.f_r = 0;
	    g.f_s = 0;
	    while(g.i < argc)
	    {
	    	if(ft_strcmp("-p", argv[g.i]) == 0)
	    		g.f_p = 1;
	    	else if(ft_strcmp("-q", argv[g.i]) == 0)
	    		g.f_q = 1;
	    	else if(ft_strcmp("-r", argv[g.i]) == 0)
	    		g.f_r = 1;
	    	else if(ft_strcmp("-s", argv[g.i]) == 0)
	    	{
	    		g.i++;
	    		g.f_s++;
	    	}
	    	else
	    		break;

	    	g.i++;
	    }
	    g.nb_file = g.i - argc;
	    char *std;
	    if(g.f_p || (!g.nb_file && !g.f_s))
	    {
	    	fake_gnl_all(&std, 0);
	    	if(g.f_p)
	    		printf("%s", std);
	    	if(ft_strcmp(argv[1], "sha256") == 0)
	    		go_sha256(std, &g);
	    	else
	    		go_md5(std, &g);
	    	printf("\n");
	    }
	    g.pars = 2;
	    while(g.pars < argc)
	    {

	    	if(ft_strcmp("-p", argv[g.pars]) == 0)
	    		g.f_p = 1;
	    	else if(ft_strcmp("-q", argv[g.pars]) == 0)
	    		g.f_q = 1;
	    	else if(ft_strcmp("-r",argv[g.pars]) == 0)
	    		g.f_r = 1;
	    	else if(ft_strcmp("-s", argv[g.pars]) == 0)
	    	{
	    		g.pars++;
	    		if(g.pars < argc)
	    		{
	    			if(!g.f_r)
	    			{
	    				if(!g.f_q)
	    				{
	    					if(ft_strcmp(argv[1], "sha256") == 0)
		    					ft_putstr("SHA256 (\"");
		    				else
		    					ft_putstr("MD5 (\"");
		    				ft_putstr(argv[g.pars]);
		    				ft_putstr("\") = ");
	    				}
	    				if(ft_strcmp(argv[1], "sha256") == 0)
	    					go_sha256(argv[g.pars], &g);
	    				else
	    					go_md5(argv[g.pars], &g);
	    			
	    					ft_putchar('\n');
	    			}
	    			else
	    			{
	    				if(ft_strcmp(argv[1], "sha256") == 0)
	    					go_sha256(argv[g.pars], &g);
	    				else
	    					go_md5(argv[g.pars], &g);

	    				if(!g.f_q)
	    				{
	    					ft_putstr(" \"");
	    					ft_putstr(argv[g.pars]);
	    					ft_putstr("\"\n");
	    				}
	    				else
	    					ft_putstr("\n");
	    			}
	    		}
	    			
	    	}
	    	else
	    		break;
	    	g.pars++;
	    //	ft_putstr(argv[g.i]);
	    //	ft_putstr("\n");
	    	//printf("%s\n", argv[g.i]);
	    }

	    while (g.pars < argc)
	    {
	    	int fd;
	    	if((fd = open(argv[g.pars], O_RDONLY)) < 0)
	    	{
	    		if(ft_strcmp(argv[1], "sha256") == 0)
	    			ft_putstr("ft_ssl: sha256: ");
	    		else
	    			ft_putstr("ft_ssl: md5: ");
	    		ft_putstr(argv[g.pars]);
	    		ft_putstr(": No such file or directory\n");
	    		g.pars++;
	    		continue;
	    	}
	    	fake_gnl_all(&g.stdin, fd);

	    	if(!g.f_r)
	    			{
	    				if(!g.f_q)
	    				{
	    					if(ft_strcmp(argv[1], "sha256") == 0)
		    					ft_putstr("SHA256 (");
		    				else
		    					ft_putstr("MD5 (");
		    				ft_putstr(argv[g.pars]);
		    				ft_putstr(") = ");
	    				}
	    				go_md5(g.stdin, &g);
	    			
	    					ft_putchar('\n');
	    			}
	    			else
	    			{
	    				
	    				go_md5(g.stdin, &g);

	    				if(!g.f_q)
	    				{
	    					ft_putstr(" ");
	    					ft_putstr(argv[g.pars]);
	    					ft_putstr("\n");
	    				}
	    				else
	    					ft_putstr("\n");
	    			}


	    	g.pars++;
	    }
	   // printf("%d\n", g.i);


	    //std = ft_strdup("pickle rick\n");
	    
	}
	else if (ft_strcmp(argv[1], "sha256") == 0)
	{
		go_sha256(ft_strdup(argv[2]),&g);
	}
	else
	{
		ft_putstr("ft_sll: Error: '");
		ft_putstr(argv[2]);
		ft_putstr("' is an invalid command.\n\nStandard commands:\n\nMessage Digest commands:\nmd5\nsha256\n\nCipher commands:");

	}
    
 
    return 0;
}
