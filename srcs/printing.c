/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpinson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 20:23:17 by mpinson           #+#    #+#             */
/*   Updated: 2018/06/07 20:23:18 by mpinson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "md5.h"

void		go_md5(char *std, t_gen *g)
{
	char	*tmp;

	if (md5((uint8_t *)std, ft_strlen(std), g) == -1)
		return ;
	tmp = unsigned_itoa_base(revers_uint32(g->h0), 16);
	add0(tmp);
	ft_putstr(tmp);
	free(tmp);
	tmp = unsigned_itoa_base(revers_uint32(g->h1), 16);
	add0(tmp);
	ft_putstr(tmp);
	free(tmp);
	tmp = unsigned_itoa_base(revers_uint32(g->h2), 16);
	add0(tmp);
	ft_putstr(tmp);
	free(tmp);
	tmp = unsigned_itoa_base(revers_uint32(g->h3), 16);
	add0(tmp);
	ft_putstr(tmp);
	free(tmp);
}

void		print_sha256(t_gen *g)
{
	char	*tmp;

	tmp = unsigned_itoa_base(g->h3, 16);
	add0(tmp);
	ft_putstr(tmp);
	free(tmp);
	tmp = unsigned_itoa_base(g->h4, 16);
	add0(tmp);
	ft_putstr(tmp);
	free(tmp);
	tmp = unsigned_itoa_base(g->h5, 16);
	add0(tmp);
	ft_putstr(tmp);
	free(tmp);
	tmp = unsigned_itoa_base(g->h6, 16);
	add0(tmp);
	ft_putstr(tmp);
	free(tmp);
	tmp = unsigned_itoa_base(g->h7, 16);
	add0(tmp);
	ft_putstr(tmp);
	free(tmp);
}

void		go_sha256(char *std, t_gen *g)
{
	char	*tmp;

	if (sha256((uint8_t *)std, ft_strlen(std), g) == -1)
		return ;
	tmp = unsigned_itoa_base(g->h0, 16);
	add0(tmp);
	ft_putstr(tmp);
	free(tmp);
	tmp = unsigned_itoa_base(g->h1, 16);
	add0(tmp);
	ft_putstr(tmp);
	free(tmp);
	tmp = unsigned_itoa_base(g->h2, 16);
	add0(tmp);
	ft_putstr(tmp);
	free(tmp);
	print_sha256(g);
}

void		print_sha224(t_gen *g)
{
	char	*tmp;

	tmp = unsigned_itoa_base(g->h3, 16);
	add0(tmp);
	ft_putstr(tmp);
	free(tmp);
	tmp = unsigned_itoa_base(g->h4, 16);
	add0(tmp);
	ft_putstr(tmp);
	free(tmp);
	tmp = unsigned_itoa_base(g->h5, 16);
	add0(tmp);
	ft_putstr(tmp);
	free(tmp);
	tmp = unsigned_itoa_base(g->h6, 16);
	add0(tmp);
	ft_putstr(tmp);
	free(tmp);
	tmp = unsigned_itoa_base(g->h7, 16);
	add0(tmp);
	ft_putstr(tmp);
	free(tmp);
}

void		go_sha224(char *std, t_gen *g)
{
	char	*tmp;

	if (sha224((uint8_t *)std, ft_strlen(std), g) == -1)
		return ;
	tmp = unsigned_itoa_base(g->h0, 16);
	add0(tmp);
	ft_putstr(tmp);
	free(tmp);
	tmp = unsigned_itoa_base(g->h1, 16);
	add0(tmp);
	ft_putstr(tmp);
	free(tmp);
	tmp = unsigned_itoa_base(g->h2, 16);
	add0(tmp);
	ft_putstr(tmp);
	free(tmp);
	print_sha224(g);
}
