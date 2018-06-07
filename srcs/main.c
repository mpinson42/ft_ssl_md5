/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpinson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 18:12:04 by mpinson           #+#    #+#             */
/*   Updated: 2018/06/07 18:12:06 by mpinson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "md5.h"

void		ft_bonus_ssl(t_gen *g, int confirm, char *red)
{
	while (confirm == 0)
	{
		write(1, "ft_ssl> ", 8);
		fake_gnl(&red);
		if (ft_strcmp(red, "md5") == 0)
			confirm = 1;
		else if (ft_strcmp(red, "sha256") == 0)
			confirm = 2;
		else if (ft_strcmp(red, "quit") == 0)
			return ;
		else
		{
			ft_putstr("ft_sll: Error: '");
			ft_putstr(red);
			ft_putstr("' is an invalid command.\n\nStandard commands:\n\n\
				Message Digestcommands:\nmd5\nsha256\n\nCipher commands:\n");
		}
	}
	fake_gnl_all(&red, 0);
	if (confirm == 1)
		go_md5(red, g);
	else if (confirm == 2)
		go_sha256(red, g);
	return ;
}

void		file_no_rotat(t_gen *g, char **argv)
{
	if (!g->f_q)
	{
		if (ft_strcmp(argv[1], "sha256") == 0)
			ft_putstr("SHA256 (");
		else
			ft_putstr("MD5 (");
		ft_putstr(argv[g->pars]);
		ft_putstr(") = ");
	}
	if (ft_strcmp(argv[1], "sha256") == 0)
		go_sha256(g->stdin, g);
	else
		go_md5(g->stdin, g);
	ft_putchar('\n');
}

void		file_rotat(t_gen *g, char **argv)
{
	if (no_such_file(g, argv) == -1)
		return ;
	fake_gnl_all(&g->stdin, g->fd);
	if (!g->f_r)
		file_no_rotat(g, argv);
	else
	{
		if (ft_strcmp(argv[1], "sha256") == 0)
			go_sha256(g->stdin, g);
		else
			go_md5(g->stdin, g);
		if (!g->f_q)
		{
			ft_putstr(" ");
			ft_putstr(argv[g->pars]);
			ft_putstr("\n");
		}
		else
			ft_putstr("\n");
	}
	g->pars++;
}

void		md5_sha(t_gen *g, char **argv, int argc)
{
	pars_entre(g, argc, argv);
	if (g->f_p || (!g->nb_file && !g->f_s))
	{
		fake_gnl_all(&g->stdin, 0);
		if (g->f_p)
			ft_putstr(g->stdin);
		if (ft_strcmp(argv[1], "sha256") == 0)
			go_sha256(g->stdin, g);
		else
			go_md5(g->stdin, g);
		ft_putstr("\n");
	}
	g->pars = 2;
	while (g->pars < argc)
		if (print_s(g, argv, argc) == -1)
			break ;
	while (g->pars < argc)
		file_rotat(g, argv);
}

int			main(int argc, char **argv)
{
	t_gen	g;

	if (argc == 1)
		ft_bonus_ssl(&g, 0, NULL);
	if (argc == 1)
		return (0);
	if (ft_strcmp(argv[1], "md5") == 0 || ft_strcmp(argv[1], "sha256") == 0)
	{
		md5_sha(&g, argv, argc);
	}
	else if (ft_strcmp(argv[1], "sha256") == 0)
		go_sha256(ft_strdup(argv[2]), &g);
	else
	{
		ft_putstr("ft_sll: Error: '");
		ft_putstr(argv[2]);
		ft_putstr("' is an invalid command.\n\nStandard commands:\n\n\
			Message Digest commands:\nmd5\nsha256\n\nCipher commands:");
	}
	return (0);
}
